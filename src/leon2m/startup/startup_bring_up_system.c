/* startup_bring_up_system  (FUN_a015266c)
 *
 * Run the second start-up step: wait for OTP and the input processor, then initialise the system.
 * Name basis: proven - prints 'Boot from %02X', 'wait otp ready', 'wait sub init'; called from startup_main
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015266c @ 0xa015266c..0xa0152a20 (948 bytes), flags -mcpu=v8 -O3 -g (the same code also builds
 * with -msoft-float).
 * Source forms the exact build depends on:
 *  - gcc 3.4 sched-deps flushes its pending memory lists after 32 references: the 34th memory operation of phase
 *    1 (the clear of byte_0x31) is a barrier, so bit_18, byte_0x33, half_0x36, byte_0x32 and delay_to_show come
 *    after it in the source. The statement order of phase 1 is one order that reproduces the target byte for byte
 *    under that rule; the stores, their values and their final order are exactly the target's;
 *  - callee return types: ipc_input_cpu_get_state_bit26, ipc_input_cpu_get_ready_bit and dbg_is_print_enabled
 *    return unsigned char ('btst 0xff' at the use);
 *  - the boot-source wait is a do-while whose body starts with an asm nop.
 */

/* Clock generators of panel_set_pll_frequency (the firmware's print names). */
enum { GPLL_DISPM = 0, GPLL_FRC = 4 };
#define PLL_960_MHZ        960000000    /* in Hz */

/* Bits 20..22 of word 0 of a panel timing row: the link type. */
#define ROW_LINK_TYPE_MASK 0x700000
#define ROW_LINK_TYPE_2    0x200000

#define DBG_START_UP       0x10         /* debug class of the start-up messages */
#define WAIT_UNTIL_EMPTY   2            /* ipc_8051_wait_tx_queue mode 2: flush until the queue is empty */

/* The start of the system configuration record (stSysConfig), field names as in docs/RECORDS.md and the
   shared word list; the others are named by bit or offset. */
struct sys_config_record {
    /* word 0, bits 31..8 */
    unsigned int bit_31:1, bit_30:1, bit_29:1, bit_28:1, frc_lock_mode:1, main_bypass:1, bit_25:1, bit_24:1,
                 link_option_enable:1, bit_22:1, bit_21:1, bit_20:1, bit_19:1, bit_18:1, bits_8_17:10;
    unsigned char byte_3;               /* +3: non-zero selects the second form of the output timing */
    /* word +4 */
    unsigned int converter_mode:4, path_mode_ch0:4, path_mode_ch1:4, bits_16_19:4;
    unsigned char byte_0x06;
    unsigned char auto_level_mode;      /* +7 */
    unsigned char brightness;           /* +8 */
    unsigned char color_gain;           /* +9 */
    unsigned char color_matrix_param;   /* +0xA */
    unsigned char picture_mode;         /* +0xB */
    unsigned char red_gain, green_gain, blue_gain;              /* +0xC..+0xE, 0..100 */
    unsigned char red_offset, green_offset, blue_offset;        /* +0xF..+0x11, 0..100 */
    unsigned char red_offset_first, green_offset_first, blue_offset_first;     /* +0x12..+0x14 */
    unsigned char red_offset_second, green_offset_second, blue_offset_second;  /* +0x15..+0x17 */
    unsigned char gamma_selection;      /* +0x18 */
    unsigned char byte_0x19, byte_0x1a, byte_0x1b, byte_0x1c;
    unsigned char preset_index;         /* +0x1D */
    unsigned char link_option0, link_option1, link_option2, link_option3;     /* +0x1E..+0x21 */
    unsigned char byte_0x22, byte_0x23, byte_0x24, byte_0x25, byte_0x26, byte_0x27, byte_0x28, byte_0x29;
    unsigned char channel2_enable;      /* +0x2A */
    unsigned char byte_0x2b;
    unsigned char channel3_enable;      /* +0x2C */
    unsigned char byte_0x2d;
    unsigned char byte_0x2e, byte_0x2f, byte_0x30, byte_0x31, byte_0x32, byte_0x33;
    unsigned char delay_to_show;        /* +0x34 */
    unsigned char byte_0x35;
    unsigned short half_0x36;
};
extern struct sys_config_record sys_config;
extern unsigned char sys_boot_source;
extern void (*sys_callback_table_slot8)(void);
extern int dbg_printf();
extern void startup_init_clocks(void);
extern void startup_init_core(void);
extern void ipc_input_cpu_write_port_nibbles_copy(void);
extern int ipc_8051_get_boot_source(void);
extern void startup_init_pins(unsigned char);
extern unsigned char ipc_input_cpu_get_state_bit26(void);
extern unsigned char dbg_is_print_enabled(unsigned char);
extern void startup_init_eeprom_layout(void);
extern void startup_load_default_records(void);
extern void nvram_validate_settings_at_startup(void);
extern void startup_reset_input_table(void);
extern void startup_reset_port_table(void);
extern void startup_init_clock_blocks(int, int);
extern int startup_return_one(void);
extern void sys_frc_set_config_index(unsigned char);
extern void startup_init_display_clocks(int);
extern void panel_set_pll_frequency(unsigned char ch, unsigned int freq);
extern void ldc_send_dpll_init_check(void);
extern void input_api_select_ports(int, int);
extern unsigned char ipc_input_cpu_get_ready_bit(void);
extern void FGA_Init(void);
extern void startup_init_converter_sources(void);
extern void startup_init_display_output(void);
extern void System_Initialize(void);
extern void startup_reset_channel_records(void);
extern void startup_select_default_port(void);
extern void startup_init_input_ports(void);
extern unsigned int *panel_get_active_row(void);
extern void sys_poll_events_stub_copy15(void);
extern void ipc_set_command_flags(void);
extern void ipc_set_port_option_mask(void);
extern void ipc_8051_wait_tx_queue(int, int);
extern void startup_init_8051_i2c_ports(void);
extern void startup_load_port_edids(void);
extern void input_report_present_ports(void);

/*
 * The second start-up step of the main processor.
 *
 * Called once by startup_main, before its main loop. The three waits below have no time limit: start-up goes on
 * only after the 8051 has reported a non-zero boot source and the input processor has set both bits it is
 * waited for.
 *
 * Phases, in order:
 *  1. Start values of the system configuration record: in word 0 bits 27 (frc_lock_mode), 25 and 21 set and
 *     bits 31..28, 26, 24..22, 19 and 18 cleared; the three 4-bit fields of word +4 cleared; brightness 100;
 *     colour gain, the gains and the offsets 50; colour matrix parameter and the first / second offsets 0x80;
 *     bytes +0x2E, +0x2F and +0x33 set to 1; the others written here cleared.
 *  2. Clocks, processor core and timers, the port values to the input processor.
 *  3. Wait 1: until the 8051 reports a boot source (non-zero); print "Boot from <source>" and set up the pins
 *     from it.
 *  4. Wait 2: until state bit 26 of the input processor is set, printing "wait otp ready" on every pass while
 *     start-up messages are on; then "otp ready".
 *  5. Storage layout, default records, the stored settings (checked, rewritten with the defaults when their
 *     header is invalid), callback slot 8 when one is set, input and port tables reset, clock blocks, converter
 *     settings index, display clocks, clock generators DISPM and FRC at 960 MHz, the dimming processor's check
 *     command, the selected ports switched on.
 *  6. Wait 3: until the input processor's ready bit is set, printing "wait sub init" likewise; then "sub init".
 *  7. Calibration tables (FGA_Init), converter sources, display start-up (startup_init_display_output),
 *     System_Initialize, the channel records, port 0x61 for channel 0, the input ports. With link type 2 in the
 *     active row the empty routine sys_poll_events_stub_copy15 is called. Then the command flags and the port
 *     option mask go to the input processor, the queue to the 8051 is flushed until empty, the 8051's I2C ports
 *     are set up, the port EDIDs are loaded and the present ports are reported.
 */
void startup_bring_up_system(void)
{
    unsigned char boot_source;

    /* 1. Start values of the system configuration record (order: see the matching notes). */
    sys_config.byte_0x2e = 1;
    sys_config.byte_0x2f = 1;
    sys_config.bit_31 = 0;
    sys_config.bit_29 = 0;
    sys_config.bit_25 = 1;
    sys_config.bit_24 = 0;
    sys_config.link_option_enable = 0;
    sys_config.auto_level_mode = 0;
    sys_config.bit_28 = 0;
    sys_config.frc_lock_mode = 1;
    sys_config.main_bypass = 0;
    sys_config.converter_mode = 0;
    sys_config.bit_22 = 0;
    sys_config.byte_0x06 = 0;
    sys_config.bit_30 = 0;
    sys_config.bit_21 = 1;
    sys_config.bit_19 = 0;
    sys_config.path_mode_ch1 = 0;
    sys_config.color_matrix_param = 0x80;
    sys_config.picture_mode = 0;
    sys_config.color_gain = 50;
    sys_config.blue_gain = 50;
    sys_config.blue_offset = 50;
    sys_config.green_gain = 50;
    sys_config.green_offset = 50;
    sys_config.red_gain = 50;
    sys_config.red_offset_first = 0x80;
    sys_config.green_offset_first = 0x80;
    sys_config.brightness = 100;
    sys_config.blue_offset_first = 0x80;
    sys_config.red_offset_second = 0x80;
    sys_config.green_offset_second = 0x80;
    sys_config.path_mode_ch0 = 0;
    sys_config.red_offset = 50;
    sys_config.blue_offset_second = 0x80;
    sys_config.gamma_selection = 0;
    sys_config.byte_0x1c = 0;
    sys_config.preset_index = 0;
    sys_config.byte_3 = 0;
    sys_config.byte_0x22 = 0;
    sys_config.byte_0x23 = 0;
    sys_config.byte_0x30 = 0;
    sys_config.byte_0x31 = 0;
    sys_config.bit_18 = 0;
    sys_config.half_0x36 = 0;
    sys_config.byte_0x32 = 0;
    sys_config.delay_to_show = 0;
    sys_config.byte_0x33 = 1;

    /* 2. */
    startup_init_clocks();
    startup_init_core();
    ipc_input_cpu_write_port_nibbles_copy();

    /* 3. Wait 1: the 8051's boot source. */
    do {
        __asm__ volatile ("nop");
        boot_source = ipc_8051_get_boot_source();
        sys_boot_source = boot_source;
    } while (boot_source == 0);
    dbg_printf("Boot from %02X\r\n", boot_source);
    startup_init_pins(sys_boot_source);

    /* 4. Wait 2: state bit 26 of the input processor. */
    while (ipc_input_cpu_get_state_bit26() == 0) {
        if (dbg_is_print_enabled(DBG_START_UP))
            dbg_printf("\n wait otp ready\r\n");
    }
    if (dbg_is_print_enabled(DBG_START_UP))
        dbg_printf("\n otp ready\r\n");

    /* 5. Settings, tables and clocks. */
    startup_init_eeprom_layout();
    startup_load_default_records();
    nvram_validate_settings_at_startup();
    if (sys_callback_table_slot8 != 0)
        sys_callback_table_slot8();
    startup_reset_input_table();
    startup_reset_port_table();
    startup_init_clock_blocks(0x1e, 0x32);
    sys_frc_set_config_index(startup_return_one());
    startup_init_display_clocks(0);
    panel_set_pll_frequency(GPLL_DISPM, PLL_960_MHZ);
    panel_set_pll_frequency(GPLL_FRC, PLL_960_MHZ);
    ldc_send_dpll_init_check();
    input_api_select_ports(0, 1);

    /* 6. Wait 3: the input processor's ready bit. */
    while (ipc_input_cpu_get_ready_bit() == 0) {
        if (dbg_is_print_enabled(DBG_START_UP))
            dbg_printf("\n wait sub init\r\n");
    }
    if (dbg_is_print_enabled(DBG_START_UP))
        dbg_printf("\n sub init\r\n");

    /* 7. Display, system and inputs. */
    FGA_Init();
    startup_init_converter_sources();
    startup_init_display_output();
    System_Initialize();
    startup_reset_channel_records();
    startup_select_default_port();
    startup_init_input_ports();
    if ((*panel_get_active_row() & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2)
        sys_poll_events_stub_copy15();
    ipc_set_command_flags();
    ipc_set_port_option_mask();
    ipc_8051_wait_tx_queue(WAIT_UNTIL_EMPTY, 0);
    startup_init_8051_i2c_ports();
    startup_load_port_edids();
    input_report_present_ports();
}

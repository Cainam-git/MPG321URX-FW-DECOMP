/* System_Initialize  (FUN_a015209c)
 *
 * Initialise clocks, port records, the output configuration and frame-rate conversion.
 * Name basis: proven - prints 'System_Initialize' and 'System_Initialize End' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015209c @ 0xa015209c-0xa015266c (372 words; the asm header's "1284 bytes" label is wrong, its range is
 * right), flags -mcpu=v8 -O3 -g. Written from the asm.
 * Source forms the exact build depends on:
 *  - the callee prototypes from the call sites: sys_init_enable_output_blocks, startup_load_block8_config,
 *    pq_load_profile_table, startup_init_output_layers and audio_init_config get no arguments;
 *    pq_gamma_load_first_curve_preset2 / _second_curve_preset2 get only %o0;
 *  - block_config (12 bytes) and output_config (36 bytes) are PASSED BY VALUE; output_config and the request byte
 *    live in inner blocks (firmware frame order: record copies at -40..-88, output_config at -128, its copy at
 *    -168, the byte at -169);
 *  - device_settings is read through a packed struct with 16-bit fields at the odd offsets +1 / +3 / +5 (word
 *    loads), copied in the order spread_rate_value, spread_depth_value, spread_ctrl_byte;
 *  - word 0 of the row is a union of the word (mask tests) and bit-fields: the print uses the 3-bit field
 *    row_field (with a mask and shift there, gcse moves the word load into every switch arm);
 *  - "if (x == K) A; else B;" test forms (the firmware's subx/addx constants);
 *  - the display mode switch is written out here (the code of DispModeTransform) with the arms in the source order
 *    0x10, 0x11, 0x20, 0x21, 0x24, 0x40, 0x41, 0x22/0x42 (register names), and display_mode = 0 before it;
 *  - output_config fields byte_0x03, byte_0x15..0x17 and word_0x18..0x20 are copied uninitialised,
 *    as in the firmware; colour_depth_code is not written for other bpc values and spread_mode not when the
 *    clock modulation is off.
 * volatile: none. Aids: none.
 */

#define PWM_CLOCK_REFCLK_12MHZ 0        /* ConfigScalerPWM: clock source 0, the 12 MHz clock */

/* Bits 20..22 of word 0 of a panel timing row: the link type. */
#define ROW_LINK_TYPE_MASK 0x700000
#define ROW_LINK_TYPE_0    0
#define ROW_LINK_TYPE_2    0x200000

/* Bits 17..19 of word 0: the field that selects between variants of a display mode (as in DispModeTransform). */
#define ROW_FIELD_MASK     0xe0000
#define ROW_FIELD_1        0x20000
#define ROW_FIELD_2        0x40000

#define DBG_START_UP       0x10         /* debug class of the start-up messages (also 'wait otp ready', 'sub init') */

extern unsigned char ipc_8051_cec_registers_entry[];

/* The output configuration handed to panel_output_setup_path (field names as in that routine). */
struct panel_output_config {
    unsigned char spread_on;            /* +0: 0 = clock modulation off */
    unsigned char spread_mode;          /* +1: not 0 = rate and depth values, 0 = control byte */
    unsigned char row_bit25, byte_0x03;
    unsigned int colour_depth_code;     /* +4 */
    unsigned int display_mode;          /* +8 */
    unsigned char ed58_value, ede4_value;               /* +0xC / +0xD */
    unsigned short spread_ctrl_byte;    /* +0xE */
    unsigned short spread_rate_value, spread_depth_value;  /* +0x10 / +0x12 */
    unsigned char byte_0x14, byte_0x15, byte_0x16, byte_0x17;
    unsigned int word_0x18, word_0x1c, word_0x20;
};

/* One entry of input_block_configs (input_block_set_config); byte_8 / byte_9 are the first bytes of its word_8. */
struct input_block_config { unsigned int word_0, word_4; unsigned char byte_8, byte_9; };

/* The start of a panel timing row. */
struct panel_timing_row {
  union {
    unsigned int flags;
    struct { unsigned int bits_23_31 : 9, link_type : 3, row_field : 3, bits_0_16 : 17; } bits;
  } word0;
  unsigned short half_0x04;
  unsigned char display_mode;           /* +6: the row's display mode byte */
  unsigned char bpc;                    /* +7: bits per colour */
};
/* The same active row seen from its refresh rate. */
struct panel_timing_row_rate { unsigned char pad00[0x52]; unsigned short refresh_rate; /* +0x52: tenths of Hz */ };

/* The clock modulation fields of the device settings record. */
struct __attribute__((packed, aligned(4))) device_settings_spread {
  unsigned char byte_0x00;
  unsigned short spread_ctrl_byte : 16, spread_rate_value : 16, spread_depth_value : 16;   /* +1 / +3 / +5 */
  unsigned char pip_mode;               /* +7 */
};
/* The bus id fields (+0x10) of the first two port entries (0x12 bytes each). */
struct port_entries_first_two { unsigned char pad00[0x10]; unsigned char entry0_bus_id; unsigned char pad11[0x11];
                                unsigned char entry1_bus_id; };
extern struct panel_timing_row_rate panel_active_row;
extern struct device_settings_spread device_settings;
extern struct port_entries_first_two port_entries;
extern unsigned short part_record_hdr_peak_luminance;
extern unsigned char sys_config_byte_3;
extern struct panel_timing_row *panel_get_active_row(void);
extern int dbg_printf();
extern void ConfigScalerPWM(unsigned char, unsigned char, unsigned short, int);
extern void panel_pwm_set_mode_field(unsigned char, int);
extern void gpio_set_drive_field(unsigned char, unsigned char);
extern unsigned char input_port_table_get_bus_id(unsigned char);
extern void audio_init_config(void);
extern void gpio_set_aux_bit2_high_copy(void);
extern void sys_init_picture_blocks(void);
extern void sys_poll_events_stub_copy16(void);
extern void startup_init_input_blocks(void);
extern void input_block_set_config(unsigned char, struct input_block_config);
extern void input_blocks_init(void);
extern void startup_init_block_5a80(void);
extern void panel_output_setup_path(struct panel_output_config);
extern void sys_store_request_byte(unsigned char *);
extern void startup_load_block8_config(void);
extern void startup_init_path_blocks(void);
extern void startup_init_level_generator(void);
extern void hdmi_cec_init(unsigned char);
extern void hdmi_cec_set_send_hook(unsigned int);
extern void sys_poll_events_stub_copy12(void);
extern void ldc_send_panel_size_and_start(void);
extern void ldc_send_zone_counts(void);
extern void ldc_send_zone_grid_32x16(void);
extern void ldc_send_cmd_0x84(unsigned int, unsigned char);
extern void pq_load_profile_table(void);
extern void sys_init_enable_output_blocks(void);
extern void FRCConfigPostFRC(unsigned char, unsigned short, unsigned char);
extern void sys_frc_setup_lock(unsigned char, unsigned char, unsigned short, unsigned short);
extern void sys_frc_set_lock_mode(int, unsigned char, unsigned char);
extern void startup_init_output_layers(void);
extern void irq_set_source_handler(int, int, void (*)(void));
extern void ipc_write_8051_byte(int, int);
extern void irq_unmask_sources(int, int);
extern void ipc_handshake_8051_bytes(void);
extern void input_apply_8051_port_flags(void);
extern void ipc_set_hdr_peak_luminance(unsigned short);
extern void pq_gamma_load_first_curve_preset2(unsigned char *);
extern void pq_gamma_load_second_curve_preset2(unsigned char *);
extern void ipc_apply_port_enable_mask(void);
extern unsigned char dbg_is_print_enabled(unsigned int);

/*
 * Set up the picture path, the output and the frame-rate converter at start-up.
 *
 * Called once, by startup_bring_up_system, right after the display start-up (startup_init_display_output) and
 * before the channel records are reset. Nothing here reads the input timing; everything comes from the active
 * panel timing row (panel_get_active_row, the row at 0xA802E378), the device settings and fixed values.
 *
 * Phases, in order:
 *  1. Print "System_Initialize". PWM set-up calls: channel 7 and channel 0xFF have no registers in
 *     ConfigScalerPWM and panel_pwm_set_mode_field, so these calls write nothing.
 *  2. Pin drive fields (gpio_set_drive_field): fields 0 and 1 get 7, fields 2 and 3 the port table bus ids of
 *     port entries 0 and 1. Audio set-up, the auxiliary pin, the picture blocks and input block 8.
 *  3. The four input block configurations {2, 1, 1, 1}, then the input blocks and the block at 0xCF015A80.
 *  4. "Disp_Init": build the output configuration and hand it to panel_output_setup_path:
 *     - clock modulation from the device settings: with a rate value, on with rate and depth (spread_mode 1);
 *       else with a control byte, on with the control byte (spread_mode 0); else off;
 *     - colour depth code from the row's bits per colour: 8 bpc gives 3 with link type 2, else 0; 10 bpc gives 2;
 *     - display mode from the row's display mode byte and its 3-bit field, the same table as DispModeTransform
 *       (printed with the same "------>DispModeTransform" text);
 *     - ed58_value 0x80, ede4_value 0, row_bit25 0, byte_0x14 0.
 *     When the row's link type is 0, the request byte (sys_store_request_byte) is set to 0.
 *  5. Picture block 8 configuration, the signal path blocks, the level generator, the CEC block with its send
 *     hook (ipc_8051_set_cec_registers), the dimming processor commands (panel size and start, zone counts,
 *     32 x 16 zone grid, command 0x84), the profile table and the output blocks.
 *  6. Frame-rate converter: FRCConfigPostFRC at the row's refresh rate, sys_frc_setup_lock for free run at the
 *     same rate, lock mode 0 on channels 0..3; then the start sequence of the two output halves.
 *  7. Interrupt level 1: source 1 runs ipc_handshake_8051_bytes (after 0x99 is written to shared 8051 byte 4),
 *     source 2 runs input_apply_8051_port_flags. In between, the part record's HDR peak luminance goes to the
 *     input processor.
 *  8. Gamma: both preset-curve stages load preset 2 (no table given). The input processor applies the port
 *     enable mask. Print "System_Initialize End" when start-up messages are on.
 */
void System_Initialize(void)
{
  struct panel_timing_row *row_at_start, *row;
  struct input_block_config block_config;

  row_at_start = panel_get_active_row();
  dbg_printf("System_Initialize\r\n");

  /* 1. PWM channel 7 and channel 0xFF: no registers, nothing is written. */
  ConfigScalerPWM(7, 0xd, 0x3c0, PWM_CLOCK_REFCLK_12MHZ);
  panel_pwm_set_mode_field(7, 1);
  ConfigScalerPWM(7, 0xff, 0x9c40, PWM_CLOCK_REFCLK_12MHZ);
  panel_pwm_set_mode_field(7, 0);
  ConfigScalerPWM(7, 0xb, 0x7530, PWM_CLOCK_REFCLK_12MHZ);
  ConfigScalerPWM(7, 0xc, 0x7530, PWM_CLOCK_REFCLK_12MHZ);
  ConfigScalerPWM(7, 0xe, 0x7530, PWM_CLOCK_REFCLK_12MHZ);
  ConfigScalerPWM(0xff, 0x18, 0x3c0, PWM_CLOCK_REFCLK_12MHZ);
  ConfigScalerPWM(0xff, 0xff, 0x3c0, PWM_CLOCK_REFCLK_12MHZ);
  ConfigScalerPWM(0xff, 0xff, 0x3c0, PWM_CLOCK_REFCLK_12MHZ);
  ConfigScalerPWM(0xff, 0xff, 0x3c0, PWM_CLOCK_REFCLK_12MHZ);

  /* 2. Pin drive fields: 0xCF03C158 bits 0..2 / 3..5 and 0xCF03C144 bits 0..2 / 3..5. */
  gpio_set_drive_field(0, 7);
  gpio_set_drive_field(1, 7);
  gpio_set_drive_field(2, input_port_table_get_bus_id(port_entries.entry0_bus_id));
  gpio_set_drive_field(3, input_port_table_get_bus_id(port_entries.entry1_bus_id));
  audio_init_config();
  gpio_set_aux_bit2_high_copy();
  sys_init_picture_blocks();
  sys_poll_events_stub_copy16();
  startup_init_input_blocks();

  /* 3. The same configuration for input blocks 0..3. */
  block_config.word_0 = 2;
  block_config.word_4 = 1;
  block_config.byte_8 = 1;
  block_config.byte_9 = 1;
  input_block_set_config(0, block_config);
  input_block_set_config(1, block_config);
  input_block_set_config(2, block_config);
  input_block_set_config(3, block_config);
  input_blocks_init();
  startup_init_block_5a80();

  /* 4. Disp_Init: the output configuration for panel_output_setup_path. */
  {
  struct panel_output_config output_config;
  unsigned int display_mode;

  row = panel_get_active_row();
  output_config.row_bit25 = 0;
  dbg_printf("Disp_Init\r\n");
  output_config.spread_rate_value = device_settings.spread_rate_value;
  output_config.spread_depth_value = device_settings.spread_depth_value;
  output_config.spread_ctrl_byte = device_settings.spread_ctrl_byte;
  /* Clock modulation: rate and depth values win over the control byte. */
  if (output_config.spread_rate_value != 0) {
    output_config.spread_on = 1;
    output_config.spread_mode = 1;
  } else if (output_config.spread_ctrl_byte != 0) {
    output_config.spread_on = 1;
    output_config.spread_mode = 0;
  } else {
    output_config.spread_on = 0;
  }
  /* Colour depth code by bits per colour. */
  switch (row->bpc) {
  case 8:
    if ((row->word0.flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2)
      output_config.colour_depth_code = 3;
    else
      output_config.colour_depth_code = 0;
    break;
  case 10:
    output_config.colour_depth_code = 2;
    break;
  }

  /* Display mode: the table of DispModeTransform. */
  row = panel_get_active_row();
  display_mode = 0;
  switch (row->display_mode) {
  case 0x10:
    display_mode = 1;
    break;
  case 0x11:
    if ((row->word0.flags & ROW_FIELD_MASK) == ROW_FIELD_1) display_mode = 3;
    else display_mode = 4;
    break;
  case 0x20:
    display_mode = 5;
    break;
  case 0x21:
    if ((row->word0.flags & ROW_FIELD_MASK) == 0) display_mode = 0x11;
    else display_mode = 8;
    break;
  case 0x24:
    display_mode = 0xe;
    break;
  case 0x40:
    if ((row->word0.flags & ROW_FIELD_MASK) == 0) display_mode = 6;
    else display_mode = 5;
    break;
  case 0x41:
    if ((row->word0.flags & ROW_FIELD_MASK) == ROW_FIELD_2) display_mode = 0xa;
    else if ((row->word0.flags & ROW_FIELD_MASK) == 0) display_mode = 9;
    else display_mode = 8;
    break;
  case 0x22:
  case 0x42:
    if ((row->word0.flags & ROW_FIELD_MASK) == ROW_FIELD_2) display_mode = 0xd;
    else if ((row->word0.flags & ROW_FIELD_MASK) == 0) display_mode = 0xc;
    else display_mode = 0xb;
    break;
  }
  dbg_printf("------>DispModeTransform %d,%d , %d\r\n", row->display_mode, row->word0.bits.row_field, display_mode);
  output_config.display_mode = display_mode;
  output_config.ed58_value = 0x80;
  output_config.ede4_value = 0;
  output_config.byte_0x14 = 0;
  panel_output_setup_path(output_config);
  if ((row_at_start->word0.flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_0) {
    unsigned char request_byte = 0;
    sys_store_request_byte(&request_byte);
  }
  }

  /* 5. Picture and path blocks, level generator, CEC, dimming processor, profile table, output blocks. */
  startup_load_block8_config();
  startup_init_path_blocks();
  startup_init_level_generator();
  hdmi_cec_init(0);
  hdmi_cec_set_send_hook(ipc_8051_cec_registers_entry);
  sys_poll_events_stub_copy12();
  ldc_send_panel_size_and_start();
  ldc_send_zone_counts();
  ldc_send_zone_grid_32x16();
  ldc_send_cmd_0x84(0x400, 0x16);
  pq_load_profile_table();
  sys_init_enable_output_blocks();

  /* 6. Frame-rate converter at the row's refresh rate: free run, no channel locked. */
  FRCConfigPostFRC(sys_config_byte_3 != 0, panel_active_row.refresh_rate, 1);
  sys_frc_setup_lock(0, 0, 0, panel_active_row.refresh_rate);
  sys_frc_set_lock_mode(0, 0, 0);
  sys_frc_set_lock_mode(1, 0, 0);
  sys_frc_set_lock_mode(2, 0, 0);
  sys_frc_set_lock_mode(3, 0, 0);
  startup_init_output_layers();

  /* 7. Interrupt level 1, sources 1 and 2. */
  irq_set_source_handler(1, 1, ipc_handshake_8051_bytes);
  ipc_write_8051_byte(4, 0x99);
  irq_unmask_sources(1, 1);
  ipc_set_hdr_peak_luminance(part_record_hdr_peak_luminance);
  irq_set_source_handler(1, 2, input_apply_8051_port_flags);
  irq_unmask_sources(1, 2);

  /* 8. Preset curves (0 = no table given: preset 2), port enable mask, end message. */
  pq_gamma_load_first_curve_preset2(0);
  pq_gamma_load_second_curve_preset2(0);
  ipc_apply_port_enable_mask();
  if (dbg_is_print_enabled(DBG_START_UP))
    dbg_printf("System_Initialize End\r\n");
}

/* sys_main  (FUN_CODE_3fe7)
 *
 * Start the system, then serve the mailbox and supervise the main processor forever.
 * Name basis: proven - docs/MAP.md start-up step 2; prints 'NT68500 MCU Test program', 'Wakeup!!!'; calls
 *   startup_load_core_images, ipc_service_mailbox, sys_watch_main_core
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_3fe7 @ 0x3fe7..0x42f6 (783 bytes), built with OPTIMIZE(8,SPEED) (c51opts; also exact with
 * REGFILE(R.ORC); level 7 gives 787 bytes). Entered by LJMP from the Keil start-up at 0xA64F.
 * Source forms the exact build depends on:
 * - 'wake_bit2 = power_wake_source & WAKE_SOURCE_BIT2; if (wake_bit2)' gives the ANL A,#04H / JZ of the firmware
 *   (a plain 'if (power_wake_source & 4)' gives JNB ACC.2).
 * - The chip test before the loop is '(reg_chip_id == 0x1a) | (reg_chip_id == 0x20)' with reg_chip_id volatile
 *   (Keil evaluates the right operand first: R7 = (== 0x20), R6 = (== 0x1a), ORL); the test inside the loop is
 *   the short-circuit '||'.
 * - sys_main_work_word is one 16-bit XDATA word used both as the NOP delay counter and as the holder of the two
 *   wake-test results ('if ((sys_main_work_word = f()) != ...)').
 * - volatile only on hardware registers: 0xF0xx / 0xF2xx / 0xF6xx, reg_chip_id (0xD511) and 0xDCB0 (bit 1 pulse,
 *   re-read in the loop). The rest is RAM.
 */
#include <intrins.h>
sfr IE = 0xA8;
sbit EA = IE ^ 7;
extern bit sys_shared_bit_param, BITS_21_7;
extern unsigned char volatile xdata DAT_EXTMEM_f00a, DAT_EXTMEM_f0e0, DAT_EXTMEM_f0e2, reg_flash_read_mode, reg_startup_wake_status;
extern unsigned char volatile xdata reg_ipc_shared_bytes, DAT_EXTMEM_f60a, DAT_EXTMEM_f60b, reg_dma_flash_count_low;
extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned char xdata DAT_EXTMEM_e135, DAT_EXTMEM_3100;
extern unsigned char volatile xdata reg_chip_id;
extern unsigned char xdata sys_run_state, flash_read_opcode, DAT_EXTMEM_dcf0;
extern unsigned char xdata power_wake_source, power_wake_retry_count;
extern unsigned int xdata sys_main_work_word;
extern void lib_printf517(void *fmt, ...) large;
extern void sys_setup_pll_and_select(void);
extern void uart_init(void);
extern void power_clear_sequence_table(void);
extern void power_reset_wake_table(unsigned char m);
extern void power_leave_power_saving(void);
extern void sys_pulse_variant_reg(void);
extern void sys_toggle_warm_reset(void);
extern void flash_clear_transfer_buffer(void);
extern void startup_load_core_images(void);
extern void sys_watch_main_core(void);
extern void startup_release_leon2m(unsigned char why);
extern void startup_init_chip_regs(void);
extern unsigned long flash_get_leon2_base_address(void);
extern void FE2P_SetLeon2BaseAddress(void);
extern void ipc_run_cmd_0x25_sequence(void);
extern void ipc_service_mailbox(void);
extern void sys_run_timed_ramp(void);
extern void power_watch_dp_activity(void);
extern void usb_update_dp_port_flags(void);
extern unsigned char sys_scan_keys_and_ir(void);
extern unsigned char power_poll_wake_sources(void);
extern bit power_test_ddc_wake(void);
extern bit power_take_cec_wake_request(void);
extern unsigned char power_find_active_wake_pin(void);
extern unsigned char power_check_wakeup_timer(void);
extern void timer_delay_ticks(unsigned int t);
extern void power_apply_standby_pins(void);
extern void dp_mrx_disable_aux_irqs(void);
extern void timer_apply_clock_rates(void);
extern void sys_ir_ring_flush(void);
extern void sys_service_ddc_and_cec(void);

/* sys_run_state values (set to 0 / 1 by main-processor commands 0x16 / 0x17 in ipc_run_command). */
#define RUN_STATE_POWER_SAVING  0
#define RUN_STATE_POWER_OFF     1
#define RUN_STATE_RUNNING       2

/* Chip variants in reg_chip_id. */
#define CHIP_VARIANT_1A         0x1A
#define CHIP_VARIANT_20         0x20

/* Flash read command chosen from reg_flash_read_mode. */
#define READ_MODE_QUAD          0x04
#define READ_MODE_DUAL          0x20
#define FLASH_READ_QUAD         0x6B
#define FLASH_READ_DUAL         0x3B
#define FLASH_READ_FAST         0x0B

/* power_wake_source codes: what ended standby. The code is passed to the main processor as its boot source. */
#define WAKE_NONE               0
#define WAKE_KEY_POWER_OFF      2     /* key or IR code while powered off */
#define WAKE_CEC                3     /* CEC power-up request */
#define WAKE_KEY_POWER_SAVING   4     /* key or IR code while saving power */
#define WAKE_ENTRY_KIND0        5     /* wake table entry kinds (power_check_wake_entry): */
#define WAKE_ENTRY_KIND1_2      6
#define WAKE_ENTRY_KIND3_4      7
#define WAKE_ENTRY_KIND5        8
#define WAKE_ENTRY_KIND6        9
#define WAKE_DP_RX0             10    /* entry kinds 7, 8: DP receiver 0 */
#define WAKE_DP_RX1             11    /* entry kinds 9, 10: DP receiver 1 */
#define WAKE_TIMER              0x0C  /* the wake-up timer ran out */
#define WAKE_PIN_FIRST          0x0D  /* + index of the wake pin found active */
#define WAKE_DDC                0x13  /* DDC/CI request on a port of the wake table */

#define ENTRY_KIND_NONE         0x0D  /* power_poll_wake_sources: nothing fired */
#define WAKE_PIN_NONE           0xFF  /* power_find_active_wake_pin: no pin active */
#define WAKE_SOURCE_BIT2        0x04  /* bit 2 of the 0xF0DD byte copied at start-up */

#define DELAY_PASSES            100   /* passes of two NOPs */
#define WAKE_WAIT_TICKS         100
#define WAKE_WAIT_ROUNDS        10
#define DCB0_BUSY_BITS          0xC0  /* bits 7..6 of XDATA 0xDCB0 */

/* sys_main - main routine of the 8051 application (bank 1); never returns.
 *
 * Phases:
 *   1. Start-up, interrupts off: clocks, serial ports and timers, pin sequence and wake-up tables, chip blocks on,
 *      warm-reset pulse, a short delay, then the banner "------NT68500 MCU Test program -----".
 *   2. Pick the flash read command (quad, dual or fast read) from reg_flash_read_mode, write 0xAA to XDATA
 *      0xF00A / 0xF0E0 / 0xF0E2, fill the 2 KB flash buffer with 0xFF, copy the byte at 0xF0DD into
 *      power_wake_source and clear reg_ipc_shared_bytes.
 *   3. startup_load_core_images copies the other processors' programs and starts them (docs/MAP.md, start-up
 *      step 2). sys_watch_main_core then runs once with sys_shared_bit_param set, which restarts both of its
 *      alive timers.
 *   4. Release the main processor: startup_release_leon2m writes 1 into bits 8..15 of portal word 0xB8, which the
 *      main processor reads as its boot source (ipc_8051_get_boot_source, 'Boot from %02X'); 2 follows when bit 2
 *      of the 0xF0DD byte was set. Interrupts on, chip registers for the variant, flash window base for the main
 *      processor; on variants 0x1A and 0x20 three registers of the image-DMA block (0xF60A..0xF60C) are set.
 *   5. Endless loop. Every pass: on variants 0x1A / 0x20 the command 0x25 sequence steps; 0x55 goes to XDATA
 *      0xF00A and 0xF0E0. Then by sys_run_state:
 *      - running: serve the mailbox (ipc_service_mailbox) and check that the LEON processors are alive
 *        (sys_watch_main_core powers off when they stop).
 *      - power saving / power off: test the wake-up sources (below). When one fired, wake up: for a DP receiver
 *        wake or while 0xDCB0 bits 7..6 are set, pulse 0xDCB0 bit 1 and wait 100 ticks, up to 10 rounds
 *        ('cnt %d %d'); set the standby pins, turn off the DP AUX interrupts, print 'Wakeup!!! %BX', redo part of
 *        phase 1 (clock rates, PLL, chip blocks, warm reset), load and start the other processors again
 *        (phase 3), release the main processor with the wake code as its boot source and go back to running.
 *      Last in every pass: sys_service_ddc_and_cec.
 *
 * Wake-up sources tested in the loop, later tests overwrite earlier ones:
 *   power saving: key / IR (4), the current wake table entry (5..11 by its kind; kinds 11 and 12 give no code),
 *     DDC/CI request (0x13), CEC (3), wake pin (0x0D + pin index).
 *   power off: key / IR (2), wake-up timer (0x0C), CEC (3).
 */
void sys_main(void)
{
    unsigned char wake_bit2;

    /* 1. Basic chip start-up with interrupts off. */
    EA = 0;
    sys_setup_pll_and_select();
    uart_init();
    power_clear_sequence_table();
    power_reset_wake_table(1);
    power_leave_power_saving();
    sys_pulse_variant_reg();
    sys_toggle_warm_reset();
    sys_main_work_word = 0;
    do {
        _nop_();
        _nop_();
        sys_main_work_word++;
    } while (sys_main_work_word != DELAY_PASSES);
    lib_printf517((void code *)0xca8d /* "\r\n------NT68500 MCU Test program -----\n" */);
    /* 2. Flash read command, buffers and the start-up wake byte. */
    if (reg_flash_read_mode & READ_MODE_QUAD) flash_read_opcode = FLASH_READ_QUAD;
    else if (reg_flash_read_mode & READ_MODE_DUAL) flash_read_opcode = FLASH_READ_DUAL;
    else flash_read_opcode = FLASH_READ_FAST;
    DAT_EXTMEM_f00a = 0xaa;
    DAT_EXTMEM_f0e0 = 0xaa;
    DAT_EXTMEM_f0e2 = 0xaa;
    flash_clear_transfer_buffer();
    power_wake_source = reg_startup_wake_status;
    reg_ipc_shared_bytes = 0;
    /* 3. Load and start the other processors; restart the alive timers. */
    startup_load_core_images();
    sys_shared_bit_param = 1;
    sys_watch_main_core();
    /* 4. Release the main processor (boot source 1, then 2 when bit 2 was set). */
    startup_release_leon2m(1);
    wake_bit2 = power_wake_source & WAKE_SOURCE_BIT2;
    if (wake_bit2) startup_release_leon2m(2);
    EA = 1;
    startup_init_chip_regs();
    flash_get_leon2_base_address();
    FE2P_SetLeon2BaseAddress();
    if ((reg_chip_id == CHIP_VARIANT_1A) | (reg_chip_id == CHIP_VARIANT_20)) {
        DAT_EXTMEM_f60b = 0;
        reg_dma_flash_count_low = 0x80;
        DAT_EXTMEM_f60a |= 0x80;
    }
    /* 5. Main loop. */
    for (;;) {
        if (reg_chip_id == CHIP_VARIANT_1A || reg_chip_id == CHIP_VARIANT_20) ipc_run_cmd_0x25_sequence();
        DAT_EXTMEM_f00a = 0x55;
        DAT_EXTMEM_f0e0 = 0x55;
        if (sys_run_state == RUN_STATE_RUNNING) {
            ipc_service_mailbox();
            sys_shared_bit_param = 0;
            sys_watch_main_core();
        } else {
            /* Standby: find what, if anything, asks to wake up. */
            power_wake_source = WAKE_NONE;
            if (sys_run_state == RUN_STATE_POWER_SAVING) {
                sys_run_timed_ramp();
                power_watch_dp_activity();
                usb_update_dp_port_flags();
                if (sys_scan_keys_and_ir()) power_wake_source = WAKE_KEY_POWER_SAVING;
                if ((sys_main_work_word = power_poll_wake_sources()) != ENTRY_KIND_NONE) {
                    switch (sys_main_work_word) {
                    case 0: power_wake_source = WAKE_ENTRY_KIND0; break;
                    case 1: case 2: power_wake_source = WAKE_ENTRY_KIND1_2; break;
                    case 3: case 4: power_wake_source = WAKE_ENTRY_KIND3_4; break;
                    case 5: power_wake_source = WAKE_ENTRY_KIND5; break;
                    case 6: power_wake_source = WAKE_ENTRY_KIND6; break;
                    case 7: case 8: power_wake_source = WAKE_DP_RX0; break;
                    case 9: case 10: power_wake_source = WAKE_DP_RX1; break;
                    }
                }
                if (power_test_ddc_wake()) power_wake_source = WAKE_DDC;
                if (power_take_cec_wake_request()) power_wake_source = WAKE_CEC;
                if ((sys_main_work_word = power_find_active_wake_pin()) != WAKE_PIN_NONE) power_wake_source = sys_main_work_word + WAKE_PIN_FIRST;
            } else if (sys_run_state == RUN_STATE_POWER_OFF) {
                if (sys_scan_keys_and_ir()) power_wake_source = WAKE_KEY_POWER_OFF;
                if (power_check_wakeup_timer()) power_wake_source = WAKE_TIMER;
                if (power_take_cec_wake_request()) power_wake_source = WAKE_CEC;
            }
            if (power_wake_source != WAKE_NONE) {
                /* Wake-up. First the 0xDCB0 wait rounds for a DP receiver wake or busy bits. */
                power_wake_retry_count = 0;
                if (power_wake_source == WAKE_DP_RX0 || power_wake_source == WAKE_DP_RX1 || (DAT_EXTMEM_dcb0 & DCB0_BUSY_BITS)) {
                    do {
                        DAT_EXTMEM_f00a = 0x55;
                        DAT_EXTMEM_f0e0 = 0x55;
                        DAT_EXTMEM_dcb0 |= 0x02;
                        DAT_EXTMEM_dcb0 &= ~0x02;
                        timer_delay_ticks(WAKE_WAIT_TICKS);
                        power_wake_retry_count++;
                        lib_printf517((void code *)0xcab5 /* "cnt %d %d\r\n" */, (unsigned int)power_wake_retry_count, (unsigned int)DAT_EXTMEM_dcb0);
                    } while ((DAT_EXTMEM_dcb0 & DCB0_BUSY_BITS) && power_wake_retry_count < WAKE_WAIT_ROUNDS);
                }
                power_apply_standby_pins();
                dp_mrx_disable_aux_irqs();
                lib_printf517((void code *)0xcac1 /* "Wakeup!!! %BX\r\n\r\n\r\n" */, power_wake_source);
                /* Redo the clock and chip set-up of the start-up. */
                DAT_EXTMEM_f00a = 0xaa;
                DAT_EXTMEM_f0e0 = 0xaa;
                DAT_EXTMEM_f0e2 = 0xaa;
                timer_apply_clock_rates();
                sys_setup_pll_and_select();
                if (reg_chip_id == CHIP_VARIANT_20) DAT_EXTMEM_e135 &= 0x3f;
                power_leave_power_saving();
                sys_toggle_warm_reset();
                if (DAT_EXTMEM_3100 & 0x01) DAT_EXTMEM_dcf0 = 1;
                else DAT_EXTMEM_dcf0 = 0;
                sys_main_work_word = 0;
                do {
                    _nop_();
                    _nop_();
                    sys_main_work_word++;
                } while (sys_main_work_word != DELAY_PASSES);
                /* Start the other processors again; the wake code becomes the boot source. */
                startup_load_core_images();
                sys_shared_bit_param = 1;
                sys_watch_main_core();
                startup_release_leon2m(power_wake_source);
                sys_run_state = RUN_STATE_RUNNING;
                sys_ir_ring_flush();
                BITS_21_7 = 0;
            }
        }
        sys_service_ddc_and_cec();
    }
}

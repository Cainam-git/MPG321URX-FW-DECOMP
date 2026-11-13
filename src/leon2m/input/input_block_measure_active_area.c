/* input_block_measure_active_area  (FUN_a00f40e4)
 *
 * Start a measurement on an input block, wait for it and store the measured values.
 * Name basis: derived - registers 0x37 / 0x36 with a time limit; used by the output timing set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f40e4 @ 0xa00f40e4-0xa00f42b8 (117 words), flags -mcpu=v8 -O3 -g.
 * Source form: register 0x3a is read first in both compares of the offset choice.
 */
extern unsigned char input_adc_adjust_aborted;
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short input_capture_read16(unsigned char blk, unsigned char reg);
extern void input_capture_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned char input_block_is_change_pending(unsigned char blk);
extern void input_block_reset_window_regs(unsigned char blk);
extern void input_block_set_offset(unsigned char blk, unsigned short v);
extern void timer_sleep_ticks(int ms);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);

#define MEASURE_WAIT_TICKS  0x63    /* longest wait for the measurement, in ticks */

/*
 * Run one measurement on input block `block`, copy its results into the block's registers and store the
 * block's offset. Returns 1 when the measurement finished, 0 when it could not be done.
 *
 * Nothing is done (0 is returned) when bit 7 of register 0x54 is clear. Otherwise: input_adc_adjust_aborted is
 * cleared, the block's window registers are reset (input_block_reset_window_regs), register 0x37 gets 0x40 and
 * register 0x36 gets 0 and then 0x11 (this starts the measurement), the routine sleeps 20 ticks and waits for
 * bit 0 of register 0x36 to clear. It gives up, with input_adc_adjust_aborted set to 1 and 0 returned, when the
 * block has a pending change (input_block_is_change_pending) or the bit is still set after 0x63 ticks.
 *
 * After a finished measurement:
 *   register 0x12 = register 0x3E (12 bits), registers 0x0E and 0x0C = register 0x38 (11 bits);
 *   the block's offset (input_block_set_offset) is set to 1 when register 0x3A is above register 0x38, to 0xFFFF
 *   (-1) when it is below, and to 0 when they are equal.
 *
 * Called by sys_channel_apply_output_timing for a port whose type (input_get_port_sync_mode) is 5, just before the
 * channel's output timing is built; the return value is not used there.
 */
unsigned char input_block_measure_active_area(unsigned char block)
{
    unsigned short start_ticks;
    unsigned char finished;

    if (!(input_capture_read8(block, 0x54) & 0x80))
        return 0;
    input_adc_adjust_aborted = 0;
    input_block_reset_window_regs(block);
    input_capture_write8(block, 0x37, 0x40);
    input_capture_write8(block, 0x36, 0);
    input_capture_write8(block, 0x36, 0x11);
    timer_sleep_ticks(20);
    finished = 0;
    start_ticks = timer_get_ticks16();
    for (;;) {
        if (input_block_is_change_pending(block) == 1) {
            input_adc_adjust_aborted = 1;
            break;
        }
        if (!(input_capture_read8(block, 0x36) & 1)) {
            finished = 1;
            break;
        }
        if (timer_ticks_since(start_ticks) > MEASURE_WAIT_TICKS)
            break;
    }
    if (finished == 0)
        input_adc_adjust_aborted = 1;
    if (input_adc_adjust_aborted == 1)
        return 0;
    input_capture_write16(block, 0x12, input_capture_read16(block, 0x3e) & 0xfff);
    input_capture_write16(block, 0xe, input_capture_read16(block, 0x38) & 0x7ff);
    input_capture_write16(block, 0xc, input_capture_read16(block, 0x38) & 0x7ff);
    if (input_capture_read16(block, 0x3a) > input_capture_read16(block, 0x38))
        input_block_set_offset(block, 1);
    else if (input_capture_read16(block, 0x3a) < input_capture_read16(block, 0x38))
        input_block_set_offset(block, 0xffff);
    else
        input_block_set_offset(block, 0);
    return 1;
}

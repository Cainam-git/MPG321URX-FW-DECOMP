/* input_block_reset_window_regs  (FUN_a0121e3c)
 *
 * Reset an input block's window registers when the low nibble of its capture register 4 is above 1.
 * Name basis: descriptive - registers 8, 9, 10 and the following; test on capture register 4 bits 0..3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121e3c @ 0xa0121e3c, flags -mcpu=v8 -O2 -g.
 */
extern unsigned int input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);

/*
 * Put capture registers 8..11 of an input block back to 1, 0, 0, 0, but only when the low nibble of register 4
 * is above 1.
 *
 *   block   input block number (0..7)
 *
 * No result. Called before a measurement by input_block_measure_active_area, input_adc_auto_adjust's gain search
 * and sys_channel_apply_output_timing.
 */
void input_block_reset_window_regs(unsigned char block)
{
    if ((input_capture_read8(block, 4) & 0xf) > 1) {
        input_capture_write8(block, 8, 1);
        input_capture_write8(block, 9, 0);
        input_capture_write8(block, 10, 0);
        input_capture_write8(block, 11, 0);
    }
}

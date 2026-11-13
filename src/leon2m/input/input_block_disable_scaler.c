/* input_block_disable_scaler  (FUN_a00f8918)
 *
 * Switch the scaling bit of an input block off.
 * Name basis: descriptive - bit 7 of register 0x9C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8918 @ 0xa00f8918, flags -mcpu=v8 -O2 -g.
 */
extern int input_capture_update_bits();

/* Clear bit 7 of register 0x9C of the capture block (set by input_block_enable_scaler_ratio). */
void input_block_disable_scaler(unsigned char block)
{
    input_capture_update_bits(block, 0x9c, 0x80, 0);
    return;
}

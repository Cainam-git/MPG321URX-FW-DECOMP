/* input_block_pulse_reg2f_bit7  (FUN_a00f9910)
 *
 * Set and then clear bit 7 of register 0x2F of an input block.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9910 @ 0xa00f9910, 12 words. The word after the routine is data.
 */
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

/* Set bit 7 of register 0x2F of the capture block and clear it again at once. Nothing calls this routine. */
void input_block_pulse_reg2f_bit7(unsigned int block)
{
    input_capture_update_bits(block & 0xff, 0x2f, 0x80, 1);
    input_capture_update_bits(block & 0xff, 0x2f, 0x80, 0);
}

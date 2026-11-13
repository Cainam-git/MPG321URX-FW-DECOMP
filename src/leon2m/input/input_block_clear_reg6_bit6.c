/* input_block_clear_reg6_bit6  (FUN_a00f8f14)
 *
 * Clear bit 6 of register 6 of an input block.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8f14 @ 0xa00f8f14, 8 words, flags -mcpu=v8 -O2 -g.
 * The call is a tail call: the caller's return address is passed on, so the callee returns straight to the
 * caller. The last word is the nop the compiler places behind such a call.
 */
extern void input_capture_update_bits(unsigned char, unsigned char, unsigned char, unsigned char);

/* Clear bit 6 of register 6 of the capture block. Nothing calls this routine. */
void input_block_clear_reg6_bit6(unsigned char block)
{
    input_capture_update_bits(block, 6, 0x40, 0);
}

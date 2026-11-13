/* input_block_set_reg5c_bit0  (FUN_a00f90fc)
 *
 * Set bit 0 of register 0x5C of an input block.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f90fc @ 0xa00f90fc, 8 words, flags -mcpu=v8 -O2 -g.
 * The call is a tail call: the caller's return address is passed on, so the callee returns straight to the
 * caller. The last word is the nop the compiler places behind such a call.
 */
extern void input_capture_update_bits(unsigned char, unsigned char, unsigned char, unsigned char);

/* Set bit 0 of register 0x5C of the capture block. Nothing calls this routine. */
void input_block_set_reg5c_bit0(unsigned char block)
{
    input_capture_update_bits(block, 0x5c, 1, 1);
}

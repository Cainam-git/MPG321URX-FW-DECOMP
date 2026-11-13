/* input_block0_set_regad_bit0  (FUN_a010b34c)
 *
 * Set bit 0 of register 0xAD of input block 0.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b34c @ 0xa010b34c, flags -mcpu=v8 -O2 -g (section default).
 * The call is a tail call: the caller's return address is handed on, so the callee returns straight to this
 * routine's caller. The last word is the nop the compiler places behind such a call sequence.
 */
extern void input_capture_update_bits(unsigned char, unsigned char, unsigned char, unsigned char);

/*
 * Set bit 0 of register 0xAD of input block 0.
 *
 * No routine in the image calls it; no stored address points at it.
 */
void input_block0_set_regad_bit0(void)
{
    input_capture_update_bits(0, 0xad, 1, 1);
}

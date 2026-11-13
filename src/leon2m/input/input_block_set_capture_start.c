/* input_block_set_capture_start  (FUN_a00f8938)
 *
 * Write the horizontal start (made even) and the vertical start of an input block.
 * Name basis: descriptive - registers 0x14 and 0x10
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8938 @ 0xa00f8938, 13 words, flags -mcpu=v8 -O3 -g.
 * Source form: the "& ~1" is its own statement on the unsigned int parameter. In one expression the compiler turns
 * (u16)(x & ~1) into x & 0xfffe (sethi, or, and); as a statement it keeps "and -2" and the 16-bit
 * zero-extension (sll, srl), as the firmware does. The parameter types come from the callee's prototype.
 */
extern void input_capture_write16(unsigned char, unsigned char, unsigned short);

/* Write the horizontal start (made even) to capture register 0x14 and the vertical start to register 0x10.
 * input_block_get_capture_hstart and input_block_get_capture_vstart read them back. */
void input_block_set_capture_start(unsigned char block, unsigned int h_start, unsigned short v_start)
{
    h_start &= ~1;
    input_capture_write16(block, 0x14, h_start);
    input_capture_write16(block, 0x10, v_start);
}

/* input_block_get_capture_hstart  (FUN_a00f8dd4)
 *
 * Return the 12-bit horizontal start of an input block.
 * Returns: value
 * Name basis: derived - register 0x14, the one input_block_set_capture_start writes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8dd4 @ 0xa00f8dd4, flags -mcpu=v8 -O2 -g.
 */
extern int input_capture_read16(unsigned int, unsigned int);

/* Read 16-bit register 0x14 of the capture block and keep its low 12 bits: the horizontal start that
 * input_block_set_capture_start writes. The second parameter is not used. */
unsigned int input_block_get_capture_hstart(unsigned int block, unsigned int unused)
{
    return input_capture_read16(block & 0xff, 0x14) & 0xfff;
}

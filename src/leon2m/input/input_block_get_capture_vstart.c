/* input_block_get_capture_vstart  (FUN_a00f8df0)
 *
 * Return the 11-bit vertical start of an input block.
 * Returns: value
 * Name basis: derived - register 0x10, the one input_block_set_capture_start writes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8df0 @ 0xa00f8df0, flags -mcpu=v8 -O2 -g.
 */
extern int input_capture_read16(int, int);

/* Read 16-bit register 0x10 of the capture block and keep its low 11 bits: the vertical start that
 * input_block_set_capture_start writes. The second parameter is not used. */
int input_block_get_capture_vstart(int block, int unused)
{
    int masked_block = block & 0xff;
    int value = input_capture_read16(masked_block, 0x10);
    return value & 0x7ff;
}

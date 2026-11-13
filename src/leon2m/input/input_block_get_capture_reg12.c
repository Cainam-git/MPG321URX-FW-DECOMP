/* input_block_get_capture_reg12  (FUN_a00f88ac)
 *
 * Return 16-bit register 0x12 of an input block's capture unit.
 * Returns: value
 * Note: sys_channel_fill_size_fields copies it to channel record +0x1A and +0x1E, the horizontal start fields.
 * Name basis: descriptive - mechanics only; the register that input_block_set_capture_reg12 writes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f88ac @ 0xa00f88ac, flags -mcpu=v8 -O2 -g.
 * Source form: the block number is masked to a byte in a separate statement.
 */
extern int input_capture_read16();

/* Read 16-bit register 0x12 of the capture block, the one input_block_set_capture_reg12 writes.
 * The second parameter is not used. */
unsigned short input_block_get_capture_reg12(unsigned int block, unsigned int unused)
{
    block = block & 0xff;
    return input_capture_read16(block, 0x12);
}

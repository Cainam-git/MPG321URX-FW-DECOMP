/* input_block_read_reg8f_word  (FUN_a00f9334)
 *
 * Return the 16-bit register 0x8F of an input block.
 * Returns: value
 * Name basis: descriptive - used by the sync state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9334 @ 0xa00f9334, flags -mcpu=v8 -O2 -g.
 * Source form: the block number is masked to a byte in a separate statement.
 */
extern int input_capture_read16();

/* Read 16-bit register 0x8f of the capture block. The second parameter is not used. */
unsigned short input_block_read_reg8f_word(unsigned int block, unsigned int unused)
{
    block = block & 0xff;
    return input_capture_read16(block, 0x8f);
}

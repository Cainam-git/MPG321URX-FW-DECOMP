/* input_block_read_reg95_word  (FUN_a00f92f4)
 *
 * Return the 16-bit register 0x95 of an input block.
 * Returns: value
 * Name basis: descriptive - used by the sync state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f92f4 @ 0xa00f92f4, flags -mcpu=v8 -O2 -g.
 * Source form: the block number is masked to a byte in a separate statement.
 */
extern int input_capture_read16();

/* Read 16-bit register 0x95 of the capture block. The second parameter is not used. */
unsigned short input_block_read_reg95_word(unsigned int block, unsigned int unused)
{
    block = block & 0xff;
    return input_capture_read16(block, 0x95);
}

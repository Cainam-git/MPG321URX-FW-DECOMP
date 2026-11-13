/* input_block_read_reg97_word  (FUN_a00f9314)
 *
 * Return the 16-bit register 0x97 of an input block.
 * Returns: value
 * Name basis: descriptive - used by the sync state machine and the port timing record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9314 @ 0xa00f9314, flags -mcpu=v8 -O2 -g.
 * Source form: the block number is masked to a byte in a separate statement.
 */
extern int input_capture_read16();

/* Read 16-bit register 0x97 of the capture block. The second parameter is not used. */
unsigned short input_block_read_reg97_word(unsigned int block, unsigned int unused)
{
    block = block & 0xff;
    return input_capture_read16(block, 0x97);
}

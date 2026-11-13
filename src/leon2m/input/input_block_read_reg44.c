/* input_block_read_reg44  (FUN_a00f635c)
 *
 * Read register 0x44 of an input block.
 * Returns: value
 * Name basis: descriptive - used by the automatic level control
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f635c @ 0xa00f635c, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);

/* Read register 0x44 of the capture block blk. Called by pq_auto_level_task, which reads registers 0x43, 0x44
 * and 0x45 (one routine each) of the block. */
unsigned char input_block_read_reg44(unsigned char blk)
{
    return input_capture_read8(blk, 0x44);
}

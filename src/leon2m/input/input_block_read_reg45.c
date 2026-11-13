/* input_block_read_reg45  (FUN_a00f6378)
 *
 * Read register 0x45 of an input block.
 * Returns: value
 * Name basis: descriptive - used by the automatic level control
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6378 @ 0xa00f6378, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);

/* Read register 0x45 of the capture block blk. Called by pq_auto_level_task, which reads registers 0x43, 0x44
 * and 0x45 (one routine each) of the block. */
unsigned char input_block_read_reg45(unsigned char blk)
{
    return input_capture_read8(blk, 0x45);
}

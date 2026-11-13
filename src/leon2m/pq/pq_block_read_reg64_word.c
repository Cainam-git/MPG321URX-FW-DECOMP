/* pq_block_read_reg64_word  (FUN_a0105ca4)
 *
 * Read the 16-bit register 0x64 of a picture block.
 * Returns: value
 * Name basis: descriptive - forwards to the block's 16-bit read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105ca4 @ 0xa0105ca4, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the block number is masked to 8 bits in the routine ('block = block & 0xff') before the
 * call; the second parameter is not read.
 */
extern int pq_block_read16();

#define BLK_LINES 0x64   /* picture block register: lines */

/*
 * Return the 16-bit register 0x64 of a picture block, read with pq_block_read16.
 *
 *   block   picture block; only its low 8 bits are passed on
 *   unused  not read
 *
 * Only caller: input_channel_bring_up_task.
 */
unsigned short pq_block_read_reg64_word(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_LINES);
}

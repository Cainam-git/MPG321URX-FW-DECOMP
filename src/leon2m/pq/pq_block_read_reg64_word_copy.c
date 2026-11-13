/* pq_block_read_reg64_word_copy  (FUN_a0106274)
 *
 * Read the 16-bit register 0x64 of a picture block.
 * Returns: value
 * Note: Identical copy of pq_block_read_reg64_word.
 * Name basis: descriptive - forwards to the block's 16-bit read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106274 @ 0xa0106274, flags -mcpu=v8 -O2 -g (the section default).
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
 * Callers: sys_fill_output_size_record (as the active height h3 of the output size), pq_pivot_setup_timing
 * and pq_pivot_update_counter (block 0).
 * The same code as pq_block_read_reg64_word.
 */
unsigned short pq_block_read_reg64_word_copy(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_LINES);
}

/* pq_block_read_reg5b_word_copy  (FUN_a0106900)
 *
 * Read the 16-bit register 0x5B of a picture block.
 * Returns: value
 * Note: Identical copy of pq_block_read_reg5b_word; called by sys_fill_output_size_record.
 * Name basis: descriptive - forwards to pq_block_read16 with register 0x5B; called twice by
 *   sys_fill_output_size_record (field h1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106900 @ 0xa0106900, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the block number is masked to 8 bits in the routine ('block = block & 0xff') before the
 * call; the second parameter is not read.
 */
extern int pq_block_read16();

#define BLK_VTOTAL 0x5b   /* picture block register: vertical total */

/*
 * Return the 16-bit register 0x5B of a picture block, read with pq_block_read16.
 *
 *   block   picture block; only its low 8 bits are passed on
 *   unused  not read
 *
 * Only caller: sys_fill_output_size_record (as the frame length h1 of the output size).
 * The same code as pq_block_read_reg5b_word.
 */
unsigned short pq_block_read_reg5b_word_copy(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_VTOTAL);
}

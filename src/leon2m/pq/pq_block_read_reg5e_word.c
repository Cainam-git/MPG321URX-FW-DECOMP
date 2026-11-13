/* pq_block_read_reg5e_word  (FUN_a0105cc4)
 *
 * Read the 16-bit register 0x5E of a picture block.
 * Returns: value
 * Name basis: descriptive - forwards to the block's 16-bit read; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105cc4 @ 0xa0105cc4, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the block number is masked to 8 bits in the routine ('block = block & 0xff') before the
 * call; the second parameter is not read.
 */
extern int pq_block_read16();

#define BLK_HTOTAL 0x5e   /* picture block register: horizontal total */

/*
 * Return the 16-bit register 0x5E of a picture block, read with pq_block_read16.
 *
 *   block   picture block; only its low 8 bits are passed on
 *   unused  not read
 *
 * Nothing calls this routine.
 */
unsigned short pq_block_read_reg5e_word(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_HTOTAL);
}

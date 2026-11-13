/* pq_block_read_reg66_word  (FUN_a0106880)
 *
 * Read the 16-bit register 0x66 of a picture block.
 * Returns: value
 * Name basis: descriptive - forwards to the block's 16-bit read; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106880 @ 0xa0106880, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the block number is masked to 8 bits in the routine ('block = block & 0xff') before the
 * call; the second parameter is not read.
 */
extern int pq_block_read16();

#define BLK_REG_66 0x66   /* picture block register 0x66; pq_block_set_window_regs writes the channel's x_extra to it */

/*
 * Return the 16-bit register 0x66 of a picture block, read with pq_block_read16.
 *
 *   block   picture block; only its low 8 bits are passed on
 *   unused  not read
 *
 * Nothing calls this routine.
 */
unsigned short pq_block_read_reg66_word(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_REG_66);
}

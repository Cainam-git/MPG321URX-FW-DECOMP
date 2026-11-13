/* pq_block_read_reg62_word  (FUN_a01068c0)
 *
 * Read the 16-bit register 0x62 of a picture block.
 * Returns: value
 * Name basis: descriptive - forwards to the block's 16-bit read; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01068c0 @ 0xa01068c0, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the block number is masked to 8 bits in the routine ('block = block & 0xff') before the
 * call; the second parameter is not read.
 */
extern int pq_block_read16();

#define BLK_REG_62 0x62   /* picture block register 0x62; pq_block_set_window_regs writes the channel's y_extra to it */

/*
 * Return the 16-bit register 0x62 of a picture block, read with pq_block_read16.
 *
 *   block   picture block; only its low 8 bits are passed on
 *   unused  not read
 *
 * Nothing calls this routine.
 */
unsigned short pq_block_read_reg62_word(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_REG_62);
}

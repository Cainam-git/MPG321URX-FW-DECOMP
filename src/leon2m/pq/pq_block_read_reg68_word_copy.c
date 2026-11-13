/* pq_block_read_reg68_word_copy  (FUN_a01062c0)
 *
 * Read the 16-bit register 0x68 of a picture block.
 * Returns: value
 * Note: Identical copy of pq_block_read_reg68_word; called by sys_fill_output_size_record.
 * Name basis: descriptive - forwards to pq_block_read16 with register 0x68; called twice by
 *   sys_fill_output_size_record (field h2)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01062c0 @ 0xa01062c0, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the block number is masked to 8 bits in the routine ('block = block & 0xff') before the
 * call; the second parameter is not read.
 */
extern int pq_block_read16();

#define BLK_REG_68 0x68   /* picture block register 0x68; pq_block_set_window_regs writes the channel width to it */

/*
 * Return the 16-bit register 0x68 of a picture block, read with pq_block_read16.
 *
 *   block   picture block; only its low 8 bits are passed on
 *   unused  not read
 *
 * Only caller: sys_fill_output_size_record (as the active width h2 of the output size).
 * The same code as pq_block_read_reg68_word.
 */
unsigned short pq_block_read_reg68_word_copy(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_REG_68);
}

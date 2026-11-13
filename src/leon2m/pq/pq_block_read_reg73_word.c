/* pq_block_read_reg73_word  (FUN_a0106860)
 *
 * Read the 16-bit register 0x73 of a picture block.
 * Returns: value
 * Name basis: descriptive - forwards to the block's 16-bit read; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106860 @ 0xa0106860, flags -mcpu=v8 -O2 -g (section default).
 * Source form: pq_block_read16 is declared without a parameter list and int-returning; the block number is
 * masked to its low byte in the parameter itself before the call.
 */

#define BLK_REG_73 0x73                 /* low byte of the pair 0x73 / 0x74 */

extern int pq_block_read16();

/*
 * Return the 16-bit value of registers 0x73 (low byte) and 0x74 of a picture block (pq_block_read16).
 *   block   picture block, low byte used
 *   unused  not used
 * No caller of this routine is found in the firmware.
 */
unsigned short pq_block_read_reg73_word(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_REG_73);
}

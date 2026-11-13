/* pq_block_read_reg6f_word  (FUN_a01068a0)
 *
 * Read the 16-bit register 0x6F of a picture block.
 * Returns: value
 * Name basis: descriptive - forwards to the block's 16-bit read; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01068a0 @ 0xa01068a0, flags -mcpu=v8 -O2 -g (section default).
 * Source form: pq_block_read16 is declared without a parameter list and int-returning; the block number is
 * masked to its low byte in the parameter itself before the call.
 */

/* Low byte of the pair 0x6F / 0x70; panel_output_setup_channel_timing writes it (BLK_ROW_0X30_SUM_2). */
#define BLK_ROW_0X30_SUM_2 0x6f

extern int pq_block_read16();

/*
 * Return the 16-bit value of registers 0x6F (low byte) and 0x70 of a picture block (pq_block_read16).
 *   block   picture block, low byte used
 *   unused  not used
 * No caller of this routine is found in the firmware.
 */
unsigned short pq_block_read_reg6f_word(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return pq_block_read16(block, BLK_ROW_0X30_SUM_2);
}

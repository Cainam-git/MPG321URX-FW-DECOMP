/* pq_block_set_regs_d0_d1  (FUN_a0106d3c)
 *
 * Write registers 0xD0 and 0xD1 of a picture block.
 * Name basis: descriptive - used by the channel window set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106d3c @ 0xa0106d3c, flags -mcpu=v8 -O2 -g (the section default; -O3 -g and -Os -g give the
 * same bytes).
 * Source form: two calls to pq_block_write8; the second is a tail call and passes three extra arguments
 * after the value (parameters 4..6, handed on in the same registers).
 */
extern int pq_block_write8();

#define REG_D0 0xd0   /* picture block register D0 */
#define REG_D1 0xd1   /* picture block register D1 */

/*
 * Write the 8-bit registers 0xD0 and 0xD1 of a picture block.
 *
 *   block, d0_value, d1_value   block number and the two register values
 *   d1_arg4..6                  handed on to pq_block_write8, which takes only three parameters
 *
 * Only caller: sys_setup_channel_window, with the values 0x3F / 0xFF or 0x30 / 0xC0 for the block given in
 * bits 12..15 of channel 3's record word 0.
 */
void pq_block_set_regs_d0_d1(unsigned char block, unsigned char d0_value, unsigned char d1_value, unsigned int d1_arg4,
                 unsigned int d1_arg5, unsigned int d1_arg6)

{
  pq_block_write8(block, REG_D0, d0_value);
  pq_block_write8(block, REG_D1, d1_value, d1_arg4, d1_arg5, d1_arg6);
  return;
}

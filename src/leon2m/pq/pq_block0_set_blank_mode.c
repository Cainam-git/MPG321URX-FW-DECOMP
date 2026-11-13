/* pq_block0_set_blank_mode  (FUN_a0105d04)
 *
 * Write the blanking mode of picture block 0.
 * Name basis: derived - register 0x54 of block 0: 0 = show, 2 = blank
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105d04 @ 0xa0105d04, flags -mcpu=v8 -O2 -g (the section default; -O3 -g and -Os -g give the
 * same bytes).
 * Source form: a single call to pq_block_write8 with an unsigned char parameter.
 */
extern int pq_block_write8();

#define BLOCK_0 0                       /* picture block 0 */
#define BLK_BLANK_MODE 0x54             /* blanking mode register of a picture block */

/*
 * Write the blanking mode of picture block 0.
 *
 *   blanking_mode  value for register BLK_BLANK_MODE of block 0 (pq_block_show writes 0 there, pq_block_blank 2)
 *
 * Callers: pq_fga_handle_command (2, later 0) and sys_api_set_block0_reg54_mode (0, 1 or 2), which nothing
 * calls.
 */
void pq_block0_set_blank_mode(unsigned char blanking_mode)

{
  pq_block_write8(BLOCK_0,BLK_BLANK_MODE,blanking_mode);
  return;
}

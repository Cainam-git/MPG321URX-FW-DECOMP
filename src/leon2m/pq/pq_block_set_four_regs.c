/* pq_block_set_four_regs  (FUN_a0105a3c)
 *
 * Write four 16-bit registers of a picture block.
 * Name basis: descriptive - registers 0x73, 0x75, 0x6F and one more; used by the channel window set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105a3c @ 0xa0105a3c, flags -mcpu=v8 -O3 -g.
 * Source form: the registers are written in the order 0x73, 0x75, 0x6F, 0x71, not in the order of the
 * parameters.
 */
extern void pq_block_write16();

#define BLK_LINES_2 0x71   /* picture block register: lines 2 */

/*
 * Write four 16-bit registers of a picture block.
 *
 *   blk                    picture block
 *   width_2, lines_part    the channel record's width_2 and lines_part   -> register 0x75, BLK_LINES_2
 *   x_offset, y_offset     the channel record's x_offset and y_offset    -> register 0x73, register 0x6F
 *
 * Only caller: sys_setup_channel_window, right after pq_block_set_window_regs.
 */
void pq_block_set_four_regs(unsigned char blk, unsigned short width_2, unsigned short lines_part, unsigned short x_offset, unsigned short y_offset)
{
    pq_block_write16(blk, 0x73, x_offset);
    pq_block_write16(blk, 0x75, width_2);
    pq_block_write16(blk, 0x6f, y_offset);
    pq_block_write16(blk, BLK_LINES_2, lines_part);
}

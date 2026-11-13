/* pq_block_set_window_regs  (FUN_a0105910)
 *
 * Write six window values of a picture block and raise two limits when needed.
 * Name basis: descriptive - registers 0x64, 0x68, 0x66, 0x62, 0xA0 and 0xBE; used by the channel window set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105910 @ 0xa0105910-0xa0105a3c (75 words), flags -mcpu=v8 -O3 -g.
 */
extern void pq_block_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short pq_block_read16(unsigned char blk, unsigned char reg);

#define LAST_BLOCK 3                 /* only blocks 0..3 are written */
#define BLK_LINES 0x64               /* picture block register: lines */
#define REG_68 0x68                  /* window register, meaning not documented */
#define REG_66 0x66                  /* window register, meaning not documented */
#define REG_62 0x62                  /* window register, meaning not documented */
#define REG_A0 0xa0                  /* window register, meaning not documented */
#define REG_BE 0xbe                  /* window register, meaning not documented */
#define BLK_VTOTAL 0x5b              /* picture block register: vertical total */
#define BLK_HTOTAL 0x5e              /* picture block register: horizontal total */

/*
 * Write the six window values of a picture block (blk 0..3; other blocks: nothing is done).
 *
 *   width, lines        the channel record's width and lines   -> REG_68, BLK_LINES
 *   x_extra, y_extra    the channel record's x_extra, y_extra  -> REG_66, REG_62
 *   reg_a0, reg_be      two set-up values of the caller        -> REG_A0, REG_BE (reg_be as a byte)
 *
 * Then the totals are raised when needed: when BLK_VTOTAL is not above lines + y_extra it becomes
 * lines + y_extra + 0x10, and when BLK_HTOTAL is not above width + x_extra it becomes width + x_extra + 0x10.
 *
 * Only caller: sys_setup_channel_window.
 */
void pq_block_set_window_regs(unsigned char blk, unsigned short width, unsigned short lines, unsigned short x_extra, unsigned short y_extra,
                  unsigned short reg_a0, unsigned char reg_be)
{
    if (blk > LAST_BLOCK)
        return;
    pq_block_write16(blk, BLK_LINES, lines);
    pq_block_write16(blk, REG_68, width);
    pq_block_write16(blk, REG_66, x_extra);
    pq_block_write16(blk, REG_62, y_extra);
    pq_block_write16(blk, REG_A0, reg_a0);
    pq_block_write16(blk, REG_BE, reg_be);
    if (pq_block_read16(blk, BLK_VTOTAL) <= lines + y_extra)
        pq_block_write16(blk, BLK_VTOTAL, lines + y_extra + 0x10);
    if (pq_block_read16(blk, BLK_HTOTAL) <= width + x_extra)
        pq_block_write16(blk, BLK_HTOTAL, width + x_extra + 0x10);
}

/* pq_block8_count_reg50_step  (FUN_a0118994)
 *
 * Count calls that find bit 0 of a block's register 0x50 set; past 50 write 0x40 or 0 to 0xCF012F00.
 *   block: picture block whose register 0x50 is read
 * Note: Counts only while bit 0 of 0xCF012E00 is set and bit 0 of 0xCF0115C0 is clear; the value written is
 *   0x40 when 0xCF012F24 is not 0. Nothing calls it.
 * Name basis: descriptive - counter at 0xA802C99C; registers 0xCF012E00, 0xCF0115C0, 0xCF012F00, 0xCF012F24
 *   and block register 0x50; no reference in the image
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118994 @ 0xa0118994-0xa0118a28 (37 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the BLOCK8_F24 test is written '!= 0' with the 0x40 arm first (the firmware falls through into the 0x40
 *    store);
 *  - pq_block_read8 is declared unsigned char (unsigned char, unsigned char), and the parameter is unsigned char.
 */
extern unsigned char pq_block8_reg50_count;
extern unsigned char pq_block_read8(unsigned char port, unsigned char reg);

#define BLOCK8_E00   (*(volatile unsigned int *)0xcf012e00)     /* bit 0 set by pq_block8_start */
#define REG_115C0    (*(volatile unsigned int *)0xcf0115c0)     /* sys_shut_down_blocks writes 0xF here */
#define BLOCK8_F00   (*(volatile unsigned int *)0xcf012f00)
#define BLOCK8_F24   (*(volatile unsigned int *)0xcf012f24)

#define BLOCK_REG_50     0x50       /* register of the picture block given as the argument; bit 0 is tested */
#define COUNT_LIMIT      0x32       /* the count is reset on the step after it reaches 50 */
#define F00_VALUE_40     0x40       /* written when BLOCK8_F24 is not 0 */

/*
 * One step of a counter: while bit 0 of BLOCK8_E00 is set, bit 0 of 0xCF0115C0 is clear and bit 0 of register
 * 0x50 of picture block 'block' is set, pq_block8_reg50_count goes up by one. On the step after it has reached
 * 50 it goes back to 0 instead, and BLOCK8_F00 receives 0x40 when BLOCK8_F24 is not 0, else 0.
 *
 *   block   picture block number for pq_block_read8
 *
 * Nothing in the firmware calls this routine.
 */
void pq_block8_count_reg50_step(unsigned char block)
{
    if (((BLOCK8_E00 & 1) != 0) &&
        ((REG_115C0 & 1) == 0) &&
        (pq_block_read8(block, BLOCK_REG_50) & 1)) {
        if ((unsigned char)(pq_block8_reg50_count + 1) > COUNT_LIMIT) {
            pq_block8_reg50_count = 0;
            if (BLOCK8_F24 != 0) {
                BLOCK8_F00 = F00_VALUE_40;
            } else {
                BLOCK8_F00 = 0;
            }
        } else {
            pq_block8_reg50_count = pq_block8_reg50_count + 1;
        }
    }
}

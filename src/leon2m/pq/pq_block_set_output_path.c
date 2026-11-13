/* pq_block_set_output_path  (FUN_a0106920)
 *
 * Switch the output path of a picture block on or off.
 * Name basis: derived - path and bits depend on the chip revision
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106920 @ 0xa0106920-0xa0106b08 (122 words), flags -mcpu=v8 -O3 -g.
 * Source form: the revision 0x80 / 0x81 part is the then-arm (the firmware's fall-through); the revision is read
 * again for the CHIP_REV_80 test (the firmware calls sys_get_chip_revision twice); the BLK_REG_86 value is two
 * statements (one combined expression lets the compiler drop the third AND). volatile only on the hardware
 * registers.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define REG_CF00F1C0         R(0xcf00f1c0)   /* bit 0 follows the path on revision 0x81 */
#define OUTPUT_SYNC_POLARITY R(0xcf00ed58)   /* bit 4 */
#define REG_CF00ED84         R(0xcf00ed84)   /* bit 0 */

#define CHIP_REV_80 0x80
#define CHIP_REV_81 0x81

#define PQ_BLOCK_0  0

/* Registers of picture block 0 used here. */
#define BLK_REG_7D  0x7d
#define BLK_REG_86  0x86
#define REG86_BIT2  0x04
#define REG86_BIT3  0x08
#define REG86_BIT4  0x10
#define REG7D_BIT5  0x20

#define PATH_ON_WAIT_TICKS 0x50         /* timer_sleep_ticks waits n + 1 ticks */

extern unsigned char sys_get_chip_revision(void);
extern unsigned char pq_block_read8(unsigned char block, unsigned char reg);
extern void pq_block_write8(unsigned char block, unsigned char reg, unsigned char value);
extern void pq_block_update_bits(unsigned char block, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char sys_frc_is_running(void);
extern void timer_sleep_ticks(int ticks);

/*
 * Switch the output path of picture block 0 on (on != 0) or off. For any other block nothing happens.
 *
 * What is written depends only on the chip revision and on 'on':
 *   revision above 0x81: bit 3 of block register 0x86, then bit 4; switching on waits 81 ticks between the two.
 *   revision 0x80 / 0x81: on revision 0x81 bit 0 of REG_CF00F1C0 first follows 'on'. Register 0x86 gets bits
 *     3 and 4 set and bit 2 cleared (on), or bit 4 set and bits 2 and 3 cleared (off). Then bit 5 of block
 *     register 0x7D is the state of a second step: switching on sets it, and clears bit 4 of
 *     OUTPUT_SYNC_POLARITY and bit 0 of REG_CF00ED84; switching off clears it and sets those two bits again.
 *     Nothing is done when the bit already has the wanted state, and switching on leaves it alone while the
 *     frame-rate converter runs.
 *
 * Called with on = 1 by pq_block_show after the block is unblanked, and with on = 0 by pq_block_blank and
 * pq_block_blank_with_color.
 */
void pq_block_set_output_path(unsigned char block, unsigned char on)
{
    unsigned char reg86;

    if (block != PQ_BLOCK_0)
        return;
    if (sys_get_chip_revision() <= CHIP_REV_81) {
        if (on) {
            if (sys_get_chip_revision() > CHIP_REV_80)
                REG_CF00F1C0 |= 1;
            reg86 = pq_block_read8(PQ_BLOCK_0, BLK_REG_86);
            reg86 = (reg86 & ~(REG86_BIT2 | REG86_BIT3)) | (REG86_BIT4 | REG86_BIT3);
            pq_block_write8(PQ_BLOCK_0, BLK_REG_86, reg86 & ~REG86_BIT2);
            if (sys_frc_is_running())
                return;
            if (pq_block_read8(PQ_BLOCK_0, BLK_REG_7D) & REG7D_BIT5)
                return;             /* already on */
            pq_block_update_bits(PQ_BLOCK_0, BLK_REG_7D, REG7D_BIT5, 1);
            OUTPUT_SYNC_POLARITY &= ~0x10;
            REG_CF00ED84 &= ~1;
        } else {
            if (sys_get_chip_revision() > CHIP_REV_80)
                REG_CF00F1C0 &= ~1;
            reg86 = pq_block_read8(PQ_BLOCK_0, BLK_REG_86);
            reg86 = (reg86 & ~(REG86_BIT2 | REG86_BIT3)) | REG86_BIT4;
            pq_block_write8(PQ_BLOCK_0, BLK_REG_86, reg86 & ~(REG86_BIT2 | REG86_BIT3));
            if (!(pq_block_read8(PQ_BLOCK_0, BLK_REG_7D) & REG7D_BIT5))
                return;             /* already off */
            pq_block_update_bits(PQ_BLOCK_0, BLK_REG_7D, REG7D_BIT5, 0);
            OUTPUT_SYNC_POLARITY |= 0x10;
            REG_CF00ED84 |= 1;
        }
    } else {
        if (on) {
            pq_block_update_bits(PQ_BLOCK_0, BLK_REG_86, REG86_BIT3, 1);
            timer_sleep_ticks(PATH_ON_WAIT_TICKS);
            pq_block_update_bits(PQ_BLOCK_0, BLK_REG_86, REG86_BIT4, 1);
        } else {
            pq_block_update_bits(PQ_BLOCK_0, BLK_REG_86, REG86_BIT3, 0);
            pq_block_update_bits(PQ_BLOCK_0, BLK_REG_86, REG86_BIT4, 0);
        }
    }
}

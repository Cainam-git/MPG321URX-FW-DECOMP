/* leon2m FUN_a0101bb0 @ 0xa0101bb0-0xa0101c64 (45 words).
 * When init != 0: clears bit 6 of hardware register 0xcf016118, writes 0 to 0xcf0160c4 and then sets its bit 1,
 * keeps only bits 4-7 of 0xcf0160d8, writes 0 to 0xcf016104, clears bit 0 of 0xcf01610c and clears the byte
 * counter 0xa802c981. Then increments the counter and writes it to 0xcf016110 and 0xcf016114; when it has reached
 * 0xff, writes 0 to both registers and to the counter and returns 0, otherwise returns 1 (result variable r,
 * returned as r & 1). Called from FUN_a0129c10.
 */
#define REG_cf016118 (*(volatile unsigned int *)0xcf016118)
#define REG_cf0160c4 (*(volatile unsigned int *)0xcf0160c4)
#define REG_cf0160d8 (*(volatile unsigned int *)0xcf0160d8)
#define REG_cf016104 (*(volatile unsigned int *)0xcf016104)
#define REG_cf01610c (*(volatile unsigned int *)0xcf01610c)
#define REG_cf016110 (*(volatile unsigned int *)0xcf016110)
#define REG_cf016114 (*(volatile unsigned int *)0xcf016114)

extern unsigned char DAT_a802c981;

int FUN_a0101bb0(unsigned char init)
{
    unsigned char r = 1;

    if (init) {
        REG_cf016118 &= ~0x40;
        REG_cf0160c4 = 0;
        REG_cf0160c4 |= 2;
        REG_cf0160d8 &= 0xf0;
        REG_cf016104 = 0;
        REG_cf01610c &= ~1;
        DAT_a802c981 = 0;
    }
    DAT_a802c981++;
    REG_cf016110 = DAT_a802c981;
    REG_cf016114 = DAT_a802c981;
    if (DAT_a802c981 == 0xff) {
        REG_cf016110 = 0;
        DAT_a802c981 = 0;
        REG_cf016114 = 0;
        r = 0;
    }
    return r & 1;
}

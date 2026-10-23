/* leon2s FUN_a00ca4e8 @ 0xa00ca4e8-0xa00ca6d4, -mcpu=v8 -Os -g.
 * void. Register sequence on the block 0xcf018e00 (R00..R18 = offsets 0x00..0x18): R10 = 0x1b, R14 = 0x80,
 * bit 0 of R18 cleared, R00 = 0x11, R14 = 8 and a wait until bit 3 of R14 clears, R08 = 0x10, R0C = 0x3f. Then
 * the bytes DAT_a807ce50[1..0x8a] are written to R04; whenever R0C reads 0 first, bit 2 of R14 is set and waited
 * for, then R10 = 0x1b and R0C = 0x3f, otherwise R0C is decremented. Then R04 = 0x80, the four bytes 0x50, 4,
 * 0, 0 from a stack buffer go to R04 with R0C = 0..3, R08 = 0, bit 2 of R14 set and waited for, R00 = 0x33,
 * bit 4 of R10 set and waited for, and 32 reads of R04 fill DAT_a807d088[0..31].
 * Source form: the last loop has its own counter variable.
 */
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807d088[];

#define R00 (*(volatile unsigned int *)0xcf018e00)
#define R04 (*(volatile unsigned int *)0xcf018e04)
#define R08 (*(volatile unsigned int *)0xcf018e08)
#define R0C (*(volatile unsigned int *)0xcf018e0c)
#define R10 (*(volatile unsigned int *)0xcf018e10)
#define R14 (*(volatile unsigned int *)0xcf018e14)
#define R18 (*(volatile unsigned int *)0xcf018e18)

void FUN_a00ca4e8(void)
{
    unsigned char buf[4];
    unsigned char i, j;

    R10 = 0x1b;
    R14 = 0x80;
    R18 &= ~1;
    R00 = 0x11;
    R14 = 8;
    while (R14 & 8)
        ;
    R08 = 0x10;
    R0C = 0x3f;
    for (i = 1; i <= 0x8a; i++) {
        if (R0C == 0) {
            R04 = DAT_a807ce50[i];
            R14 |= 4;
            while (R14 & 4)
                ;
            R10 = 0x1b;
            R0C = 0x3f;
        } else {
            R04 = DAT_a807ce50[i];
            R0C = R0C - 1;
        }
    }
    R04 = 0x80;
    buf[0] = 0x50;
    buf[1] = 4;
    buf[2] = 0;
    buf[3] = 0;
    R0C = 0;
    R04 = buf[0];
    R0C = 1;
    R04 = buf[1];
    R0C = 2;
    R04 = buf[2];
    R0C = 3;
    R04 = buf[3];
    R08 = 0;
    R14 |= 4;
    while (R14 & 4)
        ;
    R00 = 0x33;
    R10 |= 0x10;
    while (R10 & 0x10)
        ;
    for (j = 0; j <= 0x1f; j++)
        DAT_a807d088[j] = R04;
}

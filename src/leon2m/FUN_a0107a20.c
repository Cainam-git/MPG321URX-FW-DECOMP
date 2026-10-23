/* leon2m FUN_a0107a20 @ 0xa0107a20-0xa0107b9c (95 words).
 * For p 0..2 (other p do nothing). on == 1: for p 0 or 2 sets bit 5 of register 0xcf03c348 and calls
 * FUN_a00fe880(6, 2 or 1, 9) (2 when byte 0xa8027a82 is 1); for p 1 or 2 sets bit 5 of register 0xcf03c2b8 and
 * calls FUN_a00fe880(6, 1 or 2, 9) (1 when the byte is 1). Other on: the same selections call FUN_a00fe880 with
 * 0 as the third argument first and then clear bit 5 of the register.
 */
#define R348 (*(volatile unsigned int *)0xcf03c348)
#define R2b8 (*(volatile unsigned int *)0xcf03c2b8)
extern unsigned char DAT_a8027a82;
extern void FUN_a00fe880(unsigned char, unsigned char, unsigned char);

void FUN_a0107a20(unsigned char p, unsigned char on)
{
    if (p > 2)
        return;
    if (on == 1) {
        if (p == 0 || p == 2) {
            R348 |= 0x20;
            if (DAT_a8027a82 == 1)
                FUN_a00fe880(6, 2, 9);
            else
                FUN_a00fe880(6, 1, 9);
        }
        if (p == 1 || p == 2) {
            R2b8 |= 0x20;
            if (DAT_a8027a82 == 1)
                FUN_a00fe880(6, 1, 9);
            else
                FUN_a00fe880(6, 2, 9);
        }
    } else {
        if (p == 0 || p == 2) {
            if (DAT_a8027a82 == 1)
                FUN_a00fe880(6, 2, 0);
            else
                FUN_a00fe880(6, 1, 0);
            R348 &= ~0x20;
        }
        if (p == 1 || p == 2) {
            if (DAT_a8027a82 == 1)
                FUN_a00fe880(6, 1, 0);
            else
                FUN_a00fe880(6, 2, 0);
            R2b8 &= ~0x20;
        }
    }
}

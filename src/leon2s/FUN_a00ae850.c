/* leon2s FUN_a00ae850 @ 0xa00ae850-0xa00aea0c, -mcpu=v8 -Os -g.
 * void. FUN_a00ae5e4(0) when byte DAT_a807dd37 is 1. When bit 1 of register 0xcf004680 is set: a delay loop of
 * 60000 nop passes; then, when register 0xcf003800 is not 0, the 0x30 registers 0xe00.. (address
 * (n * 4) | 0xcf000000) are copied byte-wise into row DAT_a8078830 of ARR_a807963d (0x30-byte rows) and each is
 * cleared, and DAT_a8078830 steps 0..15 cyclically; otherwise, when register 0xcf003980 is not 0, registers
 * 0xe60.. go the same way into row DAT_a8078820 of ARR_a80795dc. Then FUN_a00a6c98(0, 0xf7, 8, 1),
 * FUN_a00a6c98(0, 0x30, 0x80, 1), 0x22 to 0xcf004680, FUN_a00a6c98(0, 0x30, 0x80, 0). Ends with the tail call
 * FUN_a00856fc(0).
 * Source form: the inline reg_addr() helper keeps (n + 0xe00) * 4 unfolded; each access calls it.
 */
extern unsigned char DAT_a807dd37;
extern unsigned char DAT_a8078830;
extern unsigned char DAT_a8078820;
extern unsigned char ARR_a807963d[][0x30];
extern unsigned char ARR_a80795dc[][0x30];
extern unsigned int FUN_a00ae5e4(unsigned int);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00856fc(unsigned char);

#define R3800 (*(volatile unsigned int *)0xcf003800)
#define R3980 (*(volatile unsigned int *)0xcf003980)
#define R4680 (*(volatile unsigned int *)0xcf004680)

static __inline__ volatile unsigned int *reg_addr(unsigned int a)
{
    return (volatile unsigned int *)((a * 4) | 0xcf000000);
}

void FUN_a00ae850(void)
{
    unsigned short i;

    if (DAT_a807dd37 == 1)
        FUN_a00ae5e4(0);
    if (R4680 & 2) {
        for (i = 0; i < 60000; i++)
            __asm__("nop");
        if (R3800 != 0) {
            for (i = 0; i < 0x30; i++) {
                ARR_a807963d[DAT_a8078830][i] = *reg_addr(i + 0xe00);
                *reg_addr(i + 0xe00) = 0;
            }
            if (DAT_a8078830 <= 0xe)
                DAT_a8078830++;
            else
                DAT_a8078830 = 0;
        } else if (R3980 != 0) {
            for (i = 0; i < 0x30; i++) {
                ARR_a80795dc[DAT_a8078820][i] = *reg_addr(i + 0xe60);
                *reg_addr(i + 0xe60) = 0;
            }
        }
        FUN_a00a6c98(0, 0xf7, 8, 1);
        FUN_a00a6c98(0, 0x30, 0x80, 1);
        R4680 = 0x22;
        FUN_a00a6c98(0, 0x30, 0x80, 0);
    }
    FUN_a00856fc(0);
}

/* leon2m FUN_a00e1f50 @ 0xa00e1f50-0xa00e1fc8 (30 words), flags -mcpu=v8 -O3 -g.
 * Code facts: c = FUN_a0125e38() (returns 0/1: subx). c == 0: log FUN_a00df170(0x199698), word DAT_a802d654 =
 * address 0xa8028ff0, word DAT_a802d658 = FUN_a0124208() (returns 0x1429); else: log 0x1996a8, d654 = address
 * 0xa8027bc0, d658 = FUN_a0124214(). Then tail call FUN_a00e0e44(0) (one argument: restore %g0,0,%o0; e0e44 compares
 * %i0 with d658). void, no params.
 * The tail callee takes one argument. The values 0xa8028ff0 / 0xa8027bc0 are symbol addresses (each its own sethi).
 * Source form: the '== 0' arm is first in the source (the firmware falls through into the 0x199698 arm).
 * Compiler aids: none.
 */
extern unsigned int DAT_a802d654;
extern unsigned int DAT_a802d658;
extern unsigned char DAT_a8027bc0[];
extern unsigned char DAT_a8028ff0[];
extern int FUN_a00df170();
extern void FUN_a00e0e44(int);
extern unsigned int FUN_a0124208(void);
extern unsigned int FUN_a0124214(void);
extern unsigned char FUN_a0125e38(void);

void FUN_a00e1f50(void)
{
    if (FUN_a0125e38() == 0) {
        FUN_a00df170(0x199698);
        DAT_a802d654 = (unsigned int)DAT_a8028ff0;
        DAT_a802d658 = FUN_a0124208();
    } else {
        FUN_a00df170(0x1996a8);
        DAT_a802d654 = (unsigned int)DAT_a8027bc0;
        DAT_a802d658 = FUN_a0124214();
    }
    FUN_a00e0e44(0);
}

/* leon2m FUN_a00e1fc8 @ 0xa00e1fc8-0xa00e2040 (30 words), flags -mcpu=v8 -O3 -g.
 * Code facts: DDR table select: if FUN_a0125e38() (u8) == 0: print s_00199698 "Old DDR", word 0xa802d654 =
 * 0xa8028ff0, word 0xa802d658 = FUN_a0124208(); else print s_001996a8 "New DDR", d654 = 0xa8027bc0, d658 =
 * FUN_a0124214(). Then tail FUN_a00e0e44(0). void, no parameters.
 * The test is on the return value of FUN_a0125e38(). FUN_a00e0e44 takes one argument (0) and its value is not
 * masked. The stored values are addresses (each its own sethi|or: symbols DAT_a8028ff0 / DAT_a8027bc0).
 * Source form: the == 0 arm is first in the source (the firmware falls through into the "Old DDR" arm).
 * Compiler aids: none.
 */
extern void *_DAT_a802d654;
extern unsigned int _DAT_a802d658;
extern unsigned char DAT_a8027bc0[], DAT_a8028ff0[];
extern const char s_001996a8[], s_00199698[];
extern int FUN_a00df170();
extern void FUN_a00e0e44(int);
extern unsigned int FUN_a0124208(void);
extern unsigned int FUN_a0124214(void);
extern unsigned char FUN_a0125e38(void);

void FUN_a00e1fc8(void)
{
    if (FUN_a0125e38() == 0) {
        FUN_a00df170(s_00199698);
        _DAT_a802d654 = DAT_a8028ff0;
        _DAT_a802d658 = FUN_a0124208();
    } else {
        FUN_a00df170(s_001996a8);
        _DAT_a802d654 = DAT_a8027bc0;
        _DAT_a802d658 = FUN_a0124214();
    }
    FUN_a00e0e44(0);
}

/* FUN_a00bdb48 (leon2m, 0xa00bdb48-0xa00bdb88, 64 bytes, 16 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: writes bytes 7 = 0x30, 8 = 0x30, 9 = 0x9f of DAT_a802d078 (fw base sethi/or 0xa802d078),
 * calls FUN_a00bac3c(0x2f), masks the parameter to its low byte, calls FUN_a00ba950(p) and
 * tail-calls FUN_a00babe4(p, 0xb) (restore %g0,0xb,%o1 in the delay slot).
 * Form: the source order of the three stores is ascending 7, 8, 9; it is the only one of the 6 orders
 * that gives the fw store order 9, 8, 7 after scheduling. Aids: none.
 */
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

void FUN_a00bdb48(unsigned int param_1)
{
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = 0x9f;
    (void)FUN_a00bac3c(0x2f);
    param_1 &= 0xff;
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
}

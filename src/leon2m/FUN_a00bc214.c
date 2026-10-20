/* leon2m FUN_a00bc214 @ 0xa00bc214-0xa00bc258 (17 words), flags -mcpu=v8 -O3 -g.
 * Code facts: record DAT_a802d078 bytes 7, 8, 9 = 0x30, 0x32, 0x31 (stored in that order), FUN_a00bac3c(0x4a)
 * (return unused), param & 0xff after that call, FUN_a00ba950(p), tail FUN_a01487e8(p, 0xb, &DAT_a802d078): the
 * record address stays in %i2 and the restore passes it as %o2. FUN_a01487e8 is a wrapper that forwards o0/o1/o2
 * to FUN_a01337e8, which reads %i2 (mov %i2,%l2) as a buffer pointer: an 11-byte send of d078.
 * Source form: the record base DAT_a802d078 (FUN_a00bdb48 form).
 * Compiler aids: none.
 */
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00bc214(unsigned int param_1)
{
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x32;
    DAT_a802d078[9] = 0x31;
    (void)FUN_a00bac3c(0x4a);
    param_1 &= 0xff;
    (void)FUN_a00ba950(param_1);
    FUN_a01487e8(param_1, 0xb, DAT_a802d078);
}

/*
 * FUN_a00af168 (leon2s, 0xa00af168-0xa00af1e8, 128 bytes), flags -mcpu=v8 -Os -g.
 * Code facts: DP DSC enable. on != 0: FUN_a00a6c98(p, 0x480, 1, 1), FUN_a00a6c00(p, 0x482, 0xc0),
 * FUN_a00aef04(p), FUN_a00a6c00(p, 0x484, 2), FUN_a00a6c98(p, 0x486, 2, 1). on == 0:
 * FUN_a00a6c98(p, 0x480, 1, 0). Then the sibcall print FUN_a0073044(s_a006c510 "DP DSC en= %d", on):
 * the %d argument is 'on' (fw keeps the extended param in %i1 = %o1 after the restore; the draft
 * passed no argument). Each arm has its own call sequence (the FUN_a00af464 lever): -Os then
 * pre-sets (p, 0x480, 1, 1) above the test and crossjumps the final 6c98 call.
 * Aids: none.
 */
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned int);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00aef04(unsigned int);
extern int FUN_a0073044(const char *, ...);
extern char s_a006c510[];

void FUN_a00af168(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0) {
        FUN_a00a6c98(param_1, 0x480, 1, 1);
        FUN_a00a6c00(param_1, 0x482, 0xc0);
        FUN_a00aef04(param_1);
        FUN_a00a6c00(param_1, 0x484, 2);
        FUN_a00a6c98(param_1, 0x486, 2, 1);
    } else {
        FUN_a00a6c98(param_1, 0x480, 1, 0);
    }
    FUN_a0073044(s_a006c510, param_2);
}

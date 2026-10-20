/* FUN_a00a7168 (leon2s 0xa00a7168-0xa00a71b4, 76 bytes), flags -mcpu=v8 -Os -g.
 * t = param_1 & 0xff, with t >= 4 replaced by 0; val = DAT_a00b4d88[t] (u16). Writes the low byte of
 * param_3 to the register word at 0xcf000000 | ((val + (u16)param_2) << 2). The write counterpart of
 * FUN_a00a71b4 with the same branch-free clamp: 'cmp %g1, 4; subx %g0, 0, %g1' yields the mask -1 for
 * t < 4 and 0 for t >= 4, written as '(t >= 4) - 1'.
 */
extern unsigned short DAT_a00b4d88[];

void FUN_a00a7168(unsigned int param_1, unsigned int param_2, unsigned int param_3)
{
    unsigned int t = param_1 & 0xff;
    unsigned int mask = (t >= 4) - 1;
    unsigned int idx = (param_1 & mask) & 0xff;
    unsigned int val = DAT_a00b4d88[idx];
    *(volatile unsigned int *)(0xcf000000 | ((val + (unsigned short)param_2) << 2)) = param_3 & 0xff;
}

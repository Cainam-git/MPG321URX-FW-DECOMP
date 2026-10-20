/* leon2s FUN_a00a71b4 @ 0xa00a71b4 (-mcpu=v8 -Os -g)
 * t = param_1 & 0xFF, with t >= 4 replaced by 0; val = DAT_a00b4d88[t] (u16). Returns the low byte of the register
 * word at 0xCF000000 | ((val + (u16)param_2) << 2). The clamp is branch-free: 'cmp %g1, 4; subx %g0, 0, %g1'
 * yields the mask -1 for t < 4 and 0 for t >= 4, written as '(t >= 4) - 1'.
 */
extern unsigned short DAT_a00b4d88[];

unsigned int FUN_a00a71b4(unsigned int param_1, unsigned int param_2)
{
    unsigned int t = param_1 & 0xff;
    unsigned int mask = (t >= 4) - 1;
    unsigned int idx = (param_1 & mask) & 0xff;
    unsigned int val = DAT_a00b4d88[idx];
    return (*(volatile unsigned int *)(0xcf000000 | ((val + (unsigned short)param_2) << 2))) & 0xff;
}

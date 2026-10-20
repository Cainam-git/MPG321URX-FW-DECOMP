/* leon2s FUN_a00a6668 @ 0xa00a6668  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned short DAT_a00b4d9c[];

unsigned int FUN_a00a6668(unsigned int param_1, unsigned int param_2)
{
    unsigned int t = param_1 & 0xff;
    unsigned int mask = (t >= 2) - 1;
    unsigned int idx = (param_1 & mask) & 0xff;
    unsigned int val = DAT_a00b4d9c[idx] + (unsigned short)param_2;
    return (*(volatile unsigned int *)(0xcf000000 | ((val + 2) << 2)) << 8 |
            *(volatile unsigned int *)(0xcf000000 | ((val + 1) << 2))) << 8 |
           *(volatile unsigned int *)(0xcf000000 | (val << 2));
}

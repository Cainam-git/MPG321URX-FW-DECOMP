/* leon2s FUN_a00a6668 @ 0xa00a6668 (-mcpu=v8 -Os -g)
 * k = p1 & 0xff when it is below 2, otherwise 0; v = halfword k of table 0xA00B4D9C + p2 (16 bits). With R(x) the
 * register 0xCF000000 | (x << 2), returns (R(v + 2) << 16) | (R(v + 1) << 8) | R(v).
 * Source form: Ghidra's type and symbol names are kept.
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

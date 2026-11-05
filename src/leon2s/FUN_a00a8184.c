/* leon2s FUN_a00a8184 @ 0xa00a8184 (-mcpu=v8 -Os -g)
 * For p1 (low byte) <= 1 and p2 (low byte) <= 5: t = halfword [p1 * 6 + p2] of table 0xA00B4D44; the register
 * at 0xCF000000 | ((t + p3) * 4) is read, the bits of mask p4 are replaced by those of p5 (p5 & p4), and the low
 * byte of the result is written back. Other p1 / p2 return without an access. No value is placed in the return
 * register; callers do not read it.
 * Source form: Ghidra's type and symbol names are kept; the range test uses two flag variables as in
 * FUN_a00a8054; the function has the C89 implicit int return type with plain 'return;' statements (the return
 * register counts as live, which gives the firmware's register allocation); the merged value is computed first
 * as 'v = param_5; v &= param_4;' into an unsigned char.
 */
typedef unsigned int uint;

extern unsigned char DAT_a00b4d44;

FUN_a00a8184(uint param_1, uint param_2, unsigned short param_3, unsigned char param_4, uint param_5)
{
    uint uVar1;
    uint cond1;
    uint cond2;
    unsigned char v;
    volatile uint *r;

    v = param_5;
    v &= param_4;
    cond1 = (param_1 & 0xff) > 1;
    uVar1 = (param_1 & 0xff) * 6 + (param_2 & 0xff);
    cond2 = (param_2 & 0xff) > 5;
    if (cond1 || cond2)
        return;
    r = (volatile uint *)((*(unsigned short *)(&DAT_a00b4d44 + uVar1 * 2) + (param_3 & 0xffff)) * 4 | 0xcf000000);
    *r = (unsigned char)(v | (*r & ~param_4));
    return;
}

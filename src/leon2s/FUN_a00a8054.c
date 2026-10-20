/* leon2s FUN_a00a8054 @ 0xa00a8054 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned int uint;

extern unsigned char DAT_a00b4d44;

void FUN_a00a8054(uint param_1, uint param_2, unsigned short param_3, uint param_4)
{
    uint uVar1;
    uint cond1;
    uint cond2;

    cond1 = (param_1 & 0xff) > 1;
    uVar1 = (param_1 & 0xff) * 6 + (param_2 & 0xff);
    cond2 = (param_2 & 0xff) > 5;
    if (cond1 || cond2) {
        return;
    }
    *(volatile uint *)((*(unsigned short *)(&DAT_a00b4d44 + uVar1 * 2) + (param_3 & 0xffff)) * 4 | 0xcf000000) = param_4 & 0xff;
    return;
}

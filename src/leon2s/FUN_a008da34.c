/* leon2s FUN_a008da34 @ 0xa008da34 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned int FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);
extern void FUN_a00a8054(unsigned int, unsigned int, unsigned short, unsigned int);

void FUN_a008da34(unsigned int param_1, unsigned char param_2)
{
    unsigned char uVar1;

    param_1 = param_1 & 0xff;
    uVar1 = FUN_a00a7fd8(param_1, 1, 0x7f);
    uVar1 = uVar1 & 0xfffffff3;

    switch (param_2) {
    case 1:
        uVar1 = uVar1 | 8;
        break;
    case 2:
        uVar1 = uVar1 | 0xc;
        break;
    default:
        uVar1 = uVar1 | 4;
        break;
    }

    FUN_a00a8054(param_1, 1, 0x7f, uVar1 & 0xff);
}

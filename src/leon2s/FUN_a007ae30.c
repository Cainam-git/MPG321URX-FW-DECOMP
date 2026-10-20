/* leon2s FUN_a007ae30 @ 0xa007ae30 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
void FUN_a007ae30(unsigned int param_1, unsigned char param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;
    unsigned int uVar3;

    uVar2 = (param_2 == 1);
    uVar3 = param_1 & 0xff;
    FUN_a00a7424(uVar2, 7, uVar3, 0x1c04);
    uVar1 = FUN_a0073520(uVar3);
    if ((uVar1 & 0xff) != 0) {
        FUN_a00a7424(uVar2, 7, uVar3, 0x2c04);
    }
    return uVar2;
}

/* leon2s FUN_a008c8b0 @ 0xa008c8b0 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. For each of four units (4, 6, 0xc, 0xe): if
 * FUN_a0089f98(unit) reports something (non-zero 16-bit value), it runs FUN_a008b9ec(n) and
 * then FUN_a008a1b4(unit, FUN_a008a040(unit) & 0xff, 1). The
 * unit argument of the check is missing from Ghidra's output.
 */
extern int FUN_a0089f98();
extern int FUN_a008b9ec();
extern int FUN_a008a040();
extern int FUN_a008a1b4();
extern int FUN_a00a29b0();
extern int FUN_a008a110();
extern int FUN_a008c6f8();

void FUN_a008c8b0(void)
{
    unsigned short uVar1;
    unsigned int uVar2;

    uVar1 = FUN_a0089f98(4);
    if ((uVar1 & 0xffff) != 0) {
        FUN_a008b9ec(0);
        uVar1 = FUN_a008a040(4);
        FUN_a008a1b4(4, uVar1 & 0xff, 1);
    }

    uVar1 = FUN_a0089f98(6);
    if ((uVar1 & 0xffff) != 0) {
        FUN_a008b9ec(1);
        uVar1 = FUN_a008a040(6);
        FUN_a008a1b4(6, uVar1 & 0xff, 1);
    }

    uVar1 = FUN_a0089f98(0xc);
    uVar2 = 0xc;
    if ((uVar1 & 0xffff) != 0) {
        uVar1 = FUN_a008a040(0xc);
        uVar2 = FUN_a00a29b0(0);
        FUN_a008a110(0xc, uVar1 & 0xff, uVar2 & 0xff);
    }

    uVar1 = FUN_a0089f98(0xe);
    uVar2 = 0xe;
    if ((uVar1 & 0xffff) != 0) {
        uVar1 = FUN_a008a040(0xe);
        uVar2 = FUN_a00a29b0(1);
        FUN_a008a110(0xe, uVar1 & 0xff, uVar2 & 0xff);
    }

    FUN_a008c6f8();
}

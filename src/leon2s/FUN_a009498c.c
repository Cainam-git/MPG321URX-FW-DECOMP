/* leon2s FUN_a009498c @ 0xa009498c (-mcpu=v8 -Os -g)
 * Table 0xA807D580 holds records of 7 words; k = p1 & 0xff. When bit 2 of word 0 of record k is set, calls
 * FUN_a00a80cc(k, 3, 0xf1, 1, 1) and, when bit 4 of that word (read again) is clear, FUN_a00a80cc(k, 3, 0xf2, 1,
 * 1). Otherwise calls FUN_a00a80cc(k, 3, 0xf1, 1, 0) and FUN_a00a80cc(k, 3, 0xf2, 1, 0).
 * Source form: Ghidra's type and symbol names are kept.
 */
extern void FUN_a00a80cc();
extern unsigned int ARR_a807d580[];

void FUN_a009498c(unsigned int param_1)
{
    unsigned int uVar1;
    unsigned int uVar2;

    uVar1 = param_1 & 0xff;
    uVar2 = 0;
    if ((ARR_a807d580[uVar1 * 7] & 4) != 0) {
        uVar2 = 1;
        FUN_a00a80cc(uVar1, 3, 0xf1, 1, 1);
        if ((ARR_a807d580[uVar1 * 7] & 0x10) == 0) {
            FUN_a00a80cc(uVar1, 3, 0xf2, 1, uVar2);
        }
    } else {
        FUN_a00a80cc(uVar1, 3, 0xf1, 1, 0);
        FUN_a00a80cc(uVar1, 3, 0xf2, 1, uVar2);
    }
}

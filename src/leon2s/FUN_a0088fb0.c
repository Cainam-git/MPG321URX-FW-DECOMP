/* leon2s FUN_a0088fb0 @ 0xa0088fb0  MATCH (-mcpu=v8 -Os -g)
 * Returns the halfword ARR_a8078a00[param_1 & 0xFF] and clears it. The source forms the byte offset (param_1 &
 * 0xff) * 2 and indexes with offset / 2; the target uses that doubled offset in lduh / clrh.
 */
extern unsigned short ARR_a8078a00[];

unsigned short FUN_a0088fb0(unsigned int param_1)
{
    unsigned short uVar1;
    int iVar2;
    
    iVar2 = (param_1 & 0xff) * 2;
    uVar1 = ARR_a8078a00[iVar2 / 2];
    ARR_a8078a00[iVar2 / 2] = 0;
    return uVar1;
}

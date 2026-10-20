/* leon2s FUN_a00919e0 @ 0xa00919e0  MATCH (-mcpu=v8 -Os -g)
 * Sets bit 13 (0x2000) of word 5 (+0x14) of the 28-byte entry (param_1 & 0xFF) of the table at 0xA807D580, in the
 * same array form as FUN_a0091988.
 */
extern unsigned int ARR_a807d580[];

void FUN_a00919e0(unsigned int param_1)
{
    unsigned int iVar1;
    
    iVar1 = (param_1 & 0xff) * 0x1c;
    ARR_a807d580[iVar1 / 4 + 5] |= 0x2000;
    return;
}

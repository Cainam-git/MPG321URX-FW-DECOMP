/* leon2s FUN_a00919b0 @ 0xa00919b0 (-mcpu=v8 -Os -g)
 * Clears bit 13 (0x2000) of the word at offset 0x14 of the 28-byte per-port record p (p = the parameter byte) in
 * the table at 0xA807D580. The byte offset p * 0x1c is computed first (sll/sub/sll: x8, -1, x4) and the word array
 * is indexed with offset / 4 + 5.
 */
extern unsigned int ARR_a807d580[];

void FUN_a00919b0(unsigned int param_1)
{
    unsigned int iVar1;
    
    iVar1 = (param_1 & 0xff) * 0x1c;
    ARR_a807d580[iVar1 / 4 + 5] &= 0xffffdfff;
    return;
}

/* leon2s FUN_a00918ec @ 0xa00918ec (-mcpu=v8 -Os -g)
 * Sets bit 2 of the word at offset +0x10 of entry (param_1 & 0xFF) of the table at 0xA807D580 (28-byte entries).
 * The index expression iVar1 / 4 + 4 on the word array gives sll %o5, 2 and folds the +16 bytes into the
 * displacement (ld / st [%o5 + 0x10]), as in FUN_a0091988.
 */
extern unsigned int ARR_a807d580[];

void FUN_a00918ec(unsigned int param_1)
{
    unsigned int iVar1;
    
    iVar1 = (param_1 & 0xff) * 0x1c;
    ARR_a807d580[iVar1 / 4 + 4] |= 4;
    return;
}

/* leon2s FUN_a0091988 @ 0xa0091988  MATCH (-mcpu=v8 -Os -g)
 * Clears bit 4 of the first word of the 28-byte entry (param_1 & 0xFF) of the table at 0xA807D580. The offset is
 * computed as index * 7 * 4 (sll / sub); the source writes it as (index * 0x1c) / 4 as a word index.
 */
extern unsigned int ARR_a807d580[];

void FUN_a0091988(unsigned int param_1)
{
    unsigned int iVar1;
    
    iVar1 = (param_1 & 0xff) * 0x1c;
    ARR_a807d580[iVar1 / 4] &= 0xffffffef;
    return;
}

/* leon2s FUN_a0091a88 @ 0xa0091a88 (-mcpu=v8 -Os -g)
 * Table 0xA807D580 holds records of 7 words. For p1 (low byte) 0 or 1, clears bit 14 (0x4000) of word 5 of record
 * p1; other values return without a write.
 * Source form: Ghidra's type and symbol names are kept.
 */
extern unsigned int ARR_a807d580[];

void FUN_a0091a88(unsigned int param_1)
{
    unsigned int idx = param_1 & 0xff;
    unsigned int *p = &ARR_a807d580[idx * 7];
    
    if (idx <= 1) {
        p[5] &= 0xffffbfff;
    }
}

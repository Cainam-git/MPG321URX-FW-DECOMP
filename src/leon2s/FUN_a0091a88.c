/* leon2s FUN_a0091a88 @ 0xa0091a88  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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

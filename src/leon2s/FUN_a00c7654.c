/* leon2s FUN_a00c7654 @ 0xa00c7654-0xa00c76c0 (27 words), flags -mcpu=v8 -Os -g.
 * Write twin of FUN_a00c7770.
 * Code facts: idx > 2 (u8): tail ROM print func_0xa0f83044(s_9f1c1f18, s_9f1c1ed8, idx, reg, val) (the
 * 'sll idx,2,%i5' in the bleu delay slot is the table offset of the other path, not an argument). Else the
 * hardware word ((DAT_9f1c1ec8[idx] + reg) << 2) | 0xcf000000 = val (u8). void.
 * Required forms: the table and strings are SYMBOLS (the FUN_a00c7770 form), void, u8 val.
 * volatile only on the 0xcf... hardware register. Aids: none.
 */
extern unsigned int DAT_9f1c1ec8[];
extern char s_9f1c1f18[], s_9f1c1ed8[];
extern int func_0xa0f83044(const char *, ...);

void FUN_a00c7654(unsigned char idx, unsigned short reg, unsigned char val)
{
    if (idx > 2) {
        func_0xa0f83044(s_9f1c1f18, s_9f1c1ed8, idx, reg, val);
        return;
    }
    *(volatile unsigned int *)(((DAT_9f1c1ec8[idx] + reg) << 2) | 0xcf000000) = val;
}

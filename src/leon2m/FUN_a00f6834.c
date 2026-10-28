/* leon2m FUN_a00f6834 @ 0xa00f6834-0xa00f6898 (25 words), flags -mcpu=v8 -O3 -g.
 * Code facts: v = FUN_a00f2254(blk, 0x20) & ~0x5f. p == 0: FUN_a00f2298(blk, 0x20, v). Otherwise the low nibble
 * of p is or-ed into v and bit 0x50 is set (bit 7 of p set) or cleared (bit 7 clear) before
 * FUN_a00f2298(blk, 0x20, ...); the last call is a tail call.
 * Source form: the 'v | (p & 0xf)' term is written inside each of the two calls (one shared statement before the
 * test is computed ahead of the p == 0 branch). Aids: none.
 */
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);

void FUN_a00f6834(unsigned char blk, unsigned char p)
{
    unsigned char v = FUN_a00f2254(blk, 0x20) & ~0x5f;

    if (p == 0) {
        FUN_a00f2298(blk, 0x20, v);
        return;
    }
    if (p & 0x80)
        FUN_a00f2298(blk, 0x20, v | (p & 0xf) | 0x50);
    else
        FUN_a00f2298(blk, 0x20, (v | (p & 0xf)) & ~0x50);
}

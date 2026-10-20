/* leon2m FUN_a0120bf4 @ 0xa0120bf4-0xa0120c58 (25 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/25 mismatches.
 * Code facts: v = FUN_a00f1f9c(blk, 0x11) & 3 (u8 register read, 2-bit field); returns 1 / 4 / 2 / 8
 * for v = 0 / 1 / 2 / 3 (default 8), as a u8 (fw 'and 0xf' = nonzero-bits form of the extension).
 * Required form: a switch with an explicit 'case 3: r = 8' equal to the default
 * (case-tree root lever: it makes 1 the tree root like the fw; the block crossjumps into the
 * default, no extra code). Aids: none.
 */
extern unsigned char FUN_a00f1f9c(unsigned char, unsigned char);

unsigned char FUN_a0120bf4(unsigned char blk)
{
    unsigned char r;

    switch (FUN_a00f1f9c(blk, 0x11) & 3) {
    case 0: r = 1; break;
    case 1: r = 4; break;
    case 2: r = 2; break;
    case 3: r = 8; break;
    default: r = 8; break;
    }
    return r;
}

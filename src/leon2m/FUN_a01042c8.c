/* leon2m FUN_a01042c8 @ 0xa01042c8-0xa0104380 (46 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 46 words.
 * Code facts: stable read of register 0x89 of block blk: a = FUN_a00f29d4(blk, 0x89); FUN_a0121bcc(1, rate) (wait);
 * b = FUN_a00f29d4(blk, 0x89); up to 3 more rounds while -15 <= (int)(a - b) <= 15 (n = 0..2, u8); returns
 * (a + b) >> 1 (unsigned). Callee prototypes as in src/leon2m (blk/reg u8, frames u8, rate u16).
 * Fix vs the autoc draft (78.26): BEHAVIOUR - the draft's loop test compared (u8)(a - b) with -15 and exited on
 * the opposite ranges; the retry runs while the difference is INSIDE +-15 (fw 'cmp d, -15; bge' then
 * 'cmp d, 15; bg,a' with the n < 3 term as subx/btst). Plain for loop. Aids: none.
 */
extern unsigned int FUN_a00f29d4(unsigned char blk, unsigned char reg);
extern void FUN_a0121bcc(unsigned char frames, unsigned short rate);

unsigned int FUN_a01042c8(unsigned char blk, unsigned short rate)
{
    unsigned int a, b;
    unsigned char n;

    a = FUN_a00f29d4(blk, 0x89);
    FUN_a0121bcc(1, rate);
    b = FUN_a00f29d4(blk, 0x89);
    for (n = 0; (int)(a - b) >= -15 && (int)(a - b) <= 15 && n < 3; n++) {
        a = FUN_a00f29d4(blk, 0x89);
        FUN_a0121bcc(1, rate);
        b = FUN_a00f29d4(blk, 0x89);
    }
    return (a + b) >> 1;
}

/* leon2m FUN_a012127c @ 0xa012127c-0xa0121374 (62 words).
 * Block blk: lo = low nibble of register 4 (FUN_a00f1a90(blk, 4)). Returns without a write when FUN_a00fd820(blk)
 * is 0x71, 0x81 or 0xb1 (three separate calls). Otherwise writes register 4 = lo | hi with FUN_a00f1ad4, where
 * hi = 0x80 when on == 0; 0xe0 when FUN_a00fd820(blk) == 0x91; else by h: > 0x3b3 -> 0xf0, > 0x1de -> 0xe0,
 * > 0xf4 -> 0xc0, else 0x80, shifted left by one bit (as a byte) when FUN_a00f1f9c(blk, 0x1a) > 0x1f.
 * Called by FUN_a0104a34 and FUN_a01213a4.
 */
extern unsigned char FUN_a00fd820(unsigned char);
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned char FUN_a00f1f9c(unsigned char blk, unsigned char reg);

void FUN_a012127c(unsigned char blk, unsigned short h, unsigned char on)
{
    unsigned char lo, hi;

    lo = FUN_a00f1a90(blk, 4) & 0xf;
    if (FUN_a00fd820(blk) == 0x71)
        return;
    if (FUN_a00fd820(blk) == 0x81)
        return;
    if (FUN_a00fd820(blk) == 0xb1)
        return;
    hi = 0x80;
    if (on) {
        if (FUN_a00fd820(blk) == 0x91)
            hi = 0xe0;
        else {
            if (h > 0x3b3)
                hi = 0xf0;
            else if (h > 0x1de)
                hi = 0xe0;
            else if (h > 0xf4)
                hi = 0xc0;
            if (FUN_a00f1f9c(blk, 0x1a) > 0x1f)
                hi <<= 1;
        }
    }
    FUN_a00f1ad4(blk, 4, lo | hi);
}

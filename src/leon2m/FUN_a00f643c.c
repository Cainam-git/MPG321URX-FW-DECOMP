/* leon2m FUN_a00f643c @ 0xa00f643c (-mcpu=v8 -O3 -g)
 * Loads a 24-entry table through an index/data register pair: clears bit 1 of 0xCF00EF30 and writes 1 to
 * 0xCF00EF34; then for i = 0..23 writes i to 0xCF00EF38 and a byte to 0xCF00EF3C: p->v[i] for each bit i set in
 * the word p->mask (entries with a clear bit are skipped), or 0 for every i when p is null. Finally sets bit 1 of
 * 0xCF00EF30. p points to { u32 mask; u8 v[24]; }. Callers: FUN_a0147560, FUN_a0150a98.
 * Source form: one loop with the p test inside it (GCC unswitches it into the two firmware loops).
 */
#define R(a) (*(volatile unsigned int *)(a))

struct tab {
    unsigned int mask;
    unsigned char v[24];
};

void FUN_a00f643c(struct tab *p)
{
    unsigned char i;

    R(0xcf00ef30) &= ~2;
    R(0xcf00ef34) = 1;
    for (i = 0; i <= 0x17; i++) {
        if (p) {
            if ((p->mask >> i) & 1) {
                R(0xcf00ef38) = i;
                R(0xcf00ef3c) = p->v[i];
            }
        } else {
            R(0xcf00ef38) = i;
            R(0xcf00ef3c) = 0;
        }
    }
    R(0xcf00ef30) |= 2;
}

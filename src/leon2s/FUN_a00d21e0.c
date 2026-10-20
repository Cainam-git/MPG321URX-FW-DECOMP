/* leon2s FUN_a00d21e0 @ 0xa00d21e0-0xa00d2210 (12 words), flags -mcpu=v8 -Os -g.
 * Leaf bit-field write: a = 1 << hi; m = (a - (1 << lo)) | a (bits lo..hi); *reg = (*reg & ~m) |
 * ((val << lo) & m). hi is u8, lo/val int.
 * Source form: one 'a' temp for 1 << hi inside the mask expression, and the read-modify-write as a local t
 * (t = *reg; t &= ~m; t |= ...; *reg = t), which gives the firmware order (ld before the val shift, andn/or
 * into the loaded register).
 */
void FUN_a00d21e0(unsigned int *reg, unsigned char hi, int lo, int val)
{
    unsigned int a = 1 << hi;
    unsigned int m = (a - (1 << lo)) | a;
    unsigned int t = *reg;
    t &= ~m;
    t |= (val << lo) & m;
    *reg = t;
}

/* leon2m FUN_a0109844 @ 0xa0109844-0xa01099fc (110 words).
 * f = low byte of register 0xcf011d8c. For the pair (0xcf011de0 -> 0xcf011f64, bits 0 and 1 of f) and the pair
 * (0xcf011e00 -> 0xcf011f6c, bits 2 and 3): when the first bit is clear, 0 is written to the output register
 * (FUN_a00f308c). Otherwise v = the input register (FUN_a00f3078) as 16 bits; without the second bit x = v / 2,
 * with it x = v * 10 / 3, replaced by x / 10 + 1 when x % 10 is non-zero, then rounded up to a multiple of 32
 * (all 16-bit); x is written to the output register.
 */
#define REG(a) ((volatile unsigned int *)(a))
extern unsigned int FUN_a00f3078(volatile unsigned int *p);
extern void FUN_a00f308c(volatile unsigned int *r, unsigned int v);

void FUN_a0109844(void)
{
    unsigned char f = *REG(0xcf011d8c);
    unsigned short v, x;

    if (f & 1) {
        v = FUN_a00f3078(REG(0xcf011de0));
        if (f & 2) {
            x = v * 10 / 3;
            if (x % 10)
                x = x / 10 + 1;
            if (x & 0x1f)
                x = (x >> 5 << 5) + 0x20;
        } else
            x = v >> 1;
        FUN_a00f308c(REG(0xcf011f64), x);
    } else {
        FUN_a00f308c(REG(0xcf011f64), 0);
    }
    if (f & 4) {
        v = FUN_a00f3078(REG(0xcf011e00));
        if (f & 8) {
            x = v * 10 / 3;
            if (x % 10)
                x = x / 10 + 1;
            if (x & 0x1f)
                x = (x >> 5 << 5) + 0x20;
        } else
            x = v >> 1;
        FUN_a00f308c(REG(0xcf011f6c), x);
    } else {
        FUN_a00f308c(REG(0xcf011f6c), 0);
    }
}

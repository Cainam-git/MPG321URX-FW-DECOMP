/* leon2m FUN_a00f76dc @ 0xa00f76dc-0xa00f7894 (110 words).
 * When bit 0 of register 0xcf00eec4 is set and start is 0: returns 0. When the bit is clear and start is 0:
 * copies bits 0..1 of register 0xcf00ec84 to bits 1..2 of register 0xcf00ee80 (bits 3..7 kept), clears bit 5 of
 * 0xcf00eec0 and bits 4 and 6 of 0xcf00eec4 (low byte kept), clears 32 local sums, n = 4 << bits 2..3 of
 * 0xcf00eec0; for k = 0..7 writes 1 << k to 0xcf00ee84 and for i = 0..31 reads three bytes from 0xcf00eec8
 * (as bits 0..7, 8..15, 16..23) and adds the value to sum i when i < n; then copies sums 0..n-1 to out.
 * Every path except the first sets bit 0 of 0xcf00eec4 and returns 1.
 * Source form: the two bits of 0xcf00ec84 are read first into an unsigned char local.
 */
#define R(a) (*(volatile unsigned int *)(a))

unsigned char FUN_a00f76dc(unsigned char start, unsigned int *out)
{
    unsigned int sum[32];
    unsigned char i, k, n;

    if (R(0xcf00eec4) & 1) {
        if (start == 0)
            return 0;
    } else if (start == 0) {
        {
            unsigned char m = R(0xcf00ec84) & 3;

            R(0xcf00ee80) = (R(0xcf00ee80) & 0xf9) | m << 1;
        }
        R(0xcf00eec0) &= ~0x20;
        R(0xcf00eec4) &= 0xaf;
        for (i = 0; i < 32; i++)
            sum[i] = 0;
        n = 4 << ((R(0xcf00eec0) >> 2) & 3);
        for (k = 0; k < 8; k++) {
            R(0xcf00ee84) = 1 << k;
            for (i = 0; i < 32; i++) {
                unsigned int b0 = R(0xcf00eec8) & 0xff;
                unsigned int b1 = R(0xcf00eec8) & 0xff;
                unsigned int b2 = R(0xcf00eec8) & 0xff;

                if (i < n)
                    sum[i] += b2 << 16 | b1 << 8 | b0;
            }
        }
        for (i = 0; i < n; i++)
            out[i] = sum[i];
    }
    R(0xcf00eec4) |= 1;
    return 1;
}

/* FUN_a00c83e4 (leon2s 0xa00c83e4-0xa00c8444, 96 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Counts the set bits of the 5 bytes p[0..4], clearing each byte in place one lowest set bit at a time
 * (p[i] &= p[i] - 1 until it is 0), and returns 1 when the total (unsigned char) is 20, else 0.
 * Called by FUN_a00c850c, which declares it returning char.
 * Source form: the loop works on p[i] directly (GCC keeps the byte in a register and stores it once after the
 * inner loop); total and i are both initialised to 0 at their declarations (i's start value is then copied
 * from total's register).
 */
char FUN_a00c83e4(unsigned char *p)
{
    unsigned char total = 0;
    unsigned char i = 0;
    unsigned char n;

    for (i = 0; i < 5; i++) {
        n = 0;
        while (p[i]) {
            p[i] &= p[i] - 1;
            n++;
        }
        total += n;
    }
    return total == 20;
}

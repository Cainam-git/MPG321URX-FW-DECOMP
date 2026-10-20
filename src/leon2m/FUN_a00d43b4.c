/* leon2m FUN_a00d43b4 @ 0xa00d43b4 (-mcpu=v8 -O2 -g)
 * This function reads a base value from `FUN_a0144414`, then performs four register reads via `FUN_a0145660` with the same base and different command codes (0xb, 0xe, 0xd, 0xe). It computes `(r1 - r2) * 100 / (r3 - r4)` and returns `100 - that quotient`, masked to a byte. The structure matches the similar finished function exactly (same call order, same arithmetic), differing only in the constants and the final subtraction. The only uncertainty is whether the final `& 0xff` is applied to the result of the subtraction or to the quotient before subtraction; the target shows `and %i0, 0xff` after t
 */
extern int FUN_a0144414(void);
extern int FUN_a0145660(int, int);

int FUN_a00d43b4(void)
{
    int base = FUN_a0144414() & 0xff;
    int r1 = (unsigned short)FUN_a0145660(base, 0xb);
    int r2 = (unsigned short)FUN_a0145660(base, 0xe);
    int num = (r1 - r2) * 100;
    int r3 = (unsigned short)FUN_a0145660(base, 0xd);
    int r4 = (unsigned short)FUN_a0145660(base, 0xe);
    return (100 - (num / (r3 - r4))) & 0xff;
}

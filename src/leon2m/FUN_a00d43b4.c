/* leon2m FUN_a00d43b4 @ 0xa00d43b4 (-mcpu=v8 -O2 -g)
 * b = FUN_a0144414() & 0xff; with the u16 fields f(id) = FUN_a0145660(b, id) returns
 * (100 - (f(0xb) - f(0xe)) * 100 / (f(0xd) - f(0xe))) & 0xff (fields read in the order 0xb, 0xe, 0xd, 0xe).
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

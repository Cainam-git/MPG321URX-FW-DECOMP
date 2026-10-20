/* leon2m FUN_a00d4250 @ 0xa00d4250 (-mcpu=v8 -O2 -g)
 * Returns ((v4 - v6) * 100 / (v5 - v6)) & 0xff, where vN is the low 16 bits of FUN_a0145660(base, N) and base is
 * the low byte of FUN_a0144414(). FUN_a0145660 is called in the order 4, 6, 5, 6 (index 6 is fetched twice). The
 * (unsigned short) casts produce the sll 0x10 / srl 0x10 zero-extension pairs of the target.
 */
extern int FUN_a0144414(void);
extern int FUN_a0145660(int, int);

int FUN_a00d4250(void)
{
    int base = FUN_a0144414() & 0xff;
    int r1 = (unsigned short)FUN_a0145660(base, 4);
    int r2 = (unsigned short)FUN_a0145660(base, 6);
    int num = (r1 - r2) * 100;
    int r3 = (unsigned short)FUN_a0145660(base, 5);
    int r4 = (unsigned short)FUN_a0145660(base, 6);
    return (num / (r3 - r4)) & 0xff;
}

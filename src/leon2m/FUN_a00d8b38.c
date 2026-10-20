/* leon2m FUN_a00d8b38 @ 0xa00d8b38-0xa00d8bd8 (40 words).
 * Reads t = FUN_a0145660(0, 2) as a halfword and rounds it to v = (t + 5) / 10. Returns 120 when t is 1203..1207,
 * 144 when v is 143..145, 180 when v is 179..181, 240 when v is 239..241, otherwise v.
 * Callers include FUN_a00a5e68, FUN_a00a6b98, FUN_a00b37a4, FUN_a00b3860, FUN_a00b88e0, FUN_a00b9750, FUN_a00bf538.
 * v is computed after the first test (computing it before the test changes the register allocation).
 */
extern unsigned short FUN_a0145660(unsigned char, unsigned int);

unsigned short FUN_a00d8b38(void)
{
    unsigned short t = FUN_a0145660(0, 2);
    unsigned short v;

    if (t >= 1203 && t <= 1207)
        return 120;
    v = (t + 5) / 10;
    if (v >= 143 && v <= 145)
        return 144;
    if (v >= 179 && v <= 181)
        return 180;
    if (v >= 239 && v <= 241)
        return 240;
    return v;
}

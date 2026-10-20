/* leon2m FUN_a0122e24 @ 0xa0122e24-0xa0122e80 (23 words).
 * Reads hardware registers 0xcf03d024 and 0xcf011824 and keeps their low bytes, writes a to 0xcf03d024, 0x76 to
 * 0xcf011820 and b to 0xcf011824, reads 0xcf011828, then writes the two kept bytes back (0xcf011824 first) and
 * returns the low byte of the 0xcf011828 value. No direct callers (address taken). The kept values and the result
 * are unsigned char locals, which gives the and 0xff before each store and the register window (save) of the firmware.
 */
#define R(a) (*(volatile unsigned int *)(a))

unsigned char FUN_a0122e24(unsigned char a, unsigned char b)
{
    unsigned char x = R(0xcf03d024);
    unsigned char y = R(0xcf011824);
    unsigned char v;

    R(0xcf03d024) = a;
    R(0xcf011820) = 0x76;
    R(0xcf011824) = b;
    v = R(0xcf011828);
    R(0xcf011824) = y;
    R(0xcf03d024) = x;
    return v;
}

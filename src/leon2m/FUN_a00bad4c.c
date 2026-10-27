/* FUN_a00bad4c (leon2m 0xa00bad4c-0xa00badc0, 116 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the three decimal digits of c as ASCII to DAT_a802d078[7] (hundreds), [8] (tens) and [9] (units). Nothing
 * in the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00bacc4 and
 * FUN_a00badc0.
 */
extern unsigned char DAT_a802d078[];

void FUN_a00bad4c(unsigned char c)
{
    unsigned char h, t;

    h = c / 100;
    c -= h * 100;
    t = c / 10;
    c -= t * 10;
    DAT_a802d078[7] = h + 0x30;
    DAT_a802d078[8] = t + 0x30;
    DAT_a802d078[9] = c + 0x30;
}

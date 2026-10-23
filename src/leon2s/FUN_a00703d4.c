/* FUN_a00703d4 (leon2s 0xa00703d4-0xa0070404, 48 bytes, leaf), flags -mcpu=v8 -Os -g.
 * m = 1 << n; returns ((DAT_a80788d8 >> 8) & m) as a byte when DAT_a80788d8 & m is set, else 0.
 * Called by FUN_a00c601c.
 */
extern unsigned int DAT_a80788d8;

unsigned char FUN_a00703d4(unsigned int n)
{
    unsigned int w = DAT_a80788d8;
    unsigned int m = 1 << n;

    if (w & m)
        return (w >> 8) & m;
    return 0;
}

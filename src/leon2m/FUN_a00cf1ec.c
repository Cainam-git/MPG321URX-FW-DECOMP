/* FUN_a00cf1ec (leon2m 0xa00cf1ec-0xa00cf23c, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns byte +0 of the first of the three 4-byte entries of DAT_a8025c58 whose byte +1 equals c, or 0 when none
 * does. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00cf194 and FUN_a00cf23c.
 */
struct H4 { unsigned char b0, b1; unsigned short h2; };
extern struct H4 DAT_a8025c58[];

unsigned char FUN_a00cf1ec(unsigned char c)
{
    unsigned char i;

    for (i = 0; i < 3; i++)
        if (DAT_a8025c58[i].b1 == c)
            return DAT_a8025c58[i].b0;
    return 0;
}

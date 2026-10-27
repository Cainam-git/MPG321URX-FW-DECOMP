/* FUN_a0144768 (leon2m 0xa0144768-0xa01447bc, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns byte +2 of the first of the five 3-byte entries of DAT_001a6da3 whose byte +1 equals c, or 0 when none
 * does. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a01446e0 and FUN_a01447bc.
 */
struct T3 { unsigned char b0, b1, b2; };
extern const struct T3 DAT_001a6da3[];

unsigned char FUN_a0144768(unsigned char c)
{
    unsigned char i;

    for (i = 0; i < 5; i++)
        if (DAT_001a6da3[i].b1 == c)
            return DAT_001a6da3[i].b2;
    return 0;
}

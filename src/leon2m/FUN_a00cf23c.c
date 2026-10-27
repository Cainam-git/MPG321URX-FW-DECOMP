/* FUN_a00cf23c (leon2m 0xa00cf23c-0xa00cf280, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the OR of the halfwords at +2 of the first three 4-byte entries of DAT_a8025c58. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00cf1ec and FUN_a00cf280.
 * Source form: an unsigned char loop counter.
 */
struct H4 { unsigned short h0, h2; };
extern struct H4 DAT_a8025c58[];

unsigned short FUN_a00cf23c(void)
{
    unsigned short r = 0;
    unsigned char i;

    for (i = 0; i < 3; i++)
        r |= DAT_a8025c58[i].h2;
    return r;
}

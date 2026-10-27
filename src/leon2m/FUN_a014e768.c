/* FUN_a014e768 (leon2m 0xa014e768-0xa014e7bc, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Takes x = bit 5 of the halfword at +0 of 0x2a-byte entry c of DAT_a802e224; when x is 1 stores 2 to the byte
 * DAT_a802cc18[c], otherwise decrements that byte unless it is 0; returns x. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a014e758 and FUN_a014e7bc.
 */
struct E2a { unsigned short h0; unsigned char p2[0x28]; };
extern struct E2a DAT_a802e224[];
extern unsigned char DAT_a802cc18[];

unsigned int FUN_a014e768(unsigned char c)
{
    unsigned int x = (DAT_a802e224[c].h0 >> 5) & 1;

    if (x == 1)
        DAT_a802cc18[c] = 2;
    else if (DAT_a802cc18[c] != 0)
        DAT_a802cc18[c]--;
    return x;
}

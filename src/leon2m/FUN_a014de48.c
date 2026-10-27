/* FUN_a014de48 (leon2m 0xa014de48-0xa014deec, 164 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Maps c = 0..3 to k = c (other values to 0xff); when k is at most 4, takes p = bits 12..15 of the first word of
 * 0x78-byte entry k of DAT_a802df30 and stores b & 1 to bit 4 of the halfword at +0 of 0x2a-byte entry p of
 * DAT_a802e224. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies
 * between FUN_a014dd98 and FUN_a014deec. Source form: a switch mapping c to k; a one-bit bit-field for bit 4.
 */
struct Chan { unsigned int w; unsigned char p04[0x74]; };
struct E2aF { unsigned short hi:11, b4:1, lo:4; };
struct E2a { struct E2aF f; unsigned char p2[0x28]; };
extern struct Chan DAT_a802df30[4];
extern struct E2a DAT_a802e224[];

void FUN_a014de48(unsigned char c, unsigned int b)
{
    unsigned char k;

    switch (c) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 1;
        break;
    case 2:
        k = 2;
        break;
    case 3:
        k = 3;
        break;
    default:
        k = 0xff;
        break;
    }
    if (k <= 4)
        DAT_a802e224[(DAT_a802df30[k].w >> 12) & 0xf].f.b4 = b;
}

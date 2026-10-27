/* FUN_a014dd98 (leon2m 0xa014dd98-0xa014de48, 176 bytes), flags -mcpu=v8 -O3 -g.
 * The FUN_a014de48 operation followed by a call: maps c = 0..3 to k = c (other values to 0xff); when k is at most
 * 4, stores b & 1 to bit 4 of the halfword at +0 of the DAT_a802e224 entry of the port of DAT_a802df30[k] and calls
 * FUN_a01312d4(k, b) as a tail call. Called by FUN_a00830f4, FUN_a008454c, FUN_a00d5eac, FUN_a00d5f3c,
 * FUN_a00db738, FUN_a00dbcf0, FUN_a00dc3dc. Source form: the form of FUN_a014de48 (switch mapping c to k, one-bit
 * bit-field).
 */
struct Chan { unsigned int w; unsigned char p04[0x74]; };
struct E2aF { unsigned short hi:11, b4:1, lo:4; };
struct E2a { struct E2aF f; unsigned char p2[0x28]; };
extern struct Chan DAT_a802df30[4];
extern struct E2a DAT_a802e224[];
extern void FUN_a01312d4(unsigned char, unsigned char);

void FUN_a014dd98(unsigned char c, unsigned int b)
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
    if (k <= 4) {
        DAT_a802e224[(DAT_a802df30[k].w >> 12) & 0xf].f.b4 = b;
        FUN_a01312d4(k, b);
    }
}

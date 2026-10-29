/* leon2m FUN_a014be10 @ 0xa014be10-0xa014bf64 (340 bytes), flags -mcpu=v8 -O3 -g.
 * port = bits 12..15 of the word 0xa802df30; v = byte 0xa802e3d8 (0xa802e3d0 + 8). Returns
 * (v * (halfword 0xa802e216 - 126) + 50) / 100 + 126 when bit 6 of the halfword at 0xa802e224 + port * 0x2a is
 * set and FUN_a014ba68() is not 0, or when FUN_a0140058(port) returns non-zero; otherwise
 * (v * 0x25f + 50) / 100 + 126 when the word 0xa802e3d0 + 0x38 is 1 or 2, else (v * 0x381 + 50) / 100 + 126.
 * The divisions are unsigned; the result is returned as an unsigned short.
 * Source form: FUN_a014ba68 (the matched routine at 0xa014ba68) is defined static in this file and inlined; the
 * bit-6 test is written '((h0 & 0x40) >> 6) == 1' (an equality test, so GCC predicts it false and the helper
 * block goes out of line); the word +0x38 tests are separate else-if arms with one body each.
 */
struct Chan { unsigned int w0; unsigned char p04[0x78 - 4]; };
struct Port { unsigned short h0; unsigned char rest[0x2a - 2]; };
struct E3D0 { unsigned char p00[8]; unsigned char b08; unsigned char p09[0x38 - 9]; unsigned int w38; };
extern struct Chan DAT_a802df30[4];
extern struct Port DAT_a802e224[];
extern struct E3D0 DAT_a802e3d0;
extern unsigned short DAT_a802e216;
extern unsigned char FUN_a0138e5c(void);
extern unsigned char FUN_a0140058(unsigned char);

static unsigned char FUN_a014ba68(void)
{
    unsigned char r;

    switch (FUN_a0138e5c()) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 1;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    default:
        r = 4;
        break;
    }
    return r;
}

unsigned short FUN_a014be10(void)
{
    unsigned short n;

    if ((((DAT_a802e224[(DAT_a802df30[0].w0 >> 12) & 0xf].h0 & 0x40) >> 6) == 1 && FUN_a014ba68() != 0)
        || FUN_a0140058((DAT_a802df30[0].w0 >> 12) & 0xf)) {
        n = (unsigned int)(DAT_a802e3d0.b08 * (DAT_a802e216 - 126) + 50) / 100 + 126;
    } else if (DAT_a802e3d0.w38 == 1) {
        n = (unsigned int)(DAT_a802e3d0.b08 * 0x25f + 50) / 100 + 126;
    } else if (DAT_a802e3d0.w38 == 2) {
        n = (unsigned int)(DAT_a802e3d0.b08 * 0x25f + 50) / 100 + 126;
    } else {
        n = (unsigned int)(DAT_a802e3d0.b08 * 0x381 + 50) / 100 + 126;
    }
    return n;
}

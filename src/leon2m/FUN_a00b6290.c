/* leon2m FUN_a00b6290 @ 0xa00b6290-0xa00b6514 (161 words), flags -mcpu=v8 -O3 -g.
 * Callers: FUN_a0093884, FUN_a0093910, FUN_a0093938, FUN_a0093960, FUN_a0093988, FUN_a00b65e4.
 * k = byte 0xa802d290 + 0x1a3, plus 2. When draw is non-zero: FUN_a0146b20(0, 0x2a + i, k * 2 + 6, 1, 0, 0) for
 * i = 0..7, then for j = 0, 1 with r = (j + k) * 2 + 5 and c = 0xa4 + (j != 0): FUN_a0146a80(0x2a, r, 2, 0xb69a, 0),
 * FUN_a0146b20(0, 0x2a, r, 2, c, 0), FUN_a0146a80(0x2d, r, 2, 0xb69a, 0), FUN_a0146b20(0, 0x2d, r, 2, c, 0).
 * Then with a = byte +0x198 and b = byte +0x19c of the record, indexed by byte +0x1a3: FUN_a0146b20(0, 0x2a / 0x2b,
 * k * 2 + 6, 1, a / 10 + 2 / a % 10 + 2, 0), FUN_a0146ab0(0x746, 0), FUN_a0146b20(1, 0x2c, (u8)(k * 2 + 6), 1, 0xc,
 * 0) (a one-pass loop), and the same two calls for b with 0x2d / 0x2e (the last one a tail call).
 * Source form: the value for the one-pass loop is an unsigned int local y = k * 2 + 6 passed as (unsigned char)y
 * (the firmware masks it with 0xff, not 0xfe).
 */
struct R290 {
    unsigned char pad[0x198];
    unsigned char t198[4];
    unsigned char t19c[4];
    unsigned char pad2[0x1a3 - 0x1a0];
    unsigned char b1a3;
};
extern struct R290 DAT_a802d290;
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146ab0(unsigned short, unsigned char);

void FUN_a00b6290(unsigned char draw)
{
    unsigned char k = DAT_a802d290.b1a3 + 2;
    unsigned char i, j;
    unsigned int y;

    if (draw) {
        for (i = 0; i <= 7; i++)
            FUN_a0146b20(0, i + 0x2a, k * 2 + 6, 1, 0, 0);
        for (j = 0; j <= 1; j++) {
            unsigned char c = j != 0;

            c += 0xa4;

            FUN_a0146a80(0x2a, (j + k) * 2 + 5, 2, 0xb69a, 0);
            FUN_a0146b20(0, 0x2a, (j + k) * 2 + 5, 2, c, 0);
            FUN_a0146a80(0x2d, (j + k) * 2 + 5, 2, 0xb69a, 0);
            FUN_a0146b20(0, 0x2d, (j + k) * 2 + 5, 2, c, 0);
        }
    }
    FUN_a0146b20(0, 0x2a, k * 2 + 6, 1, DAT_a802d290.t198[DAT_a802d290.b1a3] / 10 + 2, 0);
    FUN_a0146b20(0, 0x2b, k * 2 + 6, 1, DAT_a802d290.t198[DAT_a802d290.b1a3] % 10 + 2, 0);
    FUN_a0146ab0(0x746, 0);
    y = k * 2 + 6;
    for (i = 0; i < 1; i++)
        FUN_a0146b20(1, i + 0x2c, (unsigned char)y, 1, 0xc, 0);
    FUN_a0146b20(0, 0x2d, k * 2 + 6, 1, DAT_a802d290.t19c[DAT_a802d290.b1a3] / 10 + 2, 0);
    FUN_a0146b20(0, 0x2e, k * 2 + 6, 1, DAT_a802d290.t19c[DAT_a802d290.b1a3] % 10 + 2, 0);
}

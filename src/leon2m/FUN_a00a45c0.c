/* leon2m FUN_a00a45c0 @ 0xa00a45c0-0xa00a493c (892 bytes), flags -mcpu=v8 -O3 -g.
 * Callers: FUN_a00a493c, FUN_a00a49b8, FUN_a00b8e7c. For val, full = val / 9 and part = val % 9 (full - 1 when
 * part is 0 and full is not); rest = len - full - 2 when full < len - 2. Cells at column x + k, row y:
 * FUN_a0146a80(col, y, 1, colour, 0) + FUN_a0146b20(0, col, y, 1, code, 0): full cells with 0x869a / 0x7b;
 * then val 0: 0x869a / 0x7c and the next cell 0x839a / 0x7b; val 99: 0x869a / 0x8d and 0x869a / 0x8e; val 100:
 * 0x869a / 0x7c; other values: 0x869a / part * 2 + 0x7b and, when full <= 11, 0x869a / part * 2 + 0x7c; then rest
 * cells from x + full + 2 with 0x839a / 0x7b.
 * Source form: old-style (K&R) byte parameters; the two colours are signed short locals (sethi of the
 * shifted constant + srl 16 at each use), except the literal 0x839a in the val 0 arm.
 */
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00a45c0(x, y, val, len)
unsigned char x, y, val, len;
{
    unsigned char full, part, rest, i;
    short on = (short)0x869a, off = (short)0x839a;

    full = val / 9;
    part = val % 9;
    rest = 0;
    if (part == 0 && full != 0)
        full--;
    if (full < len - 2)
        rest = len - full - 2;
    if (full != 0)
        for (i = 0; i < full; i++) {
            FUN_a0146a80(x + i, y, 1, on, 0);
            FUN_a0146b20(0, x + i, y, 1, 0x7b, 0);
        }
    if (val == 0) {
        FUN_a0146a80(x + full, y, 1, on, 0);
        FUN_a0146b20(0, x + full, y, 1, 0x7c, 0);
        FUN_a0146a80(x + full + 1, y, 1, 0x839a, 0);
        FUN_a0146b20(0, x + full + 1, y, 1, 0x7b, 0);
    } else if (val == 99) {
        FUN_a0146a80(x + full, y, 1, on, 0);
        FUN_a0146b20(0, x + full, y, 1, 0x8d, 0);
        FUN_a0146a80(x + full + 1, y, 1, on, 0);
        FUN_a0146b20(0, x + full + 1, y, 1, 0x8e, 0);
    } else if (val == 100) {
        FUN_a0146a80(x + full, y, 1, on, 0);
        FUN_a0146b20(0, x + full, y, 1, 0x7c, 0);
    } else {
        FUN_a0146a80(x + full, y, 1, on, 0);
        FUN_a0146b20(0, x + full, y, 1, part * 2 + 0x7b, 0);
        if (full <= 11) {
            FUN_a0146a80(x + full + 1, y, 1, on, 0);
            FUN_a0146b20(0, x + full + 1, y, 1, part * 2 + 0x7c, 0);
        }
    }
    for (i = 0; i < rest; i++) {
        FUN_a0146a80(x + full + i + 2, y, 1, off, 0);
        FUN_a0146b20(0, x + full + i + 2, y, 1, 0x7b, 0);
    }
}

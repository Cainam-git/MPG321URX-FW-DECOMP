/* FUN_a00901a0 (leon2s 0xa00901a0-0xa0090374, 468 bytes), flags -mcpu=v8 -Os -g.
 * Returns a byte code built from the port registers read with FUN_a00a657c(port, reg) (rd below).
 * FUN_a008fea8(port) != 0: r = 2; when bits 6..7 of rd(0x145) are both set, r = 0xe, then 0x14 when bits 4..6 of
 * rd(0x146) are 1, else 0x1c / 0x22 when FUN_a008ff08(port) is 1 / 2; otherwise r = 8 when bits 6..7 of rd(0x145)
 * are 2. r is incremented when bits 6..7 of rd(0x148) are not 0, or when bits 2..3 of rd(0x146) are not 1 and
 * either not 0 or bits 0..6 of rd(0x147) are 1; r += 2 when bits 5..7 of rd(0x144) are 1, r += 4 when they are 3.
 * FUN_a008fea8(port) == 0: returns 1 unless bit 1 of rd(0x134) is set; then t = (bits 2..3 of rd(0x146) != 1) and
 * r = t + 0x1a when FUN_a008ff08(port) is non-zero, else t.
 * Source form: r = 2 before the 0x145 test; the increment condition is one || / && expression; t is an
 * unsigned int for the 0x1a sum.
 */
extern unsigned char FUN_a008fea8(unsigned char);
extern unsigned char FUN_a008ff08(unsigned char);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);

unsigned char FUN_a00901a0(unsigned char port)
{
    unsigned char r = 1;
    unsigned int t;

    if (FUN_a008fea8(port)) {
        r = 2;
        if ((FUN_a00a657c(port, 0x145) & 0xc0) == 0xc0) {
            r = 0xe;
            if ((FUN_a00a657c(port, 0x146) & 0x70) == 0x10)
                r = 0x14;
            else if (FUN_a008ff08(port) == 1)
                r = 0x1c;
            else if (FUN_a008ff08(port) == 2)
                r = 0x22;
        } else if ((FUN_a00a657c(port, 0x145) & 0xc0) == 0x80)
            r = 8;
        if ((FUN_a00a657c(port, 0x148) & 0xc0)
            || ((FUN_a00a657c(port, 0x146) & 0xc) != 4
                && ((FUN_a00a657c(port, 0x146) & 0xc) || (FUN_a00a657c(port, 0x147) & 0x7f) == 1)))
            r++;
        if ((FUN_a00a657c(port, 0x144) & 0xe0) == 0x20)
            r += 2;
        if ((FUN_a00a657c(port, 0x144) & 0xe0) == 0x60)
            r += 4;
    } else if (FUN_a00a657c(port, 0x134) & 2) {
        if (FUN_a008ff08(port)) {
            t = (FUN_a00a657c(port, 0x146) & 0xc) != 4;
            r = t + 0x1a;
        } else
            r = (FUN_a00a657c(port, 0x146) & 0xc) != 4;
    }
    return r;
}

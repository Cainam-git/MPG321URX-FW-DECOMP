/* leon2m FUN_a00ea308 @ 0xa00ea308-0xa00ea638 (816 bytes), flags -mcpu=v8 -O3 -g -msoft-float. Caller: FUN_a00ea878.
 * FUN_a00ea308(unit, p2, p3, b, p5): register fields are read with FUN_a00e0754 with (reg, mask, shift) from entry b
 * of three word tables (b == -1 passes the table addresses themselves), as in FUN_a00e9c80.
 * fail = field 0xa8026268/0xa8026258/0xa802b618. Each pass: for i = 0..7 with bit i clear in fail, v =
 * FUN_a00e0514(unit, word b of 0xa8026248 + i, word b of 0xa8026238), q = v >> 3; q == 0xf: FUN_a00df80c(),
 * FUN_a00e0bc0(), "Error: wr_deskew_cdly_state_error_flag = %d.\n" with 1 to FUN_a00df170, returns -1; otherwise
 * FUN_a00e05d8(unit, the same two words, ((q + 1) << 3) + (v & 7)), then FUN_a00ea25c(unit, b, i, 0),
 * FUN_a00ea25c(unit, b, i, 1), FUN_a00ea25c(unit, b, i, 0); the first nonzero result is returned. The words of
 * 0xa8026248 / 0xa8026238 are indexed by b also when b == -1. Then res = FUN_a00e4538(unit, p2, p3, p5) and fail is
 * read again: res == 1 with fail == 0xff ends the passes; res < 2 with fail != 0xff starts the next pass; otherwise
 * FUN_a00df80c(), FUN_a00e0bc0(), "Error: Bist result = %d, dq_fail = %d.\n" with res, fail, and -1 is returned.
 * After the passes, for i = 0..7: v, q as above; q != 0: FUN_a00e05d8(.., ((q - 1) << 3) + (v & 7)) and the three
 * FUN_a00ea25c probes as above. Returns 0.
 * Source form: the loop over i with ((q - 1) << 3) follows the outer for (;;), left by 'break'; in both loops the
 * low bits are kept in v ('v &= 7;' before the q test) and w = (shifted q) + v is formed after the test; the table at
 * 0xa802b618 is declared as PTR_a802b618 (the symbol names set the order of the address pseudos and so the register
 * choices).
 */
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00e4538(unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00ea25c(unsigned int, int, int, int);
extern unsigned int DAT_a8026268[], DAT_a8026258[], PTR_a802b618[];
extern unsigned int DAT_a8026248[], DAT_a8026238[];

int FUN_a00ea308(unsigned int unit, unsigned int p2, unsigned int p3, int b, unsigned int p5)
{
    unsigned int fail, v, q, w;
    unsigned int res;
    int i, r;

    if (b == -1)
        fail = FUN_a00e0754(unit, (unsigned int)DAT_a8026268, (unsigned int)DAT_a8026258, (unsigned int)PTR_a802b618);
    else
        fail = FUN_a00e0754(unit, DAT_a8026268[b], DAT_a8026258[b], PTR_a802b618[b]);
    for (;;) {
        for (i = 0; i < 8; i++) {
            if ((1 << i) & fail)
                continue;
            v = FUN_a00e0514(unit, DAT_a8026248[b] + i, DAT_a8026238[b]);
            q = v >> 3;
            v &= 7;
            if (q == 0xf) {
                FUN_a00df80c();
                FUN_a00e0bc0();
                FUN_a00df170("Error: wr_deskew_cdly_state_error_flag = %d.\n", 1);
                return -1;
            }
            w = ((q + 1) << 3) + v;
            FUN_a00e05d8(unit, DAT_a8026248[b] + i, DAT_a8026238[b], w);
            r = FUN_a00ea25c(unit, b, i, 0);
            if (r)
                return r;
            r = FUN_a00ea25c(unit, b, i, 1);
            if (r)
                return r;
            r = FUN_a00ea25c(unit, b, i, 0);
            if (r)
                return r;
        }
        res = FUN_a00e4538(unit, p2, p3, p5);
        if (b == -1)
            fail = FUN_a00e0754(unit, (unsigned int)DAT_a8026268, (unsigned int)DAT_a8026258, (unsigned int)PTR_a802b618);
        else
            fail = FUN_a00e0754(unit, DAT_a8026268[b], DAT_a8026258[b], PTR_a802b618[b]);
        if ((res == 1) & (fail == 0xff))
            break;
        if ((res < 2) & (fail != 0xff))
            continue;
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: Bist result = %d, dq_fail = %d.\n", res, fail);
        return -1;
    }
    for (i = 0; i < 8; i++) {
        v = FUN_a00e0514(unit, DAT_a8026248[b] + i, DAT_a8026238[b]);
        q = v >> 3;
        v &= 7;
        if (q == 0)
            continue;
        w = ((q - 1) << 3) + v;
        FUN_a00e05d8(unit, DAT_a8026248[b] + i, DAT_a8026238[b], w);
        r = FUN_a00ea25c(unit, b, i, 0);
        if (r)
            return r;
        r = FUN_a00ea25c(unit, b, i, 1);
        if (r)
            return r;
        r = FUN_a00ea25c(unit, b, i, 0);
        if (r)
            return r;
    }
    return 0;
}

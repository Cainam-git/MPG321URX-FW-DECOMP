/* leon2m FUN_a00ea638 @ 0xa00ea638-0xa00ea878 (576 bytes), flags -mcpu=v8 -O3 -g -msoft-float. Caller: FUN_a00ea878.
 * FUN_a00ea638(unit, p2, p3, b, p5): register fields are read with FUN_a00e0754 with (reg, mask, shift) from entry b
 * of three word tables (b == -1 passes the table addresses themselves), as in FUN_a00e9c80.
 * fail = field 0xa8026268/0xa8026258/0xa802b618, done = 0. Each pass: for i = 0..7 with bit i clear in both fail and
 * done, v = FUN_a00e0514(unit, word b of 0xa8026248 + i, word b of 0xa8026238) and FUN_a00e05d8(unit, the same two
 * words, v + 1), then FUN_a00ea25c(unit, b, i, 0), FUN_a00ea25c(unit, b, i, 1), FUN_a00ea25c(unit, b, i, 0); the first
 * nonzero result is returned. Other bits are set in done. The words of 0xa8026248 / 0xa8026238 are indexed by b also
 * when b == -1. Then res = FUN_a00e4538(unit, p2, p3, p5) and fail is read again: res < 2 with done == 0xff returns 0,
 * res < 2 with done != 0xff starts the next pass; otherwise FUN_a00df80c(), FUN_a00e0bc0(), "Error: Bist result = %d,
 * dq_fail = %d, dq_fail_fw = %d.\n" with res, fail, done to FUN_a00df170, and -1 is returned.
 * Source form: the second read of fail and both tests after it are written in each arm of if (b == -1) inside
 * for (;;); the addresses of the tables at 0xa8026248 and 0xa8026238 are held in the pointer locals t248 / t238
 * (declared t238 first, assigned t248 first) before the loop; the table at 0xa802b618 is declared as s_a802b618
 * (the declaration order and the symbol names set the order of the address pseudos and so the register choices).
 */
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00e4538(unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00ea25c(unsigned int, int, int, int);
extern unsigned int DAT_a8026268[], DAT_a8026258[], s_a802b618[];
extern unsigned int DAT_a8026248[], DAT_a8026238[];

int FUN_a00ea638(unsigned int unit, unsigned int p2, unsigned int p3, int b, unsigned int p5)
{
    unsigned int fail, done, v;
    unsigned int res;
    int i, r;
    unsigned int *t238, *t248;

    done = 0;
    if (b == -1)
        fail = FUN_a00e0754(unit, (unsigned int)DAT_a8026268, (unsigned int)DAT_a8026258, (unsigned int)s_a802b618);
    else
        fail = FUN_a00e0754(unit, DAT_a8026268[b], DAT_a8026258[b], s_a802b618[b]);
    t248 = DAT_a8026248;
    t238 = DAT_a8026238;
    for (;;) {
        for (i = 0; i < 8; i++) {
            if (!((1 << i) & fail) && !((1 << i) & done)) {
                v = FUN_a00e0514(unit, t248[b] + i, t238[b]);
                FUN_a00e05d8(unit, t248[b] + i, t238[b], v + 1);
                r = FUN_a00ea25c(unit, b, i, 0);
                if (r)
                    return r;
                r = FUN_a00ea25c(unit, b, i, 1);
                if (r)
                    return r;
                r = FUN_a00ea25c(unit, b, i, 0);
                if (r)
                    return r;
            } else
                done |= 1 << i;
        }
        res = FUN_a00e4538(unit, p2, p3, p5);
        if (b == -1) {
            fail = FUN_a00e0754(unit, (unsigned int)DAT_a8026268, (unsigned int)DAT_a8026258, (unsigned int)s_a802b618);
            if ((res < 2) & (done == 0xff))
                return 0;
            if (((res < 2) & (done != 0xff)) == 0)
                break;
        } else {
            fail = FUN_a00e0754(unit, DAT_a8026268[b], DAT_a8026258[b], s_a802b618[b]);
            if ((res < 2) & (done == 0xff))
                return 0;
            if (((res < 2) & (done != 0xff)) == 0)
                break;
        }
    }
    FUN_a00df80c();
    FUN_a00e0bc0();
    FUN_a00df170("Error: Bist result = %d, dq_fail = %d, dq_fail_fw = %d.\n", res, fail, done);
    return -1;
}

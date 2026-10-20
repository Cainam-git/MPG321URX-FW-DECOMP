/* leon2m FUN_a00d9764 @ 0xa00d9764-0xa00d9978 (133 words).
 * Limits byte s = 0xa802d290+0x11 to 14 and stores it back, then FUN_a0145ee8(0, 0). When chk() is true,
 * FUN_a014a11c(0..2, 100); otherwise the bytes +0x12, +0x13, +0x14 are each limited to 100, stored back and
 * passed to FUN_a014a11c(0..2, v), followed by FUN_a00d94fc() (the last step is FUN_a00d972c, inlined).
 * s selects k (0:7 1:4 2:1 3:0x17 4:0x18 5:5 6:6 7:8 8:4 9:0xf, others 4); when byte +0x11 is 1, byte +0x181
 * is 4..6 and bit 11 of the word at +0xa8 is set, k becomes 0xf, 0x10 or 0x11 instead.
 * Then FUN_a014c778(k & 0x1f) and tail FUN_a00d94fc().
 * chk(): FUN_a014bd70(0) == 1, or FUN_a01438dc(0) == 1 and FUN_a014ba68() is 1..4 (static helper, inlined).
 * Source forms: s is an unsigned short (as in FUN_a00d972c) and the switch takes its low byte; selectors 1 and 8
 * use the default arm. The 4..6 test is written as nested ifs (an && chain folds into a range test).
 */
struct R290 {
    unsigned char pad0[0x11];
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char pad15[0xa8 - 0x15];
    unsigned int wa8;
    unsigned char padac[0x181 - 0xac];
    unsigned char b181;
};
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014ba68(void);
extern void FUN_a0145ee8(int, int);
extern void FUN_a014a11c(int, unsigned char);
extern void FUN_a014c778(unsigned char);
extern void FUN_a00d94fc(void);

static int chk(void)
{
    if (FUN_a014bd70(0) == 1)
        return 1;
    if (FUN_a01438dc(0) == 1) {
        switch (FUN_a014ba68()) {
        case 1: return 1;
        case 2: return 1;
        case 3: return 1;
        case 4: return 1;
        }
    }
    return 0;
}

void FUN_a00d972c(void)
{
    struct R290 *p = &DAT_a802d290;
    unsigned short v = p->b14;

    if (v > 100)
        v = 100;
    p->b14 = v;
    FUN_a014a11c(2, v);
    FUN_a00d94fc();
}

void FUN_a00d9764(void)
{
    unsigned short s = DAT_a802d290.b11;
    unsigned char k;

    if (s > 14)
        s = 14;
    DAT_a802d290.b11 = s;
    FUN_a0145ee8(0, 0);
    if (chk()) {
        FUN_a014a11c(0, 100);
        FUN_a014a11c(1, 100);
        FUN_a014a11c(2, 100);
    } else {
        struct R290 *p = &DAT_a802d290;
        unsigned short v;

        v = p->b12;
        if (v > 100)
            v = 100;
        p->b12 = v;
        FUN_a014a11c(0, v);
        v = p->b13;
        if (v > 100)
            v = 100;
        p->b13 = v;
        FUN_a014a11c(1, v);
        FUN_a00d972c();
    }
    switch ((unsigned char)s) {
    case 0: k = 7; break;
    case 2: k = 1; break;
    case 3: k = 0x17; break;
    case 4: k = 0x18; break;
    case 5: k = 5; break;
    case 6: k = 6; break;
    case 7: k = 8; break;
    case 9: k = 0xf; break;
    default: k = 4; break;
    }
    if (DAT_a802d290.b11 == 1) {
        unsigned char b = DAT_a802d290.b181;
        if (b > 3)
            if (b <= 6)
                if (DAT_a802d290.wa8 & 0x800) {
                    if (b == 4)
                        k = 0xf;
                    else if (b == 5)
                        k = 0x10;
                    else if (b == 6)
                        k = 0x11;
                }
    }
    FUN_a014c778(k & 0x1f);
    FUN_a00d94fc();
}

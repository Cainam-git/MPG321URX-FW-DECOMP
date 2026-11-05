/* leon2m FUN_a00b4144 @ 0xa00b4144-0xa00b5014 (3792 bytes), flags -mcpu=v8 -O3 -g. 46 call sites in 29
 * functions (FUN_a00911a0 ... FUN_a00b1004) pass (row, mode).
 * Calls func_0x4008e2a4, FUN_a0146b50(0x1e5, 0), FUN_a0146b6c(2, 0), FUN_a0146a80(0x37, 9, 4, 0x596, 0) and
 * FUN_a00a31a4(0, 0x37, 9, 4, FUN_a00a3844(DAT_001928b0, DAT_a802d290[8] + 0xcb (mode 2) or + 0xae), 0).
 * y = row * 2 - 9 for row > 6, else row * 2 + 5. Five halfword values ca, cb, cc, cd, ce: mode 1 0x714a, 0x799a,
 * 0x392, 0x742, 0x589a (and row is stored in DAT_a802b08f), other modes 0x75ca, 0x7d9a, 0xb92, 0x7c2, 0x5b9a; cb is
 * 0x699a / 0x6d9a when row is not 6 or 7. After two func_0x4008e2a4 calls: mode 1 calls FUN_a00b3ed0(1, 1, y, 0x11),
 * FUN_a0146c40(1, 1, 0) and FUN_a0146c40(2, 1, 0); other modes call FUN_a00b3ed0(0, 0, 0, 0) when FUN_a0090fcc()
 * is <= 0x91 or > 0xae. Then FUN_a0146a80 rows and runs of characters through put_str (the body of the matched
 * FUN_a00b32e4: FUN_a0146ab0(c, 0), then FUN_a0146b20(1, x + k, y, 1, ch or ch + k, 0) for k < n) at rows y, y + 1
 * and y + 2: row 0, 6, 7 (codes 0x49/0x4f, 0x64/0x6a, 0x70/0x76 in mode 1, 0x7f/0x82, 0x88/0x8b, 0x91/0x94
 * otherwise), row 8 and 1 (0x79 / 0x97, 0x52 / 0x85), other rows 0x30 / 0x32, row 5 at y + 2 0x6d / 0x8e, other rows
 * 0x31 / 0x33; finally the border codes 0x9a..0xa3 with ce (and 0x9b / 0xa1 runs of 11 with ce in mode 1, 0x32 /
 * 0x33 with cc otherwise).
 * Source form: put_str is a static copy of FUN_a00b32e4 (inlined); the y + 2 test is written 'row != 5' with the
 * cc arm first.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08f;
extern unsigned int DAT_001928b0[];
extern void func_0x4008e2a4(void);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146ab0(unsigned short, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);

static void put_str(unsigned char dir, unsigned char inc, unsigned short c, unsigned short x, unsigned char y,
                    unsigned char n, unsigned char ch)
{
    unsigned char k;

    FUN_a0146ab0(c, 0);
    if (dir == 1) {
        for (k = 0; k < n; k++) {
            if (inc)
                FUN_a0146b20(1, x + k, y, 1, ch + k, 0);
            else
                FUN_a0146b20(1, x + k, y, 1, ch, 0);
        }
    } else {
        for (k = 0; k < n; k++) {
            if (inc)
                FUN_a0146b20(1, x, y + k, 1, ch + k, 0);
            else
                FUN_a0146b20(1, x, y + k, 1, ch, 0);
        }
    }
}

void FUN_a00b4144(unsigned char row, unsigned char mode)
{
    unsigned char y;
    unsigned short ca, cb, cc, cd, ce;

    func_0x4008e2a4();
    if (mode == 2) {
        FUN_a0146b50(0x1e5, 0);
        FUN_a0146b6c(2, 0);
        FUN_a0146a80(0x37, 9, 4, 0x596, 0);
        FUN_a00a31a4(0, 0x37, 9, 4, FUN_a00a3844(DAT_001928b0, DAT_a802d290[8] + 0xcb), 0);
    } else {
        FUN_a0146b50(0x1e5, 0);
        FUN_a0146b6c(2, 0);
        FUN_a0146a80(0x37, 9, 4, 0x596, 0);
        FUN_a00a31a4(0, 0x37, 9, 4, FUN_a00a3844(DAT_001928b0, DAT_a802d290[8] + 0xae), 0);
    }
    if (row > 6)
        y = row * 2 - 9;
    else
        y = row * 2 + 5;
    if (mode == 1) {
        DAT_a802b08f = row;
        ca = 0x714a;
        cb = 0x799a;
        cc = 0x392;
        cd = 0x742;
        if ((unsigned char)(row - 6) > 1)
            cb = 0x699a;
        ce = 0x589a;
    } else {
        ca = 0x75ca;
        cb = 0x7d9a;
        cc = 0xb92;
        cd = 0x7c2;
        if ((unsigned char)(row - 6) > 1)
            cb = 0x6d9a;
        ce = 0x5b9a;
    }
    func_0x4008e2a4();
    func_0x4008e2a4();
    if (mode == 1) {
        FUN_a00b3ed0(1, 1, y, 0x11);
        FUN_a0146c40(1, 1, 0);
        FUN_a0146c40(2, 1, 0);
    } else if (FUN_a0090fcc() <= 0x91 || FUN_a0090fcc() > 0xae)
        FUN_a00b3ed0(0, 0, 0, 0);
    if ((unsigned char)(row - 6) < 2 || row == 0) {
        FUN_a0146a80(2, y, 3, cb, 0);
        FUN_a0146a80(2, y + 1, 3, cb, 0);
        FUN_a0146a80(5, y + 1, 0xc, cd, 0);
        FUN_a0146a80(2, y + 2, 3, cb, 0);
        if (row == 0) {
            if (mode == 1) {
                put_str(1, 1, cb, 2, y, 3, 0x49);
                put_str(1, 1, cb, 2, y + 2, 3, 0x4f);
            } else {
                put_str(1, 1, cb, 2, y, 3, 0x7f);
                put_str(1, 1, cb, 2, y + 2, 3, 0x82);
            }
        } else if (row == 6) {
            if (mode == 1) {
                put_str(1, 1, cb, 2, y, 3, 0x64);
                put_str(1, 1, cb, 2, y + 2, 3, 0x6a);
            } else {
                put_str(1, 1, cb, 2, y, 3, 0x88);
                put_str(1, 1, cb, 2, y + 2, 3, 0x8b);
            }
        } else if (row == 7) {
            if (mode == 1) {
                put_str(1, 1, cb, 2, y, 3, 0x70);
                put_str(1, 1, cb, 2, y + 2, 3, 0x76);
            } else {
                put_str(1, 1, cb, 2, y, 3, 0x91);
                put_str(1, 1, cb, 2, y + 2, 3, 0x94);
            }
        }
    } else {
        if (row != 1 && row != 8) {
            if (mode == 1)
                put_str(1, 0, cc, 2, y, 3, 0x30);
            else
                put_str(1, 0, cc, 2, y, 3, 0x32);
        } else if (row == 8) {
            if (mode == 1)
                put_str(1, 1, cb, 2, y, 3, 0x79);
            else
                put_str(1, 1, cb, 2, y, 3, 0x97);
        } else if (row == 1) {
            if (mode == 1)
                put_str(1, 1, cb, 2, y, 3, 0x52);
            else
                put_str(1, 1, cb, 2, y, 3, 0x85);
        }
        FUN_a0146a80(2, y + 1, 3, ca, 0);
        FUN_a0146a80(5, y + 1, 0xc, cd, 0);
        if (row != 5) {
            if (mode == 1)
                put_str(1, 0, cc, 2, y + 2, 3, 0x31);
            else
                put_str(1, 0, cc, 2, y + 2, 3, 0x33);
        } else {
            if (mode == 1)
                put_str(1, 1, cb, 2, y + 2, 3, 0x6d);
            else
                put_str(1, 1, cb, 2, y + 2, 3, 0x8e);
        }
    }
    put_str(1, 0, ce, 1, y, 1, 0x9a);
    if (mode == 1)
        put_str(1, 0, ce, 5, y, 11, 0x9b);
    else
        put_str(1, 0, cc, 5, y, 11, 0x32);
    put_str(1, 0, ce, 0x10, y, 1, 0x9c);
    put_str(1, 0, ce, 0x11, y, 1, 0x9d);
    put_str(1, 0, ce, 1, y + 1, 1, 0x9e);
    put_str(1, 0, ce, 0x11, y + 1, 1, 0x9f);
    put_str(1, 0, ce, 1, y + 2, 1, 0xa0);
    if (mode == 1)
        put_str(1, 0, ce, 5, y + 2, 11, 0xa1);
    else
        put_str(1, 0, cc, 5, y + 2, 11, 0x33);
    put_str(1, 0, ce, 0x10, y + 2, 1, 0xa2);
    put_str(1, 0, ce, 0x11, y + 2, 1, 0xa3);
}

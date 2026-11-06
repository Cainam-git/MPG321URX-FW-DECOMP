/* leon2m FUN_a00d3650 @ 0xa00d3650-0xa00d3a30 (992 bytes), flags -mcpu=v8 -O3 -g. FUN_a00d3650(port, req) answers the
 * request record req with a 40-byte record r on the stack.
 *
 * r is cleared and FUN_a00d0e48(req, r, 1) fills r[0..6]: r[0] = 0x6e, r[1] = 0x86 for req[3] in {0x63, 0x31, 0x32,
 * 0x27, 0x28, 0x35, 0x36, 0x39, 0x3a}, 0x93 for {0x34, 0x30, 0x38, 0x3c}, else 0xc5 (req[6] == 0x40) or 0x95,
 * r[2] = 0xd0, r[3..6] = req[3..6]. For req[3] in {0x29, 0x33, 0x37, 0x3b}: func_0x4008d1a0(10), then for
 * DAT_a802b09f / req[3] = 1 / 0x29, 2 / 0x33, 0x11 / 0x37 or 0x21 / 0x3b a switch on DAT_a802b09e (jump tables
 * 0xa00cf144, 0xa00cf110, 0xa00cf0f4, 0xa00cf178) calls FUN_a00ce9c0(n, &r[7], req[5]) with n per case,
 * code 0x99; other values give code 0xe3. Then FUN_a00d1220(req, r, code & 0xfb), FUN_a0089f60(0x50) and
 * FUN_a01486a8(port, 0x19, r).
 * Source form: the r[0..6] fill is a static copy of FUN_a00d0e48, inlined (fw: its p pointer is %l0, set at
 * 0xa00d36ac, and req[3] is read again for the switch at 0xa00d3748); in it the two r[1] tests are each one '||'
 * condition on req[3] read through the pointer: only the first two compares of each condition are one
 * xor/subx/orcc pair (0xa00d3684 .. 0xa00d36a0, 0xa00d36e8 .. 0xa00d3700), the others are single compares, and
 * each condition has one r[1] store block (0xa00d373c, 0xa00d3994) storing through %l0 at 0xa00d3740.
 */
extern unsigned char DAT_a802b09f;
extern unsigned char DAT_a802b09e;
extern void func_0x4008d1a0(int);
extern void FUN_a00ce9c0(unsigned short n, unsigned char *dst, unsigned char blk);
extern void FUN_a00d1220(const unsigned char *req, unsigned char *p, unsigned char cmd);
extern void FUN_a0089f60(unsigned char);
extern void FUN_a01486a8(unsigned char, unsigned short, unsigned char *);

static void FUN_a00d0e48(const unsigned char *req, unsigned char *p, unsigned char mode)
{
    p[0] = 0x6e;
    if (mode == 0) {
        p[1] = 0x86;
        p[2] = 0xc0;
    } else if (mode == 1) {
        if (req[3] == 0x63 ||
            req[3] == 0x31 ||
            req[3] == 0x32 ||
            req[3] == 0x27 ||
            req[3] == 0x28 ||
            req[3] == 0x35 ||
            req[3] == 0x36 ||
            req[3] == 0x39 ||
            req[3] == 0x3a)
            p[1] = 0x86;
        else if (req[3] == 0x34 ||
                 req[3] == 0x30 ||
                 req[3] == 0x38 ||
                 req[3] == 0x3c)
            p[1] = 0x93;
        else if (req[6] == 0x40)
            p[1] = 0xc5;
        else
            p[1] = 0x95;
        p[2] = 0xd0;
    }
    p[3] = req[3];
    p[4] = req[4];
    p[5] = req[5];
    p[6] = req[6];
}

void FUN_a00d3650(unsigned char port, unsigned char *req)
{
    unsigned char r[40];
    unsigned char st = 0x99;
    unsigned char i;

    for (i = 0; i < 40; i++)
        r[i] = 0;
    FUN_a00d0e48(req, r, 1);
    switch (req[3]) {
    case 0x29:
    case 0x33:
    case 0x37:
    case 0x3b:
        func_0x4008d1a0(10);
        if (DAT_a802b09f == 1 && req[3] == 0x29) {
            switch (DAT_a802b09e) {
            case 1: FUN_a00ce9c0(0, &r[7], req[5]); st = 0x99; break;
            case 2: FUN_a00ce9c0(0x14, &r[7], req[5]); st = 0x99; break;
            case 3: FUN_a00ce9c0(0x10, &r[7], req[5]); st = 0x99; break;
            case 4: FUN_a00ce9c0(0x16, &r[7], req[5]); st = 0x99; break;
            case 5: FUN_a00ce9c0(0x1c, &r[7], req[5]); st = 0x99; break;
            case 6: FUN_a00ce9c0(0x20, &r[7], req[5]); st = 0x99; break;
            case 7: FUN_a00ce9c0(0x1e, &r[7], req[5]); st = 0x99; break;
            case 8: FUN_a00ce9c0(0x22, &r[7], req[5]); st = 0x99; break;
            case 9: FUN_a00ce9c0(4, &r[7], req[5]); st = 0x99; break;
            case 10: FUN_a00ce9c0(8, &r[7], req[5]); st = 0x99; break;
            case 11: FUN_a00ce9c0(0xc, &r[7], req[5]); st = 0x99; break;
            case 12: FUN_a00ce9c0(0x18, &r[7], req[5]); st = 0x99; break;
            default: st = 0xe3; break;
            }
        } else if (DAT_a802b09f == 2 && req[3] == 0x33) {
            switch (DAT_a802b09e) {
            case 1: FUN_a00ce9c0(1, &r[7], req[5]); st = 0x99; break;
            case 2: FUN_a00ce9c0(0x15, &r[7], req[5]); st = 0x99; break;
            case 3: FUN_a00ce9c0(0x11, &r[7], req[5]); st = 0x99; break;
            case 4: FUN_a00ce9c0(0x17, &r[7], req[5]); st = 0x99; break;
            case 5: FUN_a00ce9c0(0x1d, &r[7], req[5]); st = 0x99; break;
            case 6: FUN_a00ce9c0(0x21, &r[7], req[5]); st = 0x99; break;
            case 7: FUN_a00ce9c0(0x1f, &r[7], req[5]); st = 0x99; break;
            case 8: FUN_a00ce9c0(0x23, &r[7], req[5]); st = 0x99; break;
            case 9: FUN_a00ce9c0(5, &r[7], req[5]); st = 0x99; break;
            case 10: FUN_a00ce9c0(9, &r[7], req[5]); st = 0x99; break;
            case 11: FUN_a00ce9c0(0xd, &r[7], req[5]); st = 0x99; break;
            case 12: FUN_a00ce9c0(0x19, &r[7], req[5]); st = 0x99; break;
            default: st = 0xe3; break;
            }
        } else if (DAT_a802b09f == 0x11 && req[3] == 0x37) {
            switch (DAT_a802b09e) {
            case 1: FUN_a00ce9c0(2, &r[7], req[5]); st = 0x99; break;
            case 2: FUN_a00ce9c0(0x12, &r[7], req[5]); st = 0x99; break;
            case 3: FUN_a00ce9c0(6, &r[7], req[5]); st = 0x99; break;
            case 4: FUN_a00ce9c0(0xa, &r[7], req[5]); st = 0x99; break;
            case 5: FUN_a00ce9c0(0xe, &r[7], req[5]); st = 0x99; break;
            case 6: FUN_a00ce9c0(0x1a, &r[7], req[5]); st = 0x99; break;
            default: st = 0xe3; break;
            }
        } else if (DAT_a802b09f == 0x21 && req[3] == 0x3b) {
            switch (DAT_a802b09e) {
            case 1: FUN_a00ce9c0(3, &r[7], req[5]); st = 0x99; break;
            case 2: FUN_a00ce9c0(0x13, &r[7], req[5]); st = 0x99; break;
            case 3: FUN_a00ce9c0(7, &r[7], req[5]); st = 0x99; break;
            case 4: FUN_a00ce9c0(0xb, &r[7], req[5]); st = 0x99; break;
            case 5: FUN_a00ce9c0(0xf, &r[7], req[5]); st = 0x99; break;
            case 6: FUN_a00ce9c0(0x1b, &r[7], req[5]); st = 0x99; break;
            default: st = 0xe3; break;
            }
        } else
            st = 0xe3;
        break;
    }
    FUN_a00d1220(req, r, st & 0xfb);
    FUN_a0089f60(0x50);
    FUN_a01486a8(port, 0x19, r);
}

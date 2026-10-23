/*
 * FUN_a00abff0 (leon2s, 0xa00abff0-0xa00ac41c, 1068 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Uses the 300-byte record DAT_a807dc18[port] (bytes +0x112, +0x113, +0x115, +0x116,
 * +0x117, +0x11e) and writes a fixed register sequence with FUN_a00a6c00(port, reg, value) and
 * FUN_a00a6c98(port, reg, mask, on):
 * - +0x117 == 0 clears +0x112. FUN_a00abe20(port); FUN_a00a6c98(port, 0x30, 0x80, 1); 0x204 = 1, 0x206 = 1,
 *   0x21c = 0x14 (+0x11e == 0) or 6, 0x21d = 0x84, 0x225 = 0x41, 0x226 = 0; FUN_a00a6c98(port, 0x20a, 4, 1);
 *   0x261 = 0, 0x332 = 0x41.
 * - port 0 with +0x112 != 0: 0x205 = 1, 0x207 = 0x81, 0x301 = 1; otherwise 0x205, 0x207, 0x301 = 0; then
 *   0x30e = 0 and 0x333 = 0.
 * - +0x113 == 0: 0x2a8 = 1; else 0x2a8 = 3, 0x2aa = 1, 0x2ab = 1.
 * - FUN_a00a6c98(port, 0x207, 0x40, +0x115 != 0).
 * - +0x116 != 0 unless (+0x112 == 1 and port 0): 0x450 = 1, 0x451 = 0x21, 0x452 = 0, 0x453 = 0x76,
 *   0x454 = 0xb or 0x2b (DAT_a8079308 == 1 or not), 0x455 = 1, 0x456 = 1, 0x457 = 7, 0x458 = 0xe,
 *   0x459 = 2 or 1 (same test), 0x45a = 8, 0x45b = 0, 0x45c = 4, 0x45d = 0xbf; otherwise 0x450 = 0,
 *   0x45d = 0.
 * - 0x3e0..0x3e5 = 0x38, 0xec, 0x11, 0, 0, 0; tail call FUN_a00a6c98(port, 0x30, 0x80, 0).
 * Source forms: every value choice is a separate call per arm (the compiler merges the common call); the
 * 0x30e/0x333 writes and the 0x45d write are written in each arm; the 0x450 test is
 * 'b116 != 0 && (b112 == 1 && port == 0) == 0' (long arm first, the inner && as flag arithmetic).
 */
struct Rec300 {
    unsigned char pad0[0x112];
    unsigned char b112;
    unsigned char b113;
    unsigned char b114;
    unsigned char b115;
    unsigned char b116;
    unsigned char b117;
    unsigned char pad118[6];
    unsigned char b11e;
    unsigned char pad11f[0x12c - 0x11f];
};
extern struct Rec300 DAT_a807dc18[];
extern unsigned char DAT_a8079308;
extern void FUN_a00abe20(unsigned char);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a00abff0(unsigned char port)
{
    if (DAT_a807dc18[port].b117 == 0)
        DAT_a807dc18[port].b112 = 0;
    FUN_a00abe20(port);
    FUN_a00a6c98(port, 0x30, 0x80, 1);
    FUN_a00a6c00(port, 0x204, 1);
    FUN_a00a6c00(port, 0x206, 1);
    if (DAT_a807dc18[port].b11e == 0)
        FUN_a00a6c00(port, 0x21c, 0x14);
    else
        FUN_a00a6c00(port, 0x21c, 6);
    FUN_a00a6c00(port, 0x21d, 0x84);
    FUN_a00a6c00(port, 0x225, 0x41);
    FUN_a00a6c00(port, 0x226, 0);
    FUN_a00a6c98(port, 0x20a, 4, 1);
    FUN_a00a6c00(port, 0x261, 0);
    FUN_a00a6c00(port, 0x332, 0x41);
    if (port == 0 && DAT_a807dc18[port].b112) {
        FUN_a00a6c00(port, 0x205, 1);
        FUN_a00a6c00(port, 0x207, 0x81);
        FUN_a00a6c00(port, 0x301, 1);
        FUN_a00a6c00(port, 0x30e, 0);
        FUN_a00a6c00(port, 0x333, 0);
    } else {
        FUN_a00a6c00(port, 0x205, 0);
        FUN_a00a6c00(port, 0x207, 0);
        FUN_a00a6c00(port, 0x301, 0);
        FUN_a00a6c00(port, 0x30e, 0);
        FUN_a00a6c00(port, 0x333, 0);
    }
    if (DAT_a807dc18[port].b113 == 0)
        FUN_a00a6c00(port, 0x2a8, 1);
    else {
        FUN_a00a6c00(port, 0x2a8, 3);
        FUN_a00a6c00(port, 0x2aa, 1);
        FUN_a00a6c00(port, 0x2ab, 1);
    }
    if (DAT_a807dc18[port].b115)
        FUN_a00a6c98(port, 0x207, 0x40, 1);
    else
        FUN_a00a6c98(port, 0x207, 0x40, 0);
    if (DAT_a807dc18[port].b116 != 0 && (DAT_a807dc18[port].b112 == 1 && port == 0) == 0) {
        FUN_a00a6c00(port, 0x450, 1);
        FUN_a00a6c00(port, 0x451, 0x21);
        FUN_a00a6c00(port, 0x452, 0);
        FUN_a00a6c00(port, 0x453, 0x76);
        if (DAT_a8079308 == 1)
            FUN_a00a6c00(port, 0x454, 0xb);
        else
            FUN_a00a6c00(port, 0x454, 0x2b);
        FUN_a00a6c00(port, 0x455, 1);
        FUN_a00a6c00(port, 0x456, 1);
        FUN_a00a6c00(port, 0x457, 7);
        FUN_a00a6c00(port, 0x458, 0xe);
        if (DAT_a8079308 == 1)
            FUN_a00a6c00(port, 0x459, 2);
        else
            FUN_a00a6c00(port, 0x459, 1);
        FUN_a00a6c00(port, 0x45a, 8);
        FUN_a00a6c00(port, 0x45b, 0);
        FUN_a00a6c00(port, 0x45c, 4);
        FUN_a00a6c00(port, 0x45d, 0xbf);
    } else {
        FUN_a00a6c00(port, 0x450, 0);
        FUN_a00a6c00(port, 0x45d, 0);
    }
    FUN_a00a6c00(port, 0x3e0, 0x38);
    FUN_a00a6c00(port, 0x3e1, 0xec);
    FUN_a00a6c00(port, 0x3e2, 0x11);
    FUN_a00a6c00(port, 0x3e3, 0);
    FUN_a00a6c00(port, 0x3e4, 0);
    FUN_a00a6c00(port, 0x3e5, 0);
    FUN_a00a6c98(port, 0x30, 0x80, 0);
}

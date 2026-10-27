/* leon2m FUN_a01006e4 @ 0xa01006e4-0xa0100990 (684 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a01012a8.
 * Six local 12-byte records {a, b, c, d, e (halfwords), f (byte)} hold fixed values; one is copied into cur by
 * the byte DAT_a8027a75 (switch, jump table 0xa04e4, 40 entries): 0, 1, 26, 27 -> r2; 8..13 -> r0; 14..19 -> r4;
 * 20..25 -> r3; 28..39 -> r2 for port 0, else r5; all other values -> r1. Then FUN_a00f2488(port, reg, v << 2)
 * for reg 3, 5, 7, 9, 1 with v = a, b, c, d, e; FUN_a00f232c(port, 2, 0x40, f == 1); and
 * FUN_a00f232c(port, 0xb, 1, 0) when the word DAT_a8027a78 == 2 or DAT_a8027a75 == 0x2a, else
 * FUN_a00f2298(port, 0xb, 0xd).
 * Source form: initialised local structures declared in stack order (cur first), cur assigned by structure copy
 * in each case; one complete FUN_a00f232c call per arm of the f test.
 */
struct Set { unsigned short a, b, c, d, e; unsigned char f; };
extern unsigned char DAT_a8027a75;
extern unsigned int DAT_a8027a78;
extern void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val);
extern void FUN_a00f232c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);

void FUN_a01006e4(unsigned char port)
{
    struct Set cur;
    struct Set r0 = {0x629, 0x1d6, 0xbb, 0x744, 0x400, 0};
    struct Set r1 = {0x57c, 0x2cb, 0x158, 0x6ee, 0x400, 0};
    struct Set r2 = {0x662, 0x341, 0x190, 0x812, 0x4a8, 1};
    struct Set r3 = {0x64d, 0x1df, 0xc0, 0x76c, 0x400, 0};
    struct Set r4 = {0x59c, 0x2db, 0x160, 0x717, 0x400, 0};
    struct Set r5 = {0x5e6, 0x249, 0xa9, 0x787, 0x400, 0};

    switch (DAT_a8027a75) {
    case 0: case 1: case 26: case 27:
        cur = r2;
        break;
    case 8: case 9: case 10: case 11: case 12: case 13:
        cur = r0;
        break;
    case 14: case 15: case 16: case 17: case 18: case 19:
        cur = r4;
        break;
    case 20: case 21: case 22: case 23: case 24: case 25:
        cur = r3;
        break;
    case 28: case 29: case 30: case 31: case 32: case 33:
    case 34: case 35: case 36: case 37: case 38: case 39:
        if (port == 0)
            cur = r2;
        else
            cur = r5;
        break;
    default:
        cur = r1;
        break;
    }
    FUN_a00f2488(port, 3, cur.a << 2);
    FUN_a00f2488(port, 5, cur.b << 2);
    FUN_a00f2488(port, 7, cur.c << 2);
    FUN_a00f2488(port, 9, cur.d << 2);
    FUN_a00f2488(port, 1, cur.e << 2);
    if (cur.f == 1)
        FUN_a00f232c(port, 2, 0x40, 1);
    else
        FUN_a00f232c(port, 2, 0x40, 0);
    if (DAT_a8027a78 == 2 || DAT_a8027a75 == 0x2a)
        FUN_a00f232c(port, 0xb, 1, 0);
    else
        FUN_a00f2298(port, 0xb, 0xd);
}

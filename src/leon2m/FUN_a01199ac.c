/* leon2m FUN_a01199ac @ 0xa01199ac-0xa011a060 (1716 bytes), flags -mcpu=v8 -O3 -g. Caller: FUN_a0146518.
 * FUN_a01199ac(a, b, c, d, blk) writes registers of block blk of the second register family (register n at
 * 0xcf000000 + 4 * n, block base = halfword table DAT_a8027aa8[blk]; the write helpers treat blk > 1 as 0).
 * First writes register base + 0 back as its low byte with bit 7 cleared (FUN_a01191fc(blk, 0, 0x80, 0)), then
 * reads w = DAT_a802c9ca[blk], x = DAT_a802c9c0[blk], y = DAT_a802c9b8[blk], z = DAT_a802c9c8[blk];
 * mode = bits 2..3 (blk 0) or bits 4..5 (other blk) of DAT_a802c9b0. Per mode two 16-bit values are formed from
 * (c or d) minus (y * z or x * w), times (a, b, 100 - a or 100 - b), divided by 100 (0 when the difference is
 * negative):
 *   mode 1: (c - y*z) * b,         (d - x*w) * a;        mode 2: (c - x*w) * (100 - a), (d - y*z) * b;
 *   mode 3: (c - y*z) * (100 - b), (d - x*w) * (100 - a); other: (c - x*w) * a,         (d - y*z) * (100 - b).
 * The first goes to registers base + 0x81 / 0x82 (low / high byte, FUN_a011919c), w - 1 to base + 0x83 / 0xd3
 * (FUN_a0119910), the second to base + 0x84 / 0x85, z - 1 to base + 0x86. When bit 0 of register base + 0x80 is set
 * (FUN_a011996c) func_0x4008e2a4 is called three times, otherwise once.
 * Source form: K&R definition; FUN_a01191fc, FUN_a011919c, FUN_a0119910, FUN_a011996c and the byte-write helper
 * are inlined static copies of the matched functions' bodies; v is an unsigned short.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
extern unsigned char DAT_a802c9b0;
extern unsigned char DAT_a802c9b8[];
extern unsigned char DAT_a802c9c0[];
extern unsigned char DAT_a802c9c8[];
extern unsigned short DAT_a802c9ca[];
extern void func_0x4008e2a4(void);

static void wr16(unsigned int a, unsigned short v) { R(a) = (unsigned char)v; R(a + 1) = (unsigned char)(v >> 8); }

static void FUN_a011919c(unsigned char blk, unsigned char reg, unsigned short v)
{
    if (blk > 1) blk = 0;
    wr16(DAT_a8027aa8[blk] + reg, v);
}

static void wr8(unsigned char blk, unsigned int reg, unsigned char v)
{
    if (blk > 1) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}

static void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

static void FUN_a0119910(unsigned int blk, int v)
{
    wr8(blk, 0x83, v & 0xff);
    wr8(blk, 0xd3, (v >> 8) & 0xff);
}

static unsigned int FUN_a011996c(unsigned char blk)
{
    if (blk > 1) blk = 0;
    return R(DAT_a8027aa8[blk] + 0x80) & 1;
}

void FUN_a01199ac(a, b, c, d, blk)
    unsigned short a, b, c, d;
    unsigned char blk;
{
    unsigned short w;
    unsigned char x, y, z;
    int mode;
    unsigned short v;

    FUN_a01191fc(blk, 0, 0x80, 0);
    w = DAT_a802c9ca[blk];
    x = DAT_a802c9c0[blk];
    y = DAT_a802c9b8[blk];
    z = DAT_a802c9c8[blk];
    if (blk == 0)
        mode = (DAT_a802c9b0 & 0xc) >> 2;
    else
        mode = (DAT_a802c9b0 & 0x30) >> 4;

    switch (mode) {
    case 1:
        if (c >= y * z)
            v = (unsigned int)((c - y * z) * b) / 100;
        else
            v = 0;
        FUN_a011919c(blk, 0x81, v);
        FUN_a0119910(blk, w - 1);
        if (d >= x * w)
            v = (unsigned int)((d - x * w) * a) / 100;
        else
            v = 0;
        FUN_a011919c(blk, 0x84, v);
        wr8(blk, 0x86, z - 1);
        break;
    case 2:
        if (c >= x * w)
            v = (unsigned int)((c - x * w) * (100 - a)) / 100;
        else
            v = 0;
        FUN_a011919c(blk, 0x81, v);
        FUN_a0119910(blk, w - 1);
        if (d >= y * z)
            v = (unsigned int)((d - y * z) * b) / 100;
        else
            v = 0;
        FUN_a011919c(blk, 0x84, v);
        wr8(blk, 0x86, z - 1);
        break;
    case 3:
        if (c >= y * z)
            v = (unsigned int)((c - y * z) * (100 - b)) / 100;
        else
            v = 0;
        FUN_a011919c(blk, 0x81, v);
        FUN_a0119910(blk, w - 1);
        if (d >= x * w)
            v = (unsigned int)((d - x * w) * (100 - a)) / 100;
        else
            v = 0;
        FUN_a011919c(blk, 0x84, v);
        wr8(blk, 0x86, z - 1);
        break;
    default:
        if (c >= x * w)
            v = (unsigned int)((c - x * w) * a) / 100;
        else
            v = 0;
        FUN_a011919c(blk, 0x81, v);
        FUN_a0119910(blk, w - 1);
        if (d >= y * z)
            v = (unsigned int)((d - y * z) * (100 - b)) / 100;
        else
            v = 0;
        FUN_a011919c(blk, 0x84, v);
        wr8(blk, 0x86, z - 1);
        break;
    }
    if (FUN_a011996c(blk)) {
        func_0x4008e2a4();
        func_0x4008e2a4();
    }
    func_0x4008e2a4();
}

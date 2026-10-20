/* leon2m FUN_a0122e80 @ 0xa0122e80-0xa0123184 (193 words), flags -mcpu=v8 -O3 -g.
 * Code facts: params p (u8 unit), lo, hi, mode (u8). Log FUN_a00df170(string 0x1a3078); FUN_a00f2ca8(p, 0xe, 0xea,
 * 0); FUN_a00fe880(0xb, 0x10/0x20/0x40/0x80, 0xc); hw reg 0xcf03c548 &= 0xf3; 0xcf011814 = 0. mode != 0:
 * FUN_a00f2c20(p, reg, val) for (0xcc,0), (0x10, lo | (hi&0xff)<<4), (0x11,0x1e), (0x12,1), (0x30,0x47),
 * (0x33,0xf6), (0x60,0x1c), (0x19,0x10), (0x60,1), (0x60,0x1c), (0x64,0x22), (0x39,0), (0x65,0), (0x80,0xff). mode
 * == 0: (0xcc,2), (0x10, same value), (0x11,0x1e), (0x12,1), (0x30,0x47), (0x33,0xf6), (0x39,0x10), (0x60,0x1c),
 * (0x19,0x12), (0x60,0x5e), (0x64,0x21), (0x65,0), (0x80,0xff), then regs 0x40..0x4f = the 16 bytes of the ROM table
 * 0x1a3060. Then FUN_a00f2ca8(p, 0x30, 4, 0); x = hw reg 0xcf03d024; d024 = 0xc; 0xcf01d858 = 0xff; d024 = 0xf;
 * register (0x7600 + 0x50) of the 0xcf000000 | (n << 2) window (= 0xcf01d940) = 2; d024 = x & 0xff. void.
 * d024 is read once, first, then written with 0xc, 0xf and the saved low byte; c548 is read once (no self-copy).
 * Source form: hi is a full word masked at the use ('t = (hi & 0xff) << 4' in its own variable keeps the fw 'and'
 * and the 'or lo, t' operand order); the d940 address is the register-window form with a local 'base = 0x7600' (fw
 * computes sethi 0x7400|0x200, +0x50, sll 2, | 0xcf000000 at run time; a literal 0xcf01d940 shares d858's %hi).
 * FUN_a00f2c20 is (u8, u8, u8): it re-masks all three args. volatile only on the 0xcf... hw registers. Compiler
 * aids: none.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00f2c20(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f2ca8(unsigned char, unsigned int, unsigned int, unsigned int);
extern void FUN_a00fe880(unsigned char, unsigned int, unsigned int);
extern const char s_001a3078[];
extern const unsigned char DAT_001a3060[16];

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0122e80(unsigned char p, unsigned int lo, unsigned int hi, unsigned char mode)
{
    unsigned char i;
    unsigned int x;
    unsigned int t;
    unsigned int base;

    FUN_a00df170(s_001a3078);
    FUN_a00f2ca8(p, 0xe, 0xea, 0);
    FUN_a00fe880(0xb, 0x10, 0xc);
    FUN_a00fe880(0xb, 0x20, 0xc);
    FUN_a00fe880(0xb, 0x40, 0xc);
    FUN_a00fe880(0xb, 0x80, 0xc);
    R(0xcf03c548) &= 0xf3;
    R(0xcf011814) = 0;
    if (mode != 0) {
        FUN_a00f2c20(p, 0xcc, 0);
        t = (hi & 0xff) << 4;
        FUN_a00f2c20(p, 0x10, lo | t);
        FUN_a00f2c20(p, 0x11, 0x1e);
        FUN_a00f2c20(p, 0x12, 1);
        FUN_a00f2c20(p, 0x30, 0x47);
        FUN_a00f2c20(p, 0x33, 0xf6);
        FUN_a00f2c20(p, 0x60, 0x1c);
        FUN_a00f2c20(p, 0x19, 0x10);
        FUN_a00f2c20(p, 0x60, 1);
        FUN_a00f2c20(p, 0x60, 0x1c);
        FUN_a00f2c20(p, 0x64, 0x22);
        FUN_a00f2c20(p, 0x39, 0);
        FUN_a00f2c20(p, 0x65, 0);
        FUN_a00f2c20(p, 0x80, 0xff);
    } else {
        FUN_a00f2c20(p, 0xcc, 2);
        t = (hi & 0xff) << 4;
        FUN_a00f2c20(p, 0x10, lo | t);
        FUN_a00f2c20(p, 0x11, 0x1e);
        FUN_a00f2c20(p, 0x12, 1);
        FUN_a00f2c20(p, 0x30, 0x47);
        FUN_a00f2c20(p, 0x33, 0xf6);
        FUN_a00f2c20(p, 0x39, 0x10);
        FUN_a00f2c20(p, 0x60, 0x1c);
        FUN_a00f2c20(p, 0x19, 0x12);
        FUN_a00f2c20(p, 0x60, 0x5e);
        FUN_a00f2c20(p, 0x64, 0x21);
        FUN_a00f2c20(p, 0x65, 0);
        FUN_a00f2c20(p, 0x80, 0xff);
        for (i = 0; i <= 0xf; i++)
            FUN_a00f2c20(p, i + 0x40, DAT_001a3060[i]);
    }
    FUN_a00f2ca8(p, 0x30, 4, 0);
    x = R(0xcf03d024);
    R(0xcf03d024) = 0xc;
    R(0xcf01d858) = 0xff;
    R(0xcf03d024) = 0xf;
    base = 0x7600;
    R(0xcf000000 | ((base + 0x50) << 2)) = 2;
    R(0xcf03d024) = x & 0xff;
}

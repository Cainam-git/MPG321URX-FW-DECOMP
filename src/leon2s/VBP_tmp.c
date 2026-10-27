/* VBP_tmp (leon2s 0xa00a53b0-0xa00a5cb4, 2308 bytes), flags -mcpu=v8 -Os -g.
 * (u8 port, struct Out *d, u8 flag), void; called by FUN_a00a4880 (flag 0) and FUN_a00a5cb4 (flag 1). The
 * reverse of FUN_a00a5d8c: packs the 80-byte record d field by field into the register words of the block
 * regs = word 2 of the 12-byte record DAT_a807dc04[port] (volatile; every field write reads its word again).
 * Word 0x1c: bits 16..29 = (d->h14 >> 3) & 0x3fff, bits 0..13 = 0x3fff. vbp = 5; with flag 0:
 * clk = FUN_a00a535c(d->h14, d->h4a, d->h48), vbp = d->h4c, prints "DSC VBP_tmp %ld", and when
 * diff = d->h10 - d->h24 - vbp is at most 4 prints the "[WARNING] V front porch" line with diff, "equal to"
 * (diff == 4) or "less than", and 4; then FUN_a00a4ec4(0, clk / 1000).
 * Then words 0x10, 0x14, 0x18, 0x20, 0x24, 0x28, 0x2c, 0x40, 0x44, 0x48 from the fields read by
 * FUN_a00a5d8c (14-bit halves, 3-bit fields, bytes, 2-bit fields; word 0x14 bit 5 is set when d->b0c is 0),
 * with word 0x20 bits 16..29 = d->h18 >> 3, 0x28 bits 0..13 = d->h20 >> 3, 0x24 bits 16..29 = vbp + 3 and
 * 0x40 bits 16..29 = vbp + 4, 0x24 / 0x40 bits 0..13 = d->h38.
 * Source forms: single bits are set with |= and cleared through the volatile local mask (the firmware stores
 * the bit to its stack slot and reads it back before each clear, as in FUN_a00a4880); the register pointer is
 * named in every statement (re-read after each if / else join); the record fields are read where they are
 * used (code hoisting moves the loads after the bit-3 test into the block of that test).
 */
struct Out {
    unsigned short h00;
    unsigned short h02;
    unsigned char b04;
    unsigned char b05;
    unsigned char b06;
    unsigned char b07;
    unsigned char b08;
    unsigned char b09;
    unsigned char b0a;
    unsigned char b0b;
    unsigned char b0c;
    unsigned char b0d;
    unsigned char b0e;
    unsigned char b0f;
    unsigned short h10;
    unsigned char b12;
    unsigned char b13;
    unsigned short h14;
    unsigned short h16;
    unsigned short h18;
    unsigned short h1a;
    unsigned short h1c;
    unsigned short h1e;
    unsigned short h20;
    unsigned short h22;
    unsigned short h24;
    unsigned short h26;
    unsigned short h28;
    unsigned short h2a;
    unsigned short h2c;
    unsigned short h2e;
    unsigned short h30;
    unsigned char b32;
    unsigned char b33;
    unsigned short h34;
    unsigned short h36;
    unsigned short h38;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char b3c;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
    unsigned char b40;
    unsigned char _41[3];
    unsigned int w44;
    unsigned short h48;
    unsigned short h4a;
    unsigned short h4c;
    unsigned char _4e[2];
};

struct rec12 { unsigned int w0; unsigned int w4; volatile unsigned int *regs; };
extern struct rec12 DAT_a807dc04[];
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00a535c(unsigned short, unsigned short, int);
extern void FUN_a00a4ec4(unsigned char, unsigned short);

#define R(i) DAT_a807dc04[port].regs[(i) / 4]
#define BIT(i, b, c) if (c) R(i) |= (b); else { mask = (b); R(i) &= ~mask; }

void VBP_tmp(unsigned char port, struct Out *d, unsigned char flag)
{
    volatile unsigned int mask;
    unsigned short n = d->h14;
    unsigned int vbp;
    unsigned int diff;
    unsigned int clk;

    R(0x1c) = (R(0x1c) & 0xc000ffff) | (((n >> 3) & 0x3fff) << 16);
    R(0x1c) = (R(0x1c) & 0xffffc000) | 0x3fff;
    vbp = 5;
    if (flag == 0) {
        clk = FUN_a00a535c(n, d->h4a, d->h48);
        vbp = d->h4c;
        FUN_a0073044("DSC VBP_tmp %ld\r\n", vbp);
        diff = d->h10 - d->h24 - vbp;
        if (diff <= 4)
            FUN_a0073044("\033[31;1m[WARNING] V front porch (= %ld) is %s DSC decode required delay lines, VFP should be greater than %d lines\n",
                         diff, diff == 4 ? "equal to" : "less than", 4);
        FUN_a00a4ec4(0, clk / 1000);
    }
    R(0x10) = (R(0x10) & 0xc000ffff) | ((d->h00 & 0x3fff) << 16);
    R(0x10) = (R(0x10) & 0xffffc000) | (d->h02 & 0x3fff);
    R(0x14) = (R(0x14) & 0x8fffffff) | ((d->b04 & 7) << 28);
    R(0x14) = (R(0x14) & 0xf8ffffff) | (d->b05 << 24);
    R(0x14) = (R(0x14) & 0xff00ffff) | (d->b06 << 16);
    BIT(0x14, 0x800, d->b07);
    BIT(0x14, 0x400, d->b08);
    BIT(0x14, 0x100, d->b09);
    BIT(0x14, 0x80, d->b0a);
    BIT(0x14, 0x40, d->b0b);
    if (d->b0c) { mask = 0x20; R(0x14) &= ~mask; } else R(0x14) |= 0x20;
    BIT(0x14, 0x10, d->b0d);
    BIT(0x14, 8, d->b0e);
    R(0x14) = (R(0x14) & ~3) | (d->b0f & 3);
    R(0x18) = (R(0x18) & 0xc000ffff) | 0x3fff0000;
    R(0x18) = (R(0x18) & 0xffff00ff) | (d->b12 << 8);
    R(0x18) = (R(0x18) & ~0x30) | ((d->b13 & 3) << 4);
    R(0x20) = (R(0x20) & 0xc000ffff) | (((d->h18 >> 3) & 0x3fff) << 16);
    R(0x20) = (R(0x20) & 0xffffc000) | (d->h1a & 0x3fff);
    R(0x24) = (R(0x24) & 0xffffc000) | (d->h38 & 0x3fff);
    R(0x24) = (R(0x24) & 0xc000ffff) | (((vbp + 3) & 0x3fff) << 16);
    R(0x28) = (R(0x28) & 0xffffc000) | ((d->h20 >> 3) & 0x3fff);
    R(0x2c) = (R(0x2c) & 0xf000ffff) | ((d->h22 & 0xfff) << 16);
    R(0x2c) = (R(0x2c) & 0xffffc000) | (d->h24 & 0x3fff);
    R(0x40) = (R(0x40) & 0xffffc000) | (d->h38 & 0x3fff);
    R(0x40) = (R(0x40) & 0xc000ffff) | (((vbp + 4) & 0x3fff) << 16);
    BIT(0x44, 0x40, d->b3a);
    BIT(0x44, 0x20, d->b3b);
    BIT(0x44, 0x10, d->b3c);
    BIT(0x44, 8, d->b3d);
    BIT(0x44, 4, d->b3e);
    R(0x44) = (R(0x44) & ~3) | (d->b3f & 3);
    BIT(0x48, 0x80000000, d->b40);
    R(0x48) = (R(0x48) & 0xfe000000) | (d->w44 & 0x1ffffff);
}

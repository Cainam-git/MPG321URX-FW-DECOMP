/* leon2m FUN_a0151358 @ 0xa0151358-0xa0151494 (79 words), flags -mcpu=v8 -O3 -g.
 * Sets the default values of the record DAT_a802e3d0: in word +0 bits 31, 30, 29, 28, 26, 24, 23, 22, 19 and 18
 * cleared and bits 27, 25 and 21 set; in word +4 the 4-bit fields at bits 28..31, 24..27 and 20..23 cleared;
 * bytes +3, +6, +7, +0x0b, +0x18, +0x1c, +0x1d, +0x22, +0x23, +0x30..+0x32, +0x34 and the halfword +0x36 cleared;
 * byte +8 = 0x64, bytes +9 and +0x0c..+0x11 = 0x32, bytes +0x0a and +0x12..+0x17 = 0x80, bytes +0x2e, +0x2f and
 * +0x33 = 1. No direct caller found. Leaf function, no return value.
 * Source form: one assignment per field. The order of the assignments decides the store order and the register
 * choice after both scheduling passes (sched1 moves the last store of each constant to the front), so the
 * statements stand in the order that gives the firmware bytes; the word +0 bit order and the word +4 field order
 * (f28, f20, f24) are fixed by the bit masks in the code.
 */
struct E3 {
    unsigned int w31:1, w30:1, w29:1, w28:1, w27:1, w26:1, w25:1, w24:1, w23:1, w22:1, w21:1, w20:1, w19:1, w18:1,
        r0:10;
    unsigned char b03;
    unsigned int f28:4, f24:4, f20:4, f16:4;
    unsigned char b06, b07;
    unsigned char b08, b09, b0a, b0b, b0c, b0d, b0e, b0f, b10, b11, b12, b13, b14, b15, b16, b17, b18;
    unsigned char p19[3];
    unsigned char b1c, b1d;
    unsigned char p1e[4];
    unsigned char b22, b23;
    unsigned char p24[10];
    unsigned char b2e, b2f, c30, c31, b32, b33, b34;
    unsigned char p35;
    unsigned short h36;
};
extern struct E3 DAT_a802e3d0;

void FUN_a0151358(void)
{
    DAT_a802e3d0.w31 = 0;
    DAT_a802e3d0.w29 = 0;
    DAT_a802e3d0.w25 = 1;
    DAT_a802e3d0.b09 = 0x32;
    DAT_a802e3d0.w24 = 0;
    DAT_a802e3d0.w23 = 0;
    DAT_a802e3d0.b07 = 0;
    DAT_a802e3d0.w28 = 0;
    DAT_a802e3d0.w27 = 1;
    DAT_a802e3d0.b2e = 1;
    DAT_a802e3d0.b2f = 1;
    DAT_a802e3d0.b08 = 0x64;
    DAT_a802e3d0.w26 = 0;
    DAT_a802e3d0.b0b = 0;
    DAT_a802e3d0.w22 = 0;
    DAT_a802e3d0.f28 = 0;
    DAT_a802e3d0.w30 = 0;
    DAT_a802e3d0.b18 = 0;
    DAT_a802e3d0.b0a = 0x80;
    DAT_a802e3d0.w21 = 1;
    DAT_a802e3d0.b1c = 0;
    DAT_a802e3d0.w19 = 0;
    DAT_a802e3d0.b0e = 0x32;
    DAT_a802e3d0.b11 = 0x32;
    DAT_a802e3d0.b06 = 0;
    DAT_a802e3d0.f20 = 0;
    DAT_a802e3d0.b0d = 0x32;
    DAT_a802e3d0.b1d = 0;
    DAT_a802e3d0.b10 = 0x32;
    DAT_a802e3d0.b03 = 0;
    DAT_a802e3d0.b0c = 0x32;
    DAT_a802e3d0.b12 = 0x80;
    DAT_a802e3d0.b13 = 0x80;
    DAT_a802e3d0.b14 = 0x80;
    DAT_a802e3d0.b15 = 0x80;
    DAT_a802e3d0.b16 = 0x80;
    DAT_a802e3d0.b22 = 0;
    DAT_a802e3d0.b23 = 0;
    DAT_a802e3d0.f24 = 0;
    DAT_a802e3d0.b0f = 0x32;
    DAT_a802e3d0.b17 = 0x80;
    DAT_a802e3d0.c30 = 0;
    DAT_a802e3d0.c31 = 0;
    DAT_a802e3d0.b32 = 0;
    DAT_a802e3d0.b33 = 1;
    DAT_a802e3d0.w18 = 0;
    DAT_a802e3d0.b34 = 0;
    DAT_a802e3d0.h36 = 0;
}

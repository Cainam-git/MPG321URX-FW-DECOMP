/* FUN_a00a507c (leon2s 0xa00a507c-0xa00a5148, 204 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Fills a 0x48-byte record with fixed values; called by FUN_a00a5cb4. The first
 * argument is unused. Field names are their byte offsets; the gaps (0x26..0x35, 0x41..0x43) are not written.
 * The stores are written in ascending offset order; the scheduler groups the stores of each repeated
 * constant (1, 2, 0x8ca, 0x12) into the order seen in the firmware.
 */
struct cfg {
    unsigned short f00;
    unsigned short f02;
    unsigned char f04;
    unsigned char f05;
    unsigned char f06;
    unsigned char f07;
    unsigned char f08;
    unsigned char f09;
    unsigned char f0a;
    unsigned char f0b;
    unsigned char f0c;
    unsigned char f0d;
    unsigned char f0e;
    unsigned char f0f;
    unsigned short f10;
    unsigned char f12;
    unsigned char f13;
    unsigned short f14;
    unsigned short f16;
    unsigned short f18;
    unsigned short f1a;
    unsigned short f1c;
    unsigned short f1e;
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;
    unsigned char pad_26[0x10];
    unsigned short f36;
    unsigned short f38;
    unsigned char f3a;
    unsigned char f3b;
    unsigned char f3c;
    unsigned char f3d;
    unsigned char f3e;
    unsigned char f3f;
    unsigned char f40;
    unsigned char pad_41[0x3];
    unsigned int f44;
};

void FUN_a00a507c(unsigned int a, struct cfg *p)
{
    p->f00 = 0x0;
    p->f02 = 0x0;
    p->f04 = 0x1;
    p->f05 = 0x2;
    p->f06 = 0x0;
    p->f07 = 0x0;
    p->f08 = 0x0;
    p->f09 = 0x0;
    p->f0a = 0x0;
    p->f0b = 0x0;
    p->f0c = 0x1;
    p->f0d = 0x1;
    p->f0e = 0x1;
    p->f0f = 0x0;
    p->f10 = 0x8ca;
    p->f12 = 0x0;
    p->f13 = 0x0;
    p->f14 = 0x1130;
    p->f16 = 0x8ca;
    p->f18 = 0x5;
    p->f1a = 0xa;
    p->f1c = 0x55;
    p->f1e = 0x12;
    p->f20 = 0xf00;
    p->f22 = 0x4;
    p->f24 = 0x870;
    p->f36 = 0x56;
    p->f38 = 0x12;
    p->f3a = 0x0;
    p->f3b = 0x0;
    p->f3c = 0x0;
    p->f3d = 0x0;
    p->f3e = 0x0;
    p->f3f = 0x2;
    p->f40 = 0x0;
    p->f44 = 0x100;
}

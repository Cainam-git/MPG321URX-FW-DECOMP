/* leon2s FUN_a00cc1d4 @ 0xa00cc1d4-0xa00cc2f8, -mcpu=v8 -Os -g.
 * (u8 port), void. Uses the 24-byte record DAT_a8078bb0[port] (2-bit field st = bits 16..17 of word 0,
 * as in FUN_a00cb1d4). st = 1. st = 0 and return when (u8)FUN_a00c9798(port, &DAT_a807d250) != 0 or bit 3
 * of byte +1 of DAT_a807d250 is set. Otherwise FUN_a00c87e8(port, 0xc, 0x8000), DAT_a807d088[1..16] =
 * FUN_a00c7770(port, 0x12), DAT_a807d088[0] = 0xf, FUN_a00c80f0(port, DAT_a807d088, 0x74, 0x60, 0x11);
 * then word +0x10 of the record is incremented, and st = 2 when bit 21 of word 0 is set.
 * Source form: bit-fields of word 0; GCC keeps the field mask 0xfffcffff in a register for the first
 * stores. The FUN_a00c80f0 prototype (u8, u8 *, u8, u8, u16) decides the argument set-up order.
 */
struct Rec24 {
    unsigned int top : 4;
    unsigned int cnt : 4;
    unsigned int m22 : 2;
    unsigned int f21 : 1;
    unsigned int m18 : 3;
    unsigned int st : 2;
    unsigned int low : 16;
    unsigned int w4;
    unsigned int w8;
    unsigned int wc;
    unsigned int n10;
    unsigned int w14;
};
struct D250 { unsigned char lo; unsigned char hi; };
extern struct Rec24 DAT_a8078bb0[];
extern struct D250 DAT_a807d250;
extern unsigned char DAT_a807d088[];
extern unsigned int FUN_a00c9798(unsigned char, struct D250 *);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern unsigned char FUN_a00c7770(unsigned char, unsigned char);
extern int FUN_a00c80f0(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

void FUN_a00cc1d4(unsigned char port)
{
    unsigned char i;

    DAT_a8078bb0[port].st = 1;
    if ((unsigned char)FUN_a00c9798(port, &DAT_a807d250) != 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if (DAT_a807d250.hi & 8) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    FUN_a00c87e8(port, 0xc, 0x8000);
    for (i = 0; i < 0x10; i++)
        DAT_a807d088[1 + i] = FUN_a00c7770(port, 0x12);
    DAT_a807d088[0] = 0xf;
    FUN_a00c80f0(port, DAT_a807d088, 0x74, 0x60, 0x11);
    DAT_a8078bb0[port].n10++;
    if (DAT_a8078bb0[port].f21)
        DAT_a8078bb0[port].st = 2;
}

/* FUN_a00cdcdc (leon2s 0xa00cdcdc-0xa00cdde0, 260 bytes), flags -mcpu=v8 -Os -g.
 * Works on the 24-byte record DAT_a8078bb0[port] (big-endian bit-fields of word 0 as in FUN_a00c91f8, with
 * bit 19 as its own field f19; byte +9 is passed to the callees). Sets st (bits 16..17) to 1. When f19 is 0:
 * calls FUN_a00c9e44(byte +9) and compares the 32 bytes DAT_a807d088[] with DAT_a807cd88[]; at the first
 * difference st = 0 and FUN_a00c79c8(port) is tail-called. Otherwise (f19 set or all bytes equal) sets
 * f19 = 1 and calls FUN_a00c9c98(byte +9, DAT_a807ce56, 0x400), FUN_a00c9b58(byte +9, 0x400) and
 * FUN_a00c9de8(byte +9, 0x400).
 */
struct Rec24 {
    unsigned int a:3;
    unsigned int f28:1;
    unsigned int cnt:4;
    unsigned int f23:1;
    unsigned int m20:3;
    unsigned int f19:1;
    unsigned int f18:1;
    unsigned int st:2;
    unsigned int x:8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char pad[14];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned char DAT_a807d088[];
extern unsigned char DAT_a807cd88[];
extern unsigned char DAT_a807ce56[];
extern void FUN_a00c9e44(unsigned char port);
extern void FUN_a00c9c98(unsigned char, unsigned char *, unsigned short);
extern void FUN_a00c9b58(unsigned char, unsigned short);
extern void FUN_a00c9de8(unsigned int, unsigned short);
extern void FUN_a00c79c8(unsigned char port);

void FUN_a00cdcdc(unsigned char port)
{
    unsigned char i;

    DAT_a8078bb0[port].st = 1;
    if (DAT_a8078bb0[port].f19 == 0) {
        FUN_a00c9e44(DAT_a8078bb0[port].b9);
        for (i = 0; i < 0x20; i++) {
            if (DAT_a807d088[i] != DAT_a807cd88[i]) {
                DAT_a8078bb0[port].st = 0;
                FUN_a00c79c8(port);
                return;
            }
        }
    }
    DAT_a8078bb0[port].f19 = 1;
    FUN_a00c9c98(DAT_a8078bb0[port].b9, DAT_a807ce56, 0x400);
    FUN_a00c9b58(DAT_a8078bb0[port].b9, 0x400);
    FUN_a00c9de8(DAT_a8078bb0[port].b9, 0x400);
}

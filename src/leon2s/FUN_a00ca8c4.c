/*
 * FUN_a00ca8c4 (leon2s, 0xa00ca8c4-0xa00cab10, 588 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (st = bits 16..17 of word 0, b19 = bit 19,
 * b9 = byte 9). Sets st = 1. FUN_a00c9798(port, DAT_a807d250) != 0 or bits 2..3 of DAT_a807d250[1] set: st = 0;
 * n = ((DAT_a807d250[1] & 3) << 8) + DAT_a807d250[0] (u16) == 0: st = 3; FUN_a00c8048(port, 0x74, 0x80, n)
 * != 0: st = 0. Then FUN_a00c9810(port, DAT_a807ce50, n); DAT_a807ce50[0] != 3: st = 0. Otherwise counts
 * empty u16 loops of 0x8a, 0x180 and 0xb steps, copies DAT_a807ce50[1..5] to DAT_a807ce38[port * 5 ..],
 * an empty loop of 0x80 steps, copies DAT_a807ce50[0x86..0x88] to DAT_a807ce48[0..2], an empty loop of 2
 * steps; when b19 is clear, FUN_a00c99a4(b9, DAT_a807cf08, 0, 0, 0xc00) and FUN_a00ca4e8(&DAT_a807ce50[1]).
 * Same record and buffers as FUN_a00cb56c.
 */
struct Rec18 {
    unsigned int b31 : 1;
    unsigned int b30 : 1;
    unsigned int b29 : 1;
    unsigned int b28 : 1;
    unsigned int f24 : 4;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int b20 : 1;
    unsigned int b19 : 1;
    unsigned int b18 : 1;
    unsigned int st : 2;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char pad_a[6];
    unsigned int w10;
    unsigned char pad_14[4];
};
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a807d250[];
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807ce38[];
extern unsigned char DAT_a807ce48[];
extern unsigned char DAT_a807cf08[];
extern unsigned char FUN_a00c9798(unsigned char, unsigned char *);
extern unsigned char FUN_a00c8048(unsigned char, unsigned char, unsigned char, unsigned short);
extern void FUN_a00c9810(unsigned char, unsigned char *, unsigned short);
extern void FUN_a00c99a4(unsigned int, unsigned char *, unsigned char, unsigned char, unsigned short);
extern void FUN_a00ca4e8(unsigned char *);

void FUN_a00ca8c4(unsigned char port)
{
    unsigned char hi;
    unsigned short n;
    unsigned short k;

    DAT_a8078bb0[port].st = 1;
    if (FUN_a00c9798(port, DAT_a807d250)) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    hi = DAT_a807d250[1];
    n = ((hi & 3) << 8) + DAT_a807d250[0];
    if (hi & 0xc) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if (n == 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (FUN_a00c8048(port, 0x74, 0x80, n)) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    FUN_a00c9810(port, DAT_a807ce50, n);
    if (DAT_a807ce50[0] != 3) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    for (k = 0; k < 0x8a; k++)
        ;
    for (k = 0; k < 0x180; k++)
        ;
    for (k = 0; k < 0xb; k++)
        ;
    for (k = 0; k < 5; k++)
        DAT_a807ce38[port * 5 + k] = DAT_a807ce50[k + 1];
    for (k = 0; k < 0x80; k++)
        ;
    for (k = 0; k < 3; k++)
        DAT_a807ce48[k] = DAT_a807ce50[k + 0x86];
    for (k = 0; k < 2; k++)
        ;
    if (!DAT_a8078bb0[port].b19) {
        FUN_a00c99a4(DAT_a8078bb0[port].b9, DAT_a807cf08, 0, 0, 0xc00);
        FUN_a00ca4e8(&DAT_a807ce50[1]);
    }
}

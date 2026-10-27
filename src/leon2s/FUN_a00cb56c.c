/*
 * FUN_a00cb56c (leon2s, 0xa00cb56c-0xa00cb7a0, 564 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (st = bits 16..17 of word 0). Sets st = 1.
 * FUN_a00c9798(port, DAT_a807d250) != 0 or bits 2..3 of DAT_a807d250[1] set: st = 0;
 * ((DAT_a807d250[1] & 3) << 8) + DAT_a807d250[0] == 0 (u16): st = 3. Otherwise FUN_a00c87e8(port, 9, 0x8000)
 * and 32 bytes DAT_a807d088[i] = (u8)FUN_a00c7770(port, 1); FUN_a00c8048(port, 0x74, 0x80, 0x21) or
 * FUN_a00c81f8(port, DAT_a807ce50, 0x21) != 0: st = 0. Otherwise copies DAT_a807ce50[1..32] to
 * DAT_a807cd88[0..31], sets st = 1, and st = 2 at the first i where DAT_a807d088[i] != DAT_a807cd88[i].
 * Both 32-byte loops call func_0xa0f83044 with the address 0x9f1cee88 (0xF10000 below the string "\n " at
 * 0xa00dee88, the link offset of this code) when i % 16 == 0. Same record and buffers as FUN_a00caf78.
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
extern unsigned char DAT_a807cd88[];
extern unsigned char DAT_a807d088[];
extern unsigned char FUN_a00c9798(unsigned char, unsigned char *);
extern void FUN_a00c87e8(unsigned char, int, unsigned short);
extern int FUN_a00c7770(unsigned char, int);
extern unsigned char FUN_a00c8048(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a00c81f8(unsigned char, unsigned char *, unsigned char);
extern int func_0xa0f83044(const char *, ...);

void FUN_a00cb56c(unsigned char port)
{
    unsigned char hi;
    unsigned short n;
    unsigned char i;

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
    FUN_a00c87e8(port, 9, 0x8000);
    for (i = 0; i < 0x20; i++) {
        if ((i & 0xf) == 0)
            func_0xa0f83044((const char *)0x9f1cee88);
        DAT_a807d088[i] = FUN_a00c7770(port, 1);
    }
    if (FUN_a00c8048(port, 0x74, 0x80, 0x21) || FUN_a00c81f8(port, DAT_a807ce50, 0x21)) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    for (i = 0; i < 0x20; i++) {
        if ((i & 0xf) == 0)
            func_0xa0f83044((const char *)0x9f1cee88);
        DAT_a807cd88[i] = DAT_a807ce50[i + 1];
    }
    DAT_a8078bb0[port].st = 1;
    for (i = 0; i < 0x20; i++) {
        if (DAT_a807d088[i] != DAT_a807cd88[i]) {
            DAT_a8078bb0[port].st = 2;
            return;
        }
    }
}

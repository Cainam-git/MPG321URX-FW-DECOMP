/*
 * FUN_a00cc2f8 (leon2s, 0xa00cc2f8-0xa00cc5f8, 768 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (layout of FUN_a00c7a4c: bits 28, 22 and
 * st = bits 16..17 of word 0, counter word +0x10). Bit 22 clear: st = 3. FUN_a00c9798(port, DAT_a807d250)
 * != 0: st = 0. With hi = DAT_a807d250[1]: bits 2..3 of hi set: st = 0; ((hi & 3) << 8) + DAT_a807d250[0]
 * != 0: st = 3. Otherwise, with bit 28 set: register 6 = 0x90, FUN_a00c87e8(port, 0xd, 0x8000), register 1
 * gets bytes 2, 1, 0 of the counter word, 0, 1, 0, 0, the counter bytes again and 0x80
 * (FUN_a00c7654(port, reg, v)); the counter is incremented; waits until bit 7 of FUN_a00c7770(port, 6)
 * reads 0; FUN_a00c87e8(port, 0x10, 0x4020) and prints 32 bytes of register 0x12 with
 * func_0xa0f83044(s_9f1cca30, v); FUN_a00c87e8(port, 0, 0); register 6 = 0xf0 and the same wait;
 * FUN_a00c87e8(port, 0xd, 0x8000), 7 bytes of register 1 stored to DAT_a807ce50[1..7] and printed;
 * DAT_a807ce50[0] = 0x10; FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 8); st = 1.
 * Source forms: the read loop stores the call result straight into DAT_a807ce50[i + 1] and prints that
 * element (the element address is computed before the call).
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
extern const char s_9f1cca30[];
extern unsigned char FUN_a00c9798(unsigned char, unsigned char *);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern int FUN_a00c80f0(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);
extern int func_0xa0f83044(const char *, ...);

void FUN_a00cc2f8(unsigned char port)
{
    unsigned char hi;
    unsigned short n;
    unsigned char i;

    if (DAT_a8078bb0[port].b22 == 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
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
    if (n != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (DAT_a8078bb0[port].b28 == 0)
        return;
    FUN_a00c7654(port, 6, 0x90);
    FUN_a00c87e8(port, 0xd, 0x8000);
    for (i = 0; i < 3; i++)
        FUN_a00c7654(port, 1, DAT_a8078bb0[port].w10 >> ((2 - i) * 8));
    FUN_a00c7654(port, 1, 0);
    FUN_a00c7654(port, 1, 1);
    FUN_a00c7654(port, 1, 0);
    FUN_a00c7654(port, 1, 0);
    for (i = 0; i < 3; i++)
        FUN_a00c7654(port, 1, DAT_a8078bb0[port].w10 >> ((2 - i) * 8));
    FUN_a00c7654(port, 1, 0x80);
    DAT_a8078bb0[port].w10++;
    while (FUN_a00c7770(port, 6) & 0x80)
        ;
    FUN_a00c87e8(port, 0x10, 0x4020);
    for (i = 0; i < 0x20; i++)
        func_0xa0f83044(s_9f1cca30, FUN_a00c7770(port, 0x12));
    FUN_a00c87e8(port, 0, 0);
    FUN_a00c7654(port, 6, 0xf0);
    while (FUN_a00c7770(port, 6) & 0x80)
        ;
    FUN_a00c87e8(port, 0xd, 0x8000);
    for (i = 0; i < 7; i++) {
        DAT_a807ce50[i + 1] = FUN_a00c7770(port, 1);
        func_0xa0f83044(s_9f1cca30, DAT_a807ce50[i + 1]);
    }
    DAT_a807ce50[0] = 0x10;
    FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 8);
    DAT_a8078bb0[port].st = 1;
}

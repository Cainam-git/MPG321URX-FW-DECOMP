/*
 * FUN_a00cec18 (leon2s, 0xa00cec18-0xa00cef6c, 852 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (bit-fields as in FUN_a00c91f8: f28,
 * f23, st = bits 16..17; bytes +3..+8). Sets st = 1; fills a 24-byte stack buffer with 0..7 three times,
 * FUN_a00c87e8(port, 0x11, 0x8000) and writes the 24 bytes to register 1 (FUN_a00c7654(port, 1, v));
 * register 6 = 10 and waits until bit 3 of FUN_a00c7770(port, 6) reads 0; FUN_a00c87e8(port, 10, 0x8000)
 * and reads 16 bytes with FUN_a00c7770(port, 1) into the buffer; func_0xa0f963d4(0, 0x80, 0x69318, 0xf,
 * buf) and (0, 0x80, 0x69328, 7, buf + 16). With f28 set: st = 2. With f28 clear: f23 = 0;
 * FUN_a00c87e8(port, 0xb, 0x8000); register 1 gets 0xb6 zero bytes, 2, 0x10 and three zeros;
 * FUN_a00c87e8(port, 0xb, 0x4015); the 5 bytes of row port of DAT_a807ce38, 2, 0x10, three zeros, 0x80;
 * bytes +3, +4 = 1, +5..+8 = 0; FUN_a00c87e8(port, 0, 0x8000); buffer byte 0 = 0;
 * func_0xa0f96360(0, 0x80, 0x69494, 0); st = 1.
 * Source forms: unsigned short loop counters; the fill loop stores buf[i], buf[i + 8], buf[i + 16];
 * func_0xa0f963d4 returns int (the void form moves the first argument out of the call delay slot).
 */
struct Rec24 {
    unsigned int a : 3;
    unsigned int f28 : 1;
    unsigned int cnt : 4;
    unsigned int f23 : 1;
    unsigned int mid : 5;
    unsigned int st : 2;
    unsigned int x : 8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char pad[15];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807ce38[][5];
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);
extern void FUN_a00c76c0(unsigned char, unsigned short, unsigned char, unsigned char);
extern int FUN_a00c80f0(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

extern int func_0xa0f963d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int func_0xa0f96360(int, int, int, int);

void FUN_a00cec18(unsigned char port)
{
    unsigned char buf[24];
    unsigned short i;

    DAT_a8078bb0[port].st = 1;
    for (i = 0; i < 8; i++) {
        buf[i] = i;
        buf[i + 8] = i;
        buf[i + 16] = i;
    }
    FUN_a00c87e8(port, 0x11, 0x8000);
    for (i = 0; i < 0x18; i++)
        FUN_a00c7654(port, 1, buf[i]);
    FUN_a00c7654(port, 6, 10);
    while (FUN_a00c7770(port, 6) & 8)
        ;
    FUN_a00c87e8(port, 10, 0x8000);
    for (i = 0; i < 16; i++)
        buf[i] = FUN_a00c7770(port, 1);
    func_0xa0f963d4(0, 0x80, 0x69318, 0xf, buf);
    func_0xa0f963d4(0, 0x80, 0x69328, 7, buf + 16);
    if (DAT_a8078bb0[port].f28 == 0) {
        DAT_a8078bb0[port].f23 = 0;
        FUN_a00c87e8(port, 0xb, 0x8000);
        for (i = 0; i < 0xb6; i++)
            FUN_a00c7654(port, 1, 0);
        FUN_a00c7654(port, 1, 2);
        FUN_a00c7654(port, 1, 0x10);
        for (i = 0; i < 3; i++)
            FUN_a00c7654(port, 1, 0);
        FUN_a00c87e8(port, 0xb, 0x4015);
        for (i = 0; i < 5; i++)
            FUN_a00c7654(port, 1, DAT_a807ce38[port][i]);
        FUN_a00c7654(port, 1, 2);
        FUN_a00c7654(port, 1, 0x10);
        for (i = 0; i < 3; i++)
            FUN_a00c7654(port, 1, 0);
        FUN_a00c7654(port, 1, 0x80);
        DAT_a8078bb0[port].b3 = 1;
        DAT_a8078bb0[port].b4 = 1;
        DAT_a8078bb0[port].b5 = 0;
        DAT_a8078bb0[port].b6 = 0;
        DAT_a8078bb0[port].b7 = 0;
        DAT_a8078bb0[port].b8 = 0;
        FUN_a00c87e8(port, 0, 0x8000);
        buf[0] = 0;
        func_0xa0f96360(0, 0x80, 0x69494, 0);
        DAT_a8078bb0[port].st = 1;
    } else
        DAT_a8078bb0[port].st = 2;
}

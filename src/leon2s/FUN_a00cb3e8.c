/* leon2s FUN_a00cb3e8 @ 0xa00cb3e8-0xa00cb56c, -mcpu=v8 -Os -g.
 * (u8 port), void. Record DAT_a8078bb0[port] (24 bytes; st = bits 16..17, b9 = byte +9; layout of
 * FUN_a00cb1d4). st = 1. When DAT_a807d636 == port: b9 = 0xff, DAT_a807d636 = 0xff and func_0xa0f83044 with the
 * ROM address 0x9f1c2158. DAT_a807ce50[0..8] = 9, 1, 2, .. 8; FUN_a00c87e8(port, 8, 0x8000); FUN_a00c7654(port,
 * 1, DAT_a807ce50[1 + i]) for i = 0..7; FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 9); FUN_a00c7654(port, 5, 3)
 * and (port, 6, 0xd0). Then polls bit 7 of FUN_a00c7770(port, 6) with a u8 counter from 0xff; st = 0 when the
 * counter reaches 0 while the bit is still set.
 */
struct Rec24 {
    unsigned int top : 4;
    unsigned int cnt : 4;
    unsigned int mid : 6;
    unsigned int st : 2;
    unsigned int low : 16;
    unsigned char b4[5];
    unsigned char b9;
    unsigned char rest[14];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned char DAT_a807d636;
extern unsigned char DAT_a807ce50[];
extern int func_0xa0f83044(const char *, ...);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);
extern int FUN_a00c80f0(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

void FUN_a00cb3e8(unsigned char port)
{
    unsigned char i, t;

    DAT_a8078bb0[port].st = 1;
    if (DAT_a807d636 == port) {
        DAT_a8078bb0[port].b9 = 0xff;
        DAT_a807d636 = 0xff;
        func_0xa0f83044((const char *)0x9f1c2158);
    }
    DAT_a807ce50[0] = 9;
    DAT_a807ce50[1] = 1;
    DAT_a807ce50[2] = 2;
    DAT_a807ce50[3] = 3;
    DAT_a807ce50[4] = 4;
    DAT_a807ce50[5] = 5;
    DAT_a807ce50[6] = 6;
    DAT_a807ce50[7] = 7;
    DAT_a807ce50[8] = 8;
    FUN_a00c87e8(port, 8, 0x8000);
    for (i = 0; i <= 7; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[1 + i]);
    FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 9);
    FUN_a00c7654(port, 5, 3);
    FUN_a00c7654(port, 6, 0xd0);
    t = 0xff;
    while (FUN_a00c7770(port, 6) & 0x80) {
        t--;
        if (t == 0) {
            DAT_a8078bb0[port].st = 0;
            break;
        }
    }
}

/*
 * FUN_a00d0550 (leon2s, 0xa00d0550-0xa00d0798, 584 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (st = bits 16..17 of word 0, b9 = byte 9,
 * words at offsets 0xc and 0x10). FUN_a00cfb20(10) != 0, or DAT_a807d636 neither 0xff nor port: st = 3.
 * Otherwise b9 = 3, both words = 0, DAT_a807d636 = port, clears bits 0..1 of the register 0xcf018d00,
 * FUN_a00c7654(port, 4, 0x17), func_0xa0fc160c(1), FUN_a00c7654(port, 4, 0x11), FUN_a00c87e8(port, 0x11,
 * 0x8000); then FUN_a00c7654(port, 1, v) for 24 zero bytes and for the 16 bytes DAT_a807d638[0..15] (u16
 * counters); DAT_a807ce50[0..10] = {1, 2, 3, 4, 5, 6, 7, 8, 2, 0, 0}; FUN_a00c87e8(port, 1, 0x8000);
 * FUN_a00c7654(port, 1, DAT_a807ce50[k]) for k = 0..10; func_0xa0f963d4(0, 0x80, 0x69000, 0xa, DAT_a807ce50);
 * st = 1 and a tail call FUN_a00d0530(10, 100).
 * Source form: the DAT_a807d636 test is an if/else whose else arm sets st = 3 and returns.
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
    unsigned char pad_a[2];
    unsigned int w0c;
    unsigned int w10;
    unsigned char pad_14[4];
};
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a807d636;
extern unsigned char DAT_a807d638[];
extern unsigned char DAT_a807ce50[];
extern unsigned int FUN_a00cfb20(int);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void func_0xa0fc160c(unsigned int);
extern int func_0xa0f963d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int FUN_a00d0530(int, int);

#define REG_CF018D00 (*(volatile unsigned int *)0xcf018d00)

void FUN_a00d0550(unsigned char port)
{
    unsigned short k;

    if (FUN_a00cfb20(10) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (DAT_a807d636 == 0xff || DAT_a807d636 == port) {
        DAT_a8078bb0[port].b9 = 3;
        DAT_a8078bb0[port].w0c = 0;
        DAT_a8078bb0[port].w10 = 0;
        DAT_a807d636 = port;
        REG_CF018D00 &= ~3;
        FUN_a00c7654(port, 4, 0x17);
        func_0xa0fc160c(1);
        FUN_a00c7654(port, 4, 0x11);
        FUN_a00c87e8(port, 0x11, 0x8000);
    } else {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    for (k = 0; k < 0x18; k++)
        FUN_a00c7654(port, 1, 0);
    for (k = 0; k < 0x10; k++)
        FUN_a00c7654(port, 1, DAT_a807d638[k]);
    DAT_a807ce50[0] = 1;
    DAT_a807ce50[1] = 2;
    DAT_a807ce50[2] = 3;
    DAT_a807ce50[3] = 4;
    DAT_a807ce50[4] = 5;
    DAT_a807ce50[5] = 6;
    DAT_a807ce50[6] = 7;
    DAT_a807ce50[7] = 8;
    DAT_a807ce50[8] = 2;
    DAT_a807ce50[9] = 0;
    DAT_a807ce50[0xa] = 0;
    FUN_a00c87e8(port, 1, 0x8000);
    for (k = 0; k <= 0xa; k++)
        FUN_a00c7654(port, 1, DAT_a807ce50[k]);
    func_0xa0f963d4(0, 0x80, 0x69000, 0xa, DAT_a807ce50);
    DAT_a8078bb0[port].st = 1;
    FUN_a00d0530(10, 100);
}

/* FUN_a00ccb04 (leon2s 0xa00ccb04-0xa00ccd20, 540 bytes, with the merged ret/restore tail), flags -mcpu=v8 -Os -g.
 * void (u8 port). r = DAT_a8078bb0[port] (24-byte records; word 0 bit-fields top:14, st:2, low:16; byte +9;
 * words +0xc, +0x10). Sets r.st = 1. When func_0xa0fc2064() < DAT_a807d0a8[port], or DAT_a807d636 is neither
 * 0xff nor port: r.st = 3 and returns. Otherwise: DAT_a807d636 = port, byte +9 = 3, word +0xc = 0,
 * FUN_a00ccad4(port), word +0x10 = 0, FUN_a00c7ccc(port, 1), FUN_a00c7654(port, 4, 7), func_0xa0fc1794(0x14),
 * FUN_a00c7654(port, 4, 1), (port, 5, 1), FUN_a00c87e8(port, 0x13, 0x8000); FUN_a00c7654(port, 1, b) for the
 * 16 bytes of DAT_a807d638; fills DAT_a807ce50[0..0xb] with 2 1 2 3 4 5 6 7 8 2 0 0; FUN_a00c87e8(port, 1,
 * 0x8000); FUN_a00c7654(port, 1, b) for DAT_a807ce50[1..0xb]; then r.st = 0 when bit 1 of
 * func_0xa0fb7fd8(port, 0, 9) is clear, else FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 0xc).
 * Source form: K&R parameter definition; the two conditions are nested ifs, each with its own
 * 'r.st = 3; return;' else arm; the DAT_a807ce50 stores in the order 1, 3..7, 0, 8, 2, 0xa, 9, 0xb.
 */
struct Rec24 {
    unsigned int top : 14;
    unsigned int st : 2;
    unsigned int low : 16;
    unsigned char b4[5];
    unsigned char b9;
    unsigned char pada[2];
    unsigned int wc;
    unsigned int w10;
    unsigned int w14;
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned int DAT_a807d0a8[];
extern unsigned char DAT_a807d636;
extern unsigned char DAT_a807d638[];
extern unsigned char DAT_a807ce50[];
extern unsigned int func_0xa0fc2064(void);
extern void func_0xa0fc1794(unsigned int);
extern unsigned char func_0xa0fb7fd8(unsigned char, int, unsigned short);
extern void FUN_a00ccad4(unsigned char);
extern void FUN_a00c7ccc(unsigned char, unsigned char);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern int FUN_a00c80f0(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

void FUN_a00ccb04(port)
    unsigned char port;
{
    unsigned char i;

    DAT_a8078bb0[port].st = 1;
    if (func_0xa0fc2064() >= DAT_a807d0a8[port]) {
        if (DAT_a807d636 == 0xff || DAT_a807d636 == port) {
            DAT_a807d636 = port;
            DAT_a8078bb0[port].b9 = 3;
            DAT_a8078bb0[port].wc = 0;
            FUN_a00ccad4(port);
            DAT_a8078bb0[port].w10 = 0;
            FUN_a00c7ccc(port, 1);
            FUN_a00c7654(port, 4, 7);
            func_0xa0fc1794(0x14);
            FUN_a00c7654(port, 4, 1);
            FUN_a00c7654(port, 5, 1);
            FUN_a00c87e8(port, 0x13, 0x8000);
        } else {
            DAT_a8078bb0[port].st = 3;
            return;
        }
    } else {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    for (i = 0; i <= 0xf; i++)
        FUN_a00c7654(port, 1, DAT_a807d638[i]);
    DAT_a807ce50[1] = 1;
    DAT_a807ce50[3] = 3;
    DAT_a807ce50[4] = 4;
    DAT_a807ce50[5] = 5;
    DAT_a807ce50[6] = 6;
    DAT_a807ce50[7] = 7;
    DAT_a807ce50[0] = 2;
    DAT_a807ce50[8] = 8;
    DAT_a807ce50[2] = 2;
    DAT_a807ce50[0xa] = 0;
    DAT_a807ce50[9] = 2;
    DAT_a807ce50[0xb] = 0;
    FUN_a00c87e8(port, 1, 0x8000);
    for (i = 0; i <= 0xa; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[1 + i]);
    if ((func_0xa0fb7fd8(port, 0, 9) & 2) == 0)
        DAT_a8078bb0[port].st = 0;
    else
        FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 0xc);
}

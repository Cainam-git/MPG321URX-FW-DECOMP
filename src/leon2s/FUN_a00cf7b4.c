/*
 * FUN_a00cf7b4 (leon2s, 0xa00cf7b4-0xa00cf954, 416 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (st = bits 16..17 of word 0, b22 = bit 22,
 * b14 = byte at offset 0x14). b22 clear: st = 3, return. Otherwise st = 1, func_0xa0f96400(0, 0x90, 0x69493,
 * 0, buf) and func_0xa0f963d4(0, 0x80, 0x693f0, 4, DAT_a807d088). Then for u8 i = 0, 8, 16, ... below b14
 * (re-read at each test): cnt = 8, or b14 - i when i + 8 > b14; copies the byte pairs DAT_a807ce50[2 * (i + k)]
 * and [2 * (i + k) + 1] to buf[2k], buf[2k + 1] for u16 k < cnt and calls func_0xa0f963d4(0, 0x80,
 * 0x693f5 + i * 16, (signed char)(2 * cnt - 1), buf). buf is a 16-byte local.
 * Source form: the base 0x693f5 sits in a local set before the loop (the firmware keeps it in a register).
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
    unsigned char b14;
    unsigned char pad_15[3];
};
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807d088[];
extern int func_0xa0f963d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int func_0xa0f96400(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);

void FUN_a00cf7b4(unsigned char port)
{
    unsigned char buf[16];
    unsigned char i;
    unsigned char cnt;
    unsigned short k;
    unsigned int a;

    if (!DAT_a8078bb0[port].b22) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    DAT_a8078bb0[port].st = 1;
    func_0xa0f96400(0, 0x90, 0x69493, 0, buf);
    func_0xa0f963d4(0, 0x80, 0x693f0, 4, DAT_a807d088);
    a = 0x693f5;
    for (i = 0; i < DAT_a8078bb0[port].b14; i += 8) {
        cnt = 8;
        if (i + 8 > DAT_a8078bb0[port].b14)
            cnt = DAT_a8078bb0[port].b14 - i;
        for (k = 0; k < cnt; k++) {
            buf[k * 2] = DAT_a807ce50[(k + i) * 2];
            buf[k * 2 + 1] = DAT_a807ce50[(k + i) * 2 + 1];
        }
        func_0xa0f963d4(0, 0x80, a + i * 16, (signed char)(k * 2 - 1), buf);
    }
}

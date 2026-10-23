/*
 * FUN_a00cab10 (leon2s, 0xa00cab10-0xa00cad8c, 636 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (layout of FUN_a00c7a4c: bits 29, 28,
 * 19 and st = bits 16..17 of word 0, byte +9). Sets st = 1. Bit 19 clear: FUN_a00c9e44(byte +9), then
 * when any of DAT_a807d088[0..31] differs from DAT_a807cf08[0x160..0x17f]: st = 0 and tail call
 * FUN_a00c79c8(port). Then bits 19 and 29 = 1; bit 29 = 0 when row port of DAT_a807cda8 differs from row
 * port of DAT_a807ce38 (5 bytes); the 5 bytes of DAT_a807ce38[port] go to registers 0x10..0x14 with
 * func_0xa0fb8054(port, 0, reg, v); FUN_a00c87e8(port, 3, 0x8000) and DAT_a807ce50[0x8b..0x95] to
 * register 1 (FUN_a00c7654(port, 1, v)). DAT_a807ce50[0x93] != 2: st = 0. Otherwise bit 28 = 1 when
 * DAT_a807ce50[0x95] == 1 (cleared first), then FUN_a00c9c98(byte +9, &DAT_a807ce50[6], 0x400),
 * FUN_a00c9b58(byte +9, 0x400) and tail call FUN_a00c9de8(byte +9, 0x400).
 * Source forms: the last test is written '!= 2' with the st = 0 arm first.
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
    unsigned char pad_a[14];
};
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a807d088[];
extern unsigned char DAT_a807cf08[];
extern unsigned char DAT_a807cda8[][5];
extern unsigned char DAT_a807ce38[][5];
extern unsigned char DAT_a807ce50[];
extern void FUN_a00c9e44(unsigned char);
extern void FUN_a00c79c8(unsigned char);
extern void func_0xa0fb8054(unsigned char, int, unsigned short, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern void FUN_a00c9c98(unsigned char, unsigned char *, unsigned short);
extern void FUN_a00c9b58(unsigned char, unsigned short);
extern void FUN_a00c9de8(unsigned char, unsigned short);

void FUN_a00cab10(unsigned char port)
{
    unsigned char i;

    DAT_a8078bb0[port].st = 1;
    if (DAT_a8078bb0[port].b19 == 0) {
        FUN_a00c9e44(DAT_a8078bb0[port].b9);
        for (i = 0; i < 0x20; i++) {
            if (DAT_a807d088[i] != DAT_a807cf08[i + 0x160]) {
                DAT_a8078bb0[port].st = 0;
                FUN_a00c79c8(port);
                return;
            }
        }
    }
    DAT_a8078bb0[port].b19 = 1;
    DAT_a8078bb0[port].b29 = 1;
    for (i = 0; i < 5; i++) {
        if (DAT_a807cda8[port][i] != DAT_a807ce38[port][i]) {
            DAT_a8078bb0[port].b29 = 0;
            break;
        }
    }
    for (i = 0; i < 5; i++)
        func_0xa0fb8054(port, 0, i + 0x10, DAT_a807ce38[port][i]);
    FUN_a00c87e8(port, 3, 0x8000);
    for (i = 0x8b; i < 0x96; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[i]);
    if (DAT_a807ce50[0x93] != 2)
        DAT_a8078bb0[port].st = 0;
    else {
        DAT_a8078bb0[port].b28 = 0;
        if (DAT_a807ce50[0x95] == 1)
            DAT_a8078bb0[port].b28 = 1;
        FUN_a00c9c98(DAT_a8078bb0[port].b9, &DAT_a807ce50[6], 0x400);
        FUN_a00c9b58(DAT_a8078bb0[port].b9, 0x400);
        FUN_a00c9de8(DAT_a8078bb0[port].b9, 0x400);
    }
}

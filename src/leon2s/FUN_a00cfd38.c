/*
 * FUN_a00cfd38 (leon2s, 0xa00cfd38-0xa00d00e0, 936 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (layout of FUN_a00c7a4c: bits 29, 28,
 * 19 and st = bits 16..17 of word 0, byte +9). FUN_a00cfb20(10) != 0: st = 3, return. Otherwise st = 1 and
 * blocks are read with func_0xa0f96400(0, 0x90, addr, len, buf) into a 16-byte stack buffer:
 * - 0x6900b (5 bytes) to DAT_a807ce38[2][0..4] and DAT_a807ce50[1..5]; bit 29 = 1, cleared when the bytes
 *   differ from DAT_a807cda8[2][0..4];
 * - 0x69010 + k * 16 (16 bytes, k = 0..7) to DAT_a807ce50[6 + k * 16 ..];
 * - 0x69090 (5 bytes) to DAT_a807ce48[0..4] and DAT_a807ce50[0x86..0x8a];
 * - 0x69095 + k * 16 (16 bytes, k = 0..0x17) to DAT_a807cf08[k * 16 ..].
 * Bit 19 clear: FUN_a00c99a4(byte +9, DAT_a807cf08, 0, 0, 0xc00) and FUN_a00ca4e8(&DAT_a807ce50[1]).
 * FUN_a00c87e8(port, 3, 0x8000); 0x69215 (11 bytes) written to register 1 with FUN_a00c7654(port, 1, v);
 * byte 8 != 2: st = 0; else bit 28 = (byte 10 == 3).
 * Source forms: the block address base is a variable set before each k loop (addr + k * 16); the two
 * copies of each 5-byte block store the other array first.
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
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807ce38[][5];
extern unsigned char DAT_a807ce48[];
extern unsigned char DAT_a807cda8[3][5];
extern unsigned char DAT_a807cf08[];
extern int FUN_a00cfb20(int);
extern int func_0xa0f96400(int, int, int, int, unsigned char *);
extern void FUN_a00c99a4(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);
extern void FUN_a00ca4e8(unsigned char *);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);

void FUN_a00cfd38(unsigned char port)
{
    unsigned char buf[16];
    unsigned char i;
    unsigned char k;
    unsigned int addr;

    if (FUN_a00cfb20(10) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    DAT_a8078bb0[port].st = 1;
    func_0xa0f96400(0, 0x90, 0x6900b, 4, buf);
    for (i = 0; i < 5; i++) {
        DAT_a807ce38[2][i] = buf[i];
        DAT_a807ce50[i + 1] = buf[i];
    }
    DAT_a8078bb0[port].b29 = 1;
    for (i = 0; i < 5; i++) {
        if (buf[i] != DAT_a807cda8[2][i]) {
            DAT_a8078bb0[port].b29 = 0;
            break;
        }
    }
    addr = 0x69010;
    for (k = 0; k < 8; k++) {
        func_0xa0f96400(0, 0x90, addr + k * 16, 0xf, buf);
        for (i = 0; i < 16; i++)
            DAT_a807ce50[k * 16 + i + 6] = buf[i];
    }
    func_0xa0f96400(0, 0x90, 0x69090, 4, buf);
    for (i = 0; i < 5; i++) {
        DAT_a807ce48[i] = buf[i];
        DAT_a807ce50[i + 0x86] = buf[i];
    }
    addr = 0x69095;
    for (k = 0; k < 0x18; k++) {
        func_0xa0f96400(0, 0x90, addr + k * 16, 0xf, buf);
        for (i = 0; i < 16; i++)
            DAT_a807cf08[k * 16 + i] = buf[i];
    }
    if (DAT_a8078bb0[port].b19 == 0) {
        FUN_a00c99a4(DAT_a8078bb0[port].b9, DAT_a807cf08, 0, 0, 0xc00);
        FUN_a00ca4e8(&DAT_a807ce50[1]);
    }
    FUN_a00c87e8(port, 3, 0x8000);
    func_0xa0f96400(0, 0x90, 0x69215, 10, buf);
    for (i = 0; i < 11; i++)
        FUN_a00c7654(port, 1, buf[i]);
    if (buf[8] != 2)
        DAT_a8078bb0[port].st = 0;
    else if (buf[10] == 3)
        DAT_a8078bb0[port].b28 = 1;
    else
        DAT_a8078bb0[port].b28 = 0;
}

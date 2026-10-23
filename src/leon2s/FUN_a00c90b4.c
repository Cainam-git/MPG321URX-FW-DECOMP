/* leon2s FUN_a00c90b4 @ 0xa00c90b4-0xa00c91f8, -mcpu=v8 -Os -g.
 * (u8 port), void. Record DAT_a8078bb0[port] (24 bytes; word 0 bit-fields as in FUN_a00c91f8): st = 1.
 * Bit 28 clear: st = 0 and func_0xa0f83044 with the ROM address 0x9f1c2098 (outside the image), return.
 * (u8)FUN_a00c8048(port, 0x74, 0x20, 0x14) != 0 or (u8)FUN_a00c81f8(port, buf, 0x14) != 0: st = 3.
 * Otherwise the 20 bytes of buf are compared with DAT_a807d238 in groups of four with the byte order of each
 * group reversed (DAT_a807d238[4i + j] against buf[4i + 3 - j]); on the first difference
 * func_0xa0f83044(0x9f1c20a8) and st = 0.
 */
struct Rec24 {
    unsigned int a : 3;
    unsigned int f28 : 1;
    unsigned int cnt : 4;
    unsigned int f23 : 1;
    unsigned int mid : 5;
    unsigned int st : 2;
    unsigned int x : 16;
    unsigned char pad[20];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned char DAT_a807d238[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned int FUN_a00c8048(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00c81f8(unsigned char, unsigned char *, unsigned char);

void FUN_a00c90b4(unsigned char port)
{
    unsigned char buf[20];
    unsigned char i, j;

    DAT_a8078bb0[port].st = 1;
    if (DAT_a8078bb0[port].f28 == 0) {
        DAT_a8078bb0[port].st = 0;
        func_0xa0f83044((const char *)0x9f1c2098);
        return;
    }
    if ((unsigned char)FUN_a00c8048(port, 0x74, 0x20, 0x14) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if ((unsigned char)FUN_a00c81f8(port, buf, 0x14) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    for (i = 0; i <= 4; i++) {
        for (j = 0; j <= 3; j++) {
            if (DAT_a807d238[i * 4 + j] != buf[i * 4 + 3 - j]) {
                func_0xa0f83044((const char *)0x9f1c20a8);
                DAT_a8078bb0[port].st = 0;
                return;
            }
        }
    }
}

/* leon2m FUN_a00aea3c @ 0xa00aea3c-0xa00aeb98 (87 words), flags -mcpu=v8 -O3 -g.
 * With m = FUN_a01445fc(byte DAT_a802d290+0x1a3) * 2 + 4: FUN_a00b3ed0(0, 0, 0, 0); for m == 10
 * FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0) and FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11), else
 * FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0); then FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0). The byte becomes
 * FUN_a014459c((FUN_a01445fc(byte) + 3) & 3), then FUN_a00ad86c(FUN_a01445fc(byte), 1). FUN_a00869b0(0xb, 10000)
 * runs when FUN_a0143c14(0) is not 10 and bit 9 of word DAT_a802d290 is clear. Then bit 1 of byte 0xa802b08e is
 * set and FUN_a0090f94(10) is called (tail call). Same form as FUN_a00aeb98.
 */
struct St {
    unsigned int w0;
    unsigned char pad[0x1a3 - 4];
    unsigned char b1a3;
};
extern struct St DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a00869b0(int, int);
extern void FUN_a0090f94(unsigned short);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);

void FUN_a00aea3c(void)
{
    unsigned char m;

    m = (FUN_a01445fc(DAT_a802d290.b1a3) * 2 + 4) & 0xff;
    FUN_a00b3ed0(0, 0, 0, 0);

    if (m == 10) {
        FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0);
        FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11);
    } else {
        FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0);
    }

    FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0);

    DAT_a802d290.b1a3 = FUN_a014459c((FUN_a01445fc(DAT_a802d290.b1a3) + 3) & 3);
    FUN_a00ad86c(FUN_a01445fc(DAT_a802d290.b1a3), 1);
    if (FUN_a0143c14(0) != 10 && !(DAT_a802d290.w0 & 0x200))
        FUN_a00869b0(0xb, 10000);
    DAT_a802b08e = DAT_a802b08e | 2;
    FUN_a0090f94(10);
}

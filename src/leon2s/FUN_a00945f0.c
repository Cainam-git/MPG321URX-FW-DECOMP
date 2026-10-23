/* FUN_a00945f0 (leon2s 0xa00945f0-0xa0094798, 424 bytes), flags -mcpu=v8 -Os -g.
 * FUN_a00a80cc(port, 0, 0xba, 3, 0). When bit 30 of word 0 of the 0x1c-byte record ARR_a807d580[port] is set:
 * FUN_a00a8054(port, 0, 0x33, (FUN_a00a7fd8(port, 0, 0x3f) & 3) << 4) and return. Otherwise
 * FUN_a00a80cc(port, 0, 0x33, 0x30, 0); then for FUN_a0091c10(port) == 1 prints "Desired H Polarity +" and
 * FUN_a00a80cc(port, 1, 0x35, 2, 0), else prints "Desired H Polarity -" and FUN_a00a80cc(port, 1, 0x35, 2, 1),
 * (port, 0, 0xba, 2, 1), (port, 0, 0x33, 0x10, 1); the same for FUN_a0091be8(port) with "V Polarity", mask 1
 * and (port, 0, 0x33, 0x20, 1).
 * Source form: bit 30 is a 1-bit bit-field of the record word.
 */
struct Rec1c {
    unsigned int w0_31 : 1, w0_30 : 1, : 30;
    unsigned int w[6];
};
extern struct Rec1c ARR_a807d580[];
extern unsigned int FUN_a00734c4(const char *);
extern void FUN_a00a80cc(unsigned int port, unsigned int sub, short reg, unsigned int mask, unsigned int mode);
extern short FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);
extern void FUN_a00a8054(unsigned int, unsigned int, unsigned short, unsigned int);
extern unsigned int FUN_a0091c10(unsigned int);
extern unsigned int FUN_a0091be8(unsigned int);

void FUN_a00945f0(unsigned char port)
{
    FUN_a00a80cc(port, 0, 0xba, 3, 0);
    if (ARR_a807d580[port].w0_30) {
        FUN_a00a8054(port, 0, 0x33, (FUN_a00a7fd8(port, 0, 0x3f) & 3) << 4);
        return;
    }
    FUN_a00a80cc(port, 0, 0x33, 0x30, 0);
    if ((unsigned char)FUN_a0091c10(port) == 1) {
        FUN_a00734c4("\x1b[0m\t\t - Desired H Polarity + \n");
        FUN_a00a80cc(port, 1, 0x35, 2, 0);
    } else {
        FUN_a00734c4("\x1b[0m\t\t - Desired H Polarity - \n");
        FUN_a00a80cc(port, 1, 0x35, 2, 1);
        FUN_a00a80cc(port, 0, 0xba, 2, 1);
        FUN_a00a80cc(port, 0, 0x33, 0x10, 1);
    }
    if ((unsigned char)FUN_a0091be8(port) == 1) {
        FUN_a00734c4("\x1b[0m\t\t - Desired V Polarity + \n");
        FUN_a00a80cc(port, 1, 0x35, 1, 0);
    } else {
        FUN_a00734c4("\x1b[0m\t\t - Desired V Polarity - \n");
        FUN_a00a80cc(port, 1, 0x35, 1, 1);
        FUN_a00a80cc(port, 0, 0xba, 1, 1);
        FUN_a00a80cc(port, 0, 0x33, 0x20, 1);
    }
}

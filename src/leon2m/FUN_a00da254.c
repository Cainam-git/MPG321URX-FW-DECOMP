/* leon2m FUN_a00da254 @ 0xa00da254-0xa00da4b8 (516 bytes), flags -mcpu=v8 -O3 -g.
 * UserSetPIPMode: FUN_a00d99f8(2, 0); FUN_a014a8d4(4, 1, 1500) when bit 13 of the halfword at 0xa802d032 is
 * clear. Byte 0xa802d290+0x1f (0..7) selects the mode and a channel count n: 0 -> mode 0 or 2 (2 when
 * FUN_a00837e4() is not 1), n 1; 1 -> 1, 2; 2 -> 5, 2; 4 -> 3, 3; 5 and 6 -> 6, 3; 7 -> 7, 4; others 0, 0.
 * Prints the mode, copies the 16-byte record of each channel 0..n-1 from FUN_a00d6054 to FUN_a0149b8c, calls
 * FUN_a0149bf0(mode) and FUN_a014a7f4(0) for modes 3, 4, 6, 7, FUN_a014a7f4(1) otherwise.
 * When byte +0x1f is 0: FUN_a00d9fdc(1), FUN_a0149978(1, byte +0x1e if FUN_a0143c14(0) == 10, else
 * FUN_a014448c(0)), FUN_a0145348(0), FUN_a0145354(0). Otherwise FUN_a014a654(0xc, 0) and (0xd, 0) when
 * FUN_a014a6e0(0xc) or FUN_a014a6e0(0xd) returns 1, then FUN_a0149978(1, byte +0x20), FUN_a0145348(1),
 * FUN_a0145354(1). The records are copied through two local 16-byte buffers (ldd/std pairs).
 * Source form: bit 13 of 0xa802d032 is a bit-field; cases 5 and 6 are written as two separate identical
 * bodies (GCC merges them into one block, which then comes first among the out-of-line case blocks).
 */
struct R290 {
    unsigned char pad0[0x1e];
    unsigned char b1e;
    unsigned char b1f;
    unsigned char b20;
};
extern struct R290 DAT_a802d290;
extern struct { unsigned short p : 2; unsigned short b13 : 1; unsigned short q : 13; } DAT_a802d032;
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00d99f8(int, int);
extern void FUN_a014a8d4(int, int, int);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00d6054(int, void *);
extern void FUN_a0149b8c(int, void *);
extern void FUN_a0149bf0(unsigned int mode);
extern void FUN_a014a7f4(unsigned int);
extern void FUN_a00d9fdc(unsigned char sel);
extern unsigned char FUN_a0143c14(unsigned char);
extern unsigned char FUN_a014448c(int);
extern void FUN_a0149978(int, unsigned char);
extern void FUN_a0145348(unsigned char);
extern void FUN_a0145354(unsigned char);
extern unsigned char FUN_a014a6e0(unsigned char p);
extern void FUN_a014a654(unsigned char p, unsigned char q);

void FUN_a00da254(void)
{
    unsigned long long buf1[2];
    unsigned long long buf2[2];
    unsigned char n = 0;
    unsigned int mode = 0;
    unsigned char i;

    FUN_a00d99f8(2, 0);
    if (!DAT_a802d032.b13)
        FUN_a014a8d4(4, 1, 1500);
    switch (DAT_a802d290.b1f) {
    case 0:
        mode = (FUN_a00837e4() != 1) * 2;
        n = 1;
        break;
    case 1:
        mode = 1;
        n = 2;
        break;
    case 2:
        mode = 5;
        n = 2;
        break;
    case 4:
        mode = 3;
        n = 3;
        break;
    case 5:
        mode = 6;
        n = 3;
        break;
    case 6:
        mode = 6;
        n = 3;
        break;
    case 7:
        mode = 7;
        n = 4;
        break;
    }
    FUN_a00df170("\x1b[1;33mUserSetPIPMode %x\r\n\x1b[m", mode);
    for (i = 0; i < n; i++) {
        FUN_a00d6054(i, buf1);
        buf2[0] = buf1[0];
        buf2[1] = buf1[1];
        FUN_a0149b8c(i, buf2);
    }
    FUN_a0149bf0(mode);
    if (mode == 3 || mode == 4 || mode == 6 || mode == 7)
        FUN_a014a7f4(0);
    else
        FUN_a014a7f4(1);
    if (DAT_a802d290.b1f == 0) {
        FUN_a00d9fdc(1);
        if (FUN_a0143c14(0) == 10)
            FUN_a0149978(1, DAT_a802d290.b1e);
        else
            FUN_a0149978(1, FUN_a014448c(0));
        FUN_a0145348(0);
        FUN_a0145354(0);
    } else {
        if (FUN_a014a6e0(0xc) == 1 || FUN_a014a6e0(0xd) == 1) {
            FUN_a014a654(0xc, 0);
            FUN_a014a654(0xd, 0);
        }
        FUN_a0149978(1, DAT_a802d290.b20);
        FUN_a0145348(1);
        FUN_a0145354(1);
    }
}

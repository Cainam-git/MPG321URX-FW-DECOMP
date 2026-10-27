/* leon2m FUN_a00b3860 @ 0xa00b3860-0xa00b3ac8 (616 bytes), flags -mcpu=v8 -O3 -g. Callers: FUN_a00ad460,
 * FUN_a00b5378.
 * FUN_a00acc40(), FUN_a00acef4(), FUN_a0146b6c(2, 0), FUN_a0146b50(0x1a6, 0), FUN_a0146a80(0x36, 1, 5, 0x596, 0),
 * FUN_a00a31a4(0, 0x36, 1, 5, FUN_a00a3844(DAT_00196b24, FUN_a01445fc(byte DAT_a802d290+0x1e)), 0). Then two
 * formatted rows: b1 = "n%4dX%4d" with FUN_a0145660(0, 7) and FUN_a0145660(0, 8) (16-bit values) and b2 = "n%d HZ"
 * with FUN_a00d8b38() (FUN_a01577f4); for each, byte 0 = index of the first zero byte among bytes 0..15, minus 1
 * (15 when none), passed to FUN_a00a31a4(0, 0xe, 1 / 2, 8, buffer, 0) after FUN_a0146a80(0xe, 1 / 2, 8, 0x596, 0)
 * (the second after FUN_a0146b6c(2, 0) and FUN_a0146b50(0x1b5, 0)). Ends with FUN_a0146b50(0x1bc, 0),
 * FUN_a0146b6c(2, 0), FUN_a0146a80(0x37, 0x15, 4, 0xa96, 0), FUN_a00a31a4(0, 0x37, 0x15, 4, DAT_001981f0, 0),
 * FUN_a0146a80(1, 4, 0xb, 0x996, 0) and FUN_a00a31a4(0, 1, 4, 0xb, DAT_001981f8, 0) (length-prefixed strings
 * "\x06FW.021" and "\x10MPG 321U QD-OLED").
 * Source form: the FUN_a0145660 results are passed as (unsigned short) casts of int returns directly in the
 * FUN_a01577f4 call (16-bit extension right after each call).
 */
struct R290 { unsigned char p000[0x1e]; unsigned char b01e; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_00196b24[];
extern const char s_001981e0[], s_001981d8[];
extern const unsigned char DAT_001981f0[], DAT_001981f8[];
extern void FUN_a00acc40(void);
extern void FUN_a00acef4(void);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern int FUN_a0145660(unsigned int, unsigned int);
extern int FUN_a00d8b38(void);
extern void FUN_a01577f4(unsigned char *, const char *, ...);

void FUN_a00b3860(void)
{
    unsigned char b1[16];
    unsigned char b2[16];
    unsigned char n;

    FUN_a00acc40();
    FUN_a00acef4();
    FUN_a0146b6c(2, 0);
    FUN_a0146b50(0x1a6, 0);
    FUN_a0146a80(0x36, 1, 5, 0x596, 0);
    FUN_a00a31a4(0, 0x36, 1, 5, FUN_a00a3844(DAT_00196b24, FUN_a01445fc(DAT_a802d290.b01e)), 0);
    FUN_a01577f4(b1, s_001981e0, (unsigned short)FUN_a0145660(0, 7), (unsigned short)FUN_a0145660(0, 8));
    for (n = 0; n < 16; n++)
        if (b1[n] == 0)
            break;
    b1[0] = n - 1;
    FUN_a0146a80(0xe, 1, 8, 0x596, 0);
    FUN_a00a31a4(0, 0xe, 1, 8, (unsigned int)b1, 0);
    FUN_a01577f4(b2, s_001981d8, (unsigned short)FUN_a00d8b38());
    for (n = 0; n < 16; n++)
        if (b2[n] == 0)
            break;
    b2[0] = n - 1;
    FUN_a0146b6c(2, 0);
    FUN_a0146b50(0x1b5, 0);
    FUN_a0146a80(0xe, 2, 8, 0x596, 0);
    FUN_a00a31a4(0, 0xe, 2, 8, (unsigned int)b2, 0);
    FUN_a0146b50(0x1bc, 0);
    FUN_a0146b6c(2, 0);
    FUN_a0146a80(0x37, 0x15, 4, 0xa96, 0);
    FUN_a00a31a4(0, 0x37, 0x15, 4, (unsigned int)DAT_001981f0, 0);
    FUN_a0146a80(1, 4, 0xb, 0x996, 0);
    FUN_a00a31a4(0, 1, 4, 0xb, (unsigned int)DAT_001981f8, 0);
}

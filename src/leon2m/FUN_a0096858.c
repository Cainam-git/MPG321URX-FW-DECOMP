/* leon2m FUN_a0096858 @ 0xa0096858-0xa0096b54 (764 bytes), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a0096b54 (twice) and FUN_a00db1ac. FUN_a0146dc0(0, 0); clears bit 14 of halfword +0x18 of
 * DAT_a802cff4; when byte +0x4a of DAT_a802d290 is 1, FUN_a0109474(FUN_a013cda8(1), 0). Then three tests of
 * FUN_a00837e4() == 1: (1) byte +0x4a = 0, FUN_a00d5eac(0), FUN_a00da254(); (2) with word +0xb0 != 0: word +0xb0 = 0,
 * FUN_a00d4998(), FUN_a00d5f3c(); (3) with bit 7 of word +0xa8 set: when bit 15 of halfword +4 of DAT_a802cff4 is
 * set, bit 10 of it is set and FUN_a00808ac(4, 0) is called; DAT_a802afec = 0, FUN_a00b5080(), bit 7 of word +0xa8
 * cleared, FUN_a0124f44(), FUN_a00da184(), bit 1 of DAT_a802b08e set.
 * Prints "-->(%x %x)\r\n" with byte +0x1a4 of DAT_a802d290 and DAT_a8025c56. When either is 3:
 * FUN_a00d99f8(2, 0); bit 6 of halfword +0xa of DAT_a802cff4 set and FUN_a00869b0(0x14, 5000) when
 * FUN_a01445fc(FUN_a014448c(0)) != 0 and bit 20 of word +0xac is set; FUN_a0148268(0, 1), FUN_a0148268(1, 1),
 * FUN_a014a8d4(4, 1, 1000); FUN_a0149bf0(0) when FUN_a00837e4() != 0, else FUN_a0149bf0(2). Otherwise:
 * FUN_a01437dc(0x32), FUN_a0148268(0, 1), FUN_a0148268(1, 1); for DAT_a8025c56 5, 6 and 4 (in that order)
 * FUN_a0149bf0(2) when FUN_a00837e4() == 0; finally FUN_a0149bf0(0) when FUN_a00837e4() == 1.
 * Source form: the DAT_a802cff4 flags are unsigned short bit-fields (bit 14 of +0x18 cleared, bit 15 of +4 tested
 * as a HImode mask and bit 10 set from the same load); one complete FUN_a0149bf0 call per arm.
 */
struct Rcff4 {
    unsigned short h0, h2;
    unsigned short b15 : 1, b14_11 : 4, b10 : 1, r4 : 10;
    unsigned short h6, h8, ha, hc, he, h10, h12, h14, h16;
    unsigned short c15 : 1, c14 : 1, r18 : 14;
};
struct R290 {
    unsigned char p00[0x4a];
    unsigned char b4a;
    unsigned char p4b[0xa8 - 0x4b];
    unsigned int wa8, wac, wb0;
    unsigned char pb4[0x1a4 - 0xb4];
    unsigned char b1a4;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a8025c56;
extern void FUN_a0146dc0(int, int);
extern unsigned char FUN_a013cda8(unsigned char ch);
extern void FUN_a0109474(unsigned char sel, unsigned char on);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00d5eac(int);
extern void FUN_a00da254(void);
extern void FUN_a00d4998(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a00808ac(int, int);
extern void FUN_a00b5080(void);
extern void FUN_a0124f44(void);
extern void FUN_a00da184(void);
extern void FUN_a00d99f8(int, int);
extern unsigned char FUN_a014448c(int);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a00869b0(int, int);
extern void FUN_a0148268(int, int);
extern void FUN_a014a8d4(int, int, int);
extern void FUN_a0149bf0(unsigned int mode);
extern void FUN_a01437dc(unsigned short ms);
extern int FUN_a00df170(const char *fmt, ...);

void FUN_a0096858(void)
{
    FUN_a0146dc0(0, 0);
    DAT_a802cff4.c14 = 0;
    if (DAT_a802d290.b4a == 1)
        FUN_a0109474(FUN_a013cda8(1), 0);
    if (FUN_a00837e4() == 1) {
        DAT_a802d290.b4a = 0;
        FUN_a00d5eac(0);
        FUN_a00da254();
    }
    if (FUN_a00837e4() == 1 && DAT_a802d290.wb0 != 0) {
        DAT_a802d290.wb0 = 0;
        FUN_a00d4998();
        FUN_a00d5f3c();
    }
    if (FUN_a00837e4() == 1 && (DAT_a802d290.wa8 & 0x80)) {
        if (DAT_a802cff4.b15) {
            DAT_a802cff4.b10 = 1;
            FUN_a00808ac(4, 0);
        }
        DAT_a802afec = 0;
        FUN_a00b5080();
        DAT_a802d290.wa8 &= ~0x80;
        FUN_a0124f44();
        FUN_a00da184();
        DAT_a802b08e |= 2;
    }
    FUN_a00df170("-->(%x %x)\r\n", DAT_a802d290.b1a4, DAT_a8025c56);
    if (DAT_a802d290.b1a4 == 3 || DAT_a8025c56 == 3) {
        FUN_a00d99f8(2, 0);
        if (FUN_a01445fc(FUN_a014448c(0)) && (DAT_a802d290.wac & 0x100000)) {
            DAT_a802cff4.ha |= 0x40;
            FUN_a00869b0(0x14, 5000);
        }
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a014a8d4(4, 1, 1000);
        if (FUN_a00837e4())
            FUN_a0149bf0(0);
        else
            FUN_a0149bf0(2);
    } else {
        FUN_a01437dc(0x32);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        if (DAT_a8025c56 == 5 && !FUN_a00837e4())
            FUN_a0149bf0(2);
        if (DAT_a8025c56 == 6 && !FUN_a00837e4())
            FUN_a0149bf0(2);
        if (DAT_a8025c56 == 4 && !FUN_a00837e4())
            FUN_a0149bf0(2);
        if (FUN_a00837e4() == 1)
            FUN_a0149bf0(0);
    }
}

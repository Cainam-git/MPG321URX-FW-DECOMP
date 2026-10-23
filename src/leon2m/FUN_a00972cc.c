/* leon2m FUN_a00972cc @ 0xa00972cc-0xa0097498 (115 words).
 * Both paths: when bit 15 of halfword 0xa802cff4+4 is set, sets its bit 10 and calls FUN_a00808ac(4, 0); clears
 * word 0xa802afec and calls FUN_a00b5080(). When byte DAT_a802d290+0x1a3 equals byte 0xa8025c56 that is all.
 * Otherwise: sets bits 14 and 13 of halfword 0xa802cff4+0x18, copies byte +0x1a3 to +0x1f, and when it is
 * non-zero: byte +0x4a 1 -> cleared and FUN_a00d5eac(0); bit 7 of word +0xa8 set -> cleared, FUN_a00d91fc(0),
 * FUN_a00da184(); byte +0x1a4 cleared when FUN_a00837e4() is 1 and when it is 3; word +0xb0 non-zero -> cleared and
 * FUN_a00d5f3c(); bit 20 of word +0xac cleared. Then FUN_a00da254() and DAT_a802b08e |= 2.
 */
struct Rcff4 {
    unsigned char pad[4];
    unsigned short b15 : 1, b14 : 4, b10 : 1, rest : 10;
    unsigned char pad6[0x18 - 6];
    unsigned short h18;
};
struct R290 {
    unsigned char pad0[0x1f];
    unsigned char b1f;
    unsigned char pad20[0x4a - 0x20];
    unsigned char b4a;
    unsigned char pad4b[0xa8 - 0x4b];
    unsigned int wa8;
    unsigned int wac;
    unsigned int wb0;
    unsigned char padb4[0x1a3 - 0xb4];
    unsigned char b1a3;
    unsigned char b1a4;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a00808ac(unsigned char, unsigned char);
extern void FUN_a00b5080(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a00d5eac(int);
extern void FUN_a00d91fc(int);
extern void FUN_a00da184(void);
extern void FUN_a00da254(void);

void FUN_a00972cc(void)
{
    if (DAT_a802d290.b1a3 == DAT_a8025c56) {
        if (DAT_a802cff4.b15) {
            DAT_a802cff4.b10 = 1;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        return;
    }
    if (DAT_a802cff4.b15) {
        DAT_a802cff4.b10 = 1;
        FUN_a00808ac(4, 0);
    }
    _DAT_a802afec = 0;
    FUN_a00b5080();
    DAT_a802cff4.h18 |= 0x4000;
    DAT_a802cff4.h18 |= 0x2000;
    DAT_a802d290.b1f = DAT_a802d290.b1a3;
    if (DAT_a802d290.b1a3 != 0) {
        if (DAT_a802d290.b4a == 1) {
            DAT_a802d290.b4a = 0;
            FUN_a00d5eac(0);
        }
        if (DAT_a802d290.wa8 & 0x80) {
            DAT_a802d290.wa8 &= ~0x80;
            FUN_a00d91fc(0);
            FUN_a00da184();
        }
        if (FUN_a00837e4() == 1)
            DAT_a802d290.b1a4 = 0;
        if (DAT_a802d290.b1a4 == 3)
            DAT_a802d290.b1a4 = 0;
        if (DAT_a802d290.wb0 != 0) {
            DAT_a802d290.wb0 = 0;
            FUN_a00d5f3c();
        }
        DAT_a802d290.wac &= ~0x100000;
    }
    FUN_a00da254();
    DAT_a802b08e |= 2;
}

/* leon2m FUN_a00b69f4 @ 0xa00b69f4-0xa00b6b68 (93 words).
 * Toggles bit 7 of word DAT_a802d290+0xa8. When it was clear: if byte +0x1f is non-zero it is cleared and
 * FUN_a0090fd8(), FUN_a0124f44(), FUN_a00d91fc(0), FUN_a00da254() run; when FUN_a00837e4() is 1, byte +0x1a4 is
 * cleared and FUN_a0148268(0, 1), FUN_a0148268(1, 1), FUN_a00da254(), FUN_a00830f4(0) run; then byte +0x4a is
 * cleared, FUN_a00d5eac(0), bits 7 and 13 of the word are set and FUN_a00d4998() is called. Both ways then call
 * FUN_a0090fd8(), FUN_a0124f44(), FUN_a00d91fc(0), FUN_a00a9f30(5, bit 7), FUN_a01437dc(50), and when
 * FUN_a01445fc(FUN_a014448c(0)) is non-zero and bit 20 of word +0xac is set, set bit 6 of halfword 0xa802cff4+0xa
 * and call FUN_a00869b0(0x14, 5000). Ends with FUN_a00da184() and DAT_a802b08e |= 2.
 */
struct R290 {
    unsigned char pad0[0x1f];
    unsigned char b1f;
    unsigned char pad20[0x4a - 0x20];
    unsigned char b4a;
    unsigned char pad4b[0xa8 - 0x4b];
    unsigned int wa8;
    unsigned int wac;
    unsigned char padb0[0x1a4 - 0xb0];
    unsigned char b1a4;
};
struct Rcff4 {
    unsigned char pad[0xa];
    unsigned short ha;
};
extern struct R290 DAT_a802d290;
extern struct Rcff4 DAT_a802cff4;
extern unsigned char DAT_a802b08e;
extern void FUN_a0090fd8(void);
extern void FUN_a0124f44(void);
extern void FUN_a00d91fc(int);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a0148268(int, int);
extern void FUN_a00830f4(int);
extern void FUN_a00d5eac(int);
extern void FUN_a00d4998(void);
extern void FUN_a00a9f30(unsigned char, unsigned char);
extern void FUN_a01437dc(unsigned short ms);
extern unsigned char FUN_a014448c(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a00869b0(int, int);
extern void FUN_a00da184(void);

void FUN_a00b69f4(void)
{
    if (DAT_a802d290.wa8 & 0x80) {
        DAT_a802d290.wa8 &= ~0x80;
    } else {
        if (DAT_a802d290.b1f != 0) {
            DAT_a802d290.b1f = 0;
            FUN_a0090fd8();
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da254();
        }
        if (FUN_a00837e4() == 1) {
            DAT_a802d290.b1a4 = 0;
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00da254();
            FUN_a00830f4(0);
        }
        DAT_a802d290.b4a = 0;
        FUN_a00d5eac(0);
        DAT_a802d290.wa8 |= 0x80;
        if (!(DAT_a802d290.wa8 & 0x2000))
            DAT_a802d290.wa8 |= 0x2000;
        FUN_a00d4998();
    }
    FUN_a0090fd8();
    FUN_a0124f44();
    FUN_a00d91fc(0);
    FUN_a00a9f30(5, (DAT_a802d290.wa8 >> 7) & 1);
    FUN_a01437dc(50);
    if (FUN_a01445fc(FUN_a014448c(0)) && (DAT_a802d290.wac & 0x100000)) {
        DAT_a802cff4.ha |= 0x40;
        FUN_a00869b0(0x14, 5000);
    }
    FUN_a00da184();
    DAT_a802b08e |= 2;
}

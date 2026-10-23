/* leon2m FUN_a0096ce4 @ 0xa0096ce4-0xa0096e14 (76 words).
 * FUN_a00a93bc(DAT_a8025c56), FUN_a00a813c(1, DAT_a8025c56, 0), FUN_a00a9650(_DAT_a802afec - 0x77, 0),
 * FUN_a00a813c(1, bits 18..19 of word DAT_a802d290+0xac, 1); writes 0x1d to _DAT_a802afec; FUN_a00a900c(5, 1).
 * When DAT_a8025c56 differs from bits 18..19: sets bit 10 of halfword DAT_a802cff4+4 and calls
 * FUN_a00808ac(4, 0) when its bit 15 is set, clears _DAT_a802afec, calls FUN_a00b5080(), FUN_a00db054(), and
 * when FUN_a01445fc(FUN_a014448c(0)) is non-zero and bit 20 of word +0xac is set, sets bit 6 of halfword
 * DAT_a802cff4+0xa and calls FUN_a00869b0(0x14, 5000). Always ends with DAT_a802b08e |= 6.
 */
struct Rcff4 {
    unsigned char pad[4];
    unsigned short b15 : 1, b14 : 4, b10 : 1, rest : 10;
    unsigned char pad6[4];
    unsigned short ha;
};
struct R290 {
    unsigned char pad[0xac];
    unsigned int wac;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00808ac(unsigned char, unsigned char);
extern void FUN_a00b5080(void);
extern void FUN_a00db054(void);
extern unsigned char FUN_a014448c(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a00869b0(int, int);

void FUN_a0096ce4(void)
{
    FUN_a00a93bc(DAT_a8025c56);
    FUN_a00a813c(1, DAT_a8025c56, 0);
    FUN_a00a9650(_DAT_a802afec - 0x77, 0);
    FUN_a00a813c(1, (DAT_a802d290.wac >> 18) & 3, 1);
    _DAT_a802afec = 0x1d;
    FUN_a00a900c(5, 1);
    if (DAT_a8025c56 != ((DAT_a802d290.wac >> 18) & 3)) {
        if (DAT_a802cff4.b15) {
            DAT_a802cff4.b10 = 1;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        FUN_a00db054();
        if (FUN_a01445fc(FUN_a014448c(0)) && (DAT_a802d290.wac & 0x100000)) {
            DAT_a802cff4.ha |= 0x40;
            FUN_a00869b0(0x14, 5000);
        }
    }
    DAT_a802b08e |= 6;
}

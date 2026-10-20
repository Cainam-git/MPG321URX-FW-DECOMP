/* leon2m FUN_a00b50d8 @ 0xa00b50d8  (-mcpu=v8 -O3 -g)
 * Sets bit 7 of DAT_a802b08e, calls FUN_a0146298(4, 0), FUN_a0146354(1, 1, 0) and FUN_a00a2bdc(), then
 * configures one of five layouts by mode. Each layout passes the 16-bit result of FUN_a0146194(a, b) to
 * FUN_a0146370(0, value, 0) and two fixed values to FUN_a0146370(1, ...) and FUN_a0146370(3, ...), then tail-calls
 * its own routine: mode 0: (0x3C, 0x17), 0xFEC0, 0x12FB0, FUN_a00a28bc; mode 2: (0x16, 0x11), 0xF260, 0x11C90,
 * FUN_a00a2928; mode 3: (FUN_a014837c(0) / 24 + 1, 0x3D), 0xF260, 0x11C90, then FUN_a0146370(0,
 * FUN_a0146194(10, 10), 1), FUN_a00a29a8; mode 5: (0x38, 0x1B), 0xD400, 0xFE30, FUN_a00a2a38; mode 4: only
 * FUN_a0146370(1, FUN_a0146194(8, 3), 0) and FUN_a00a2adc. Other modes do nothing more.
 * Callers: FUN_a0086ae8, FUN_a008e270, FUN_a008f354, FUN_a00a5e68, FUN_a00a6b98 and others.
 * Source form: an if/else-if chain in the order 0, 2, 3, 5, 4; FUN_a0146194 is declared int and its result is
 * cast to unsigned short where it is passed on.
 */
extern unsigned char DAT_a802b08e;
extern void FUN_a0146298(int, int);
extern void FUN_a0146354(int, int, int);
extern void FUN_a00a2bdc(void);
extern int FUN_a0146194(int, int);
extern void FUN_a0146370(int, int, int);
extern unsigned short FUN_a014837c(int);
extern void FUN_a00a28bc(void);
extern void FUN_a00a2928(void);
extern void FUN_a00a29a8(void);
extern void FUN_a00a2a38(void);
extern void FUN_a00a2adc(void);

void FUN_a00b50d8(unsigned char mode)
{
    int r;

    DAT_a802b08e |= 0x80;
    FUN_a0146298(4, 0);
    FUN_a0146354(1, 1, 0);
    FUN_a00a2bdc();
    if (mode == 0) {
        r = FUN_a0146194(0x3c, 0x17);
        FUN_a0146370(0, (unsigned short)r, 0);
        FUN_a0146370(1, 0xfec0, 0);
        FUN_a0146370(3, 0x12fb0, 0);
        FUN_a00a28bc();
    } else if (mode == 2) {
        r = FUN_a0146194(0x16, 0x11);
        FUN_a0146370(0, (unsigned short)r, 0);
        FUN_a0146370(1, 0xf260, 0);
        FUN_a0146370(3, 0x11c90, 0);
        FUN_a00a2928();
    } else if (mode == 3) {
        r = FUN_a0146194((unsigned short)(FUN_a014837c(0) / 24 + 1), 0x3d);
        FUN_a0146370(0, (unsigned short)r, 0);
        FUN_a0146370(1, 0xf260, 0);
        FUN_a0146370(3, 0x11c90, 0);
        r = FUN_a0146194(10, 10);
        FUN_a0146370(0, (unsigned short)r, 1);
        FUN_a00a29a8();
    } else if (mode == 5) {
        r = FUN_a0146194(0x38, 0x1b);
        FUN_a0146370(0, (unsigned short)r, 0);
        FUN_a0146370(1, 0xd400, 0);
        FUN_a0146370(3, 0xfe30, 0);
        FUN_a00a2a38();
    } else if (mode == 4) {
        r = FUN_a0146194(8, 3);
        FUN_a0146370(1, (unsigned short)r, 0);
        FUN_a00a2adc();
    }
}

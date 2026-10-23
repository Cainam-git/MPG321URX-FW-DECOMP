/* leon2m FUN_a00aee44 @ 0xa00aee44-0xa00af44c (1544 bytes), called by FUN_a009a3cc, FUN_a00a1a68, FUN_a00af44c.
 * Locals: en[15] cleared, idx[7] = {5, 0, 4, 6, 7, 8, 11}; row = 6. FUN_a0146b50(0x120, 0), FUN_a0146b6c(0, 0).
 * mode 0xbf: row = 10, FUN_a0146b50(0x134, 0) and FUN_a00a31a4(0, 0x28, 10, 1, FUN_a00a3844(DAT_00183a70,
 * byte 0xa802d298), 0); (unsigned char)(mode + 9) <= 2: the same with FUN_a0146b50(0x111, 0).
 * Then FUN_a0146a80(0x28, row, 0xc, 0xe96, 0); for mode 0xe, 0x15, 0x23 FUN_a00a31a4(0, 0x28, row, 1,
 * FUN_a00a3844(DAT_00185af0, byte 0xa802d298), 0); w = FUN_a00a3838(); FUN_a0146c40(5, 0, 0),
 * FUN_a014667c(5, 0, 0, 0, 0, 0xf, 0, 0, 0, 0, 0), FUN_a0146870(5, 0x3c0, row * 0x24 + 0x24, (unsigned short)(w + 0x3c0),
 * row * 0x24 + 0x24, 0), FUN_a0146c40(5, 1, 0).
 * mode 0xe sets en[3], en[4], en[6] for sub 5, en[9] for sub 2, en[3], en[4] for sub 6, then continues as below.
 * mode 0x23 sets en[0], en[4], en[6], en[7], en[8], en[11] and, for each idx[i] (i = 0..6) with en[idx[i]] set,
 * calls with y = n * 2 + row + 2 (n counts these entries): FUN_a0146a80(0x28, y, 0xd, 0xe96, 0),
 * FUN_a0146b20(0, 0x28, y, 1, 1, 0), FUN_a00a31a4(0, 0x29, y, 1, FUN_a00a3844(DAT_001832e4,
 * idx[i] * 29 + byte 0xa802d298), 0); then returns.
 * mode 0xbf, and otherwise (unsigned char)(mode + 9) <= 2: for i = 0..2, y = i * 2 + row + 2,
 * FUN_a0146a80(0x28, y, 0xd, 0xe96, 0) and FUN_a00a31a4(0, 0x28, y, 1, FUN_a00a3844(&DAT_00183cb4[i * 29 +
 * byte 0xa802d298], 0), 0).
 * Other modes: for each set en[i] (i = 0..11), as for mode 0x23 with the index i, except that the n == 6 entry calls
 * FUN_a0146a80(0x28, row + 0xe, 0xa, 0xe96, 0).
 * Source form: the mode 0x23 loop reads row through an unsigned short copy (row is masked once before the loop);
 * n is incremented at the end of each loop body.
 */
struct R290 { unsigned char p000[8]; unsigned char b008; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_00183a70[], DAT_00185af0[], DAT_001832e4[], DAT_00183cb4[];
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a014667c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned short FUN_a00a3838(void);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);

void FUN_a00aee44(unsigned char mode, unsigned char sub)
{
    unsigned char en[15] = { 0 };
    unsigned char idx[7] = { 5, 0, 4, 6, 7, 8, 11 };
    unsigned char row, i, n;
    unsigned short w, y;

    FUN_a0146b50(0x120, 0);
    FUN_a0146b6c(0, 0);
    row = 6;
    if (mode == 0xbf) {
        row = 10;
        FUN_a0146b50(0x134, 0);
        FUN_a00a31a4(0, 0x28, row, 1, FUN_a00a3844(DAT_00183a70, DAT_a802d290.b008), 0);
    }
    if ((unsigned char)(mode + 9) <= 2) {
        row = 10;
        FUN_a0146b50(0x111, 0);
        FUN_a00a31a4(0, 0x28, row, 1, FUN_a00a3844(DAT_00183a70, DAT_a802d290.b008), 0);
    }
    FUN_a0146a80(0x28, row, 0xc, 0xe96, 0);
    if (mode == 0xe || mode == 0x15 || mode == 0x23)
        FUN_a00a31a4(0, 0x28, row, 1, FUN_a00a3844(DAT_00185af0, DAT_a802d290.b008), 0);
    w = FUN_a00a3838();
    FUN_a0146c40(5, 0, 0);
    FUN_a014667c(5, 0, 0, 0, 0, 0xf, 0, 0, 0, 0, 0);
    FUN_a0146870(5, 0x3c0, row * 0x24 + 0x24, (unsigned short)(w + 0x3c0), row * 0x24 + 0x24, 0);
    FUN_a0146c40(5, 1, 0);
    if (mode == 0xe) {
        if (sub == 5) {
            en[3] = 1;
            en[4] = 1;
            en[6] = 1;
        } else if (sub == 2)
            en[9] = 1;
        else if (sub == 6) {
            en[3] = 1;
            en[4] = 1;
        }
    } else if (mode == 0x23) {
        unsigned short r = row;

        en[0] = 1;
        en[4] = 1;
        en[6] = 1;
        en[7] = 1;
        en[8] = 1;
        en[11] = 1;
        for (i = 0, n = 0; i < 7; i++) {
            if (en[idx[i]]) {
                y = n * 2 + r + 2;
                FUN_a0146a80(0x28, y, 0xd, 0xe96, 0);
                FUN_a0146b20(0, 0x28, y, 1, 1, 0);
                FUN_a00a31a4(0, 0x29, y, 1, FUN_a00a3844(DAT_001832e4, idx[i] * 29 + DAT_a802d290.b008), 0);
                n++;
            }
        }
        return;
    } else if (mode == 0xbf) {
        for (i = 0; i < 3; i++) {
            y = i * 2 + row + 2;
            FUN_a0146a80(0x28, y, 0xd, 0xe96, 0);
            FUN_a00a31a4(0, 0x28, y, 1, FUN_a00a3844(DAT_00183cb4 + i * 29 + DAT_a802d290.b008, 0), 0);
        }
        return;
    }
    if ((unsigned char)(mode + 9) <= 2) {
        for (i = 0; i < 3; i++) {
            y = i * 2 + row + 2;
            FUN_a0146a80(0x28, y, 0xd, 0xe96, 0);
            FUN_a00a31a4(0, 0x28, y, 1, FUN_a00a3844(DAT_00183cb4 + i * 29 + DAT_a802d290.b008, 0), 0);
        }
    } else {
        for (i = 0, n = 0; i < 12; i++) {
            if (en[i]) {
                if (n == 6)
                    FUN_a0146a80(0x28, row + 0xe, 0xa, 0xe96, 0);
                else
                    FUN_a0146a80(0x28, n * 2 + row + 2, 0xd, 0xe96, 0);
                y = n * 2 + row + 2;
                FUN_a0146b20(0, 0x28, y, 1, 1, 0);
                FUN_a00a31a4(0, 0x29, y, 1, FUN_a00a3844(DAT_001832e4, i * 29 + DAT_a802d290.b008), 0);
                n++;
            }
        }
    }
}

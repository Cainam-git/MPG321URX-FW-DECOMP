/* leon2m FUN_a00acc40 @ 0xa00acc40-0xa00acef4 (173 words).
 * With b = byte DAT_a802d290+8 and m = b for b 0, 6, 7, 10, else 1: FUN_a0146b50(0x177, 0), FUN_a0146b6c(2, 0),
 * FUN_a0146a80(0x22, 1, 6, 0x596, 0), FUN_a00a31a4(0, 0x22, 1, 6, entry 1 of DAT_0018a6ac, 0),
 * FUN_a0146a80(0x22, 2, 6, 0x596, 0), FUN_a00a31a4(0, 0x22, 2, 6, entry m (+ 0x1d when FUN_a00d7d48() is
 * non-zero) of DAT_00193248, 0); FUN_a0146a80(0x17, 1 / 2, 0xa, 0x596, 0), FUN_a0146b20(0, 0x17, 1 / 2, 0xa, 0, 0).
 * When bit 11 of word +0xa8 is set: entry b of DAT_00188634 and entry FUN_a00b6b88(byte +0x181, 0) * 29 + b of
 * DAT_001951dc, else entry b of DAT_00188da0 and entry byte +0x182 * 29 + b of DAT_00195f24, to FUN_a00a31a4(0,
 * 0x17, 1 / 2, 0xa, entry, 0). Ends with FUN_a0146b6c(0, 0) (tail call). Entries come from FUN_a00a3844.
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
    unsigned char pad9[0xa8 - 9];
    unsigned int wa8;
    unsigned char padac[0x181 - 0xac];
    unsigned char b181;
    unsigned char b182;
};
extern struct St DAT_a802d290;
extern unsigned int DAT_0018a6ac[], DAT_00193248[], DAT_00188634[], DAT_001951dc[], DAT_00188da0[];
extern unsigned int DAT_00195f24[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned short, int, unsigned int, int);
extern int FUN_a00d7d48(void);
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);

void FUN_a00acc40(void)
{
    unsigned char m;

    if (DAT_a802d290.b08 == 0 || DAT_a802d290.b08 == 6 || DAT_a802d290.b08 == 7 || DAT_a802d290.b08 == 10)
        m = DAT_a802d290.b08;
    else
        m = 1;
    FUN_a0146b50(0x177, 0);
    FUN_a0146b6c(2, 0);
    FUN_a0146a80(0x22, 1, 6, 0x596, 0);
    FUN_a00a31a4(0, 0x22, 1, 6, FUN_a00a3844(DAT_0018a6ac, 1), 0);
    if (FUN_a00d7d48()) {
        FUN_a0146a80(0x22, 2, 6, 0x596, 0);
        FUN_a00a31a4(0, 0x22, 2, 6, FUN_a00a3844(DAT_00193248, m + 0x1d), 0);
    } else {
        FUN_a0146a80(0x22, 2, 6, 0x596, 0);
        FUN_a00a31a4(0, 0x22, 2, 6, FUN_a00a3844(DAT_00193248, m), 0);
    }
    FUN_a0146a80(0x17, 1, 0xa, 0x596, 0);
    FUN_a0146a80(0x17, 2, 0xa, 0x596, 0);
    FUN_a0146b20(0, 0x17, 1, 0xa, 0, 0);
    FUN_a0146b20(0, 0x17, 2, 0xa, 0, 0);
    if (!(DAT_a802d290.wa8 & 0x800)) {
        FUN_a00a31a4(0, 0x17, 1, 0xa, FUN_a00a3844(DAT_00188da0, DAT_a802d290.b08), 0);
        FUN_a00a31a4(0, 0x17, 2, 0xa, FUN_a00a3844(DAT_00195f24, DAT_a802d290.b182 * 29 + DAT_a802d290.b08), 0);
    } else {
        FUN_a00a31a4(0, 0x17, 1, 0xa, FUN_a00a3844(DAT_00188634, DAT_a802d290.b08), 0);
        FUN_a00a31a4(0, 0x17, 2, 0xa,
                     FUN_a00a3844(DAT_001951dc, FUN_a00b6b88(DAT_a802d290.b181, 0) * 29 + DAT_a802d290.b08), 0);
    }
    FUN_a0146b6c(0, 0);
}

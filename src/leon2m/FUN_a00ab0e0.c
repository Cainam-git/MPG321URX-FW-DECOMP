/* leon2m FUN_a00ab0e0 @ 0xa00ab0e0-0xa00ab2a8 (-mcpu=v8 -O3 -g). Called by FUN_a0095778 with mode 0.
 * mode 2: y = 10; when byte +0x190 of the record at 0xa802d290 shifted right by 2 is nonzero, x = 5 and start = 7,
 * else start = 0, x = 8 and FUN_a00a31a4(0, 8, 6, 0xd, FUN_a00a3844(DAT_0018f984, byte +8), 0).
 * Other modes: y = 0x2d; FUN_a00a2afc(), FUN_a0146b50(299, 0), FUN_a0146b6c(2, 0),
 * FUN_a00a31a4(0, 0x2a, 6, 8, FUN_a00a3844(DAT_0018f984, byte +8), 0); x = 7, start = 0.
 * Then for i = start..12 (in mode 2 with start 0 the loop ends after i = 6):
 * FUN_a00b32e4(1, 1, 0x796, y, i - start + x, 2, (i - start) * 2 + 0x11).
 * Source form: the mode test sits inside the loop (the compiler unswitches it into two loops); the +0x190 test is an
 * if/else with 'x = 5' written before 'start = 7' in the nonzero arm.
 */
struct R290 {
    unsigned char p000[8];
    unsigned char b008;
    unsigned char p009[0x190 - 9];
    unsigned char b190;
};
extern struct R290 DAT_a802d290;
extern unsigned int DAT_0018f984[];
extern void FUN_a00a2afc(void);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char, unsigned char,
                         unsigned char);

void FUN_a00ab0e0(unsigned char mode)
{
    unsigned char start, i, x, y;

    if (mode == 2) {
        y = 10;
        if (DAT_a802d290.b190 >> 2) {
            x = 5;
            start = 7;
        } else {
            start = 0;
            x = 8;
        }
        if (start == 0)
            FUN_a00a31a4(0, 8, 6, 0xd, FUN_a00a3844(DAT_0018f984, DAT_a802d290.b008), 0);
    } else {
        y = 0x2d;
        FUN_a00a2afc();
        FUN_a0146b50(299, 0);
        FUN_a0146b6c(2, 0);
        FUN_a00a31a4(0, 0x2a, 6, 8, FUN_a00a3844(DAT_0018f984, DAT_a802d290.b008), 0);
        x = 7;
        start = 0;
    }
    for (i = start; i <= 12; i++) {
        if (mode == 2) {
            if (start == 0 && i > 6)
                break;
        }
        FUN_a00b32e4(1, 1, 0x796, y, i - start + x, 2, (i - start) * 2 + 0x11);
    }
}

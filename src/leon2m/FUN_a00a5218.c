/* leon2m FUN_a00a5218 @ 0xa00a5218-0xa00a5420 (520 bytes), flags -mcpu=v8 -O3 -g. No direct callers found.
 * T = DAT_a802d290. When T.b04a is 0: if the word T+0xb0 is non-zero it is cleared and FUN_a00d4998() and
 * FUN_a00d5f3c() run; when FUN_a00837e4() returns 1: FUN_a00d91fc(0), T.b1a4 = 0, FUN_a00830f4(0); when T.b01f is
 * non-zero it is cleared and FUN_a00da254() runs; when bit 7 of the word T+0xa8 is set it is cleared and
 * FUN_a0090fd8(), FUN_a0124f44(), FUN_a00d91fc(0), FUN_a00da184() run. Then T.b04a = 1, FUN_a00d5eac(0), f = T.b04a
 * (read again), FUN_a0146a80(5, 8, 4, 0x792, 0), FUN_a0146b20(0, i + 9, 8, 1, i + 0x22 (f == 0) or i + 0x1e, 0) for
 * i = 0..3, and FUN_a0146a80(3, 8, 5, ..) / FUN_a0146a80(0xe, 8, 5, ..) with 0x792 / 0x992 for f == 0 and 0x992 /
 * 0x792 otherwise. Always sets bit 1 of byte 0xa802b08e at the end.
 * Source form: the f test is inside the loop (?: in the argument), so the loop is unswitched after jump threading
 * and the f test after the loop stays.
 */
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char p020[0x4a - 0x20]; unsigned char b04a;
              unsigned char p04b[0xa8 - 0x4b]; unsigned int w0a8; unsigned int w0ac;
              unsigned int w0b0; unsigned char p0b4[0x1a4 - 0xb4]; unsigned char b1a4; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a0090fd8(void);
extern void FUN_a0124f44(void);
extern void FUN_a00d91fc(int);
extern void FUN_a00da184(void);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00830f4(int);
extern void FUN_a00d5eac(int);
extern void FUN_a00d4998(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00a5218(void)
{
    unsigned char i, f;

    if (DAT_a802d290.b04a == 0) {
        if (DAT_a802d290.w0b0 != 0) {
            DAT_a802d290.w0b0 = 0;
            FUN_a00d4998();
            FUN_a00d5f3c();
        }
        if (FUN_a00837e4() == 1) {
            FUN_a00d91fc(0);
            DAT_a802d290.b1a4 = 0;
            FUN_a00830f4(0);
        }
        if (DAT_a802d290.b01f != 0) {
            DAT_a802d290.b01f = 0;
            FUN_a00da254();
        }
        if (DAT_a802d290.w0a8 & 0x80) {
            DAT_a802d290.w0a8 &= ~0x80;
            FUN_a0090fd8();
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da184();
        }
        DAT_a802d290.b04a = 1;
        FUN_a00d5eac(0);
        f = DAT_a802d290.b04a;
        FUN_a0146a80(5, 8, 4, 0x792, 0);
        for (i = 0; i < 4; i++)
            FUN_a0146b20(0, i + 9, 8, 1, f == 0 ? i + 0x22 : i + 0x1e, 0);
        if (f == 0) {
            FUN_a0146a80(3, 8, 5, 0x792, 0);
            FUN_a0146a80(0xe, 8, 5, 0x992, 0);
        } else {
            FUN_a0146a80(3, 8, 5, 0x992, 0);
            FUN_a0146a80(0xe, 8, 5, 0x792, 0);
        }
    }
    DAT_a802b08e |= 2;
}

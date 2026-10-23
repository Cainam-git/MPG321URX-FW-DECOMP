/* leon2m FUN_a00912ac @ 0xa00912ac-0xa009145c (108 words).
 * With a = word 0xa802afec and bit 14 of word DAT_a802d290: a == 2 and the bit set: FUN_a00a7e00(0),
 * FUN_a0146a80(1, 5, 1, 0x592, 0), a = 1. a == 1 and the bit set: FUN_a00ab080(), FUN_a00a7aec(1),
 * FUN_a00b3d14(1), a = 10, FUN_a0146a80(1, 5, 1, 0x792, 0). Otherwise FUN_a00a7e00(a - 2), then a steps down:
 * a = ((unsigned short)a + 6) % 9 + 2 until FUN_a00aa4e0(a - 2) is 1; a == 8 calls FUN_a00ab080(),
 * FUN_a00a7aec(0), FUN_a00b3d14(0) and a == 10 the same with 1. The last two paths end with
 * FUN_a00b4144(a - 2, 1) and FUN_a00b0034(a - 2) (tail call). Same form as FUN_a009145c.
 */
extern unsigned int _DAT_a802afec;
extern unsigned int DAT_a802d290;
extern void FUN_a00a7e00(unsigned char);
extern unsigned char FUN_a00aa4e0(unsigned char);
extern void FUN_a00ab080(void);
extern void FUN_a00a7aec(unsigned char);
extern void FUN_a00b3d14(unsigned char);
extern void FUN_a00b4144(unsigned char, int);
extern void FUN_a00b0034(unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

void FUN_a00912ac(void)
{
    int k;

    if (_DAT_a802afec == 2 && (DAT_a802d290 & 0x4000)) {
        FUN_a00a7e00(0);
        FUN_a0146a80(1, 5, 1, 0x592, 0);
        _DAT_a802afec = 1;
        return;
    }
    if (_DAT_a802afec == 1 && (DAT_a802d290 & 0x4000)) {
        FUN_a00ab080();
        FUN_a00a7aec(1);
        FUN_a00b3d14(1);
        _DAT_a802afec = 10;
        FUN_a0146a80(1, 5, 1, 0x792, 0);
        FUN_a00b4144(_DAT_a802afec - 2, 1);
        FUN_a00b0034(_DAT_a802afec - 2);
        return;
    }
    FUN_a00a7e00(_DAT_a802afec - 2);
    do {
        k = ((unsigned short)_DAT_a802afec + 6) % 9;
        _DAT_a802afec = k + 2;
    } while (FUN_a00aa4e0(k) != 1);
    if (_DAT_a802afec == 8) {
        FUN_a00ab080();
        FUN_a00a7aec(0);
        FUN_a00b3d14(0);
    } else if (_DAT_a802afec == 10) {
        FUN_a00ab080();
        FUN_a00a7aec(1);
        FUN_a00b3d14(1);
    }
    FUN_a00b4144(_DAT_a802afec - 2, 1);
    FUN_a00b0034(_DAT_a802afec - 2);
}

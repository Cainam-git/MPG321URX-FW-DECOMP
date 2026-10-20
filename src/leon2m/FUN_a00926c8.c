/* leon2m FUN_a00926c8 @ 0xa00926c8-0xa00927e8 (72 words).
 * Steps word 0xa802afec backwards through 0x23..0x25 (modulo 3), skipping positions that FUN_a00aa520
 * rejects: FUN_a00a8ee8(afec - 35) first, then v = ((low halfword of afec) - 33) % 3 and afec = v + 35 until
 * FUN_a00aa520(v) returns 1. Then FUN_a00a900c(position, 1); FUN_a0146c40(6, flag, 0) with flag 0 when the position
 * equals byte 0xa8025c56 and 1 otherwise; FUN_a00af44c(0x23, position); for position 0 FUN_a00a9468(1, 3) and
 * FUN_a00b34d4(0, 4), otherwise FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1); and finally FUN_a00a813c(0, byte
 * 0xa8025c56, position != that byte). Same loop as FUN_a00920f4.
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a8ee8(unsigned char);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00926c8(void)
{
    int v;

    FUN_a00a8ee8(_DAT_a802afec - 35);
    do {
        v = ((unsigned short)_DAT_a802afec - 33) % 3;
        _DAT_a802afec = v + 35;
    } while (FUN_a00aa520(v) != 1);
    FUN_a00a900c(_DAT_a802afec - 35, 1);
    if (_DAT_a802afec - 35 == DAT_a8025c56)
        FUN_a0146c40(6, 0, 0);
    else
        FUN_a0146c40(6, 1, 0);
    FUN_a00af44c(0x23, _DAT_a802afec - 35);
    if (_DAT_a802afec == 0x23) {
        FUN_a00a9468(1, 3);
        FUN_a00b34d4(0, 4);
    } else {
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    }
    if (_DAT_a802afec - 35 == DAT_a8025c56)
        FUN_a00a813c(0, DAT_a8025c56, 0);
    else
        FUN_a00a813c(0, DAT_a8025c56, 1);
}

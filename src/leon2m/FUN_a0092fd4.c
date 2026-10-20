/* leon2m FUN_a0092fd4 @ 0xa0092fd4-0xa0093144 (92 words).
 * Steps the selection word 0xa802afec backwards through 0x34..0x3b (modulo 8), skipping positions that FUN_a00aa520
 * rejects: FUN_a00a8ee8(position) first, then v = ((low halfword of afec) - 45) % 8 and afec = v + 52 until
 * FUN_a00aa520(v) returns 1. The positions form pages of 7: when position / 7 differs from the page before the step,
 * FUN_a00aa83c(1 - old page) is called. Then FUN_a00a900c(position, 1) and FUN_a00af44c(0x34, position). For
 * selection 0x35: FUN_a00a9468(1, 3) and FUN_a00b34d4(0, 4); for 0x3b: FUN_a00b34d4(0, 4) and FUN_a00a9468(1, 6);
 * otherwise byte 0xa802d419 = 0xff, FUN_a00ab4bc(), FUN_a00a9468(1, 2), FUN_a00a9468(2, 5), FUN_a00a9468(0, 0) and
 * FUN_a00b34d4(0, 1). Same loop as FUN_a00920f4.
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d419;
extern void FUN_a00a8ee8(unsigned char);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);
extern void FUN_a00aa83c(unsigned char);
extern void FUN_a00ab4bc(void);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a0092fd4(void)
{
    int v;
    unsigned char page;

    FUN_a00a8ee8(_DAT_a802afec - 52);
    page = (_DAT_a802afec - 52) / 7;
    do {
        v = ((unsigned short)_DAT_a802afec - 45) % 8;
        _DAT_a802afec = v + 52;
    } while (FUN_a00aa520(v) != 1);
    if (page != (_DAT_a802afec - 52) / 7)
        FUN_a00aa83c(1 - page);
    FUN_a00a900c(_DAT_a802afec - 52, 1);
    FUN_a00af44c(0x34, _DAT_a802afec - 52);
    if (_DAT_a802afec == 0x35) {
        FUN_a00a9468(1, 3);
        FUN_a00b34d4(0, 4);
    } else if (_DAT_a802afec == 0x3b) {
        FUN_a00b34d4(0, 4);
        FUN_a00a9468(1, 6);
    } else {
        DAT_a802d419 = 0xff;
        FUN_a00ab4bc();
        FUN_a00a9468(1, 2);
        FUN_a00a9468(2, 5);
        FUN_a00a9468(0, 0);
        FUN_a00b34d4(0, 1);
    }
}

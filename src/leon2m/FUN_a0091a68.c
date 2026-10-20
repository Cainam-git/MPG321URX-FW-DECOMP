/* leon2m FUN_a0091a68 @ 0xa0091a68-0xa0091b94 (75 words).
 * Steps word 0xa802afec backwards through 0xe..0x14 (modulo 7), skipping positions that FUN_a00aa520
 * rejects: FUN_a00a8ee8(position), FUN_a00aa0e8(position, 0) first, then v = ((low halfword of afec) - 8) % 7 and
 * afec = v + 14 until FUN_a00aa520(v) returns 1. The positions form pages of 7: when position / 7 differs from the
 * page before the step, FUN_a00ad02c(new page, 1) is called. Then FUN_a00a900c(position, 1), FUN_a00aa0e8(position,
 * 1) and FUN_a00af44c(0xe, position). Same loop as FUN_a00920f4.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);
extern void FUN_a00ad02c(unsigned char, int);
extern void FUN_a00aa0e8(unsigned char, int);

void FUN_a0091a68(void)
{
    int v;
    unsigned char page;

    FUN_a00a8ee8(_DAT_a802afec - 14);
    FUN_a00aa0e8(_DAT_a802afec - 14, 0);
    page = (_DAT_a802afec - 14) / 7;
    do {
        v = ((unsigned short)_DAT_a802afec - 8) % 7;
        _DAT_a802afec = v + 14;
    } while (FUN_a00aa520(v) != 1);
    if (page != (_DAT_a802afec - 14) / 7)
        FUN_a00ad02c((_DAT_a802afec - 14) / 7, 1);
    FUN_a00a900c(_DAT_a802afec - 14, 1);
    FUN_a00aa0e8(_DAT_a802afec - 14, 1);
    FUN_a00af44c(0xe, _DAT_a802afec - 14);
}

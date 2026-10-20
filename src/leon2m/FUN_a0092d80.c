/* leon2m FUN_a0092d80 @ 0xa0092d80-0xa0092ea8 (74 words).
 * Steps the selection word 0xa802afec forwards through 0x2a..0x33 (modulo 10), skipping positions that FUN_a00aa520
 * rejects: FUN_a00a8ee8(position), FUN_a00aa33c(position, 0) first, then v = ((low halfword of afec) - 41) % 10 and
 * afec = v + 42 until FUN_a00aa520(v) returns 1. The positions form pages of 7: when position / 7 differs from the
 * page before the step, FUN_a00ad1c0(new page) is called. Then FUN_a00a900c(position, 1), FUN_a00aa33c(position, 1)
 * and FUN_a00af44c(0x2a, position). Same loop as FUN_a00920f4.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);
extern void FUN_a00ad1c0(unsigned char);
extern void FUN_a00aa33c(unsigned char, int);

void FUN_a0092d80(void)
{
    int v;
    unsigned char page;

    FUN_a00a8ee8(_DAT_a802afec - 42);
    FUN_a00aa33c(_DAT_a802afec - 42, 0);
    page = (_DAT_a802afec - 42) / 7;
    do {
        v = ((unsigned short)_DAT_a802afec - 41) % 10;
        _DAT_a802afec = v + 42;
    } while (FUN_a00aa520(v) != 1);
    if ((_DAT_a802afec - 42) / 7 != page)
        FUN_a00ad1c0((_DAT_a802afec - 42) / 7);
    FUN_a00a900c(_DAT_a802afec - 42, 1);
    FUN_a00aa33c(_DAT_a802afec - 42, 1);
    FUN_a00af44c(0x2a, _DAT_a802afec - 42);
}

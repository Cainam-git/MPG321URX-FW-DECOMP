/* leon2m FUN_a00929e8 @ 0xa00929e8-0xa0092a80 (38 words).
 * Steps the selection word 0xa802afec backwards through 0x26..0x29 (modulo 4), skipping positions that FUN_a00aa520
 * rejects: FUN_a00a8ee8(afec - 38) first, then v = ((low halfword of afec) - 35) % 4 and afec = v + 38 until
 * FUN_a00aa520(v) returns 1. Byte 0xa802d433 (offset 0x1a3 of the block at 0xa802d290) is stepped the same way:
 * (b + 3) & 3. Then FUN_a00a900c(afec - 38, 1) and FUN_a00af44c(0x26, afec - 38). Same loop as FUN_a00920f4.
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00a8ee8(unsigned char);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);

void FUN_a00929e8(void)
{
    int v;

    FUN_a00a8ee8(_DAT_a802afec - 38);
    do {
        v = ((unsigned short)_DAT_a802afec - 35) % 4;
        _DAT_a802afec = v + 38;
    } while (FUN_a00aa520(v) != 1);
    DAT_a802d290[0x1a3] = (DAT_a802d290[0x1a3] + 3) & 3;
    FUN_a00a900c(_DAT_a802afec - 38, 1);
    FUN_a00af44c(0x26, _DAT_a802afec - 38);
}

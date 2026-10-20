/* leon2m FUN_a009e0bc @ 0xa009e0bc-0xa009e154 (38 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a93bc((u8)(word DAT_a802afec + 0x3d)); loop: r = ((low halfword of
 * DAT_a802afec, lduh +2) - 0xc2) % 2 (signed); DAT_a802afec = r + 0xc3; until
 * FUN_a00aad30((u8)r) returns 1. FUN_a00a9650((u8)(DAT_a802afec + 0x3d), 1); tail call
 * FUN_a00a813c(1, byte DAT_a8025c56, (DAT_a802afec - 0xc3 == DAT_a8025c56) ? 0 : 1). void.
 * Fix vs the autoc draft (82.05): the halfword is '(unsigned short)DAT_a802afec' (combine narrows
 * the word load to lduh [hi + 0x3ee] and keeps the word's shared %hi, like FUN_a00920f4); a
 * separate extern DAT_a802afee gets its own sethi. FUN_a00aad30 returns a byte (0/1 via clr %i0
 * and friends). Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009e0bc(void)
{
    int r;

    FUN_a00a93bc(DAT_a802afec + 0x3d);
    do {
        r = ((unsigned short)DAT_a802afec - 0xc2) % 2;
        DAT_a802afec = r + 0xc3;
    } while (FUN_a00aad30(r) != 1);
    FUN_a00a9650(DAT_a802afec + 0x3d, 1);
    if (DAT_a802afec - 0xc3 == DAT_a8025c56)
        FUN_a00a813c(1, DAT_a8025c56, 0);
    else
        FUN_a00a813c(1, DAT_a8025c56, 1);
}

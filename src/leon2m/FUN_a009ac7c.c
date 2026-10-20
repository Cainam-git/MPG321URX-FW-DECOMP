/* leon2m FUN_a009ac7c @ 0xa009ac7c-0xa009ad40 (49 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a93bc((u8)(word DAT_a802afec + 0x30)); loop: r = ((low halfword of
 * DAT_a802afec) - 205) % 4 (signed); DAT_a802afec = r + 0xd0; until FUN_a00aad30((u8)r) == 1.
 * FUN_a00a9650((u8)(DAT_a802afec + 0x30), 1); k = (u8)FUN_a014459c((u8)(DAT_a802afec + 0x30));
 * tail FUN_a00a813c(1, (u8)FUN_a01445fc(byte DAT_a8025c55), k == DAT_a8025c55 ? 0 : 1) (two
 * separate tail arms in the fw). void. Family of FUN_a009e0bc.
 * Fixes vs the autoc draft (80.00 band): '(unsigned short)DAT_a802afec' for the +2 halfword
 * (shares the word's %hi; see FUN_a00920f4); the a014459c result in its own u8 local 'k' before
 * the compare (fw 'cmp k, c55'; the inline form gives 'cmp c55, k': 95.92); void. Aids: none.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern int FUN_a014459c(unsigned char);
extern int FUN_a01445fc(unsigned char);

void FUN_a009ac7c(void)
{
    int r;
    unsigned char k;

    FUN_a00a93bc(DAT_a802afec + 0x30);
    do {
        r = ((unsigned short)DAT_a802afec - 205) % 4;
        DAT_a802afec = r + 0xd0;
    } while (FUN_a00aad30(r) != 1);
    FUN_a00a9650(DAT_a802afec + 0x30, 1);
    k = FUN_a014459c(DAT_a802afec + 0x30);
    if (k == DAT_a8025c55)
        FUN_a00a813c(1, FUN_a01445fc(DAT_a8025c55), 0);
    else
        FUN_a00a813c(1, FUN_a01445fc(DAT_a8025c55), 1);
}

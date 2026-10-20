/* leon2m FUN_a009ad40 @ 0xa009ad40-0xa009ae04 (49 words).
 * Steps the selection kept in word 0xa802afec through the values 0xd0..0xd3. FUN_a00a93bc is called with the
 * current position (afec - 0xd0). Then t = ((low halfword of afec) - 0xcf) % 4 and afec = t + 0xd0 repeat until
 * FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. FUN_a00a9650(position, 1) follows.
 * Finally FUN_a00a813c(1, FUN_a01445fc(byte 0xa8025c55), flag) is called, where flag is 0 when
 * FUN_a014459c(position) equals byte 0xa8025c55 and 1 otherwise.
 * Same loop as FUN_a0095c94 (there modulo 5 from base 0x4e).
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);

void FUN_a009ad40(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0xd0);
    do {
        t = (unsigned short)_DAT_a802afec - 0xcf;
        t = t % 4;
        _DAT_a802afec = t + 0xd0;
    } while (FUN_a00aad30(t) != 1);
    FUN_a00a9650(_DAT_a802afec - 0xd0, 1);
    if (FUN_a014459c(_DAT_a802afec - 0xd0) == DAT_a8025c55)
        FUN_a00a813c(1, FUN_a01445fc(DAT_a8025c55), 0);
    else
        FUN_a00a813c(1, FUN_a01445fc(DAT_a8025c55), 1);
}

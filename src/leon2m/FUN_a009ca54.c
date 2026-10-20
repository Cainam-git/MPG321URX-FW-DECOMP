/* leon2m FUN_a009ca54 @ 0xa009ca54-0xa009cb0c (46 words).
 * Steps the selection kept in word 0xa802afec forwards through the values 0x70..0x76 (modulo 7). FUN_a00a93bc is
 * called with the current position (afec - 0x70). Then t = ((low halfword of afec) - 0x6f) % 7 and afec = t + 0x70
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. FUN_a00acef4 is called.
 * FUN_a00a9650(position, 1) follows. Finally FUN_a00a813c(1, v, position != v) is called with v = byte 0xa8025c56.
 * Same loop as FUN_a0095c94.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a00acef4(void);

void FUN_a009ca54(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0x70);
    do {
        t = (unsigned short)_DAT_a802afec - 0x6f;
        t = t % 7;
        _DAT_a802afec = t + 0x70;
    } while (FUN_a00aad30(t) != 1);
    FUN_a00a9650(_DAT_a802afec - 0x70, 1);
    FUN_a00acef4();
    {
        unsigned char v = DAT_a8025c56;
        if (_DAT_a802afec - 0x70 == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}

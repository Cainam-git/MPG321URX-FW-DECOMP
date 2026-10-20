/* leon2m FUN_a009e00c @ 0xa009e00c-0xa009e0bc (44 words).
 * Steps word 0xa802afec forwards through the values 0xbb..0xbf (modulo 5). FUN_a00a93bc is
 * called with the current position (afec - 0xbb). Then t = ((low halfword of afec) - 0xba) % 5 and afec = t + 0xbb
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. FUN_a00a9650(position,
 * 1) follows. Finally FUN_a00a813c(1, v, position != v) is called with v = byte 0xa8025c56. Same loop as
 * FUN_a0095c94.
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

void FUN_a009e00c(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0xbb);
    do {
        t = (unsigned short)_DAT_a802afec - 0xba;
        t = t % 5;
        _DAT_a802afec = t + 0xbb;
    } while (FUN_a00aad30(t) != 1);
    FUN_a00a9650(_DAT_a802afec - 0xbb, 1);
    {
        unsigned char v = DAT_a8025c56;
        if (_DAT_a802afec - 0xbb == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}

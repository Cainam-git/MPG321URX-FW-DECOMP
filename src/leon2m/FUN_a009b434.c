/* leon2m FUN_a009b434 @ 0xa009b434-0xa009b4e8 (45 words).
 * Steps the selection kept in word 0xa802afec backwards through the values 0xed..0xef (modulo 3). FUN_a00a93bc is
 * called with the current position (afec - 0xed). Then t = ((low halfword of afec) - 0xeb) % 3 and afec = t + 0xed
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. The new position is
 * stored in byte 0xa802d40b (offset 0x17b of the block at 0xa802d290). FUN_a00a9650(position, 1) follows. Finally
 * FUN_a00a813c(1, v, position != v) is called with v = byte 0xa8025c55. Same loop as FUN_a0095c94.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);

void FUN_a009b434(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0xed);
    do {
        t = (unsigned short)_DAT_a802afec - 0xeb;
        t = t % 3;
        _DAT_a802afec = t + 0xed;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290[0x17b] = _DAT_a802afec - 0xed;
    FUN_a00a9650(_DAT_a802afec - 0xed, 1);
    {
        unsigned char v = DAT_a8025c55;
        if (_DAT_a802afec - 0xed == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}

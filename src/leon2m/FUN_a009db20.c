/* leon2m FUN_a009db20 @ 0xa009db20-0xa009dbd4 (45 words).
 * Steps the selection kept in word 0xa802afec forwards through the values 0x3c..0x3e (modulo 3). FUN_a00a93bc is
 * called with the current position (afec - 0x3c). Then t = ((low halfword of afec) - 0x3b) % 3 and afec = t + 0x3c
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. The new position is
 * stored in byte 0xa802d40c (offset 0x17c of the block at 0xa802d290). FUN_a00a9650(position, 1) follows. Finally
 * FUN_a00a813c(1, v, position != v) is called with v = byte 0xa8025c56. Same loop as FUN_a0095c94.
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

void FUN_a009db20(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0x3c);
    do {
        t = (unsigned short)_DAT_a802afec - 0x3b;
        t = t % 3;
        _DAT_a802afec = t + 0x3c;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290[0x17c] = _DAT_a802afec - 0x3c;
    FUN_a00a9650(_DAT_a802afec - 0x3c, 1);
    {
        unsigned char v = DAT_a8025c56;
        if (_DAT_a802afec - 0x3c == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}

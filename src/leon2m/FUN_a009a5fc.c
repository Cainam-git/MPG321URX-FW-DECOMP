/* leon2m FUN_a009a5fc @ 0xa009a5fc-0xa009a6c0 (49 words).
 * Steps the selection kept in word 0xa802afec backwards through the values 0x48..0x4d (modulo 6). FUN_a00a93bc is
 * called with the current position (afec - 0x48). Then t = ((low halfword of afec) - 0x43) % 6 and afec = t + 0x48
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. The new position is
 * stored in byte 0xa802d412 (offset 0x182 of the block at 0xa802d290). FUN_a00dbcf0 is called. FUN_a00a9650(position,
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
extern void FUN_a00dbcf0(void);

void FUN_a009a5fc(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0x48);
    do {
        t = (unsigned short)_DAT_a802afec - 0x43;
        t = t % 6;
        _DAT_a802afec = t + 0x48;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290[0x182] = _DAT_a802afec - 0x48;
    FUN_a00dbcf0();
    FUN_a00a9650(_DAT_a802afec - 0x48, 1);
    {
        unsigned char v = DAT_a8025c56;
        if (_DAT_a802afec - 0x48 == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}

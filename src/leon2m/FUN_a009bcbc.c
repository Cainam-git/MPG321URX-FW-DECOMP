/* leon2m FUN_a009bcbc @ 0xa009bcbc-0xa009bdcc (68 words).
 * Steps the selection kept in word 0xa802afec backwards through the values 0xd8..0xdc (modulo 5). FUN_a00a93bc is
 * called with the current position (afec - 0xd8). Then t = ((low halfword of afec) - 0xd4) % 5 and afec = t + 0xd8
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. The position is written
 * into bits 4..7 of word 0xa802d2c0 (offset 0x30 of the block at 0xa802d290), FUN_a00a9650(position, 1) and
 * FUN_a00d7a70(1) run, and FUN_a00a813c(1, v, position != v) is called with v = byte 0xa8025c55. Finally, for the
 * last position (afec 0xdc) FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1) are called, otherwise FUN_a00a9468(1, 3) and
 * FUN_a00b34d4(0, 4). Same loop as FUN_a0095c94. The 4-bit field is a bit-field.
 */
struct G290 {
    unsigned char pad0[0x30];
    unsigned int hi24 : 24;     /* 0xa802d2c0 */
    unsigned int f4 : 4;
    unsigned int lo4 : 4;
};
extern struct G290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00d7a70(int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a009bcbc(void)
{
    int t;
    unsigned char pos;

    FUN_a00a93bc(_DAT_a802afec - 0xd8);
    do {
        t = (unsigned short)_DAT_a802afec - 0xd4;
        t = t % 5;
        _DAT_a802afec = t + 0xd8;
    } while (FUN_a00aad30(t) != 1);
    pos = _DAT_a802afec - 0xd8;
    DAT_a802d290.f4 = pos;
    FUN_a00a9650(pos, 1);
    FUN_a00d7a70(1);
    if (_DAT_a802afec - 0xd8 == DAT_a8025c55)
        FUN_a00a813c(1, DAT_a8025c55, 0);
    else
        FUN_a00a813c(1, DAT_a8025c55, 1);
    if (_DAT_a802afec == 0xdc) {
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    } else {
        FUN_a00a9468(1, 3);
        FUN_a00b34d4(0, 4);
    }
}

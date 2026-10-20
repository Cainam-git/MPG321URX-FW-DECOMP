/* leon2m FUN_a009b070 @ 0xa009b070-0xa009b154 (57 words).
 * Steps word 0xa802afec forwards through the values 0xcd..0xcf (modulo 3). FUN_a00a93bc is
 * called with the current position (afec - 0xcd). Then t = ((low halfword of afec) - 0xcc) % 3 and afec = t + 0xcd
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. The setting is numbered
 * in reverse: 2 - position is stored in byte 0xa802d2c1 (offset 0x31 of the block at 0xa802d290), then
 * FUN_a00a9650(position, 1) and FUN_a00d7b20 run, and FUN_a00a813c(1, 2 - v, flag) is called with v = byte 0xa8025c55
 * and flag 0 when 2 - position equals v, 1 otherwise. Same loop as FUN_a0095c94.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00d7b20(void);

void FUN_a009b070(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0xcd);
    do {
        t = (unsigned short)_DAT_a802afec - 0xcc;
        t = t % 3;
        _DAT_a802afec = t + 0xcd;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290[0x31] = 2 - (_DAT_a802afec - 0xcd);
    FUN_a00a9650(_DAT_a802afec - 0xcd, 1);
    FUN_a00d7b20();
    if (2 - (_DAT_a802afec - 0xcd) == DAT_a8025c55)
        FUN_a00a813c(1, 2 - DAT_a8025c55, 0);
    else
        FUN_a00a813c(1, 2 - DAT_a8025c55, 1);
}

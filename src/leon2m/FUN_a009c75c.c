/* leon2m FUN_a009c75c @ 0xa009c75c-0xa009c83c (56 words).
 * Steps the selection kept in word 0xa802afec forwards through the values 0x77..0x79 (modulo 3). FUN_a00a93bc is
 * called with the current position (afec - 0x77). Then t = ((low halfword of afec) - 0x76) % 3 and afec = t + 0x77
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. The new position is
 * written into bits 18..19 of word 0xa802d33c (offset 0xac of the block at 0xa802d290). FUN_a00a813c(1, v, position
 * != v) is called with v = byte 0xa8025c56, and FUN_a00a9650(position, 1) ends the function. Same loop as
 * FUN_a0095c94. The two bits are a bit-field (a mask expression schedules the final or differently).
 */
struct G290 {
    unsigned char pad0[0xac];
    unsigned int hi12 : 12;     /* 0xa802d33c */
    unsigned int f18 : 2;
    unsigned int lo18 : 18;
};
extern struct G290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009c75c(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0x77);
    do {
        t = (unsigned short)_DAT_a802afec - 0x76;
        t = t % 3;
        _DAT_a802afec = t + 0x77;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290.f18 = _DAT_a802afec - 0x77;
    if (_DAT_a802afec - 0x77 == DAT_a8025c56)
        FUN_a00a813c(1, DAT_a8025c56, 0);
    else
        FUN_a00a813c(1, DAT_a8025c56, 1);
    FUN_a00a9650(_DAT_a802afec - 0x77, 1);
}

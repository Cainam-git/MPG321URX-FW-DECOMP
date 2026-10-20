/* leon2m FUN_a009a8dc @ 0xa009a8dc-0xa009aa34 (86 words).
 * Steps word 0xa802afec forwards through the values 0x53..0x55 (modulo 3). FUN_a00a93bc is
 * called with the current position (afec - 0x53). Then t = ((low halfword of afec) - 0x52) % 3 and afec = t + 0x53
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. For positions 1 and 2
 * the lowest bit of afec is written into bit 12 of word 0xa802d338 (offset 0xa8 of the block at 0xa802d290); for
 * position 0 the lowest bit of byte 0xa8025c56 is written there. FUN_a00a9650(position, 1) follows, and
 * FUN_a00a813c(1, v + 1, flag) is called with v = byte 0xa8025c56 and flag 0 when the position equals v + 1, 1
 * otherwise. Same loop as FUN_a0095c94. Bit 12 is a bit-field.
 */
struct G290 {
    unsigned char pad0[0xa8];
    unsigned int hi19 : 19;     /* 0xa802d338 */
    unsigned int b12 : 1;
    unsigned int lo12 : 12;
};
extern struct G290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009a8dc(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0x53);
    do {
        t = (unsigned short)_DAT_a802afec - 0x52;
        t = t % 3;
        _DAT_a802afec = t + 0x53;
    } while (FUN_a00aad30(t) != 1);
    if (_DAT_a802afec > 0x53)
        DAT_a802d290.b12 = _DAT_a802afec;
    else
        DAT_a802d290.b12 = DAT_a8025c56;
    FUN_a00a9650(_DAT_a802afec - 0x53, 1);
    if (_DAT_a802afec - 0x53 == DAT_a8025c56 + 1)
        FUN_a00a813c(1, DAT_a8025c56 + 1, 0);
    else
        FUN_a00a813c(1, DAT_a8025c56 + 1, 1);
}

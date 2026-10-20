/* leon2m FUN_a009b154 @ 0xa009b154-0xa009b20c (46 words).
 * Steps word 0xa802afec backwards through the values 0xdd..0xe1. FUN_a00a93bc is called with
 * the current position (afec - 0xdd). Then t = ((low halfword of afec) - 0xd9) % 5 and afec = t + 0xdd repeat until
 * FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. The new position is stored in byte
 * 0xa802d3ce (offset 0x13e of the block at 0xa802d290) and passed to FUN_a00a9650(position, 1). Finally
 * FUN_a00a813c(1, v, position != v) is called with v = byte 0xa8025c55.
 * Same loop as FUN_a0095c94 (there modulo 5 from base 0x4e, stepping forwards).
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009b154(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0xdd);
    do {
        t = (unsigned short)_DAT_a802afec - 0xd9;
        t = t % 5;
        _DAT_a802afec = t + 0xdd;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290[0x13e] = _DAT_a802afec - 0xdd;
    FUN_a00a9650(_DAT_a802afec - 0xdd, 1);
    {
        unsigned char v = DAT_a8025c55;
        if (_DAT_a802afec - 0xdd == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}

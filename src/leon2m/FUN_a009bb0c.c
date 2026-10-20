/* leon2m FUN_a009bb0c @ 0xa009bb0c-0xa009bbe4 (54 words).
 * Steps word 0xa802afec backwards through the values 0xea..0xec (modulo 3). FUN_a00a93bc is
 * called with the current position (afec - 0xea). Then t = ((low halfword of afec) - 0xe8) % 3 and afec = t + 0xea
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. The new position is
 * stored in byte 0xa802d2dc (offset 0x4c of the block at 0xa802d290), FUN_a00a9650(position, 1) and FUN_a00d5eac(1)
 * run, and FUN_a00a813c(1, v, position != v) is called with v = byte 0xa8025c55. Finally bit 1 of byte 0xa802b08e is
 * set and FUN_a014a8d4(1, 0, 0) is called. Same loop as FUN_a0095c94.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00d5eac(int);
extern void FUN_a014a8d4(int, int, int);

void FUN_a009bb0c(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0xea);
    do {
        t = (unsigned short)_DAT_a802afec - 0xe8;
        t = t % 3;
        _DAT_a802afec = t + 0xea;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290[0x4c] = _DAT_a802afec - 0xea;
    FUN_a00a9650(_DAT_a802afec - 0xea, 1);
    FUN_a00d5eac(1);
    if (_DAT_a802afec - 0xea == DAT_a8025c55)
        FUN_a00a813c(1, DAT_a8025c55, 0);
    else
        FUN_a00a813c(1, DAT_a8025c55, 1);
    DAT_a802b08e |= 2;
    FUN_a014a8d4(1, 0, 0);
}

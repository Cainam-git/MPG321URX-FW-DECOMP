/* leon2m FUN_a009ab58 @ 0xa009ab58-0xa009ac7c (73 words).
 * Steps word 0xa802afec forwards through the values 0x56..0x5b (modulo 6). FUN_a00a93bc is
 * called with the current position (afec - 0x56). Then t = ((low halfword of afec) - 0x55) % 6 and afec = t + 0x56
 * repeat until FUN_a00aad30(t) returns 1, so positions that FUN_a00aad30 rejects are skipped. For positions above 0,
 * position - 1 is stored in byte 0xa802d430 (offset 0x1a0 of the block at 0xa802d290); for position 0 byte 0xa8025c56
 * is copied there. FUN_a00a9650(position, 1) follows, and FUN_a00a813c(1, v + 1, flag) is called with v = byte
 * 0xa8025c56 and flag 0 when the position equals v + 1, 1 otherwise. Same loop as FUN_a0095c94.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009ab58(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0x56);
    do {
        t = (unsigned short)_DAT_a802afec - 0x55;
        t = t % 6;
        _DAT_a802afec = t + 0x56;
    } while (FUN_a00aad30(t) != 1);
    if (_DAT_a802afec > 0x56)
        DAT_a802d290[0x1a0] = _DAT_a802afec - 0x57;
    else
        DAT_a802d290[0x1a0] = DAT_a8025c56;
    FUN_a00a9650(_DAT_a802afec - 0x56, 1);
    if (_DAT_a802afec - 0x56 == DAT_a8025c56 + 1)
        FUN_a00a813c(1, DAT_a8025c56 + 1, 0);
    else
        FUN_a00a813c(1, DAT_a8025c56 + 1, 1);
}

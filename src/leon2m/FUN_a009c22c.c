/* leon2m FUN_a009c22c @ 0xa009c22c-0xa009c4a4 (158 words).
 * Steps word 0xa802afec forwards through 0x5c..0x63 (modulo 8). The positions form pages of 7.
 * FUN_a00a93bc is called with the current position within its page; then t = ((low halfword of afec) - 91) % 8 and
 * afec = t + 0x5c repeat until FUN_a00aad30(t) returns 1. FUN_a00b6b88(position, 1) gives a value that is stored in
 * byte 0xa802d411 (offset 0x181 of the block at 0xa802d290); when the page changed, FUN_a00b6bec(new page) is called.
 * When that stored value is 4..6, byte 0xa802d2a1 (offset 0x11) is set to 1 (written only when it differs),
 * otherwise it is set to byte 0xa8025c54. Then FUN_a00db738(), FUN_a00aacb4(2, 1) and FUN_a00a9650(position within
 * page, 1). Finally, when the page equals the page of w = FUN_a00b6b88(byte 0xa8025c56, 0), FUN_a00a813c(1, w % 7,
 * flag) is called with flag 0 when the position equals w and 1 otherwise.
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c54, DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);
extern void FUN_a00b6bec(unsigned char);
extern void FUN_a00db738(void);
extern void FUN_a00aacb4(int, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a009c22c(void)
{
    int t;
    unsigned char page;

    page = (_DAT_a802afec - 92) / 7;
    FUN_a00a93bc((_DAT_a802afec - 92) % 7);
    do {
        t = (unsigned short)_DAT_a802afec - 91;
        t = t % 8;
        _DAT_a802afec = t + 0x5c;
    } while (FUN_a00aad30(t) != 1);
    DAT_a802d290[0x181] = FUN_a00b6b88(_DAT_a802afec - 92, 1);
    if (page != (_DAT_a802afec - 92) / 7)
        FUN_a00b6bec((_DAT_a802afec - 92) / 7);
    if (DAT_a802d290[0x181] >= 4 && DAT_a802d290[0x181] <= 6) {
        if (DAT_a802d290[0x11] != 1)
            DAT_a802d290[0x11] = 1;
    } else
        DAT_a802d290[0x11] = DAT_a8025c54;
    FUN_a00db738();
    FUN_a00aacb4(2, 1);
    FUN_a00a9650((_DAT_a802afec - 92) % 7, 1);
    if ((_DAT_a802afec - 92) / 7 == FUN_a00b6b88(DAT_a8025c56, 0) / 7) {
        if (_DAT_a802afec - 92 == FUN_a00b6b88(DAT_a8025c56, 0))
            FUN_a00a813c(1, FUN_a00b6b88(DAT_a8025c56, 0) % 7, 0);
        else
            FUN_a00a813c(1, FUN_a00b6b88(DAT_a8025c56, 0) % 7, 1);
    }
}

/* DRV_HDMI21_Print_SCDC_Error (leon2s 0xa00795a0-0xa0079778, 472 bytes), flags -mcpu=v8 -Os -g.
 * Only for ports 2 and 3 (record index k = 0 / 1); returns 0. Under bit 11 of DAT_a8078634 prints
 * "[HDMI21]: \x1b[1m=%s=\n\x1b[m" with the function name. FUN_a00a7424(1, 0x14, p, 0x2e60),
 * FUN_a00a7424(1, 0x10, p, 0x2e60), FUN_a00b160c(1), FUN_a00a7424(0, 0x10, p, 0x2e60), FUN_a00b1794(1). Then
 * for ch below byte 0 of the 0xb0-byte record ARR_a807d680[k]: err[ch] = low (ch 0, 2) or high (ch 1, 3)
 * halfword of FUN_a00a7314(port, 0x2e64 for ch 0/1, 0x2e68 otherwise), printed as "[HDMI21]: # Port%c , ch%d,
 * H21 SCDC %ld \n" with 'A' + port, ch and err[ch] & 0x7fff under the same bit.
 * Source form: the FUN_a00a7424 calls take an unsigned char copy p of the port, the FUN_a00a7314 calls take
 * 'port & 0xff' (a separate AND per call: GCC does not see it as equal to the zero-extended copy).
 */
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned char reg, unsigned short val);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00b160c(unsigned int);
extern void FUN_a00b1794(unsigned int);
static const char fn_[] = "DRV_HDMI21_Print_SCDC_Error";

int DRV_HDMI21_Print_SCDC_Error(unsigned int port)
{
    unsigned int err[4] = {0, 0, 0, 0};
    unsigned char p = port;
    unsigned char k;
    unsigned char ch;

    if (p == 2)
        k = 0;
    else if (p == 3)
        k = 1;
    else
        return 0;
    if (DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]: \x1b[1m=%s=\n\x1b[m", fn_);
    FUN_a00a7424(1, 0x14, p, 0x2e60);
    FUN_a00a7424(1, 0x10, p, 0x2e60);
    FUN_a00b160c(1);
    FUN_a00a7424(0, 0x10, p, 0x2e60);
    FUN_a00b1794(1);
    for (ch = 0; ch < ARR_a807d680[k][0]; ch++) {
        if (ch == 0)
            err[0] = FUN_a00a7314(port & 0xff, 0x2e64) & 0xffff;
        else if (ch == 1)
            err[1] = FUN_a00a7314(port & 0xff, 0x2e64) >> 16;
        else if (ch == 2)
            err[2] = FUN_a00a7314(port & 0xff, 0x2e68) & 0xffff;
        else
            err[ch] = FUN_a00a7314(port & 0xff, 0x2e68) >> 16;
        if (DAT_a8078634 & 0x800)
            FUN_a0073044("[HDMI21]: # Port%c , ch%d, H21 SCDC %ld \n", (char)(port + 'A'), ch, err[ch] & 0x7fff);
    }
    return 0;
}

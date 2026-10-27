/* DRV_HDMI21_RX_SCDC_Chk_Err (leon2s 0xa0098bb0-0xa0098e88, 728 bytes), flags -mcpu=v8 -Os -g.
 * unsigned char (unsigned char idx). idx 0 / 1 selects port 2 / 3; any other idx returns 0. With bit 0x800 of
 * DAT_a8078634 set it prints the function name (s_a00b4318) through DAT_a0067868. Writes register 0x2e60 of
 * the port with FUN_a00a7424 (masks 0x14 / 0x10 set, FUN_a00b160c(1), mask 0x10 cleared, FUN_a00b1794(1)), then
 * for ch below the count byte of ARR_a807d680[idx] reads the error counter of channel ch (low / high halfword of
 * registers 0x2e64 and 0x2e68 via FUN_a00a7314), stores its low 15 bits into the record's halfword array at
 * ch * 2 + DAT_a807cc50[ch], and clears (value 0x8000 or at most 0x801e) or sets bit ch of the result; each case
 * is printed (DAT_a0069ce8 / DAT_a0069d20 / DAT_a0069d60) under the same flag, and the final result with
 * s_a0069da0. Returns the result bits.
 */
struct ScdcRec {
    unsigned char cnt;
    unsigned char _1[0x19];
    unsigned short err[(0xb0 - 0x1a) / 2];
};
extern struct ScdcRec ARR_a807d680[];
extern unsigned char DAT_a807cc50[];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned char reg, unsigned short val);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00b160c(unsigned int);
extern void FUN_a00b1794(unsigned int);
extern const char DAT_a0067868[], s_a00b4318[], DAT_a0069ce8[], DAT_a0069d20[], DAT_a0069d60[], s_a0069da0[];

unsigned char DRV_HDMI21_RX_SCDC_Chk_Err(unsigned char idx)
{
    unsigned int err[4] = {0, 0, 0, 0};
    unsigned int port;
    unsigned char ret = 0;
    unsigned char ch;

    if (idx == 0)
        port = 2;
    else if (idx == 1)
        port = 3;
    else
        return 0;
    if (DAT_a8078634 & 0x800)
        FUN_a0073044(DAT_a0067868, s_a00b4318);
    FUN_a00a7424(1, 0x14, port, 0x2e60);
    FUN_a00a7424(1, 0x10, port, 0x2e60);
    FUN_a00b160c(1);
    FUN_a00a7424(0, 0x10, port, 0x2e60);
    FUN_a00b1794(1);
    for (ch = 0; ch < ARR_a807d680[idx].cnt; ch++) {
        if (ch == 0)
            err[0] = FUN_a00a7314(port & 0xff, 0x2e64) & 0xffff;
        else if (ch == 1)
            err[1] = FUN_a00a7314(port & 0xff, 0x2e64) >> 16;
        else if (ch == 2)
            err[2] = FUN_a00a7314(port & 0xff, 0x2e68) & 0xffff;
        else
            err[ch] = FUN_a00a7314(port & 0xff, 0x2e68) >> 16;
        ARR_a807d680[idx].err[ch * 2 + DAT_a807cc50[ch]] = err[ch] & 0x7fff;
        if (err[ch] == 0x8000) {
            if (DAT_a8078634 & 0x800)
                FUN_a0073044(DAT_a0069ce8, (char)(port + 'A'), ch, err[ch] & 0x7fff);
            ret &= ~(1 << ch);
        } else if (err[ch] <= 0x801e) {
            if (DAT_a8078634 & 0x800)
                FUN_a0073044(DAT_a0069d20, (char)(port + 'A'), ch, err[ch] & 0x7fff);
            ret &= ~(1 << ch);
        } else {
            if (DAT_a8078634 & 0x800)
                FUN_a0073044(DAT_a0069d60, (char)(port + 'A'), ch, err[ch] & 0x7fff);
            ret |= 1 << ch;
        }
    }
    if (DAT_a8078634 & 0x800)
        FUN_a0073044(s_a0069da0, ret & 0xff);
    return ret;
}

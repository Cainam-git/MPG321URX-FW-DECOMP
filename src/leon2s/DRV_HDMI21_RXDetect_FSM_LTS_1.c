/* leon2s DRV_HDMI21_RXDetect_FSM_LTS_1 @ 0xa0098240-0xa0098300 (48 words), flags -mcpu=v8 -Os -g.
 * Code facts: u8 port. r = FUN_a00961e8(port) (u8). rec = 0xb0-byte record port of DAT_a807d680; if the
 * state word DAT_a807d648[port] != rec word +0x30: if bit 0x800 of _DAT_a8078634, print s_a0067868 with
 * s_a00b4298 (2 args; the function-name string); then rec +0x30 = state. If byte +6 of the 24-byte entry
 * r of DAT_a807cc64 == 1: print s_a0069be8 (1 arg) and state = 2. Returns 0.
 * Fixes vs the autoc draft (75.00, did not compile): FUN_a00961e8 takes the port (fw %o0 = port) and
 * returns u8; the print strings are symbols (s_a0067868 + s_a00b4298, s_a0069be8); written in the form of
 * the accepted twin DRV_HDMI21_RXDetect_FSM_LTS_2 (record pointer + state array). Aids: none.
 */
extern unsigned int _DAT_a8078634;
extern unsigned int DAT_a807d648[];
extern unsigned char DAT_a807d680[];
extern unsigned char DAT_a807cc64[];
extern char s_a0067868[], s_a00b4298[], s_a0069be8[];
extern int FUN_a0073044(const char *, ...);
extern unsigned char FUN_a00961e8(unsigned char);

unsigned int DRV_HDMI21_RXDetect_FSM_LTS_1(unsigned char param_1)
{
    unsigned char r;
    unsigned int *rec;

    r = FUN_a00961e8(param_1);
    rec = (unsigned int *)(DAT_a807d680 + param_1 * 0xb0);
    if (DAT_a807d648[param_1] != rec[0xc]) {
        if (_DAT_a8078634 & 0x800)
            FUN_a0073044(s_a0067868, s_a00b4298);
        rec[0xc] = DAT_a807d648[param_1];
    }
    if (DAT_a807cc64[r * 24 + 6] == 1) {
        FUN_a0073044(s_a0069be8);
        DAT_a807d648[param_1] = 2;
    }
    return 0;
}

/* 8051_bank1 FUN_CODE_760c @ 0x760c..0x7765 (345 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Range checks on values read with FUN_CODE_dd74 (8-bit register read) and FUN_CODE_d9a5 (16-bit read); returns
 * 0 (carry clear) on the first failed check, else 1:
 *   v = dd74(0x23) must be 1..15; dd74(0x22) must not exceed (d9a5(0x12) & 0x1FFF) / 8 / 6;
 *   d9a5(0x12) & 0x1FFF and d9a5(0x14) & 0x1FFF must be at least 0x280 / 0x200 (compared as unsigned long) and not
 *   0x1FFF; w = d9a5(0x26) + 1 must be at least 200; v = dd74(0x22) as float must not exceed 60.26 (w < 380),
 *   50.3 (w < 730) or 30.38 (otherwise).
 * LARGE locals: v at XDATA 0xA476, w at 0xA478.
 * Caller: FUN_CODE_c0a1 (LCALL at 0xC0D9).
 */
extern unsigned char FUN_CODE_dd74(unsigned char reg);
extern unsigned int FUN_CODE_d9a5(unsigned char reg);

bit FUN_CODE_760c(void)
{
    unsigned int v;
    unsigned int w;

    v = FUN_CODE_dd74(0x23);
    if (v > 15 || v == 0)
        return 0;
    v = FUN_CODE_dd74(0x22);
    w = FUN_CODE_d9a5(0x12) & 0x1fff;
    if (v > (w >> 3) / 6)
        return 0;
    v = FUN_CODE_d9a5(0x12) & 0x1fff;
    if (v < 0x280UL || v == 0x1fff)
        return 0;
    v = FUN_CODE_d9a5(0x14) & 0x1fff;
    if (v < 0x200UL || v == 0x1fff)
        return 0;
    v = FUN_CODE_dd74(0x22);
    w = FUN_CODE_d9a5(0x26) + 1;
    if (w < 200)
        return 0;
    if (w < 380) {
        if (v > 60.26)
            return 0;
    } else if (w < 730) {
        if (v > 50.3)
            return 0;
    } else {
        if (v > 30.38)
            return 0;
    }
    return 1;
}

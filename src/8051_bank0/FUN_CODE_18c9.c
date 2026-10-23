/* 8051_bank0 FUN_CODE_18c9 @ 0x18c9  STBC boot loader: SPI bus-mode factor by XDATA 0xD511
 * (OPTIMIZE(7,SPEED)).
 * Returns 0 when FUN_CODE_18bb() reports XDATA 0xD511 == 0x20, else 1. Its only caller is the
 * boot loader main FUN_CODE_151c (LCALL at 0x152e), which multiplies the result by 4 and writes it to XDATA 0xF0E6
 * (SPI flash bus mode register).
 */
bit FUN_CODE_18bb(void);

unsigned char FUN_CODE_18c9(void)
{
    unsigned char r = 1;
    if (FUN_CODE_18bb()) {
        r--;            /* variant 0x20 -> 0 */
    } else {
        r = 1;
    }
    return r;
}

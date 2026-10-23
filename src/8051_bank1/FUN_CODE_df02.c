/* 8051_bank1 FUN_CODE_df02 @ 0xdf02 (unlisted code found in a gap of the function table).
 * Sets bit 0x0D (BITS_21_5, bit 5 of byte 0x21). No caller in the image; FUN_CODE_df05 clears and FUN_CODE_df08
 * returns the same bit.
 */
extern bit BITS_21_5;
void FUN_CODE_df02(void)
{
    BITS_21_5 = 1;
}

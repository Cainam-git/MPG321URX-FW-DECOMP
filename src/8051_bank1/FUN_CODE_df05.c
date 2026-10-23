/* 8051_bank1 FUN_CODE_df05 @ 0xdf05 (unlisted code found in a gap of the function table).
 * Clears bit 0x0D (BITS_21_5, bit 5 of byte 0x21). No caller in the image.
 */
extern bit BITS_21_5;
void FUN_CODE_df05(void)
{
    BITS_21_5 = 0;
}

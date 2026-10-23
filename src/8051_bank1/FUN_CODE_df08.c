/* 8051_bank1 FUN_CODE_df08 @ 0xdf08 (unlisted code found in a gap of the function table).
 * Returns bit 0x0D (BITS_21_5) in the carry flag (MOV C,0DH; RET). No caller in the image.
 */
extern bit BITS_21_5;
bit FUN_CODE_df08(void)
{
    return BITS_21_5;
}

/* sys_test_flag_0x0d  (FUN_CODE_df08)
 *
 * Return flag bit 0x0D.
 * Returns: flag
 * Note: Not called anywhere.
 * Name basis: descriptive - bit 0x0D (byte 0x21 bit 5); no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_df08 @ 0xdf08 (code in a gap of the function table): MOV C,0DH; RET.
 */
extern bit BITS_21_5;   /* bit address 0x0D = bit 5 of the byte at 0x21 */

/*
 * Return bit 0x0D, which sys_set_flag_0x0d sets and sys_clear_flag_0x0d clears. No other code uses the bit, and
 * nothing in this program calls this routine.
 */
bit sys_test_flag_0x0d(void)
{
    return BITS_21_5;
}

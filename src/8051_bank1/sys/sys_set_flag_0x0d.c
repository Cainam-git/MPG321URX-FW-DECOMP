/* sys_set_flag_0x0d  (FUN_CODE_df02)
 *
 * Set flag bit 0x0D.
 * Note: Not called anywhere.
 * Name basis: descriptive - bit 0x0D (byte 0x21 bit 5); no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_df02 @ 0xdf02 (code in a gap of the function table): SETB 0DH; RET.
 */
extern bit BITS_21_5;   /* bit address 0x0D = bit 5 of the byte at 0x21 */

/*
 * Set bit 0x0D. sys_clear_flag_0x0d clears it and sys_test_flag_0x0d returns it; no other code uses the bit, and
 * nothing in this program calls any of the three.
 */
void sys_set_flag_0x0d(void)
{
    BITS_21_5 = 1;
}

/* sys_clear_flag_0x0d  (FUN_CODE_df05)
 *
 * Clear flag bit 0x0D.
 * Note: Not called anywhere.
 * Name basis: descriptive - bit 0x0D (byte 0x21 bit 5); no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_df05 @ 0xdf05 (code in a gap of the function table): CLR 0DH; RET.
 */
extern bit BITS_21_5;   /* bit address 0x0D = bit 5 of the byte at 0x21 */

/*
 * Clear bit 0x0D. Twin of sys_set_flag_0x0d; no other code uses the bit, and nothing in this program calls this
 * routine.
 */
void sys_clear_flag_0x0d(void)
{
    BITS_21_5 = 0;
}

/* 8051_bank1 FUN_CODE_df0b @ 0xdf0b (3 bytes)
 * Default OPTIMIZE(7,SPEED).
 * Returns bit 0x0E (BITS_21_6, bit 6 of byte 0x21) in the carry flag: MOV C,0x0E / RET.
 * Caller: FUN_CODE_d7d2 (LCALL at 0xD7D2, then JNC). The bit is set by FUN_CODE_71f0 and FUN_CODE_7a0b and cleared
 * in FUN_CODE_b06f (0xB074).
 */
extern bit BITS_21_6;

bit FUN_CODE_df0b(void)
{
    return BITS_21_6;
}

/* 8051_bank1 FUN_CODE_deb0 @ 0xdeb0 (mechanical draft at 72.7 %, finished by hand)
 * Test-and-clear of bit 0x11 (BITS_22_1): b = bit; bit = 0; return b (local bit b = BIT 0x00).
 * Callers 0x4199, 0x41e0. Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern bit BITS_22_1;
bit FUN_CODE_deb0(void)
{
    bit b;
    b = BITS_22_1;
    BITS_22_1 = 0;
    return b;
}

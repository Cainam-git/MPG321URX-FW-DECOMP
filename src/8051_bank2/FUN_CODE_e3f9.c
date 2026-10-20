/* 8051_bank2 FUN_CODE_e3f9 @ 0xe3f9
 * Returns 1 when bit 0 of the 32-bit FOTG210 register 0x30 (FUN_CODE_9b91, unsigned long as in FUN_CODE_5c20) is set,
 * else 0; the == 1 test is a long compare (?C?ULCMP at 0x342d). 7 call sites (0x6e42.., 0xbae8..).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE (also OPTIMIZE(7,SPEED)): MATCH exact None 32/32.
 */
unsigned long FUN_CODE_9b91(unsigned int reg);
unsigned char FUN_CODE_e3f9(void)
{
    if ((FUN_CODE_9b91(0x0030) & 1) == 1) return 1;
    return 0;
}

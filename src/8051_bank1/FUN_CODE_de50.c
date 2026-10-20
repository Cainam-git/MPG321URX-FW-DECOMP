/* 8051_bank1 FUN_CODE_de50 @ 0xde50 (no usable draft; not the bank-2 FUN_CODE_de50)
 * bit: 1 when FUN_CODE_ce87() returns 0xFF (CPL A / JZ), else 0. Only caller 0x39ee.
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
unsigned char FUN_CODE_ce87(void);
bit FUN_CODE_de50(void)
{
    if (FUN_CODE_ce87() != 0xff) return 0;
    return 1;
}

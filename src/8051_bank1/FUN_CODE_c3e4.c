/* 8051_bank1 FUN_CODE_c3e4 @ 0xc3e4 (90 B)  Byte-exact with OPTIMIZE(7,SPEED) LARGE.
 * Reads two 16-bit values with FUN_CODE_d9a5: a = register 0x12 masked to 13 bits, b = register 0x14, and returns
 * b * 256 / a rounded to the nearest integer, computed in single-precision float with the Keil float library
 * (?C?FCAST, ?C?FPMUL by 256.0 = 0x43800000, ?C?FPDIV, ?C?FPADD of 0.5 = 0x3F000000, ?C?CASTF).
 * Callers: FUN_CODE_c0a1 (0xC0DE) and FUN_CODE_cf38 (0xCF5A); both test the result against 100.
 * LARGE: a is kept in its XDATA slot 0xA476..0xA477 across the second call.
 */
extern unsigned int FUN_CODE_d9a5(unsigned char reg);

unsigned int FUN_CODE_c3e4(void)
{
    unsigned int a, b;

    a = FUN_CODE_d9a5(0x12) & 0x1fff;
    b = FUN_CODE_d9a5(0x14);
    return b * 256.0 / a + 0.5;
}

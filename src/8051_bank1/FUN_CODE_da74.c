/* 8051_bank1 FUN_CODE_da74 @ 0xda74 (no draft)
 * Clears bit 0x18 (BITS 23.0), then returns 1 when bits 2..3 of byte 0x10 of the buffer at the generic pointer in
 * XDATA 0xA76D..0xA76F are both set, else 0 (?C?CLDOPTR at 0x06bd with DPTR = 0x10).
 * Callers 0xd7f9, 0xdb96, 0xdbaf (none of them inside a functions.json entry).
 * Byte-exact with OPTIMIZE(8,SPEED) (MATCH exact None 29/29).
 */
extern bit DAT_BIT_0018;
extern unsigned char * xdata DAT_EXTMEM_a76d;
unsigned char FUN_CODE_da74(void)
{
    unsigned char r;
    DAT_BIT_0018 = 0;
    r = 0;
    if ((DAT_EXTMEM_a76d[0x10] & 0x0c) == 0x0c) r++;
    return r;
}

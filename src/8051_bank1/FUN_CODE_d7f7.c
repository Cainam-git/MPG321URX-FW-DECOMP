/* 8051_bank1 FUN_CODE_d7f7 @ 0xd7f7..0xd81c (37 B)
 * bit FUN_CODE_d7f7(void): clears bit 0x1D (BITS_23_5); r = FUN_CODE_da74(); sets the bit when r == 0 and XDATA
 * 0xA672 > 0xD4, or when r == 1 and XDATA 0xA673 > 0xD4; returns the bit.
 * No LCALL or LJMP to 0xD7F7 occurs in the bank-1 image (the 'AJMP 0xD802' Ghidra shows at 0xDAC4 is inside the
 * ?C?LSTKXDATA constant of FUN_CODE_daad).
 */
extern unsigned char xdata DAT_EXTMEM_a672, DAT_EXTMEM_a673;
extern bit BITS_23_5;
extern unsigned char FUN_CODE_da74(void);

bit FUN_CODE_d7f7(void)
{
    unsigned char r;

    BITS_23_5 = 0;
    r = FUN_CODE_da74();
    if (r == 0 && DAT_EXTMEM_a672 > 0xd4) BITS_23_5 = 1;
    if (r == 1 && DAT_EXTMEM_a673 > 0xd4) BITS_23_5 = 1;
    return BITS_23_5;
}

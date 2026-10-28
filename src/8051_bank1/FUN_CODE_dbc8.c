/* 8051_bank1 FUN_CODE_dbc8 @ 0xdbc8 (23 B)
 * Clears bit n of the XDATA byte 0xA0F3: DAT_EXTMEM_a0f3 = old & ~(1 << n). FUN_CODE_dee2 returns the same byte.
 * Options: OPTIMIZE(7,SPEED) (also level 8).
 * Source form: the old byte is read into a local first.
 */

extern unsigned char xdata DAT_EXTMEM_a0f3;

void FUN_CODE_dbc8(unsigned char n)
{
    unsigned char t;

    t = DAT_EXTMEM_a0f3;
    DAT_EXTMEM_a0f3 = t & ~(1 << n);
}

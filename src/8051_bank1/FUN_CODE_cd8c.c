/* 8051_bank1 FUN_CODE_cd8c @ 0xcd8c
 * unsigned long XDATA 0xA711 - XDATA 0xA70D - XDATA 0xA717. 0xA70D / 0xA711 are read as one run (INC DPTR from
 * 0xA710 to 0xA711), so they are one array of two longs here; FUN_CODE_da91 reads 0xA711 alone. Only caller 0x242b.
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned long xdata DAT_EXTMEM_a70d[];
extern unsigned long xdata DAT_EXTMEM_a717;
unsigned long FUN_CODE_cd8c(void)
{
    return DAT_EXTMEM_a70d[1] - DAT_EXTMEM_a70d[0] - DAT_EXTMEM_a717;
}

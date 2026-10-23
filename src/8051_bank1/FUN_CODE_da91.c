/* 8051_bank1 FUN_CODE_da91 @ 0xda91
 * FUN_CODE_8b58(sector, 0x20) with sector = XDATA 0xA711 (unsigned long) / 0x1000 (?C?ULDIV at 0x083c, divisor
 * in R0..R3 = 00 00 10 00); 8b58 = the erase routine (sector, cmd), cmd 0x20. Tail LJMP.
 * Only caller 0x2456. Byte-exact with OPTIMIZE(8,SPEED).
 */
extern unsigned long xdata DAT_EXTMEM_a711;
void FUN_CODE_8b58(unsigned int sector, unsigned char cmd);

void FUN_CODE_da91(void)
{
    FUN_CODE_8b58(DAT_EXTMEM_a711 / 0x1000, 0x20);
}

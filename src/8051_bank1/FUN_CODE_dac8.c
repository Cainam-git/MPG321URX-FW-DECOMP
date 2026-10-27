/* 8051_bank1 FUN_CODE_dac8 @ 0xdac8..0xdae3 (27 B)
 * Stores the Timer 0 reload 0xFF06 (XDATA 0xA773 = 0x06 low byte, 0xA772 = 0xFF high byte) and tail-jumps to
 * FUN_CODE_9975(1, 4800). Same shape as FUN_CODE_daad (reload 0xFC18).
 * No LCALL or LJMP to 0xDAC8 occurs in the bank-1 image.
 */
extern unsigned char xdata DAT_EXTMEM_a773, DAT_EXTMEM_a772;
extern void FUN_CODE_9975(unsigned char a, unsigned long b) large;

void FUN_CODE_dac8(void)
{
    DAT_EXTMEM_a773 = 0x06;
    DAT_EXTMEM_a772 = 0xff;
    FUN_CODE_9975(1, 4800);
}

/* 8051_bank1 FUN_CODE_daad @ 0xdaad..0xdac8 (27 B)  Byte-exact with OPTIMIZE(8,SPEED) over 0xDAAD..0xDAC8.
 * Stores the fixed Timer 0 reload 0xFC18 (XDATA 0xA773 = 0x18 low byte, 0xA772 = 0xFC high byte) and tail-jumps
 * to FUN_CODE_9975(1, 4800). Same tail as FUN_CODE_cd07, which computes the reload instead.
 * Callers: FUN_CODE_71f0 (0x734A), FUN_CODE_7a0b (0x7B52), FUN_CODE_d5c8 (0xD5F0).
 */
extern unsigned char xdata DAT_EXTMEM_a773, DAT_EXTMEM_a772;
extern void FUN_CODE_9975(unsigned char a, unsigned long b) large;

void FUN_CODE_daad(void)
{
    DAT_EXTMEM_a773 = 0x18;
    DAT_EXTMEM_a772 = 0xfc;
    FUN_CODE_9975(1, 4800);
}

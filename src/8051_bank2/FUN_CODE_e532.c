/* 8051_bank2 FUN_CODE_e532 @ 0xe532..0xe53b: stores the 16-bit parameter v (R6:R7) into the unsigned int at
 * XDATA 0x0156 (high byte first, as Keil stores an int). Entered by tail jumps (LJMP) from FUN_CODE_8cdc at 0x8f92
 * with v = 0 and from FUN_CODE_a36c at 0xa496 with v = (XDATA[0xF19A] << 8) | XDATA[0xF19B]; FUN_CODE_ad56 clears
 * the same word directly.
 */
extern unsigned int xdata DAT_EXTMEM_0156;

void FUN_CODE_e532(unsigned int v)
{
    DAT_EXTMEM_0156 = v;
}

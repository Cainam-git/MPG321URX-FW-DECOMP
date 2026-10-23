/* 8051_bank1 FUN_CODE_0016 @ 0x0016  OPTIMIZE(7,SPEED), twin of 8051_bank0/FUN_CODE_18d6
 * Same instruction shape as FUN_CODE_18d6 (src/8051_bank0/FUN_CODE_18d6.c); the addresses and constants are the ones in the code below.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5;

void FUN_CODE_0016(void)
{
    DAT_EXTMEM_f0e5 |= 0x40;
    DAT_EXTMEM_f0e5 &= 0xbf;
}

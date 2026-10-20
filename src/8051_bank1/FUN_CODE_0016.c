/* 8051_bank1 FUN_CODE_0016 @ 0x0016  MATCH (OPTIMIZE(7,SPEED), twin of 8051_bank0/FUN_CODE_18d6)
 * twin of 8051_bank0/FUN_CODE_18d6: byte-exact.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5;

void FUN_CODE_0016(void)
{
    DAT_EXTMEM_f0e5 |= 0x40;
    DAT_EXTMEM_f0e5 &= 0xbf;
}

/* 8051_bank1 FUN_CODE_ddb6 @ 0xddb6
 * bit n of XDATA 0xA3E3 (shift loop, result through RRC into C). Only caller 0x3a06.
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned char xdata DAT_EXTMEM_a3e3;
bit FUN_CODE_ddb6(unsigned char n)
{
    return (DAT_EXTMEM_a3e3 >> n) & 1;
}

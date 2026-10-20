/* 8051_bank1 FUN_CODE_de03 @ 0xde03
 * XDATA 0xA73A (unsigned int, big-endian A73A/A73B) = v; XDATA 0xA739 = 1. Only caller 0x2579.
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned int xdata DAT_EXTMEM_a73a;
extern unsigned char xdata DAT_EXTMEM_a739;
void FUN_CODE_de03(unsigned int v)
{
    DAT_EXTMEM_a73a = v;
    DAT_EXTMEM_a739 = 1;
}

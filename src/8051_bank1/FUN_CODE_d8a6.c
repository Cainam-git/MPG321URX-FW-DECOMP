/* 8051_bank1 FUN_CODE_d8a6 @ 0xd8a6
 * Register bank 3. r = FUN_CODE_de20(XDATA 0xD929 & 0x0F) (accepted de20 = unsigned char (unsigned char) using 3);
 * XDATA 0xDCB1 = r * 9, 0xDCB2 = r * 15 (INC DPTR: one array). Only caller 0xd244.
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned char xdata DAT_EXTMEM_d929;
extern unsigned char xdata DAT_EXTMEM_dcb1[];
unsigned char FUN_CODE_de20(unsigned char a);
void FUN_CODE_d8a6(void) using 3
{
    unsigned char r;
    r = FUN_CODE_de20(DAT_EXTMEM_d929 & 0x0f);
    DAT_EXTMEM_dcb1[0] = r * 9;
    DAT_EXTMEM_dcb1[1] = r * 15;
}

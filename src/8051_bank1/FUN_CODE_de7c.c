/* 8051_bank1 FUN_CODE_de7c @ 0xde7c  OPTIMIZE(7,SPEED)
 * 
 */
extern xdata unsigned char DAT_EXTMEM_dcb1;
extern xdata unsigned char DAT_EXTMEM_dcb2;

void FUN_CODE_de7c(void)
{
    unsigned char xdata *dp = &DAT_EXTMEM_dcb1;
    *dp = 0x09;
    dp++;
    *dp = 0x0f;
}

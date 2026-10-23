/* 8051_bank1 FUN_CODE_dbf6 @ 0xdbf6  OPTIMIZE(7,SPEED)
 * 
 */
extern xdata unsigned char DAT_EXTMEM_d511;

unsigned long FUN_CODE_dbf6(void)
{
    if (DAT_EXTMEM_d511 == 0x20) {
        return 0x0FA0UL;
    }
    return 0x1F40UL;
}

/* 8051_bank1 FUN_CODE_de45 @ 0xde45  OPTIMIZE(7,SPEED)
 * c != 0: XDATA 0xA715 = c and 0xA716 = 0.
 */
extern xdata unsigned char DAT_EXTMEM_a715;
extern xdata unsigned char DAT_EXTMEM_a716;

void FUN_CODE_de45(char param_1)
{
    if (param_1 != 0) {
        DAT_EXTMEM_a715 = param_1;
        *(unsigned char xdata *)(&DAT_EXTMEM_a715 + 1) = 0;
    }
}

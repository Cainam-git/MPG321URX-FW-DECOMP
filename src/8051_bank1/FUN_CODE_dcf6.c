/* 8051_bank1 FUN_CODE_dcf6 @ 0xdcf6  OPTIMIZE(7,SPEED)
 * XDATA 0xF053 = 0x83, 0xF055 = 0x06, then FUN_CODE_c389(1, 0) (first byte argument in R7 = 1, second in R5 = 0).
 */
extern xdata unsigned char DAT_EXTMEM_f053;
extern xdata unsigned char DAT_EXTMEM_f055;
void FUN_CODE_c389(unsigned char, unsigned char);

void FUN_CODE_dcf6(void)
{
    DAT_EXTMEM_f053 = 0x83;
    DAT_EXTMEM_f055 = 0x06;
    FUN_CODE_c389(1, 0);
}

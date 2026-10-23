/* 8051_bank1 FUN_CODE_dedc @ 0xdedc  OPTIMIZE(7,SPEED)
 * Returns XDATA 0xA759. Same code as FUN_CODE_00f6 with other addresses and constants.
 */
unsigned char xdata DAT_EXTMEM_a759 _at_ 0xa759;

unsigned char FUN_CODE_dedc(void) {
    return DAT_EXTMEM_a759;
}

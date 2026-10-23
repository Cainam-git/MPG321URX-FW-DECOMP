/* 8051_bank1 FUN_CODE_deb9 @ 0xdeb9  OPTIMIZE(7,SPEED)
 * Copies the byte at XDATA 0xA565 to XDATA 0xA564 (two MOVX accesses through DPTR). No calls, branches or loops.
 */
extern unsigned char xdata DAT_EXTMEM_a565;
extern unsigned char xdata DAT_EXTMEM_a564;

void FUN_CODE_deb9(void) {
    DAT_EXTMEM_a564 = DAT_EXTMEM_a565;
}

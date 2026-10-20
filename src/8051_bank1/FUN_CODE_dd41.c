/* 8051_bank1 FUN_CODE_dd41 @ 0xdd41  MATCH (OPTIMIZE(7,SPEED))
 * Clears the byte at XDATA 0xA629, then stores the 16-bit return value of FUN_CODE_d94a (R6:R7) big-endian to
 * XDATA 0xA5EB/0xA5EC. FUN_CODE_d94a returns unsigned int; the function itself takes no parameters.
 */
extern xdata unsigned char DAT_EXTMEM_a629;
extern unsigned int FUN_CODE_d94a(void);

void FUN_CODE_dd41(void) {
    DAT_EXTMEM_a629 = 0;
    *((unsigned int xdata *)0xa5eb) = FUN_CODE_d94a();
}

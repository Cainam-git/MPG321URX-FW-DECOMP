/* 8051_bank1 FUN_CODE_deee @ 0xdeee  MATCH (OPTIMIZE(8,SPEED))
 * Writes the byte parameter (R7) to XDATA 0xA62E: DPTR is loaded with the address, R7 is moved to A, and a MOVX
 * store follows.
 */
void FUN_CODE_deee(unsigned char param) {
    *(unsigned char xdata *)0xa62e = param;
}

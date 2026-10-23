/* 8051_bank1 FUN_CODE_dec2 @ 0xdec2  OPTIMIZE(7,SPEED)
 * Writes param_1 to XDATA 0xA73C and param_2 to 0xA73D. The two-byte array at 0xA73C produces one MOV DPTR,#0xA73C
 * followed by MOVX @DPTR,A / INC DPTR / MOVX @DPTR,A.
 */
xdata unsigned char DAT_EXTMEM_a73c[2] _at_ 0xa73c;

void FUN_CODE_dec2(unsigned char param_1, unsigned char param_2) {
    DAT_EXTMEM_a73c[0] = param_1;
    DAT_EXTMEM_a73c[1] = param_2;
}

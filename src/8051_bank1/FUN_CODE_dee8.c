/* 8051_bank1 FUN_CODE_dee8 @ 0xdee8  OPTIMIZE(8,SPEED)
 * Stores the 32-bit value v (R4..R7) to XDATA 0xA717: 'MOV DPTR,#0xA717' followed by a tail jump to the library
 * routine ?C?LSTXDATA (FUN_CODE_09b1). The value is already in R4..R7, so no register moves precede the store.
 */
void FUN_CODE_dee8(unsigned long v) {
    *(unsigned long xdata *)0xa717 = v;
}

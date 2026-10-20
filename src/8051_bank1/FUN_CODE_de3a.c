/* 8051_bank1 FUN_CODE_de3a @ 0xde3a  MATCH (OPTIMIZE(7,SPEED))
 * Stores p1 (R7) to XDATA 0xD820 and p2 (R5) to XDATA 0xD810. The _at_ variable declarations produce
 * 'MOV DPTR,#addr; MOV A,Rn; MOVX @DPTR,A' for each store, in source order.
 */
unsigned char xdata DAT_EXTMEM_d820 _at_ 0xD820;
unsigned char xdata DAT_EXTMEM_d810 _at_ 0xD810;

void FUN_CODE_de3a(unsigned char p1, unsigned char p2) {
    DAT_EXTMEM_d820 = p1;
    DAT_EXTMEM_d810 = p2;
}

/* 8051_bank1 FUN_CODE_decb @ 0xdecb  MATCH (OPTIMIZE(7,SPEED))
 * Stores param_1 (R7) at xdata 0xA73E and param_2 (R5) at xdata 0xA73F. The xdata pointer with an increment
 * between the two stores produces the firmware sequence
 * MOV DPTR,#0xA73E; MOV A,R7; MOVX @DPTR,A; INC DPTR; MOV A,R5; MOVX @DPTR,A; RET.
 */
void FUN_CODE_decb(unsigned char param_1, unsigned char param_2) {
    volatile unsigned char xdata *p = (volatile unsigned char xdata *)0xa73e;
    *p = param_1;
    p++;
    *p = param_2;
}

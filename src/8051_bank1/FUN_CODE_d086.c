/* 8051_bank1 FUN_CODE_d086 @ 0xd086
 * Empty delay loop: unsigned int i = 0 .. 100 in R6:R7 (INC R7 / CJNE R7,#0 / INC R6, then MOV A,R7 / XRL A,#64H /
 * ORL A,R6 / JNZ), same loop shape as FUN_CODE_cc7d without the NOP. 12 call sites in bank 1.
 * Byte-exact with OPTIMIZE(8,SPEED) and OPTIMIZE(7,SPEED) (register-only, no tail).
 */
void FUN_CODE_d086(void)
{
    unsigned int i;
    for (i = 0; i != 100; i++) ;
}

/* 8051_bank2 FUN_CODE_4ffa @ 0x4ffa  OPTIMIZE(8,SPEED)
 * Returns the byte at XDATA 0x075B (MOV DPTR,#0x075B; MOVX A,@DPTR; MOV R7,A; RET).
 */
/* FUN_CODE_4ffa at 0x4ffa */
unsigned char FUN_CODE_4ffa(void) {
    return *(unsigned char xdata *)0x75b;
}

/* 8051_bank1 FUN_CODE_dea6 @ 0xdea6
 * bit: FUN_CODE_dce3() == 1 (CJNE R7,#1 / SETB C / RET / CLR C / RET). Only caller 0x3bc5.
 * Byte-exact with OPTIMIZE(8,SPEED) (level 7 gives 11 B).
 */
unsigned char FUN_CODE_dce3(void);
bit FUN_CODE_dea6(void)
{
    return FUN_CODE_dce3() == 1;
}

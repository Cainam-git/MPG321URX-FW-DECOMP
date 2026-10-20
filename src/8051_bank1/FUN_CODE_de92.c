/* 8051_bank1 FUN_CODE_de92 @ 0xde92
 * bit: 1 when FUN_CODE_dee2() returns 0, else 0 (JZ to SETB C; '!dee2()' gives ADD A,#0FFH / CPL C instead).
 * Only caller 0x38b5. Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
unsigned char FUN_CODE_dee2(void);
bit FUN_CODE_de92(void)
{
    if (FUN_CODE_dee2() != 0) return 0;
    return 1;
}

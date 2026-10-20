/* 8051_bank1 FUN_CODE_dce3 @ 0xdce3
 * Returns XDATA 0xA564 == XDATA 0xA565 (1 / 0 in R7, one RET: MOV R7,#1 / SJMP / MOV R7,#0 / RET).
 * Byte-exact with OPTIMIZE(7,SPEED) ONLY (level 8 gives 18 B). Callers 0x3be1, 0x82e5, 0xd697, 0xdea6.
 */
extern unsigned char xdata DAT_EXTMEM_a564, DAT_EXTMEM_a565;
unsigned char FUN_CODE_dce3(void)
{
    return DAT_EXTMEM_a564 == DAT_EXTMEM_a565;
}

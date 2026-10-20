/* 8051_bank1 FUN_CODE_dd96 @ 0xdd96 (no draft)
 * Fills XDATA 0xA800..0xAFFF (0x800 bytes) with 0xFF. Keil turns the 16-bit index loop into
 * MOV R6,#08H / MOV R7,#00H / MOV DPTR,#0xA800 / MOV A,#0FFH / MOVX / INC DPTR / DJNZ R7 / DJNZ R6 (the firmware's code).
 * Countdown, do-while and pointer forms give 28..33 bytes.
 * Only caller 0x405b (FUN_CODE_3fe7).
 * Byte-exact with OPTIMIZE(8,SPEED) (MATCH exact None 16/16).
 */
extern unsigned char xdata DAT_EXTMEM_a800[];
void FUN_CODE_dd96(void)
{
    unsigned int i;
    for (i = 0; i < 0x800; i++) DAT_EXTMEM_a800[i] = 0xff;
}

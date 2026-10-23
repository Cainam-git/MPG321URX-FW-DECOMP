/* 8051_bank1 FUN_CODE_dcbb @ 0xdcbb (hand; first form at 25 %)
 * Clears XDATA 0xA6AF..0xA6C0 (0x12 bytes), one indexed store per pass (MOV A,#LOW / ADD A,R7 / ... / MOVX).
 * The LARGE model gives the firmware's loop test MOV A,R7 / CJNE A,#12H (SMALL gives CJNE R7,#12H: 75 %), and
 * 'i != 0x12' keeps the indexed form ('i < 0x12' becomes INC DPTR / DJNZ: 25 %).
 * Only caller 0x3fef (FUN_CODE_3fe7).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata DAT_EXTMEM_a6af[];
void FUN_CODE_dcbb(void)
{
    unsigned char i;
    for (i = 0; i != 0x12; i++) DAT_EXTMEM_a6af[i] = 0;
}

/* 8051_bank1 FUN_CODE_d884 @ 0xd884 (no draft)
 * 'using 3' write: sel 0 -> XDATA 0x4D00[idx] = v, sel 1 -> XDATA 0x4E00[idx] = v (v in R3). Twin of FUN_CODE_d737.
 * LARGE gives MOV A,R7 / CJNE A,#01H (SMALL: 50 %); a switch gives 58.8 %.
 * Callers: 11 in FUN_CODE_34c8 (0x3564 .. 0x3825), 48 in FUN_CODE_45aa (0x45bc .. 0x482b, last one LJMP),
 * 13 in FUN_CODE_942e (0x9441 .. 0x951f, last one LJMP).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE (MATCH exact None 34/34).
 */
extern unsigned char xdata DAT_EXTMEM_4d00[];
extern unsigned char xdata DAT_EXTMEM_4e00[];
void FUN_CODE_d884(unsigned char sel, unsigned char idx, unsigned char v) using 3
{
    if (sel == 0) DAT_EXTMEM_4d00[idx] = v;
    else if (sel == 1) DAT_EXTMEM_4e00[idx] = v;
}

/* 8051_bank2 FUN_CODE_e0c9 @ 0xe0c9 (60 B, 0xE0C9..0xE105), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_e0c9(off, src, n): copies n bytes from the generic pointer src (read with ?C?CLDOPTR) to the XDATA array
 * at 0x064A, element (unsigned char)(off + i) for i = 0 .. n-1. LARGE parameters: off stays in R7, src is stored
 * at 0x08EF..0x08F1, n is the memory parameter 0x08F2 (re-read on every pass); i is kept in R6.
 * Caller: LJMP from 0xA406 (case 0x41 / 0x42 of the FUN_CODE_a36c switch) with src = XDATA 0xF19B, n = 5 or 3,
 * off = 0 or 5.
 * Source form: the index is cast to unsigned char; without the cast Keil adds with carry and keeps off and i in
 * XDATA.
 */
extern unsigned char xdata DAT_EXTMEM_064a[];

void FUN_CODE_e0c9(unsigned char off, unsigned char *src, unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++) DAT_EXTMEM_064a[(unsigned char)(off + i)] = src[i];
}

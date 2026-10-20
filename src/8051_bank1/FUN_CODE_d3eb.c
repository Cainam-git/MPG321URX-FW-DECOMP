/* 8051_bank1 FUN_CODE_d3eb @ 0xd3eb
 * Tail call FUN_CODE_6f26(DAT_EXTMEM_a800, XDATA ulong 0xA711, XDATA uint 0xA715): the 2 KB buffer XDATA 0xA800 with
 * the same flash address / length pair as FUN_CODE_d3b9 (its twin).
 * Same Keil shape as d3b9: arg 1 into R6:R7 and PUSHed while args 2/3 go to 6f26's LARGE parameter block
 * (+2 = 0xA4B8, +6 = 0xA4BC).
 * JUDGE NOTE: the first judge run records '?_FUN_CODE_6f26?BYTE': 42166 (= 0xA4B6, where 6f26 homes R6:R7, see
 * MOV DPTR,#0A4B6H at 0x6f26) in symbols/8051_bank1.libs.json; judged in a scratch copy, symbols/ not written.
 * Only caller 0x243a (case body of the 0x224f switch, no functions.json entry).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE (MATCH exact None 50/50).
 */
extern unsigned char xdata DAT_EXTMEM_a800[];
extern unsigned long xdata DAT_EXTMEM_a711;
extern unsigned int xdata DAT_EXTMEM_a715;
void FUN_CODE_6f26(unsigned char xdata *src, unsigned long addr, unsigned int len);
void FUN_CODE_d3eb(void)
{
    FUN_CODE_6f26(DAT_EXTMEM_a800, DAT_EXTMEM_a711, DAT_EXTMEM_a715);
}

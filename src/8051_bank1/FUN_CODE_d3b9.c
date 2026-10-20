/* 8051_bank1 FUN_CODE_d3b9 @ 0xd3b9 (no draft)
 * Tail call FUN_CODE_7ca8(DAT_EXTMEM_a800, XDATA ulong 0xA711, XDATA uint 0xA715): SPI flash read of len bytes from
 * flash address addr into the 2 KB buffer XDATA 0xA800 (FUN_CODE_dd96 fills that buffer with 0xFF). Twin: FUN_CODE_d3eb.
 * dst must be the array symbol: Keil then evaluates it first into R6:R7 and PUSHes it while it stores addr / len into
 * 7ca8's LARGE parameter block (+2 = 0xA4B5, +6 = 0xA4B9); a constant pointer is loaded last (MOV R7 / MOV R6, 42 B).
 * JUDGE NOTE: the first judge run records '?_FUN_CODE_7ca8?BYTE': 42163 (= 0xA4B3, where 7ca8 homes dst) in
 * symbols/8051_bank1.libs.json; judging in a scratch copy of tools/ + symbols/ leaves symbols/ unchanged.
 * Only caller 0x2445 (case body of the 0x224f switch, no functions.json entry).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE (MATCH exact None 50/50).
 */
extern unsigned char xdata DAT_EXTMEM_a800[];
extern unsigned long xdata DAT_EXTMEM_a711;
extern unsigned int xdata DAT_EXTMEM_a715;
void FUN_CODE_7ca8(unsigned char xdata *dst, unsigned long addr, unsigned int len);
void FUN_CODE_d3b9(void)
{
    FUN_CODE_7ca8(DAT_EXTMEM_a800, DAT_EXTMEM_a711, DAT_EXTMEM_a715);
}

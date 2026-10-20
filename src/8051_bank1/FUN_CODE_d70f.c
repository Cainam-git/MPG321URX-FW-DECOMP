/* 8051_bank1 FUN_CODE_d70f @ 0xd70f
 * i (R7) clamped to 1; XDATA 0xA73A[i] = ((b & 7) << 5) | (c & 0x1F) (b in R5, c in R3); XDATA 0xA739 = 2
 * (FUN_CODE_de03 writes the same 0xA73A pair and 0xA739 = 1). Only caller 0x25a6.
 * Byte-exact with OPTIMIZE(8,SPEED) ONLY (level 7 gives 41 B).
 */
extern unsigned char xdata DAT_EXTMEM_a73a[];
extern unsigned char xdata DAT_EXTMEM_a739;
void FUN_CODE_d70f(unsigned char i, unsigned char b, unsigned char c)
{
    if (i > 1) i = 1;
    DAT_EXTMEM_a73a[i] = ((b & 7) << 5) | (c & 0x1f);
    DAT_EXTMEM_a739 = 2;
}

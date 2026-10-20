/* 8051_bank2 FUN_CODE_e306 @ 0xe306
 * n = len / 32 rounded up (len >> 5, + 1 when len & 0x1F; n is this function's LARGE local at XDATA 0x090B), then tail
 * FUN_CODE_b1a9(buf, XDATA 0x08C9 (unsigned long), n, 1); buf arrives in R1..R3 and is passed on unchanged.
 * b1a9 small prototype as in FUN_CODE_8437. Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned long xdata DAT_EXTMEM_08c9;
extern void FUN_CODE_b1a9(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
void FUN_CODE_e306(unsigned char *buf, unsigned char len)
{
    unsigned char n;
    n = len >> 5;
    if (len & 0x1f) n++;
    FUN_CODE_b1a9(buf, DAT_EXTMEM_08c9, n, 1);
}

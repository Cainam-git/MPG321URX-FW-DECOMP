/* 8051_bank2 FUN_CODE_e1a4 @ 0xe1a4
 * Twin of FUN_CODE_e373 with FUN_CODE_b1a9: b1a9(DATA 0x22 buffer, addr (own parameter, R4..R7 unchanged),
 * XDATA 0x098A, 0), tail LJMP; b1a9 small prototype as in FUN_CODE_8437. 8 call sites (0x47f9 ..).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char data DAT_0022[];
extern unsigned char xdata DAT_EXTMEM_098a;
extern void FUN_CODE_b1a9(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
void FUN_CODE_e1a4(unsigned long addr)
{
    FUN_CODE_b1a9(DAT_0022, addr, DAT_EXTMEM_098a, 0);
}

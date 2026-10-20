/* 8051_bank2 FUN_CODE_e373 @ 0xe373
 * FUN_CODE_abce(DATA 0x22 buffer, addr, XDATA 0x098A, 0): addr is this function's own unsigned long parameter, passed
 * on unchanged in R4..R7; the buffer pointer is generic type 00 (R3 = 0, R2 = HIGH, R1 = 0x22, as at 0x524b / 0x7759 /
 * 0x79ac / 0xe068 / 0xe087 / 0xe1b0). Tail LJMP. abce declared small as in FUN_CODE_8437 (n / f at DATA 0x0F / 0x10).
 * 10 call sites in bank 2. Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char data DAT_0022[];
extern unsigned char xdata DAT_EXTMEM_098a;
extern void FUN_CODE_abce(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
void FUN_CODE_e373(unsigned long addr)
{
    FUN_CODE_abce(DAT_0022, addr, DAT_EXTMEM_098a, 0);
}

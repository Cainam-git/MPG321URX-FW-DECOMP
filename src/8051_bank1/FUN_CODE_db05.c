/* 8051_bank1 FUN_CODE_db05 @ 0xdb05
 * XDATA 0xF230[i] = v for i < 0x10 (v in R7, i in R5). 6 call sites in bank 1.
 * Byte-exact with OPTIMIZE(8,SPEED) and OPTIMIZE(7,SPEED).
 */
extern unsigned char xdata DAT_EXTMEM_f230[];

void FUN_CODE_db05(unsigned char v, unsigned char i)
{
    if (i < 0x10) DAT_EXTMEM_f230[i] = v;
}

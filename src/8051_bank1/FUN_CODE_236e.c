/* 8051_bank1 FUN_CODE_236e @ 0x236e  MATCH (OPTIMIZE(7,SPEED))
 * Passes the three bytes at XDATA 0xA4AE..0xA4B0 to FUN_CODE_abc4, then calls FUN_CODE_c59a with a fresh read of
 * 0xA4AE and finally FUN_CODE_279f. The incremented pointer keeps DPTR live and produces one MOV DPTR followed by
 * INC DPTR; the separate cast for the second read of 0xA4AE produces the target's DPTR reload.
 */
extern xdata unsigned char DAT_EXTMEM_a4ae;
extern xdata unsigned char DAT_EXTMEM_a4af;
extern xdata unsigned char DAT_EXTMEM_a4b0;

void FUN_CODE_abc4(unsigned char, unsigned char, unsigned char); // 0xabc4
void FUN_CODE_c59a(unsigned char); // 0xc59a
void FUN_CODE_279f(void); // 0x279f

void FUN_CODE_236e(void)
{
    unsigned char b0, b1, b2;
    unsigned char xdata *p = (unsigned char xdata *)0xa4ae;
    
    b0 = *p;
    p++;
    b1 = *p;
    p++;
    b2 = *p;
    
    FUN_CODE_abc4(b0, b1, b2);
    FUN_CODE_c59a(*(unsigned char xdata *)0xa4ae);
    FUN_CODE_279f();
}

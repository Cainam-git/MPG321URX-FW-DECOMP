/* 8051_bank1 FUN_CODE_d83f @ 0xd83f..0xd862 (35 B)
 * Calls FUN_CODE_db64 with the XDATA byte 0xA1E6, then FUN_CODE_d021, prints it with "k %BX\r\n" (CODE 0xDDAE)
 * through FUN_CODE_2820 and increments 0xA1E6.
 * No LCALL or LJMP to 0xD83F occurs in the bank-1 image.
 */
extern unsigned char xdata DAT_EXTMEM_a1e6;
extern void FUN_CODE_db64(unsigned char v);
extern void FUN_CODE_d021(void);
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_d83f(void)
{
    FUN_CODE_db64(DAT_EXTMEM_a1e6);
    FUN_CODE_d021();
    FUN_CODE_2820((void code *)0xddae, DAT_EXTMEM_a1e6);
    DAT_EXTMEM_a1e6++;
}

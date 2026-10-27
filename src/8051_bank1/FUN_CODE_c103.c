/* 8051_bank1 FUN_CODE_c103 @ 0xc103 (96 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * r = FUN_CODE_65e9() (bit result, LARGE local r at XDATA 0xA492, cleared first); reads mailbox word 0x0C into
 * the long at XDATA 0xA48E (FUN_CODE_a4e9, one word), replaces its low byte with r, writes the long back to word
 * 0x0C (FUN_CODE_b228, one word) and, when r is not 0, prints "MailBox_UpdateDDCFlag %BX\r\n" (CODE 0x54AF) with r
 * through FUN_CODE_2820.
 * Caller: FUN_CODE_9243 (first call of its command loop).
 * Source form: '(x & 0xffffff00) | ((unsigned long)r & 0xff)': the masked long r is computed first (R7, then R3)
 *   and only bytes 0..2 of x are loaded.
 */
extern unsigned long xdata DAT_EXTMEM_a48e;
extern bit FUN_CODE_65e9(void);
void FUN_CODE_a4e9(unsigned char off, unsigned long *dst, unsigned char n);
void FUN_CODE_b228(unsigned char off, unsigned long *src, unsigned char n);
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_c103(void)
{
    unsigned char r;

    r = 0;
    r = FUN_CODE_65e9();
    FUN_CODE_a4e9(0x0c, &DAT_EXTMEM_a48e, 1);
    DAT_EXTMEM_a48e = (DAT_EXTMEM_a48e & 0xffffff00) | ((unsigned long)r & 0xff);
    FUN_CODE_b228(0x0c, &DAT_EXTMEM_a48e, 1);
    if (r) FUN_CODE_2820((void code *)0x54af, r);
}

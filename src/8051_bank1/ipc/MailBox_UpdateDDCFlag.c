/* MailBox_UpdateDDCFlag  (FUN_CODE_c103)
 *
 * Report in the mailbox status word whether a port's DDC was accessed.
 * Name basis: proven - prints 'MailBox_UpdateDDCFlag %BX' (original name); low byte of portal word 0x0C from
 *   ddc_detect_port_access
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c103, OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * Source form: '(word & 0xffffff00) | ((unsigned long)access_flag & 0xff)': the masked long is computed first and only
 * bytes 0..2 of the word are loaded.
 */
extern unsigned long xdata DAT_EXTMEM_a48e;
extern bit ddc_detect_port_access(void);
void ipc_portal_read(unsigned char off, unsigned long *dst, unsigned char n);
void ipc_portal_write(unsigned char off, unsigned long *src, unsigned char n);
extern void lib_printf517(void *fmt, ...) large;

/*
 * MailBox_UpdateDDCFlag - ask ddc_detect_port_access whether a port's DDC was accessed, read mailbox portal word 0x0C,
 * replace its low byte with the answer and write the word back. When the answer is not 0 it also prints
 * "MailBox_UpdateDDCFlag %BX" with it.
 * Caller: ipc_service_mailbox (first call of its command loop).
 */
void MailBox_UpdateDDCFlag(void)
{
    unsigned char access_flag;

    access_flag = 0;
    access_flag = ddc_detect_port_access();
    ipc_portal_read(0x0c, &DAT_EXTMEM_a48e, 1);
    DAT_EXTMEM_a48e = (DAT_EXTMEM_a48e & 0xffffff00) | ((unsigned long)access_flag & 0xff);
    ipc_portal_write(0x0c, &DAT_EXTMEM_a48e, 1);
    if (access_flag) lib_printf517((void code *)0x54af, access_flag);
}

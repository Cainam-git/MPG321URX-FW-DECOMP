/* ipc_clear_report_record  (FUN_CODE_d41d)
 *
 * Clear the outgoing report record for the main processor.
 * Note: Not called anywhere.
 * Name basis: derived - record 0xA3E5..0xA46B that ipc_fill_report_record fills (types 1..5); no caller in the
 *   image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d41d @ 0xd41d..0xd44e (49 B)  Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: the record is one object (INC DPTR between its byte stores) and is cleared in this order: byte at
 * +2, word at +3, word at +0, word at +5, then the 32 long entries (?C?LSTKXDATA with an inline 0).
 */
/* The report record at XDATA 0xA3E5..0xA46B; only the offsets are known, so the fields carry them. */
struct ipc_report_record_layout {
    unsigned int word_0x0;
    unsigned char byte_0x2;
    unsigned int word_0x3;
    unsigned int word_0x5;
    unsigned long entries[32];  /* +0x7 */
};
extern struct ipc_report_record_layout xdata ipc_report_record;

/*
 * Clear the outgoing report record for the main processor (the record ipc_fill_report_record fills).
 * Nothing in the image calls this routine.
 */
void ipc_clear_report_record(void)
{
    unsigned char i;

    ipc_report_record.byte_0x2 = 0;
    ipc_report_record.word_0x3 = 0;
    ipc_report_record.word_0x0 = 0;
    ipc_report_record.word_0x5 = 0;
    for (i = 0; i < 0x20; i++) ipc_report_record.entries[i] = 0;
}

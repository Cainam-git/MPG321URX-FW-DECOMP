/* ipc_test_report_slot_free  (FUN_CODE_de12)
 *
 * Report whether the outgoing report record is empty and can be refilled.
 * Returns: 1 when free
 * Name basis: derived - byte count 0xA3EA of the report record; the builder ipc_fill_report_record runs only
 *   when it is 0
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de12 @ 0xde12
 * Options: OPTIMIZE(8,SPEED).
 * Source form: the 16-bit test 'if (length) return 0;' gives MOVX / JNZ to the low byte's JZ / INC DPTR / MOVX / JZ, as in
 * the firmware; the two-char forms (a[0] || a[1]) do not.
 */
extern unsigned int xdata ipc_report_record_length;

/* Return 1 when ipc_report_record_length is zero (no report waits to be
 * sent), else 0. Callers: ipc_fill_report_record and ipc_build_report_message. */
bit ipc_test_report_slot_free(void)
{
    if (ipc_report_record_length) return 0;
    return 1;
}

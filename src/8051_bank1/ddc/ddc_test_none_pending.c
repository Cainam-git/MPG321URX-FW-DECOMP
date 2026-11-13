/* ddc_test_none_pending  (FUN_CODE_de92)
 *
 * Report whether no DDC/CI channel has a message waiting.
 * Returns: 1 when none
 * Name basis: derived - pending byte 0xA0F3 is 0; tested by the report builder before a type 4 report
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de92 @ 0xde92  OPTIMIZE(8,SPEED) (also level 7).
 * Source form: 'if (... != 0) return 0; return 1;' gives JZ to SETB C; 'return !ddc_get_pending_channels();'
 * gives ADD A,#0FFH / CPL C instead.
 */
unsigned char ddc_get_pending_channels(void);

/*
 * Return 1 when no DDC/CI slave port has a request waiting to be reported (ddc_pending_channel_flags is 0), else
 * 0. Only caller: ipc_fill_report_record, which reports a waiting DDC/CI request (type 4) first when this returns 0.
 */
bit ddc_test_none_pending(void)
{
    if (ddc_get_pending_channels() != 0) return 0;
    return 1;
}

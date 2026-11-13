/* dbg_send_timing_change_notice  (FUN_a00dd5b8)
 *
 * Print three values and send them to the input processor as a timing change notice.
 * Name basis: proven - prints '=====AT Prepare Timing Change %08X %08X %08X====='; mailbox command 0xA6;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd5b8 @ 0xa00dd5b8-0xa00dd5e0 (10 words).
 * Source form: the call to ipc_print_timing_change_notice is the last statement (a tail call). The routine at
 * 0xa00dd5e0 that follows is a separate function (dbg_set_print_mask_bits).
 */
extern int dbg_printf(const char *fmt, ...);
extern void ipc_print_timing_change_notice(unsigned int a, unsigned int b, unsigned int c);

/*
 * Print the three values in hexadecimal on the debug serial port and pass them on to
 * ipc_print_timing_change_notice. The callers' meaning of the three values is not shown.
 * Nothing in the image calls this routine.
 */
void dbg_send_timing_change_notice(unsigned int a, unsigned int b, unsigned int c)
{
    dbg_printf("=====AT Prepare Timing Change %08X %08X %08X=====\r\n", a, b, c);
    ipc_print_timing_change_notice(a, b, c);
}

/* MailBox_SetWakeUpTimer  (FUN_a0134184)
 *
 * Tell the 8051 the wake-up timer value.
 * Name basis: proven - prints 'MailBox_SetWakeUpTimer' (original name); 8051 command 0x1C; unused
 *
 * Matching notes
 * --------------
 * FUN_a0134184, flags -mcpu=v8 -O2 -g. ipc_send_8051_command is declared without a prototype, as the firmware's
 * own calls need. The low byte is taken into an unsigned char local before the test.
 */
extern unsigned char dbg_is_print_enabled(int);
extern int dbg_printf();
extern int ipc_send_8051_command();

#define DBG_MAILBOX                 0x20    /* debug class of the 8051 mailbox prints */
#define IPC_8051_CMD_WAKEUP_TIMER   0x1c
#define IPC_SEND_WAIT_TAKEN         1       /* return when the 8051 has taken the command */

/*
 * Command 0x1C: the 8051 starts its wake-up timer (it prints setWakeupTimer). No call to this routine is found in
 * the code.
 *   timer_value: 16-bit timer value, sent as byte 2 (low) and byte 3 (high)
 */
void MailBox_SetWakeUpTimer(unsigned short timer_value)
{
    unsigned char lo = timer_value;

    if (dbg_is_print_enabled(DBG_MAILBOX))
        dbg_printf("\nMailBox_SetWakeUpTimer : %02X\r\n", timer_value);
    ipc_send_8051_command(IPC_8051_CMD_WAKEUP_TIMER, 0, lo, timer_value >> 8, IPC_SEND_WAIT_TAKEN);
}

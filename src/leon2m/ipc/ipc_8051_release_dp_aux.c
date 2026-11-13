/* ipc_8051_release_dp_aux  (FUN_a0133d04)
 *
 * Tell the 8051 to hand the DisplayPort receivers back (command 0x2B).
 * Name basis: proven - ipc_send_8051_command with command 0x2B; unused; 8051 command 0x2B; the handler in the
 *   8051 program (Disable_DPMRX, original name) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133d04 (leon2m 0xa0133d04-0xa0133d28, 36 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the call to the RAM copy of ipc_send_8051_command is a tail call; the nop after it is the -g line
 * nop.
 */
extern void ipc_send_8051_command(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

#define IPC_CMD_DISABLE_DPMRX 0x2b      /* docs/MAILBOX.md: the 8051 hands the DP receivers back */

/*
 * Send command 0x2B to the 8051, which hands the DisplayPort receivers back (Disable_DPMRX; docs/MAILBOX.md).
 * Sent with mode 1: the routine returns when the 8051 has taken the command. Nothing calls this routine.
 */
void ipc_8051_release_dp_aux(void)
{
    ipc_send_8051_command(IPC_CMD_DISABLE_DPMRX, 0, 0, 0, 1);
}

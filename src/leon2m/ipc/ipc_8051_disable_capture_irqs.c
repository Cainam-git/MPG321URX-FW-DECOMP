/* ipc_8051_disable_capture_irqs  (FUN_a0133ec8)
 *
 * Tell the 8051 to disable all capture-interrupt sources (command 0x0A).
 * Name basis: derived - ipc_send_8051_command with command 0x0A; unused; 8051 command 0x0A; the handler in the
 *   8051 program (irq_set_capture_mask) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133ec8, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_STOP_CAPTURE_IRQS  0x0a
#define IPC_SEND_WAIT_TAKEN             1   /* return when the 8051 has taken the command */

/*
 * Command 0x0A: the 8051 disables all capture-interrupt sources (it runs irq_set_capture_mask with 0). Nothing in
 * the firmware calls this routine.
 *   unused_arg: byte 1; the 8051 ignores it for this command
 */
void ipc_8051_disable_capture_irqs(unsigned char unused_arg)
{
    ipc_send_8051_command(IPC_8051_CMD_STOP_CAPTURE_IRQS, unused_arg, 0, 0, IPC_SEND_WAIT_TAKEN);
}

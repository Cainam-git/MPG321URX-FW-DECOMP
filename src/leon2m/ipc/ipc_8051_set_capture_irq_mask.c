/* ipc_8051_set_capture_irq_mask  (FUN_a0133eec)
 *
 * Tell the 8051 which capture-interrupt sources are enabled (command 0x09).
 * Name basis: derived - ipc_send_8051_command with command 0x09; unused; 8051 command 0x09; the handler in the
 *   8051 program (irq_set_capture_mask) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133eec, flags -mcpu=v8 -O3 -g. Tail call of ipc_send_8051_command.
 * Source form: the 0xff case is written as 'if (mask == 0xff) mask = 0;' before the call; a ?: inside the argument
 * list compiles to a compare and branch.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_SET_CAPTURE_IRQS  0x09
#define IPC_SEND_WAIT_TAKEN            1    /* return when the 8051 has taken the command */

/*
 * Command 0x09: the 8051 sets which capture-interrupt sources are enabled (it runs irq_set_capture_mask). Nothing
 * in the firmware calls this routine.
 *   source_mask: byte 1; the value 0xFF is sent as 0
 */
void ipc_8051_set_capture_irq_mask(unsigned char source_mask)
{
    if (source_mask == 0xff)
        source_mask = 0;
    ipc_send_8051_command(IPC_8051_CMD_SET_CAPTURE_IRQS, source_mask, 0, 0, IPC_SEND_WAIT_TAKEN);
}

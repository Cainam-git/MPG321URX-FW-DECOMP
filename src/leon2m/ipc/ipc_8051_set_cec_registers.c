/* ipc_8051_set_cec_registers  (FUN_a0133ea4)
 *
 * Have the 8051 write two registers of the CEC controller (command 0x24).
 * Name basis: derived - ipc_send_8051_command with command 0x24; unused; 8051 command 0x24; the handler in the
 *   8051 program (hdmi_cec_set_two_regs) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133ea4, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_SET_CEC_REGS  0x24
#define IPC_SEND_WAIT_TAKEN        1    /* return when the 8051 has taken the command */

/*
 * Command 0x24: the 8051 writes two registers of the CEC controller, the transmit destination (byte 2) and the
 * transmit length (byte 3). Nothing in the firmware calls this routine.
 *   destination: byte 2
 *   length:      byte 3
 */
void ipc_8051_set_cec_registers(unsigned char destination, unsigned char length)
{
    ipc_send_8051_command(IPC_8051_CMD_SET_CEC_REGS, 0, destination, length, IPC_SEND_WAIT_TAKEN);
}

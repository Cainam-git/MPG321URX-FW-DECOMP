/* ipc_8051_switch_control_bit  (FUN_a0133dc8)
 *
 * Have the 8051 switch bit 3 of one of two control registers (command 0x22).
 * Name basis: descriptive - ipc_send_8051_command with command 0x22; 8051 command 0x22; the handler in the
 *   8051 program (inline in ipc_run_command) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133dc8, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_SWITCH_BIT3  0x22
#define IPC_SEND_WAIT_TAKEN       1 /* return when the 8051 has taken the command */

/*
 * Command 0x22: the 8051 switches bit 3 of the registers 0xF1EB and 0xF1E0 in opposite directions.
 *   on: byte 2; non-zero clears bit 3 of 0xF1EB and sets it in 0xF1E0, 0 does the reverse
 */
void ipc_8051_switch_control_bit(unsigned char on)
{
    ipc_send_8051_command(IPC_8051_CMD_SWITCH_BIT3, 0, on, 0, IPC_SEND_WAIT_TAKEN);
}

/* ipc_8051_set_option_byte  (FUN_a0133da0)
 *
 * Store a byte in one of six option bytes of the 8051 (command 0x23).
 * Name basis: descriptive - ipc_send_8051_command with command 0x23; unused; 8051 command 0x23; the handler in
 *   the 8051 program (inline in ipc_run_command) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133da0, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_SET_OPTION_BYTE  0x23
#define IPC_SEND_WAIT_TAKEN           1 /* return when the 8051 has taken the command */

/*
 * Command 0x23: store a byte in one of the six 8051 option bytes 0xCBC1..0xCBC6.
 *   index: byte 1, 0..5 for 0xCBC1..0xCBC6; other values store nothing
 *   value: byte 2, the byte to store
 */
void ipc_8051_set_option_byte(unsigned char index, unsigned char value)
{
    ipc_send_8051_command(IPC_8051_CMD_SET_OPTION_BYTE, index, value, 0, IPC_SEND_WAIT_TAKEN);
}

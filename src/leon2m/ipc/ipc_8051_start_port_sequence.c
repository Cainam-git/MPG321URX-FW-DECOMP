/* ipc_8051_start_port_sequence  (FUN_a0133d4c)
 *
 * Give the 8051 a port pair and start its timed port sequence (command 0x25).
 * Name basis: descriptive - ipc_send_8051_command with command 0x25; unused; 8051 command 0x25; the handler in
 *   the 8051 program (ipc_run_cmd_0x25_sequence) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133d4c, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_PORT_SEQUENCE  0x25
#define IPC_SEND_WAIT_TAKEN         1   /* return when the 8051 has taken the command */

/*
 * Command 0x25. The 8051 keeps two port numbers and, on chips with ID 0x1A or 0x20, restarts its timed port
 * sequence. Nothing in the firmware calls this routine.
 *   sequence_arg: byte 1 of the command; the 8051 stores it in 0xF17C (use not shown)
 *   first_port:   byte 2, first port of the pair
 *   second_port:  byte 3, second port of the pair
 */
void ipc_8051_start_port_sequence(unsigned char sequence_arg, unsigned char first_port, unsigned char second_port)
{
    ipc_send_8051_command(IPC_8051_CMD_PORT_SEQUENCE, sequence_arg, first_port, second_port, IPC_SEND_WAIT_TAKEN);
}

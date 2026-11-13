/* ipc_8051_set_option_flag  (FUN_a0133d78)
 *
 * Set or clear one of two flag bits in the 8051's byte 0xCAB2 (command 0x28).
 * Name basis: descriptive - ipc_send_8051_command with command 0x28; unused; 8051 command 0x28; the handler in
 *   the 8051 program (ipc_run_command_part2) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133d78, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_SET_OPTION_FLAG  0x28
#define IPC_SEND_WAIT_TAKEN           1 /* return when the 8051 has taken the command */

/*
 * Command 0x28: set or clear one flag bit in the 8051's byte 0xCAB2. Nothing in the firmware calls this routine.
 *   which_bit: byte 1; 0 selects bit 0, 1 selects bit 2, other values change nothing
 *   set:       byte 2; non-zero sets the bit, 0 clears it
 */
void ipc_8051_set_option_flag(unsigned char which_bit, unsigned char set)
{
    ipc_send_8051_command(IPC_8051_CMD_SET_OPTION_FLAG, which_bit, set, 0, IPC_SEND_WAIT_TAKEN);
}

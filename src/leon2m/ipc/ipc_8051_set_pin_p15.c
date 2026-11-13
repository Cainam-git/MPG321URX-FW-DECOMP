/* ipc_8051_set_pin_p15  (FUN_a01340fc)
 *
 * Have the 8051 drive its pin P1.5 high or low (command 0x1E).
 * Name basis: proven - ipc_send_8051_command with command 0x1E; unused; 8051 command 0x1E; the handler in the
 *   8051 program (prints CMD_SET_P15) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a01340fc, flags -mcpu=v8 -O2 -g. Both branches are tail calls of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_SET_P15  0x1e
#define IPC_SEND_WAIT_TAKEN   1 /* return when the 8051 has taken the command */

/*
 * Command 0x1E: the 8051 drives its pin P1.5 high or low (it prints CMD_SET_P15). Nothing in the firmware calls
 * this routine.
 *   on: non-zero sends 1 in bytes 2 and 3 (pin high), 0 sends 0 (pin low)
 */
void ipc_8051_set_pin_p15(unsigned char on)
{
    if (on)
        ipc_send_8051_command(IPC_8051_CMD_SET_P15, 0, 1, 1, IPC_SEND_WAIT_TAKEN);
    else
        ipc_send_8051_command(IPC_8051_CMD_SET_P15, 0, 0, 0, IPC_SEND_WAIT_TAKEN);
}

/* ipc_8051_set_flash_window_extend  (FUN_a01344a0)
 *
 * Tell the 8051 the 24-bit extension of its flash window (command 0x26).
 * Name basis: proven - unused; 8051 command 0x26; the handler in the 8051 program (flash_set_fe2p_extend,
 *   prints CMD_FE2P_SETEXTEND) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a01344a0, flags -mcpu=v8 -O2 -g. ipc_send_8051_command is declared without a prototype, as the firmware's own
 * calls need.
 */
extern int ipc_send_8051_command();

#define IPC_8051_CMD_FLASH_EXTEND  0x26
#define IPC_SEND_WAIT_TAKEN        1    /* return when the 8051 has taken the command */

/*
 * Command 0x26: the 8051 sets the 24-bit extension of its flash window (it prints CMD_FE2P_SETEXTEND). No call to this routine is found in the code.
 *   extension: 24-bit value, sent as byte 1 (bits 16..23), byte 2 (bits 8..15) and byte 3 (bits 0..7)
 */
void ipc_8051_set_flash_window_extend(unsigned int extension)

{
  ipc_send_8051_command(IPC_8051_CMD_FLASH_EXTEND,extension >> 0x10 & 0xff,extension >> 8 & 0xff,extension & 0xff,IPC_SEND_WAIT_TAKEN);
  return;
}

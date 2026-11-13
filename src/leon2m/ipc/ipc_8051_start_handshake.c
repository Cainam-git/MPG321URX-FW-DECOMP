/* ipc_8051_start_handshake  (FUN_a0134068)
 *
 * Send 8051 command 0x27, which holds the 8051 in a handshake on mailbox word 0xB8.
 * Name basis: derived - ipc_send_8051_command with command 0x27; unused; 8051 command 0x27; the handler in the
 *   8051 program (ipc_wait_flash_handshake, ipc_finish_flash_handshake) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0134068, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_HANDSHAKE      0x27
#define IPC_SEND_FLASH_HANDSHAKE    2   /* handshake on portal word 0xB8, then wait until the command is taken */

/*
 * Command 0x27: hold the 8051 in a handshake with the main processor. The send mode IPC_SEND_FLASH_HANDSHAKE
 * performs the handshake on portal word 0xB8 that the 8051 waits for. Nothing in the firmware calls this routine.
 */
void ipc_8051_start_handshake(void)
{
    ipc_send_8051_command(IPC_8051_CMD_HANDSHAKE, 0, 0, 0, IPC_SEND_FLASH_HANDSHAKE);
}

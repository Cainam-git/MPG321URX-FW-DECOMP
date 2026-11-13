/* ipc_8051_flash_write_bytes  (FUN_a01344f4)
 *
 * Have the 8051 program some bytes of its flash buffer at the job address (commands 0x14, 0x15).
 * Name basis: derived - unused; 8051 commands 0x14 and 0x15; the handlers in the 8051 program
 *   (flash_set_job_address, flash_write_buffer_bytes, prints FE2P WriteByte) show what they do
 *
 * Matching notes
 * --------------
 * FUN_a01344f4, flags -mcpu=v8 -O2 -g. ipc_send_8051_command is declared without a prototype, as the firmware's own
 * calls need. The last argument 2 of the second call is set in the delay slot.
 */
extern int ipc_send_8051_command();

#define IPC_8051_CMD_FLASH_SET_JOB     0x14
#define IPC_8051_CMD_FLASH_WRITE_BYTES 0x15
#define IPC_SEND_WAIT_TAKEN            1    /* return when the 8051 has taken the command */
#define IPC_SEND_FLASH_HANDSHAKE       2    /* handshake on portal word 0xB8, then wait until taken */

/*
 * Have the 8051 program a few bytes of its flash data buffer into flash: command 0x14 sets the job address, then
 * command 0x15 programs the bytes inside the flash handshake. No call to this routine is found in the code.
 *   flash_offset:  16-bit offset of the job address, sent as byte 2 (high) and byte 3 (low) of command 0x14
 *   buffer_offset: offset in the 8051's data buffer, byte 2 (high) and byte 3 (low) of command 0x15
 *   count:         number of bytes, byte 1 of command 0x15
 */
void ipc_8051_flash_write_bytes(short flash_offset, short buffer_offset, unsigned char count)
{
    ipc_send_8051_command(IPC_8051_CMD_FLASH_SET_JOB, 0, (flash_offset >> 8) & 0xff, flash_offset & 0xff, IPC_SEND_WAIT_TAKEN);
    ipc_send_8051_command(IPC_8051_CMD_FLASH_WRITE_BYTES, count, (buffer_offset >> 8) & 0xff, buffer_offset & 0xff, IPC_SEND_FLASH_HANDSHAKE);
}

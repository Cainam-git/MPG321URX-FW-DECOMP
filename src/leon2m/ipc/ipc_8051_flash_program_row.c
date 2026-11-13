/* ipc_8051_flash_program_row  (FUN_a0134428)
 *
 * Ask the 8051 to program a flash-backed storage row at an address.
 * Note: Writes flash.
 * Name basis: derived - 8051 command 0x14 (address), then 0x11; used by the flash row advance
 *
 * Matching notes
 * --------------
 * FUN_a0134428, flags -mcpu=v8 -O2 -g. The parameters are unsigned int (the assembly works on full 32-bit
 * registers with explicit masks); the two-step shift (x << 16) >> 24 gives the target's sll + srl pair instead of a
 * single srl.
 */
extern int ipc_send_8051_command(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); /* 0x4008f3f4 */

#define IPC_8051_CMD_FLASH_PROGRAM   0x11
#define IPC_8051_CMD_FLASH_SET_JOB   0x14
#define IPC_SEND_WAIT_TAKEN          1  /* return when the 8051 has taken the command */
#define IPC_SEND_FLASH_HANDSHAKE     2  /* handshake on portal word 0xB8, then wait until taken */

/*
 * Have the 8051 program its flash data buffer into flash: command 0x14 sets the job (length and address), then
 * command 0x11 runs it inside the flash handshake. Caller: nvram_flash_advance_row.
 *   offset: 16-bit offset of the job address, sent as byte 2 (high) and byte 3 (low) of command 0x14
 *   length: job length, byte 1 of command 0x14
 */
void ipc_8051_flash_program_row(unsigned int offset, unsigned int length)
{
    ipc_send_8051_command(IPC_8051_CMD_FLASH_SET_JOB, length & 0xff, (offset << 16) >> 24, offset & 0xff, IPC_SEND_WAIT_TAKEN);
    ipc_send_8051_command(IPC_8051_CMD_FLASH_PROGRAM, 0, 0, 0, IPC_SEND_FLASH_HANDSHAKE);
}

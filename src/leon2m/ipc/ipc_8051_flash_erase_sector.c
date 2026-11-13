/* ipc_8051_flash_erase_sector  (FUN_a0134464)
 *
 * Ask the 8051 to erase the flash sector at an address.
 * Note: Erases flash.
 * Name basis: derived - 8051 command 0x14 (address), then 0x13; used by nvram_erase_area
 *
 * Matching notes
 * --------------
 * FUN_a0134464, flags -mcpu=v8 -O2 -g. Returns void; the last argument 2 is set in the delay slot of the second
 * call.
 */
extern int ipc_send_8051_command(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); /* 0x4008f3f4 */

#define IPC_8051_CMD_FLASH_ERASE     0x13
#define IPC_8051_CMD_FLASH_SET_JOB   0x14
#define IPC_SEND_WAIT_TAKEN          1  /* return when the 8051 has taken the command */
#define IPC_SEND_FLASH_HANDSHAKE     2  /* handshake on portal word 0xB8, then wait until taken */

/*
 * Have the 8051 erase the flash sector at the given address: command 0x14 sets the job address (length 0), then
 * command 0x13 runs the erase inside the flash handshake. Callers: nvram_flash_advance_row and nvram_erase_area.
 *   offset: 16-bit offset of the job address, sent as byte 2 (high) and byte 3 (low) of command 0x14
 */
void ipc_8051_flash_erase_sector(unsigned int offset)
{
    ipc_send_8051_command(IPC_8051_CMD_FLASH_SET_JOB, 0, (offset << 16) >> 24, offset & 0xff, IPC_SEND_WAIT_TAKEN);
    ipc_send_8051_command(IPC_8051_CMD_FLASH_ERASE, 0, 0, 0, IPC_SEND_FLASH_HANDSHAKE);
}

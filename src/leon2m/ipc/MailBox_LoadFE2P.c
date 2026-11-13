/* MailBox_LoadFE2P  (FUN_a0134394)
 *
 * Ask the 8051 to load a flash-backed storage row at an address.
 * Name basis: proven - prints 'MailBox_LoadFE2P' (original name); 8051 commands 0x14 and 0x12
 *
 * Matching notes
 * --------------
 * FUN_a0134394, flags -mcpu=v8 -O2 -g. The callee returns void; an int return changes the delay-slot filling of
 * the first call.
 */
extern unsigned char dbg_is_print_enabled(int);
extern int dbg_printf();
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define DBG_MAILBOX                  0x20   /* debug class of the 8051 mailbox prints */
#define IPC_8051_CMD_FLASH_READ      0x12
#define IPC_8051_CMD_FLASH_SET_JOB   0x14
#define IPC_SEND_WAIT_TAKEN          1      /* return when the 8051 has taken the command */
#define IPC_SEND_FLASH_HANDSHAKE     2      /* handshake on portal word 0xB8, then wait until taken */

/*
 * Make the 8051 read a range of its flash into its data buffer: command 0x14 sets the job, then command 0x12 runs
 * it inside the flash handshake. The 8051 posts a checksum of the buffer to portal word 0xB0 (docs/MAILBOX.md).
 * Callers: nvram_flash_advance_row and nvram_flash_prepare_write.
 *   offset: 16-bit offset of the job address, sent as byte 2 (high) and byte 3 (low)
 *   length: job length, byte 1 of command 0x14
 */
void MailBox_LoadFE2P(unsigned short offset, unsigned char length)
{
    if (dbg_is_print_enabled(DBG_MAILBOX))
        dbg_printf("\nMailBox_LoadFE2P : 0x%04X 0x%04X\r\n", offset, length);
    ipc_send_8051_command(IPC_8051_CMD_FLASH_SET_JOB, length, offset >> 8, (unsigned char)offset, IPC_SEND_WAIT_TAKEN);
    ipc_send_8051_command(IPC_8051_CMD_FLASH_READ, 0, 0, 0, IPC_SEND_FLASH_HANDSHAKE);
}

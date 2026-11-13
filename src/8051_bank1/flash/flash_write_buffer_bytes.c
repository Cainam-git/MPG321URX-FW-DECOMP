/* flash_write_buffer_bytes  (FUN_CODE_9fc8)
 *
 * Program bytes from the flash data buffer to the job address.
 *   offset: buffer offset
 *   count: byte count
 * Name basis: proven - flash_program from 0xA800 + offset; prints 'FE2P WriteByte'; command 0x15
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9fc8 @ 0x9fc8..0xa085 (189 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE parameters: offset at XDATA 0xA4B3, count at 0xA4B5; the printf call is the tail LJMP.
 */
extern unsigned char xdata flash_data_buffer[];
extern unsigned long xdata flash_job_address;
extern void flash_program(unsigned char xdata *p, unsigned long a, unsigned int n);
extern void lib_printf517(void *fmt, ...) large;

/*
 * flash_write_buffer_bytes - program count bytes of flash_data_buffer, from offset on, into the flash at
 * flash_job_address + offset, then print "FE2P WriteByte" with the five buffer bytes offset - 2 .. offset + 2.
 *   offset  position in the buffer and distance from the job address
 *   count   number of bytes
 * Only caller: mailbox command IPC_8051_CMD_FLASH_WRITE_BYTES (0x15) in ipc_run_command (offset from command
 * bytes 2 and 3, count from byte 1).
 */
void flash_write_buffer_bytes(unsigned int offset, unsigned char count)
{
    flash_program(&flash_data_buffer[offset], flash_job_address + offset, count);
    lib_printf517((void code *)0xc496, flash_data_buffer[offset - 2], flash_data_buffer[offset - 1], flash_data_buffer[offset],
                  flash_data_buffer[offset + 1], flash_data_buffer[offset + 2]);   /* "FE2P WriteByte %BX %BX %BX %BX %BX\r\n" */
}

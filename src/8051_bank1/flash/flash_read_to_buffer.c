/* flash_read_to_buffer  (FUN_CODE_d3b9)
 *
 * Read the requested flash range into the 2 KB transfer buffer.
 * Name basis: derived - mailbox command 0x12 (flash read job); address/length from the command record
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d3b9 @ 0xd3b9  Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: the buffer must be the array symbol. Keil then evaluates it first into R6:R7 and PUSHes it while it
 * stores the address and length into the LARGE parameter block of flash_read_bytes; a constant pointer is loaded last.
 * Link key: '?_FUN_CODE_7ca8?BYTE' = 0xA4B3 (where flash_read_bytes homes its first parameter), recorded in
 * symbols/8051_bank1.libs.json.
 */
extern unsigned char xdata flash_data_buffer[];
extern unsigned long xdata flash_job_address;
extern unsigned int xdata flash_job_length;
void flash_read_bytes(unsigned char xdata *dst, unsigned long addr, unsigned int len);

/*
 * Read the bytes of the current flash job (address and length in XDATA 0xA711 / 0xA715) into the 2 KB flash data
 * buffer. Part of mailbox command 0x12 (flash read job, docs/MAILBOX.md). Twin of flash_write_from_buffer.
 */
void flash_read_to_buffer(void)
{
    flash_read_bytes(flash_data_buffer, flash_job_address, flash_job_length);
}

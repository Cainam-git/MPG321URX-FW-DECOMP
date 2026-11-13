/* flash_write_from_buffer  (FUN_CODE_d3eb)
 *
 * Program the 2 KB transfer buffer into the requested flash range.
 * Name basis: derived - mailbox command 0x11 (flash write job); calls the page-program routine
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d3eb @ 0xd3eb  Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: as flash_read_to_buffer, the buffer is the array symbol (first argument in R6:R7, PUSHed while the
 * other two go to the LARGE parameter block of flash_program).
 * Link key: '?_FUN_CODE_6f26?BYTE' = 0xA4B6 (where flash_program homes its first parameter), recorded in
 * symbols/8051_bank1.libs.json.
 */
extern unsigned char xdata flash_data_buffer[];
extern unsigned long xdata flash_job_address;
extern unsigned int xdata flash_job_length;
void flash_program(unsigned char xdata *src, unsigned long addr, unsigned int len);

/*
 * Program the 2 KB flash data buffer into the flash range of the current job (address and length in XDATA 0xA711 /
 * 0xA715). Part of mailbox command 0x11 (flash program job, docs/MAILBOX.md). Twin of flash_read_to_buffer.
 */
void flash_write_from_buffer(void)
{
    flash_program(flash_data_buffer, flash_job_address, flash_job_length);
}

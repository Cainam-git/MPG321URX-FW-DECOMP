/* flash_set_job_length  (FUN_CODE_de45)
 *
 * Set the flash job length in 256-byte units when non-zero.
 *   blocks: length / 256
 * Name basis: derived - length word 0xA715 used by flash_read_to_buffer / flash_write_from_buffer; mailbox
 *   command 0x14
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de45 @ 0xde45  OPTIMIZE(7,SPEED)
 * Source form: the second byte is reached as (&flash_job_length + 1).
 */
extern xdata unsigned char flash_job_length;
extern xdata unsigned char DAT_EXTMEM_a716;

/* When blocks is not zero, set the flash job length (the 16-bit big-endian
 * word at 0xA715, read as an unsigned int by the flash read and program
 * jobs) to blocks * 256: blocks goes to the high byte, 0 to the low byte.
 * Run for mailbox command 0x14.
 *   blocks: length in units of 256 bytes */
void flash_set_job_length(char blocks)
{
    if (blocks != 0) {
        flash_job_length = blocks;
        *(unsigned char xdata *)(&flash_job_length + 1) = 0;
    }
}

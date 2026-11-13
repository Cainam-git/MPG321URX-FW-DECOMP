/* flash_read_three_reply_bytes  (FUN_CODE_c21d)
 *
 * Send a flash command and read its three answer bytes.
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - opcode from XDATA 0xF068, answer to 0xF064..0xF066 through the flash FIFO
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c21d, no caller in the image. Same register sequence as startup_copy_flash_image.
 * Source forms: the mode value goes through the loop counter ('index = mode & 0x0C | 1; mode = index;' gives MOV R7,A
 * before the store); the discarded read is the expression statement 'reg_flash_fifo_port;' (volatile register).
 */
extern volatile unsigned char xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low;
extern volatile unsigned char xdata reg_flash_spi_format, reg_flash_fifo_port;
extern unsigned char xdata DAT_EXTMEM_f068;
extern unsigned char xdata DAT_EXTMEM_f064[];
/*
 * flash_read_three_reply_bytes - send the flash opcode stored at XDATA 0xF068 (read opcode register, format 7, count
 * 0x000002) and store three bytes read from the FIFO to XDATA 0xF064..0xF066 (the first byte read after FIFO port
 * 0x82 is dropped). Same register sequence as startup_copy_flash_image. No caller in the bank-1 image.
 */
void flash_read_three_reply_bytes(void)
{
    unsigned char index;
    index = reg_flash_spi_mode & 0x0c | 1;
    reg_flash_spi_mode = index;
    reg_flash_spi_format = 7;
    reg_flash_spi_read_opcode = DAT_EXTMEM_f068;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 0;
    reg_flash_spi_count_low = 2;
    reg_flash_fifo_port = 0x81;
    reg_flash_spi_start = 2;
    while ((unsigned int)(reg_flash_spi_start & 2)) ;
    reg_flash_fifo_port = 0x82;
    reg_flash_fifo_port;
    for (index = 0; index < 3; index++) DAT_EXTMEM_f064[index] = reg_flash_fifo_port;
}

/* flash_write_command_byte  (FUN_CODE_cad5)
 *
 * Send a flash command followed by one data byte.
 *   cmd: opcode
 *   data_byte
 * Name basis: proven - opcode to 0xF0EE, data byte to 0xF1C3; caller flash_write_extended_addr
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cad5 @ 0xcad5  Byte-exact with OPTIMIZE(8,SPEED) REGFILE(R.ORC), also without REGFILE.
 * Source form: 'data_byte' is 16 bits wide in the definition, although only its low byte (R5) is used: with an
 * 8-bit parameter Keil parks 'cmd' in R6 first and the bytes differ. The caller passes a byte only.
 */
extern unsigned char volatile xdata reg_flash_fifo_port, reg_flash_fifo_wdata, reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low, reg_flash_spi_write_opcode, reg_flash_spi_format;

/*
 * Send the flash command 'cmd' followed by one data byte (the count
 * register is set to 1) and wait until the controller has finished (bit 0 of
 * the start register clears). The data byte goes into the write-data
 * register between the buffer control values 0x82 and 0x84. Used by
 * flash_write_extended_addr with command 0xC5.
 */
void flash_write_command_byte(unsigned char cmd, unsigned int data_byte)
{
    reg_flash_fifo_port = 0x80;
    reg_flash_spi_mode = reg_flash_spi_mode & 0x0c | 0x41;
    reg_flash_spi_format = 3;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 0;
    reg_flash_spi_count_low = 1;
    reg_flash_spi_write_opcode = cmd;
    reg_flash_fifo_port = 0x82;
    reg_flash_fifo_wdata = data_byte;
    reg_flash_fifo_port = 0x84;
    reg_flash_spi_start = 1;
    while ((unsigned int)(reg_flash_spi_start & 1)) ;
}

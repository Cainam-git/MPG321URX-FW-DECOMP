/* flash_send_cmd_read_byte  (FUN_CODE_cf73)
 *
 * Send one SPI flash command and return the byte the flash answers.
 *   cmd: SPI flash opcode
 * Returns: answer byte
 * Name basis: proven - SPI master regs 0xF0EA/0xF0EF; used with 05h Read Status (standard SPI opcode)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cf73 @ 0xcf73  Byte-exact with OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form: the busy test is int-typed (ANL / JNZ instead of JB).
 */
extern unsigned char volatile xdata reg_flash_fifo_port, reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low, reg_flash_spi_read_byte, reg_flash_spi_format;

/*
 * Send the flash command 'cmd' with no address and no data (all three count
 * registers 0), start a one-byte read (start register = 2), wait until bit 1
 * of the start register clears and return the byte the flash answered. Used
 * by flash_write_extended_addr with command 0x05 (Read Status Register).
 */
unsigned char flash_send_cmd_read_byte(unsigned char cmd)
{
    reg_flash_fifo_port = 0;
    reg_flash_spi_read_opcode = cmd;
    reg_flash_spi_mode = reg_flash_spi_mode & 0x0c | 0x41;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 0;
    reg_flash_spi_count_low = 0;
    reg_flash_spi_format = 7;
    reg_flash_spi_start = 2;                                    /* start read */
    while ((unsigned int)(reg_flash_spi_start & 2)) ;
    return reg_flash_spi_read_byte;
}

/* flash_send_cmd  (FUN_CODE_d5f3)
 *
 * Send one single-byte command to the SPI flash and wait until it is out.
 *   cmd: SPI opcode
 * Name basis: proven - SPI master regs 0xF0EE/0xF0E5; used with 06h Write Enable (standard SPI opcode)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d5f3 @ 0xd5f3  Options: OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form: the busy test is an int-typed expression ((unsigned int)(x & 1)): that is what makes Keil emit
 * ANL A,#1 / JNZ instead of a JB on ACC.0.
 */
#define SPI_MODE_KEEP_BUS 0x0c  /* bits of the mode register that are kept */
#define SPI_MODE_COMMAND  0x41  /* command-only transfer */

extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low, reg_flash_spi_write_opcode;

/*
 * Send a one-byte command to the SPI flash and wait until the transfer is finished: opcode into the write opcode
 * register, command-only mode, data count 0, then start (bit 0 of reg_flash_spi_start, which the controller
 * clears when done). Used by flash_write_extended_addr with 06h (write enable).
 */
void flash_send_cmd(unsigned char cmd)
{
    reg_flash_spi_write_opcode = cmd;
    reg_flash_spi_mode = reg_flash_spi_mode & SPI_MODE_KEEP_BUS | SPI_MODE_COMMAND;
    reg_flash_spi_count_high = 0;                                    /* no data bytes */
    reg_flash_spi_count_mid = 0;
    reg_flash_spi_count_low = 0;
    reg_flash_spi_start = 1;
    while ((unsigned int)(reg_flash_spi_start & 1)) ;                /* wait while busy */
}

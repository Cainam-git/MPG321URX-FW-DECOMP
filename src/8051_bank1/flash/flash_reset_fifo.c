/* flash_reset_fifo  (FUN_CODE_0016)
 *
 * Pulse the reset bit of the SPI flash FIFO.
 * Name basis: derived - bit 6 of 0xF0E5 set then cleared; same code as the boot loader's flash_reset_fifo;
 *   callers flash program/read
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_0016 @ 0x0016  OPTIMIZE(7,SPEED)
 * Source form: a set and a clear as two separate statements (the register is volatile, so both are written).
 */
extern unsigned char volatile xdata reg_flash_spi_start;

#define SPI_FIFO_RESET  0x40  /* reg_flash_spi_start bit 6 */

/*
 * flash_reset_fifo - pulse the FIFO reset bit of the SPI flash controller: set bit 6, then clear it again.
 * Called by flash_read_bytes, flash_program and startup_load_core_images before they start a flash transfer.
 */
void flash_reset_fifo(void)
{
    reg_flash_spi_start |= SPI_FIFO_RESET;
    reg_flash_spi_start &= 0xbf;
}

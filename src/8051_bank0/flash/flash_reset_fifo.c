/* flash_reset_fifo  (FUN_CODE_18d6)
 *
 * Pulse the reset bit of the SPI FIFO.
 * Name basis: derived - OR-store then AND-store on one register
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: the register is volatile, so it is read again for the AND (a second MOVX A,@DPTR) as in the
 * firmware; without volatile the value stays in A.
 */
extern unsigned char volatile xdata reg_flash_spi_start;

#define SPI_FIFO_RESET      0x40    /* bit 6 of reg_flash_spi_start */

/* flash_reset_fifo
 *
 * Sets bit 6 of reg_flash_spi_start and clears it again.  Called once by startup_boot_main, before the first
 * flash command.
 */
void flash_reset_fifo(void)
{
    reg_flash_spi_start |= SPI_FIFO_RESET;
    reg_flash_spi_start &= ~SPI_FIFO_RESET & 0xff;
}

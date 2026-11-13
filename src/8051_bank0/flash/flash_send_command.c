/* flash_send_command  (FUN_CODE_17af)
 *
 * Send a flash command that has no data.
 * Name basis: proven - opcode register, start bit, then a wait for completion
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: the mode is built in the local t; the busy test has an (int) cast, which gives the original's
 * ANL A,#1 / JZ instead of JNB ACC.0.  The unused externs in the declarations are kept as matched.
 */

#define SPI_MODE_KEEP_BUS     0x0c  /* bits 2..3 of reg_flash_spi_mode (bus mode) are kept */
#define SPI_MODE_TRANSFER     0x41
#define SPI_START_TRANSFER    0x01  /* reg_flash_spi_start bit 0: set to start, clears when done */
#define POLL_DELAY            10    /* timer_delay_nops rounds between two busy tests */

extern unsigned char volatile xdata reg_flash_spi_mode, reg_flash_command, reg_flash_length_high, reg_flash_length_mid, reg_flash_length_low, reg_flash_spi_start;
extern unsigned char volatile xdata reg_flash_transfer_type, reg_flash_fifo_f1c0, reg_flash_fifo_write, DAT_EXTMEM_f00a, reg_flash_read_opcode, reg_flash_read_byte;
void timer_delay_nops(unsigned char rounds);

/* flash_send_command
 *
 * Sends the single opcode cmd to the flash chip, with no address and no data, and waits until the controller is
 * done.  The transfer type register is not written here.
 *   cmd: opcode
 * Called by SetExtendedAddr and flash_setup_bus_mode, both with 0x06 (write enable).
 */
void flash_send_command(unsigned char cmd)
{
    unsigned char t;
    t = reg_flash_spi_mode & SPI_MODE_KEEP_BUS;
    t |= SPI_MODE_TRANSFER;
    reg_flash_spi_mode = t;
    reg_flash_command = cmd;
    reg_flash_length_high = 0;
    reg_flash_length_mid = 0;
    reg_flash_length_low = 0;
    reg_flash_spi_start = SPI_START_TRANSFER;
    while ((int)(reg_flash_spi_start & SPI_START_TRANSFER)) timer_delay_nops(POLL_DELAY);
}

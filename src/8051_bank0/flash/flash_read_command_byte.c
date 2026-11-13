/* flash_read_command_byte  (FUN_CODE_172d)
 *
 * Send a flash command and return the one byte it answers.
 * Returns: answer byte
 * Name basis: proven - used for the read-status command 0x05 and the extended address read
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: the mode is built in the local t; the busy test has an (int) cast, which gives the original's
 * ANL A,#1 / JZ.  The unused externs in the declarations are kept as matched.
 */

#define SPI_MODE_KEEP_BUS     0x0c  /* bits 2..3 of reg_flash_spi_mode (bus mode) are kept */
#define SPI_MODE_TRANSFER     0x41
#define SPI_TYPE_READ_ONE_BYTE 0x07 /* reg_flash_transfer_type of this command */
#define SPI_START_READ        0x02  /* reg_flash_spi_start bit 1: set to start, clears when done */
#define FIFO_MODE_00          0x00
#define POLL_DELAY            10    /* timer_delay_nops rounds between two busy tests */
#define REG_F00A_VALUE        0x55  /* value written to register 0xF00A; its purpose is not shown */

extern unsigned char volatile xdata reg_flash_spi_mode, reg_flash_command, reg_flash_length_high, reg_flash_length_mid, reg_flash_length_low, reg_flash_spi_start;
extern unsigned char volatile xdata reg_flash_transfer_type, reg_flash_fifo_f1c0, reg_flash_fifo_write, DAT_EXTMEM_f00a, reg_flash_read_opcode, reg_flash_read_byte;
void timer_delay_nops(unsigned char rounds);

/* flash_read_command_byte
 *
 * Sends the opcode cmd to the flash chip and returns the one byte it answers.  The opcode goes into the read
 * opcode register, not the command register, and the answer is taken from reg_flash_read_byte.
 *   cmd: opcode (0x05 read status, 0x35 read status byte 2, 0x15, 0xC8 read extended address)
 * Called by SetExtendedAddr, flash_setup_bus_mode and flash_read_extended_address.
 */
unsigned char flash_read_command_byte(unsigned char cmd)
{
    unsigned char t;
    DAT_EXTMEM_f00a = REG_F00A_VALUE;
    reg_flash_fifo_f1c0 = FIFO_MODE_00;
    reg_flash_read_opcode = cmd;
    t = reg_flash_spi_mode & SPI_MODE_KEEP_BUS;
    t |= SPI_MODE_TRANSFER;
    reg_flash_spi_mode = t;
    reg_flash_length_high = 0;
    reg_flash_length_mid = 0;
    reg_flash_length_low = 0;
    reg_flash_transfer_type = SPI_TYPE_READ_ONE_BYTE;
    reg_flash_spi_start = SPI_START_READ;
    while ((int)(reg_flash_spi_start & SPI_START_READ)) timer_delay_nops(POLL_DELAY);
    return reg_flash_read_byte;
}

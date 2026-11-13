/* flash_write_command_byte  (FUN_CODE_16db)
 *
 * Send a flash command with one data byte.
 * Name basis: proven - through the FIFO; used for the write-extended-address command 0xC5
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: the mode is built in the local t; the busy test has an (int) cast, which gives the original's
 * ANL A,#1 / JZ.  The unused externs in the declarations are kept as matched.
 */

#define SPI_MODE_KEEP_BUS     0x0c  /* bits 2..3 of reg_flash_spi_mode (bus mode) are kept */
#define SPI_MODE_TRANSFER     0x41
#define SPI_TYPE_CMD_ONE_BYTE 0x03  /* reg_flash_transfer_type of this command */
#define SPI_START_TRANSFER    0x01  /* reg_flash_spi_start bit 0: set to start, clears when done */
#define FIFO_MODE_IDLE        0x80
#define FIFO_MODE_WRITE       0x82
#define FIFO_MODE_AFTER_WRITE 0x84
#define POLL_DELAY            10    /* timer_delay_nops rounds between two busy tests */

extern unsigned char volatile xdata reg_flash_spi_mode, reg_flash_command, reg_flash_length_high, reg_flash_length_mid, reg_flash_length_low, reg_flash_spi_start;
extern unsigned char volatile xdata reg_flash_transfer_type, reg_flash_fifo_f1c0, reg_flash_fifo_write, DAT_EXTMEM_f00a, reg_flash_read_opcode, reg_flash_read_byte;
void timer_delay_nops(unsigned char rounds);

/* flash_write_command_byte
 *
 * Sends the opcode cmd followed by the one data byte value to the flash chip (the data byte through the FIFO), and
 * waits until the controller is done.
 *   cmd: opcode;  value: the byte after it
 * Only caller: SetExtendedAddr, with 0xC5 and the new extended address.
 */
void flash_write_command_byte(unsigned char cmd, unsigned char value)
{
    unsigned char t;
    reg_flash_fifo_f1c0 = FIFO_MODE_IDLE;
    t = reg_flash_spi_mode & SPI_MODE_KEEP_BUS;
    t |= SPI_MODE_TRANSFER;
    reg_flash_spi_mode = t;
    reg_flash_transfer_type = SPI_TYPE_CMD_ONE_BYTE;
    reg_flash_length_high = 0;
    reg_flash_length_mid = 0;
    reg_flash_length_low = 1;   /* one byte after the opcode */
    reg_flash_command = cmd;
    reg_flash_fifo_f1c0 = FIFO_MODE_WRITE;
    reg_flash_fifo_write = value;
    reg_flash_fifo_f1c0 = FIFO_MODE_AFTER_WRITE;
    reg_flash_spi_start = SPI_START_TRANSFER;
    while ((int)(reg_flash_spi_start & SPI_START_TRANSFER)) timer_delay_nops(POLL_DELAY);
}

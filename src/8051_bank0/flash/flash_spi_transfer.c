/* flash_spi_transfer  (FUN_CODE_124f)
 *
 * Send a command to the flash chip and read the answer bytes.
 * Name basis: proven - generic SPI transfer: bytes out including the opcode, bytes in through the FIFO
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED).
 * Source form: one local t holds the mode copy and later the dropped first FIFO byte; the length is computed as an
 * unsigned long and its low byte stored through "(unsigned int)(total & 0xff)"; the busy test has an (int) cast.
 * The exact build depends on these.  The same routine is also compiled inside flash/flash_setup_bus_mode.c (see there).
 */

/* Values of the flash controller registers as this routine writes them; their single bits are not named in the
 * firmware or our documentation. */
#define SPI_MODE_KEEP_BUS     0x0c  /* bits 2..3 of reg_flash_spi_mode (bus mode) are kept */
#define SPI_MODE_TRANSFER     0x41
#define SPI_TYPE_TRANSFER     0x13  /* low bits of reg_flash_transfer_type; bits 5.. = bytes out */
#define SPI_START_TRANSFER    0x01  /* reg_flash_spi_start bit 0: set to start, clears when done */
#define FIFO_MODE_WRITE       0x82  /* reg_flash_fifo_f1c0 while the command bytes go in */
#define FIFO_MODE_AFTER_WRITE 0x84
#define FIFO_MODE_81          0x81
#define FIFO_MODE_READ        0x82  /* reg_flash_fifo_f1c8 while the answer comes out */
#define FIFO_MODE_IDLE        0x80  /* both FIFO registers when the transfer is over */

extern unsigned char volatile xdata reg_flash_spi_mode, reg_flash_transfer_type, reg_flash_length_high, reg_flash_length_mid, reg_flash_length_low, reg_flash_command;
extern unsigned char volatile xdata reg_flash_fifo_f1c0, reg_flash_fifo_write, reg_flash_fifo_f1c8, reg_flash_spi_start;

/* flash_spi_transfer
 *
 * Sends n_out bytes to the flash chip (out[0] is the opcode, the rest go through the FIFO), then reads n_in answer
 * bytes into in[].  The controller is given n_out + n_in - 1 as the transfer length.
 *   n_out: bytes to send, opcode included;  out: those bytes
 *   n_in:  answer bytes to read (0 = none);  in: where they go
 * Called by flash_setup_bus_mode (status writes, nothing read) and flash_read_jedec_id (0x9F, four bytes read).
 */
void flash_spi_transfer(unsigned int n_out, unsigned char *out, unsigned int n_in, unsigned char *in)
{
    unsigned char t;        /* mode copy, later the dropped first FIFO byte */
    unsigned long total;    /* transfer length given to the controller */
    unsigned int i;
    /* Transfer mode with the bus-mode bits kept, the number of bytes out, the length. */
    t = reg_flash_spi_mode & SPI_MODE_KEEP_BUS;
    t |= SPI_MODE_TRANSFER;
    reg_flash_spi_mode = t;
    total = n_out + n_in - 1;
    reg_flash_transfer_type = ((unsigned char)n_out << 5) | SPI_TYPE_TRANSFER;
    reg_flash_length_high = total >> 16;
    reg_flash_length_mid = total >> 8;
    reg_flash_length_low = (unsigned int)(total & 0xff);
    /* Opcode to its own register, the further bytes through the FIFO. */
    reg_flash_command = out[0];
    reg_flash_fifo_f1c0 = FIFO_MODE_WRITE;
    for (i = 1; i < n_out; i++) reg_flash_fifo_write = out[i];
    reg_flash_fifo_f1c0 = FIFO_MODE_AFTER_WRITE;
    reg_flash_fifo_f1c8 = FIFO_MODE_81;
    reg_flash_spi_start = SPI_START_TRANSFER;
    while ((int)(reg_flash_spi_start & SPI_START_TRANSFER));
    /* Answer: the first FIFO byte is read and dropped. */
    if (n_in > 0) {
        reg_flash_fifo_f1c8 = FIFO_MODE_READ;
        t = reg_flash_fifo_f1c8;
        for (i = 0; i < n_in; i++) in[i] = reg_flash_fifo_f1c8;
    }
    reg_flash_fifo_f1c0 = FIFO_MODE_IDLE;
    reg_flash_fifo_f1c8 = FIFO_MODE_IDLE;
}

/* flash_read_stream  (FUN_CODE_1491)
 *
 * Read n bytes from the flash chip through the FIFO with a given read opcode and address.
 * Note: Drops bits 15..8 of the address (a latent bug of the original).
 * Name basis: proven - streaming read; always 512 bytes
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED).
 * Source form: the dropped first FIFO byte goes to its own local; the address low byte is stored through
 * "(unsigned int)(addr & 0xff)"; the busy test has an (int) cast; the copy is a do-while on --n.  The exact build
 * depends on these.
 */

#define SPI_MODE_KEEP_BUS   0x0c  /* bits 2..3 of reg_flash_spi_mode (bus mode) are kept */
#define SPI_MODE_STREAM     0x01
#define SPI_TYPE_STREAM     0x0b  /* reg_flash_transfer_type of this read */
#define STREAM_LENGTH_HIGH  0x00  /* transfer length 0x000200 = 512 bytes, whatever n is */
#define STREAM_LENGTH_MID   0x02
#define STREAM_LENGTH_LOW   0x00
#define FIFO_MODE_81        0x81
#define FIFO_MODE_READ      0x82
#define SPI_START_READ      0x02  /* reg_flash_spi_start bit 1: set to start, clears when done */

extern unsigned char volatile xdata reg_flash_read_opcode, reg_flash_spi_mode, reg_flash_transfer_type, reg_flash_length_high, reg_flash_length_mid, reg_flash_length_low;
extern unsigned char volatile xdata reg_flash_addr_f0f0, reg_flash_addr_f0f1, reg_flash_addr_f0f2, reg_flash_fifo_f1c0, reg_flash_spi_start;

/* flash_read_stream
 *
 * Reads n bytes from the flash chip with the read opcode op, from address addr, into dst.  The controller is told
 * to fetch 512 bytes every time; only the first n after the dropped first FIFO byte are taken.
 *   op:   read opcode (flash_setup_bus_mode passes 0x6B quad or 0x3B dual)
 *   addr: flash address; only bits 31..24, 23..16 and 7..0 reach the address registers, bits 15..8 are not
 *         written anywhere
 *   n:    bytes to copy, 1..255 (0 copies 256: the loop counts down before it tests)
 *   dst:  where they go
 * Only caller: flash_setup_bus_mode, which reads 10 bytes from address 0 to compare them with CODE 0x0000.
 */
void flash_read_stream(unsigned char op, unsigned long addr, unsigned char n, unsigned char *dst)
{
    unsigned char t;        /* mode copy */
    unsigned char first;    /* first FIFO byte, read and dropped */
    reg_flash_read_opcode = op;
    t = reg_flash_spi_mode & SPI_MODE_KEEP_BUS;
    t |= SPI_MODE_STREAM;
    reg_flash_spi_mode = t;
    reg_flash_transfer_type = SPI_TYPE_STREAM;
    reg_flash_length_high = STREAM_LENGTH_HIGH;
    reg_flash_length_mid = STREAM_LENGTH_MID;
    reg_flash_length_low = STREAM_LENGTH_LOW;
    reg_flash_addr_f0f0 = addr >> 24;
    reg_flash_addr_f0f1 = addr >> 16;
    reg_flash_addr_f0f2 = (unsigned int)(addr & 0xff);  /* bits 15..8 are skipped */
    reg_flash_fifo_f1c0 = FIFO_MODE_81;
    reg_flash_spi_start = SPI_START_READ;
    while ((int)(reg_flash_spi_start & SPI_START_READ));
    reg_flash_fifo_f1c0 = FIFO_MODE_READ;
    first = reg_flash_fifo_f1c0;
    do {
        *dst++ = reg_flash_fifo_f1c0;
    } while (--n);
}

/* flash_spi_transfer  (FUN_CODE_7df1)
 *
 * Send command bytes to the SPI flash and read the answer bytes.
 *   send_count: bytes to send
 *   send_bytes: command bytes
 *   read_count: bytes to read
 *   read_bytes: answer
 * Name basis: proven - writes wn bytes, reads rn bytes through the flash controller FIFO 0xF1C3/0xF1C8; used
 *   for the status registers
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_7df1 @ 0x7df1 (325 bytes), OPTIMIZE(8,SPEED) LARGE.
 * volatile on the controller registers: reg_flash_spi_start is polled, the FIFO data registers are written and
 *   read repeatedly at one address. Because reg_flash_spi_mode is volatile, Keil reads mode back after storing it
 *   ('MOVX @DPTR,A; MOVX A,@DPTR' before 'ORL A,#41H').
 * Source form: 'mode = reg_flash_spi_mode & SPI_MODE_KEEP_BUS; mode |= SPI_MODE_TRANSFER;' as two statements;
 *   'byte_count & 0xff' for the last count byte (the value goes through R7 like the two shifted bytes;
 *   '(unsigned char)byte_count' stores it straight from A). byte_count is a long holding a 16-bit sum.
 */
extern unsigned char volatile xdata reg_flash_spi_mode;
extern unsigned char volatile xdata reg_flash_spi_format, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low, reg_flash_spi_write_opcode;
extern unsigned char volatile xdata reg_flash_fifo_port, reg_flash_fifo_wdata;
extern unsigned char volatile xdata reg_flash_fifo_rdata;
extern unsigned char volatile xdata reg_flash_spi_start;

#define SPI_MODE_KEEP_BUS     0x0c  /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_TRANSFER     0x41
#define SPI_FORMAT_SEND_SHIFT 5     /* reg_flash_spi_format bits 7..5: number of bytes sent */
#define SPI_FORMAT_BITS_13    0x13
#define SPI_START_TRANSFER    0x01  /* reg_flash_spi_start bit 0: set to start, clears when done */

/*
 * flash_spi_transfer - send a command to the SPI flash and read its answer.
 *   send_count   number of bytes sent (opcode included)
 *   send_bytes   the opcode in [0], further bytes after it
 *   read_count   number of answer bytes to read (0: none)
 *   read_bytes   receives the answer
 * The opcode goes into reg_flash_spi_write_opcode, the further bytes through the FIFO; the controller is given
 * the total byte count minus one. After the transfer the first byte of the read FIFO is dropped and the next
 * read_count bytes are the answer.
 * Callers: flash_unprotect and flash_restore_status (the flash status registers).
 */
void flash_spi_transfer(unsigned int send_count, unsigned char *send_bytes, unsigned int read_count, unsigned char *read_bytes)
{
    unsigned int i;
    unsigned char mode;
    unsigned long byte_count;

    mode = reg_flash_spi_mode & SPI_MODE_KEEP_BUS;
    mode |= SPI_MODE_TRANSFER;
    reg_flash_spi_mode = mode;
    byte_count = send_count + read_count - 1;
    reg_flash_spi_format = ((unsigned char)send_count << SPI_FORMAT_SEND_SHIFT) | SPI_FORMAT_BITS_13;
    reg_flash_spi_count_high = byte_count >> 16;
    reg_flash_spi_count_mid = byte_count >> 8;
    reg_flash_spi_count_low = byte_count & 0xff;
    reg_flash_spi_write_opcode = send_bytes[0];
    reg_flash_fifo_port = 0x82;
    for (i = 1; i < send_count; i++)
        reg_flash_fifo_wdata = send_bytes[i];
    reg_flash_fifo_port = 0x84;
    reg_flash_fifo_rdata = 0x81;
    reg_flash_spi_start = SPI_START_TRANSFER;
    while ((unsigned int)(reg_flash_spi_start & SPI_START_TRANSFER))
        ;
    if (read_count > 0) {
        reg_flash_fifo_rdata = 0x82;
        mode = reg_flash_fifo_rdata;   /* first byte of the read FIFO, not used */
        for (i = 0; i < read_count; i++)
            read_bytes[i] = reg_flash_fifo_rdata;
    }
    reg_flash_fifo_port = 0x80;
    reg_flash_fifo_rdata = 0x80;
}

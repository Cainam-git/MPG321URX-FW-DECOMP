/* flash_read_bytes  (FUN_CODE_7ca8)
 *
 * Read a range of the SPI flash into memory in 512-byte pieces.
 *   dst: XDATA buffer
 *   addr: flash address
 *   len: byte count
 * Name basis: proven - prints 'read flash flashaddr %08lx, Length %d'; caller flash_read_to_buffer
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * LARGE block: dst 0xA4B3 (passed in R6:R7), addr 0xA4B5..0xA4B8, len 0xA4B9..0xA4BA; locals first_byte 0xA4BB,
 *   read_addr 0xA4BC..0xA4BF, chunk_bytes 0xA4C0..0xA4C1.
 * Source forms: 'chunk_bytes & 0xff' for the last count byte (a plain value or a cast swaps MOV A,R5 / MOV DPTR at
 *   0x7D4A); len >= 0x200 compiles to the high-byte SUBB #2 test; the discarded first read is stored (first_byte).
 */

#define READ_CHUNK_BYTES          0x200  /* bytes per read transfer */
#define SPI_MODE_KEEP_BUS         0x0c   /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_READ             0x01
#define SPI_FORMAT_READ           0x0b
#define SPI_START_READ            0x02   /* reg_flash_spi_start bit 1: read transfer, clears when done */

extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low;
extern unsigned char volatile xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low, reg_flash_spi_format, reg_flash_fifo_port;
extern unsigned char xdata flash_read_opcode;
extern void flash_begin_access(void);
extern void flash_end_access(void);
extern void flash_reset_fifo(void);
extern void lib_printf517(void *fmt, ...) large;

/* Read 'len' bytes of the SPI flash from address 'addr' into XDATA 'dst', in transfers of up to 512 bytes.
 * Only caller: flash_read_to_buffer (mailbox command 0x12, the flash job range into the flash data buffer).
 * Prints "read flash flashaddr %08lx, Length %d", claims the flash and resets its FIFO. Each transfer uses the read
 * command chosen at start-up (flash_read_opcode: quad, dual or fast read), the byte count and address bits 23..0;
 * after the controller has finished, the first byte of the FIFO is read and dropped, then the chunk is copied out.
 * The flash is released at the end. len 0 still starts one transfer, with a count of 0.
 */
void flash_read_bytes(unsigned char xdata *dst, unsigned long addr, unsigned int len)
{
    unsigned char first_byte;
    unsigned long read_addr;
    unsigned int chunk_bytes;

    lib_printf517((void code *)0xa2f3, addr, len);    /* "read flash flashaddr %08lx, Length %d" */
    flash_begin_access();
    flash_reset_fifo();
    read_addr = addr;
    do {
        if (len >= READ_CHUNK_BYTES) {
            chunk_bytes = READ_CHUNK_BYTES;
            len -= READ_CHUNK_BYTES;
        } else {
            chunk_bytes = len;
            len = 0;
        }
        /* Set up and start one read transfer. */
        reg_flash_spi_read_opcode = flash_read_opcode;
        reg_flash_spi_mode = reg_flash_spi_mode & SPI_MODE_KEEP_BUS | SPI_MODE_READ;
        reg_flash_spi_count_high = 0;
        reg_flash_spi_count_mid = chunk_bytes >> 8;
        reg_flash_spi_count_low = chunk_bytes & 0xff;
        reg_flash_spi_addr_high = ((unsigned char *)&read_addr)[1];
        reg_flash_spi_addr_mid = ((unsigned char *)&read_addr)[2];
        reg_flash_spi_addr_low = ((unsigned char *)&read_addr)[3];
        reg_flash_spi_format = SPI_FORMAT_READ;
        reg_flash_fifo_port = 0x81;
        reg_flash_spi_start = SPI_START_READ;
        while ((unsigned int)(reg_flash_spi_start & SPI_START_READ)) ;

        /* Copy the chunk out of the FIFO; its first byte is not part of the data. */
        reg_flash_fifo_port = 0x82;
        first_byte = reg_flash_fifo_port;
        while (chunk_bytes > 0) {
            *dst++ = reg_flash_fifo_port;
            chunk_bytes--;
        }
        read_addr += READ_CHUNK_BYTES;
    } while (len);
    flash_end_access();
}

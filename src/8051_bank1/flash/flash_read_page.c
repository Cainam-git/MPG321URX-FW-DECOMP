/* flash_read_page  (FUN_CODE_b192)
 *
 * Read one 256-byte flash page into the transfer buffer.
 *   addr_23_16: address bits 23..16
 *   addr_15_8: bits 15..8
 *   addr_7_0: bits 7..0
 * Name basis: proven - Fast Read 0x0B into XDATA 0x3200 (sibling of flash_sum_page); update loop command 4
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b192 @ 0xb192, OPTIMIZE(8,SPEED) LARGE.
 * Source form: the registers are declared without a memory type (xdata by the LARGE model) and volatile; the mode
 * value goes through the local fifo_byte; the poll test is cast to unsigned int for the firmware's ANL / JNZ; the
 * first FIFO read after 0x82 is stored to fifo_byte and dropped.
 */
extern void flash_begin_access(void);
extern void flash_end_access(void);

extern volatile unsigned char reg_flash_spi_mode;
extern volatile unsigned char reg_flash_spi_read_opcode;
extern volatile unsigned char reg_flash_spi_count_high;
extern volatile unsigned char reg_flash_spi_count_mid;
extern volatile unsigned char reg_flash_spi_count_low;
extern volatile unsigned char reg_flash_spi_addr_high;
extern volatile unsigned char reg_flash_spi_addr_mid;
extern volatile unsigned char reg_flash_spi_addr_low;
extern volatile unsigned char reg_flash_spi_format;
extern volatile unsigned char reg_flash_spi_start;
extern volatile unsigned char reg_flash_fifo_port;

#define FLASH_READ_FAST     0x0B  /* SPI flash Fast Read opcode */
#define SPI_MODE_KEEP_BUS   0x0C  /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_READ       0x01  /* read or program transfer */
#define SPI_START_READ      0x02  /* reg_flash_spi_start bit 1: set to start a read, clears when done */
#define FLASH_PAGE_BUFFER   ((unsigned char xdata *)0x3200)  /* transfer buffer, also the source of flash_program_page */

/*
 * flash_read_page - read one 256-byte flash page with Fast Read into the transfer buffer at XDATA 0x3200.
 *   addr_23_16, addr_15_8, addr_7_0  the page's 24-bit flash address, one byte each
 * Only caller: the update loop fwupd_run_flash_loop, command 4 (FWUPD_CMD_READ_PAGE), with the address bytes from
 * its mailbox. The SPI set-up is the same as in flash_sum_page, which adds the bytes up instead of storing them.
 * Order: claim the flash interface, set up a 256-byte (count 0x000100) read at the address, write 0x81 to the FIFO
 * port, start and wait until reg_flash_spi_start bit 1 clears (no time limit), write 0x82 to the FIFO port, read
 * and drop one byte, then read 256 bytes into the buffer and release the interface.
 */
void flash_read_page(unsigned char addr_23_16, unsigned char addr_15_8, unsigned char addr_7_0) large {
    unsigned char i = 0;
    unsigned char fifo_byte;
    unsigned char xdata *page_buffer;
    
    flash_begin_access();
    page_buffer = FLASH_PAGE_BUFFER;
    
    reg_flash_spi_read_opcode = FLASH_READ_FAST;
    fifo_byte = (reg_flash_spi_mode & SPI_MODE_KEEP_BUS) | SPI_MODE_READ;
    reg_flash_spi_mode = fifo_byte;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 1;
    reg_flash_spi_count_low = 0;
    
    reg_flash_spi_addr_high = addr_23_16;
    reg_flash_spi_addr_mid = addr_15_8;
    reg_flash_spi_addr_low = addr_7_0;
    
    reg_flash_spi_format = 0x0B;
    reg_flash_fifo_port = 0x81;
    reg_flash_spi_start = SPI_START_READ;
    
    while ((unsigned int)(reg_flash_spi_start & SPI_START_READ));
    
    reg_flash_fifo_port = 0x82;
    fifo_byte = reg_flash_fifo_port;   /* first byte read after 0x82 is not stored */
    i = 0;
    
    /* 256 bytes: i wraps from 0xFF to 0. */
    do {
        fifo_byte = reg_flash_fifo_port;
        page_buffer[i] = fifo_byte;
        i++;
    } while (i != 0);
    
    flash_end_access();
}

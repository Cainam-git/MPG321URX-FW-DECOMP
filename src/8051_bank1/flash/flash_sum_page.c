/* flash_sum_page  (FUN_CODE_ac5b)
 *
 * Return the 16-bit sum of one 256-byte flash page.
 *   a2: address bits 23..16
 *   a1: bits 15..8
 *   a0: bits 7..0
 * Returns: sum
 * Name basis: proven - Fast Read 0x0B of 256 bytes; update loop command 2 compares it ('checksum error')
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ac5b, OPTIMIZE(8,SPEED) LARGE.
 * Source form: the mode value and the dropped first FIFO byte both go through the one char local scratch (a
 * plain expression statement or an inline store drops the register copy the firmware has). 'count++; } while
 * (count);' gives the re-read of count after the store (++count does not).
 */
#define FLASH_READ_FAST      0x0b  /* SPI flash Fast Read opcode */
#define SPI_MODE_KEEP_BUS    0x0c  /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_READ        0x01
#define SPI_START_READ       0x02  /* reg_flash_spi_start bit 1: set to start, clears when done */
extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low;
extern unsigned char volatile xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low, reg_flash_spi_format, reg_flash_fifo_port;
extern void flash_begin_access(void);
extern void flash_end_access(void);

/*
 * flash_sum_page - add up the 256 bytes of the flash page at the 24-bit address a2:a1:a0 (a2 = bits 23..16) and
 * return the sum as 16 bits. Reads only; nothing is written to the flash.
 * Used by the update loop (command 2, which compares the sum with the one it was given). The SPI set-up is the same
 * as in flash_read_page, which stores the bytes instead of adding them.
 */
unsigned int flash_sum_page(unsigned char a2, unsigned char a1, unsigned char a0)
{
    unsigned char count = 0;
    unsigned char scratch;
    unsigned int sum;

    flash_begin_access();
    /* Fast Read, 0x000100 bytes from the given address. */
    reg_flash_spi_read_opcode = FLASH_READ_FAST;
    scratch = (reg_flash_spi_mode & SPI_MODE_KEEP_BUS) | SPI_MODE_READ;
    reg_flash_spi_mode = scratch;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 1;
    reg_flash_spi_count_low = 0;
    reg_flash_spi_addr_high = a2;
    reg_flash_spi_addr_mid = a1;
    reg_flash_spi_addr_low = a0;
    reg_flash_spi_format = 0x0b;
    reg_flash_fifo_port = 0x81;
    reg_flash_spi_start = SPI_START_READ;
    while ((unsigned int)(reg_flash_spi_start & SPI_START_READ)) ;  /* no time limit */
    reg_flash_fifo_port = 0x82;
    scratch = reg_flash_fifo_port;  /* first byte read after 0x82 is dropped */
    sum = 0;
    /* 256 bytes: count wraps from 0xFF to 0. */
    do {
        sum += reg_flash_fifo_port;
        count++;
    } while (count);
    flash_end_access();
    return sum;
}

/* dbg_dump_flash_block  (FUN_CODE_a41f)
 *
 * Read 512 bytes from the flash and print them as hex.
 * Note: No caller in the bank-1 image.
 * Name basis: derived - flash read with command op through 0xF0E5..0xF1C0; prints each byte, offset every 16
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a41f @ 0xa41f..0xa4d2 (179 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals: value 0xA767, i 0xA768..0xA769.
 * Source form: the reg_flash_spi_mode update is an unsigned int expression; the char form makes Keil move opcode
 *   from R7 to R5 at entry (MOV R5,AR7) because that expression uses R7 as a temporary. The wait loop tests an
 *   int-typed value.
 * volatile on the flash registers: reg_flash_fifo_port is read again for every byte, reg_flash_spi_start is polled.
 */
extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low;
extern unsigned char volatile xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low, reg_flash_spi_format, reg_flash_fifo_port;
extern unsigned char xdata flash_block_addr_high, flash_block_addr_bits_7_0, flash_block_addr_bits_15_8;
extern void lib_printf517(void *fmt, ...) large;

#define SPI_MODE_KEEP_BUS  0x0c   /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_READ      0x01
#define SPI_FORMAT_READ    0x0b
#define SPI_START_READ     0x02   /* reg_flash_spi_start bit 1: read transfer, clears when done */
#define DUMP_BLOCK_BYTES   0x200  /* one transfer of 512 bytes (count registers 0x00 0x02 0x00) */
#define DUMP_LINE_BYTES    0x10   /* bytes printed per line */

/*
 * dbg_dump_flash_block - read one 512-byte block from the SPI flash with the read command opcode and print it
 * in hex, 16 bytes per line, each line starting with its offset ("\r\n%04X:" then "%02bX " per byte).
 *   opcode  flash read command for the transfer
 * The address registers get flash_block_addr_high, then flash_block_addr_bits_15_8 as the middle byte and
 * flash_block_addr_bits_7_0 as the last byte, the same order as in flash_sum_block and flash_read_block_to_pointer.
 * Unlike flash_read_bytes it does not claim the flash or reset its FIFO first.
 * Nothing in the bank 1 program calls this routine.
 */
void dbg_dump_flash_block(unsigned char opcode)
{
    unsigned char value;
    unsigned int i;

    reg_flash_spi_mode = (unsigned int)reg_flash_spi_mode & SPI_MODE_KEEP_BUS | SPI_MODE_READ;
    reg_flash_spi_read_opcode = opcode;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 2;
    reg_flash_spi_count_low = 0;
    reg_flash_spi_addr_high = flash_block_addr_high;
    reg_flash_spi_addr_mid = flash_block_addr_bits_15_8;
    reg_flash_spi_addr_low = flash_block_addr_bits_7_0;
    reg_flash_spi_format = SPI_FORMAT_READ;
    reg_flash_fifo_port = 0x81;
    reg_flash_spi_start = SPI_START_READ;
    while ((unsigned int)(reg_flash_spi_start & SPI_START_READ)) ;

    /* The first byte of the FIFO is not part of the data (as in flash_read_bytes). */
    reg_flash_fifo_port = 0x82;
    value = reg_flash_fifo_port;
    for (i = 0; i < DUMP_BLOCK_BYTES; i++) {
        value = reg_flash_fifo_port;
        if ((i & (DUMP_LINE_BYTES - 1)) == 0) lib_printf517((void code *)0xa32c, i);   /* "\r\n%04X:" */
        lib_printf517((void code *)0xa334, value);                                      /* "%02bX " */
    }
}

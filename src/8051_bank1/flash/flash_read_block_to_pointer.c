/* flash_read_block_to_pointer  (FUN_CODE_b6fe)
 *
 * Read 512 flash bytes to the buffer named by a pointer.
 * Note: No caller in the bank-1 image.
 * Name basis: derived - Fast Read 0x0B through 0xF0xx/0xF1C0, stores via pointer 0xA74A
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b6fe, OPTIMIZE(7,SPEED) (the same bytes at OPTIMIZE(8,SPEED) LARGE). The wait test is int-typed.
 * The 0xF0xx / 0xF1xx locations are hardware registers (volatile).
 */
extern unsigned char volatile xdata reg_flash_fifo_port, reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode;
extern unsigned char volatile xdata reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low;
extern unsigned char volatile xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low, reg_flash_spi_format;
extern unsigned char xdata flash_block_addr_high, flash_block_addr_bits_7_0, flash_block_addr_bits_15_8, DAT_EXTMEM_a778;
extern unsigned char xdata * xdata flash_block_byte_ptr;

/*
 * flash_read_block_to_pointer - Fast Read (0x0B) of 0x200 (512) bytes, stored through the pointer
 * flash_block_byte_ptr, which advances by one per byte. The address comes from the same three XDATA bytes as in
 * flash_sum_block. No caller in the bank-1 image.
 */
void flash_read_block_to_pointer(void)
{
    unsigned int i;

    reg_flash_spi_read_opcode = 0x0b;
    reg_flash_spi_mode = (reg_flash_spi_mode & 0x0c) | 1;
    reg_flash_spi_format = 0x0b;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 2;
    reg_flash_spi_count_low = 0;
    reg_flash_spi_addr_high = flash_block_addr_high;
    reg_flash_spi_addr_mid = flash_block_addr_bits_15_8;
    reg_flash_spi_addr_low = flash_block_addr_bits_7_0;
    reg_flash_fifo_port = 0x81;
    reg_flash_spi_start = 2;
    while ((unsigned int)(reg_flash_spi_start & 2)) ;
    reg_flash_fifo_port = 0x82;
    DAT_EXTMEM_a778 = reg_flash_fifo_port;
    for (i = 0; i < 0x200; i++) *flash_block_byte_ptr++ = reg_flash_fifo_port;
}

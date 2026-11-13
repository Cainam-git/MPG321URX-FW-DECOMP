/* flash_sum_block  (FUN_CODE_b5f2)
 *
 * Read 512 flash bytes and store their sum.
 * Note: No caller in the bank-1 image.
 * Name basis: derived - read opcode from flash_read_opcode through 0xF0xx/0xF1C0, sum to 0xA74C; counterpart
 *   flash_read_block_to_pointer
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b5f2, OPTIMIZE(7,SPEED) (the same bytes at OPTIMIZE(8,SPEED) LARGE). The wait test is int-typed
 * ('(unsigned int)(x & 2)', ANL/JNZ). The 0xF0xx / 0xF1xx locations are hardware registers (volatile).
 */
extern unsigned char volatile xdata reg_flash_fifo_port, reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode;
extern unsigned char volatile xdata reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low;
extern unsigned char volatile xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low, reg_flash_spi_format;
extern unsigned char xdata flash_read_opcode, flash_block_addr_high, flash_block_addr_bits_7_0, flash_block_addr_bits_15_8, DAT_EXTMEM_a779;
extern unsigned int xdata flash_block_sum;

/*
 * flash_sum_block - read 0x200 (512) bytes with the read opcode kept in flash_read_opcode and store their 16-bit
 * sum in flash_block_sum. The address comes from three XDATA bytes (0xA74E, 0xA750, 0xA74F, in that order into the
 * high, middle and low address registers). Same SPI set-up as flash_read_block_to_pointer, which stores the
 * bytes instead. No caller in the bank-1 image.
 */
void flash_sum_block(void)
{
    unsigned int i;

    reg_flash_spi_read_opcode = flash_read_opcode;
    reg_flash_spi_mode = (reg_flash_spi_mode & 0x0c) | 1;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 2;
    reg_flash_spi_count_low = 0;
    reg_flash_spi_addr_high = flash_block_addr_high;
    reg_flash_spi_addr_mid = flash_block_addr_bits_15_8;
    reg_flash_spi_addr_low = flash_block_addr_bits_7_0;
    reg_flash_spi_format = 0x0b;
    reg_flash_fifo_port = 0x81;
    reg_flash_spi_start = 2;
    while ((unsigned int)(reg_flash_spi_start & 2)) ;
    reg_flash_fifo_port = 0x82;
    DAT_EXTMEM_a779 = reg_flash_fifo_port;
    flash_block_sum = 0;
    for (i = 0; i < 0x200; i++) flash_block_sum += reg_flash_fifo_port;
}

/* flash_enable_quad_mode  (FUN_CODE_b679)
 *
 * Switch the SPI flash and its controller to quad mode.
 * Note: No caller in the bank-1 image.
 * Name basis: proven - prints 'Flash change to Quad mode!!', 'Write enable!!'; status write 0x42
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b679, OPTIMIZE(7,SPEED) (the same bytes at OPTIMIZE(8,SPEED) LARGE). The wait test is int-typed.
 * The 0xF0xx / 0xF1xx locations are hardware registers (volatile).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f134, reg_gpio_port12_partner, DAT_EXTMEM_f075, reg_flash_read_mode;
extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_count_high, reg_flash_spi_count_mid;
extern unsigned char volatile xdata reg_flash_spi_count_low, reg_flash_spi_write_opcode, reg_flash_spi_format, reg_flash_fifo_port, reg_flash_fifo_wdata;
extern unsigned char xdata flash_read_opcode;
extern void lib_printf517(void *fmt, ...) large;
void flash_send_cmd(unsigned char cmd);

/*
 * flash_enable_quad_mode - print "Flash change to Quad mode!!", send Write Enable, print "Write enable!!", then set
 * the controller registers (0xF134, 0xF11D, 0xF075, 0xF050, mode 0xF0E6) and send a two-byte write of 0x42, 0x00
 * through the FIFO (format 3, write opcode 0xF0EE = 1; the flash's Write Status command is 0x01). Waits until
 * bit 0 of reg_flash_spi_start clears (no time limit), then stores 0x6B in flash_read_opcode (the opcode
 * flash_sum_block uses). No caller in the bank-1 image.
 */
void flash_enable_quad_mode(void)
{
    lib_printf517((void code *)0xa2b8);   /* "\r\n<<<< Flash change to Quad mode!!>>>\r\n" */
    flash_send_cmd(6);
    lib_printf517((void code *)0xa2e0);   /* "\r\nWrite enable!!\r\n" */
    DAT_EXTMEM_f134 |= 0xc0;
    reg_gpio_port12_partner |= 0x80;
    reg_gpio_port12_partner &= 0xbf;
    DAT_EXTMEM_f075 |= 0x10;
    reg_flash_read_mode = (reg_flash_read_mode & 0xdf) | 0x04;
    reg_flash_spi_mode = (reg_flash_spi_mode & 0x0c) | 0x41;
    reg_flash_spi_format = 3;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 0;
    reg_flash_spi_count_low = 2;
    reg_flash_spi_write_opcode = 1;
    reg_flash_fifo_port = 0x82;
    reg_flash_fifo_wdata = 0x42;
    reg_flash_fifo_wdata = 0;
    reg_flash_fifo_port = 0x84;
    reg_flash_spi_start = 1;
    while ((unsigned int)(reg_flash_spi_start & 1)) ;
    flash_read_opcode = 0x6b;
}

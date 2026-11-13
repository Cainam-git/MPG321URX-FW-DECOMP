/* flash_program_page  (FUN_CODE_bd81)
 *
 * Program one 256-byte page from the transfer buffer into the flash.
 *   addr_23_16: address bits 23..16
 *   addr_15_8: bits 15..8
 *   addr_7_0: bits 7..0
 * Name basis: proven - source XDATA 0x3200, 24-bit address; update loop commands 2 and 5
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_bd81, OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char volatile xdata reg_flash_fifo_port, reg_flash_fifo_wdata, reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low;
extern void flash_begin_access(void);
extern void flash_end_access(void);
extern void flash_send_cmd(unsigned char cmd);
extern unsigned char flash_send_cmd_read_byte(unsigned char cmd);
extern void flash_start_page_program(void);
/*
 * flash_program_page - write the 256 bytes at XDATA 0x3200 into the flash page at the 24-bit address
 * addr_23_16:addr_15_8:addr_7_0.
 * Order (between flash_begin_access and flash_end_access): FIFO port 0x82 and 256 bytes into the write data
 * register, FIFO port 0x81, Write Enable (06h), wait until the write-enable bit (Read Status bit 1) is set, address
 * registers, flash_start_page_program (Page Program, 02h), wait until the busy bit (bit 0) clears.
 * Used by the update loop fwupd_run_flash_loop (commands 2 and 5).
 */
void flash_program_page(unsigned char addr_23_16, unsigned char addr_15_8, unsigned char addr_7_0)
{
    unsigned char xdata *page_buffer;
    unsigned char i;
    flash_begin_access();
    page_buffer = (unsigned char xdata *)0x3200;
    reg_flash_fifo_port = 0x82;
    i = 0;
    do {
        reg_flash_fifo_wdata = page_buffer[i++];
    } while (i);
    reg_flash_fifo_port = 0x81;
    flash_send_cmd(6);
    while (!(flash_send_cmd_read_byte(5) & 2)) ;
    reg_flash_spi_addr_high = addr_23_16;
    reg_flash_spi_addr_mid = addr_15_8;
    reg_flash_spi_addr_low = addr_7_0;
    flash_start_page_program();
    while (flash_send_cmd_read_byte(5) & 1) ;
    flash_end_access();
}

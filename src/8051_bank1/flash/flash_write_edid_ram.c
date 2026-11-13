/* flash_write_edid_ram  (FUN_CODE_aa93)
 *
 * Program the 512 bytes of EDID RAM into the flash as two pages.
 * Note: No caller in the bank-1 image.
 * Name basis: derived - source 0xF800..0xF9FF (EDID RAM, message type 1), two Page Program runs at the address
 *   0xA75F
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_aa93 @ 0xAA93..0xAB2C (153 bytes), OPTIMIZE(8,SPEED) REGFILE(R.ORC) (the same bytes with LARGE
 *   added). The counter i stays in R2:R3 across the calls (whole-program register file).
 * Source form: the bytes move through the stored pointer flash_block_byte_ptr ('*flash_block_byte_ptr++', ?C?ILDIX).
 * The flash registers are volatile.
 */
extern unsigned char volatile xdata reg_flash_fifo_port, reg_flash_fifo_wdata;
extern unsigned char volatile xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low;
extern unsigned char xdata * xdata flash_block_byte_ptr;
extern union { unsigned long l; unsigned char b[4]; } xdata flash_edid_write_addr;
void flash_send_cmd(unsigned char cmd);
unsigned char flash_send_cmd_read_byte(unsigned char cmd);
extern void flash_start_page_program(void);

#define EDID_RAM_START          0xf800  /* edid_ram, filled by message type 1 */
#define EDID_WRITE_BYTES        0x200
#define EDID_WRITE_PAGES        2
#define FLASH_PAGE_BYTES        0x100
#define FLASH_CMD_WRITE_ENABLE  0x06
#define FLASH_CMD_READ_STATUS   0x05
#define FLASH_STATUS_BUSY       0x01
#define FLASH_STATUS_WEL        0x02

/*
 * flash_write_edid_ram - program the first 512 bytes of the EDID RAM (0xF800..0xF9FF) into the SPI flash as two
 * 256-byte pages, starting at the flash address in flash_edid_write_addr.
 * The 512 bytes go into the flash FIFO first. Then for each page: write enable, wait for the write-enable bit,
 * address bits 23..0 into the SPI address registers, flash_start_page_program, address + 0x100, and wait until
 * the flash is no longer busy. flash_edid_write_addr points after the second page at the end.
 * Nothing in the bank 1 program calls this routine.
 */
void flash_write_edid_ram(void)
{
    unsigned int i;

    reg_flash_fifo_port = 0x82;
    flash_block_byte_ptr = (unsigned char xdata *)EDID_RAM_START;
    for (i = 0; i < EDID_WRITE_BYTES; i++) reg_flash_fifo_wdata = *flash_block_byte_ptr++;
    reg_flash_fifo_port = 0x82;
    for (i = 0; i < EDID_WRITE_PAGES; i++) {
        flash_send_cmd(FLASH_CMD_WRITE_ENABLE);
        while (!(flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL)) ;
        reg_flash_spi_addr_high = flash_edid_write_addr.b[1];
        reg_flash_spi_addr_mid = flash_edid_write_addr.b[2];
        reg_flash_spi_addr_low = flash_edid_write_addr.b[3];
        flash_start_page_program();
        flash_edid_write_addr.l += FLASH_PAGE_BYTES;
        while (flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY) ;
    }
}

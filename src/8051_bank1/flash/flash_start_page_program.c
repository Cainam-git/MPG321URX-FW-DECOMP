/* flash_start_page_program  (FUN_CODE_c5f0)
 *
 * Issue the Page Program command for the prepared 256-byte page.
 * Name basis: proven - opcode 0x02; callers flash_program_page, flash_write_edid_ram
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c5f0 @ 0xc5f0  OPTIMIZE(8,SPEED) REGFILE(R.ORC)
 * Source form: the wait is written 'for (;;) if (...) break;' (that makes Keil emit CLR A before the last store).
 * The dummy read of the buffer register and the write-back of 0xF1C2 with its own value are statements of the
 * original and must stay.
 */
/* Flash command code for Page Program. */
#define FLASH_CMD_PAGE_PROGRAM 2

extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low, reg_flash_spi_write_opcode, reg_flash_spi_format;
extern unsigned char volatile xdata reg_flash_fifo_port, DAT_EXTMEM_f1c1, DAT_EXTMEM_f1c2;

/*
 * Start a Page Program on the flash chip for the page that the caller has
 * already prepared: the 24-bit address is in 0xF0F0..0xF0F2 and the 256 data
 * bytes are in the write buffer (set up by flash_program_page /
 * flash_write_edid_ram). Waits until the controller has finished.
 */
void flash_start_page_program(void)
{
    reg_flash_spi_mode = reg_flash_spi_mode & 0x0c | 0x01;   /* keep bits 2..3, set bit 0 */
    reg_flash_spi_format = 3;
    reg_flash_spi_read_opcode = FLASH_CMD_PAGE_PROGRAM;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 0;
    reg_flash_spi_count_low = 0xff;
    /* Write-buffer set-up, in the order the controller needs. */
    reg_flash_fifo_port = 2;
    reg_flash_fifo_port;                                     /* dummy read */
    reg_flash_spi_write_opcode = reg_flash_fifo_port;
    DAT_EXTMEM_f1c2 = DAT_EXTMEM_f1c2;
    DAT_EXTMEM_f1c1 = 1;
    reg_flash_fifo_port = 4;
    reg_flash_spi_start = 1;
    for (;;) if (!(unsigned int)(reg_flash_spi_start & 1)) break;   /* bit 0 clears when done */
    reg_flash_fifo_port = 0;
}

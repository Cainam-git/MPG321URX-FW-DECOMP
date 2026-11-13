/* flash_program  (FUN_CODE_6f26)
 *
 * Program a buffer into the SPI flash, one 256-byte page at a time.
 *   src: XDATA source
 *   addr: flash address
 *   len: byte count
 * Name basis: proven - Page Program sequence per page; write protection lifted by flash_unprotect and restored
 *   by flash_restore_status
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * LARGE block: src 0xA4B6, addr 0xA4B8..0xA4BB, len 0xA4BC..0xA4BD, page_addr 0xA4BE..0xA4C1, page_bytes
 *   0xA4C2..0xA4C3, saved_status 0xA4C4..0xA4C5; i in R6:R7. The 0xF0xx / 0xF1xx registers are volatile.
 * Source forms: the wait for the end of the transfer is flash_start_page_program's
 *   'for (;;) if (!(unsigned int)(start & 1)) break;' (CLR A before 'fifo = 0'); the count's middle byte is
 *   '(unsigned int)(unsigned long)page_bytes >> 8': with the long conversion Keil loads the value into R2:R3 as for
 *   a long operand, and the conversion back to int leaves an int shift ('MOV A,R2'), as in the firmware; the last
 *   byte is 'page_bytes & 0xff'.
 */

/* Flash commands and status bits (names as in the other flash routines of both 8051 programs). */
#define FLASH_CMD_PAGE_PROGRAM   0x02  /* as in flash_start_page_program */
#define FLASH_CMD_READ_STATUS    0x05
#define FLASH_CMD_WRITE_ENABLE   0x06
#define FLASH_STATUS_BUSY        0x01
#define FLASH_STATUS_WEL         0x02

#define FLASH_PAGE_BYTES         0x100  /* one Page Program covers at most this many bytes */
#define SPI_MODE_KEEP_BUS        0x0c   /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_PROGRAM         0x01
#define SPI_FORMAT_WITH_ADDRESS  3
#define SPI_START_TRANSFER       0x01   /* reg_flash_spi_start bit 0: set to start, clears when done */

extern unsigned char volatile xdata reg_flash_fifo_port, DAT_EXTMEM_f1c1, DAT_EXTMEM_f1c2, reg_flash_fifo_wdata;
extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode, reg_flash_spi_count_high;
extern unsigned char volatile xdata reg_flash_spi_count_mid, reg_flash_spi_count_low, reg_flash_spi_write_opcode;
extern unsigned char volatile xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low, reg_flash_spi_format;
void flash_begin_access(void);
void flash_reset_fifo(void);
void flash_unprotect(unsigned char *save);
void flash_restore_status(unsigned char *save);
void flash_end_access(void);
void flash_send_cmd(unsigned char cmd);
unsigned char flash_send_cmd_read_byte(unsigned char cmd);

/* Program 'len' bytes from XDATA 'src' into the SPI flash at 'addr', in pieces of up to 256 bytes.
 * Callers: flash_write_from_buffer (mailbox command 0x11, the whole flash data buffer) and flash_write_buffer_bytes
 * (command 0x15, part of the buffer).
 *
 * The flash is claimed (flash_begin_access), its FIFO reset, and its write protection lifted (flash_unprotect, which
 * keeps the old status bytes in saved_status). Then per piece:
 *   1. the piece is copied into the controller's FIFO;
 *   2. Write Enable, and a wait until the status shows the write-enable bit;
 *   3. the address (bits 23..0 of page_addr) and the byte count minus 1 are set, and the controller sends the Page
 *      Program command with the FIFO data (the same register sequence as flash_start_page_program);
 *   4. page_addr moves on by 256 and the routine waits until the flash is no longer busy.
 * The pieces are taken from the start of the range: piece k goes to addr + 256 * k.
 * At the end the saved status bytes are written back (flash_restore_status) and the flash is released.
 * len 0 still programs one piece: page_bytes is then 0 and the count written is 0xFFFF (bits 15..0).
 */
void flash_program(unsigned char xdata *src, unsigned long addr, unsigned int len)
{
    union { unsigned long l; unsigned char b[4]; } page_addr;
    unsigned int page_bytes;
    unsigned char saved_status[2];
    unsigned int i;

    flash_begin_access();
    flash_reset_fifo();
    flash_unprotect(saved_status);
    page_addr.l = addr;
    do {
        /* 1. Next piece into the FIFO. */
        reg_flash_fifo_port = 0x82;
        if (len >= FLASH_PAGE_BYTES) {
            page_bytes = FLASH_PAGE_BYTES;
            len -= FLASH_PAGE_BYTES;
        } else {
            page_bytes = len;
            len = 0;
        }
        for (i = 0; i < page_bytes; i++) reg_flash_fifo_wdata = *src++;
        reg_flash_fifo_port = 0x82;

        /* 2. Write Enable. */
        flash_send_cmd(FLASH_CMD_WRITE_ENABLE);
        while (!(flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL)) ;

        /* 3. Page Program of the piece. */
        reg_flash_spi_addr_high = page_addr.b[1];
        reg_flash_spi_addr_mid = page_addr.b[2];
        reg_flash_spi_addr_low = page_addr.b[3];
        reg_flash_spi_mode = (reg_flash_spi_mode & SPI_MODE_KEEP_BUS) | SPI_MODE_PROGRAM;
        reg_flash_spi_format = SPI_FORMAT_WITH_ADDRESS;
        reg_flash_spi_read_opcode = FLASH_CMD_PAGE_PROGRAM;
        page_bytes--;
        reg_flash_spi_count_high = 0;
        reg_flash_spi_count_mid = (unsigned int)(unsigned long)page_bytes >> 8; reg_flash_spi_count_low = page_bytes & 0xff;
        reg_flash_fifo_port = 2;
        reg_flash_fifo_port;
        reg_flash_spi_write_opcode = reg_flash_fifo_port;
        DAT_EXTMEM_f1c2 = DAT_EXTMEM_f1c2;
        DAT_EXTMEM_f1c1 = 1;
        reg_flash_fifo_port = 4;
        reg_flash_spi_start = SPI_START_TRANSFER;
        for (;;) if (!(unsigned int)(reg_flash_spi_start & SPI_START_TRANSFER)) break;
        reg_flash_fifo_port = 0;

        /* 4. Next page; wait for the flash to finish this one. */
        page_addr.l += FLASH_PAGE_BYTES;
        while (flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY) ;
    } while (len != 0);
    flash_restore_status(saved_status);
    flash_end_access();
}

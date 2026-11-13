/* DoBlockErase  (FUN_CODE_8b58)
 *
 * Erase one flash unit (4 KB, 32 KB or 64 KB) with a given erase command.
 *   sector: unit number: byte address = sector << 12 for command 0x20, << 15 for 0x52, << 16 for any other
 *   cmd: erase command byte
 * Name basis: proven - prints 'DoBlockErase start %04x' (original name)
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * Inputs: sector (R6:R7), cmd (R5). LARGE block: sector 0xA4B3, cmd 0xA4B5, byte_addr 0xA4B6..0xA4B9,
 *   saved_status[12] 0xA4BA.. (12 bytes: the gap up to 0xA4C6, where the callees' blocks start).
 * Source form: the if / else if / else chain (not a switch) gives cmd in R3 with CJNE + SJMP per arm.
 */

/* Flash commands and status bits (names as in the other flash routines of both 8051 programs). */
#define FLASH_CMD_READ_STATUS    0x05
#define FLASH_CMD_WRITE_ENABLE   0x06
#define FLASH_CMD_ERASE_4K       0x20  /* sector numbers count 4 KB (flash_erase_sector_at_addr) */
#define FLASH_CMD_ERASE_32K      0x52  /* sector numbers count 32 KB */
#define FLASH_STATUS_BUSY        0x01
#define FLASH_STATUS_WEL         0x02

#define SHIFT_4K                 12
#define SHIFT_32K                15
#define SHIFT_64K                16    /* any other erase command */
#define SPI_MODE_KEEP_BUS        0x0c  /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_TRANSFER        0x41
#define SPI_FORMAT_WITH_ADDRESS  3
#define ADDRESS_BYTES            3     /* the command is followed by address bits 23..0 */
#define SPI_START_TRANSFER       0x01  /* reg_flash_spi_start bit 0: set to start, clears when done */

extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low, reg_flash_spi_write_opcode;
extern unsigned char volatile xdata reg_flash_spi_format, reg_flash_fifo_port, reg_flash_fifo_wdata;
extern void flash_begin_access(void);
extern void flash_end_access(void);
extern void flash_send_cmd(unsigned char cmd);
extern unsigned char flash_send_cmd_read_byte(unsigned char cmd);
extern void lib_printf517(void *fmt, ...) large;
extern void flash_unprotect(unsigned char *save);
extern void flash_restore_status(unsigned char *save);

/* Erase one sector or block of the SPI flash with the erase command 'cmd'.
 *   sector: number of the sector or block, in units of the erase size of 'cmd' (4 KB for 0x20, 32 KB for 0x52,
 *           64 KB for any other command);
 *   cmd:    the flash's erase command, sent as given.
 * Callers: flash_erase_sector_at_addr (mailbox command 0x13, cmd 0x20) and flash_erase_sectors (several units in a
 * row).
 * Prints "DoBlockErase start %04x" with sector, claims the flash, lifts its write protection (flash_unprotect),
 * sends Write Enable and waits for the write-enable bit, then sends the erase command with the 3-byte address
 * (bits 23..0 of the byte address) through the FIFO. It waits until the flash is no longer busy, prints
 * "sector erase\t%04lX!!" with the byte address, writes the saved status bytes back and releases the flash.
 */
void DoBlockErase(unsigned int sector, unsigned char cmd)
{
    unsigned long byte_addr;
    unsigned char saved_status[12];

    lib_printf517((void code *)0xa33b, sector);    /* "DoBlockErase start %04x\r\n" */
    flash_begin_access();
    flash_unprotect(saved_status);
    flash_send_cmd(FLASH_CMD_WRITE_ENABLE);
    while (!(flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL)) ;

    /* Byte address of the unit. */
    if (cmd == FLASH_CMD_ERASE_4K) byte_addr = (unsigned long)sector << SHIFT_4K;
    else if (cmd == FLASH_CMD_ERASE_32K) byte_addr = (unsigned long)sector << SHIFT_32K;
    else byte_addr = (unsigned long)sector << SHIFT_64K;

    /* Command transfer: erase command, then three address bytes from the FIFO. */
    reg_flash_fifo_port = 0x80;
    reg_flash_spi_mode = reg_flash_spi_mode & SPI_MODE_KEEP_BUS | SPI_MODE_TRANSFER;
    reg_flash_spi_format = SPI_FORMAT_WITH_ADDRESS;
    reg_flash_spi_count_high = 0;
    reg_flash_spi_count_mid = 0;
    reg_flash_spi_count_low = ADDRESS_BYTES;
    reg_flash_spi_write_opcode = cmd;
    reg_flash_fifo_port = 0x82;
    reg_flash_fifo_wdata = ((unsigned char *)&byte_addr)[1];
    reg_flash_fifo_wdata = ((unsigned char *)&byte_addr)[2];
    reg_flash_fifo_wdata = ((unsigned char *)&byte_addr)[3];
    reg_flash_fifo_port = 0x84;
    reg_flash_spi_start = SPI_START_TRANSFER;
    while ((unsigned int)(reg_flash_spi_start & SPI_START_TRANSFER)) ;

    /* Wait for the erase to finish. */
    while (flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY) ;
    lib_printf517((void code *)0xa355, byte_addr);    /* "sector erase\t%04lX!!\r\n" */
    flash_restore_status(saved_status);
    flash_end_access();
}

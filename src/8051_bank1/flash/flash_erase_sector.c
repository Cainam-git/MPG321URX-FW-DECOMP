/* flash_erase_sector  (FUN_CODE_9b11)
 *
 * Erase 4 KB sectors of the SPI flash.
 *   sector: 4 KB sector number
 *   cmd: erase command sent to the flash (0x20, 0x52 or 0xD8)
 * Name basis: proven - erase opcodes 0x20 / 0x52 / 0xD8, address = sector << 12; prints 'sector erase'; update
 *   loop command 1
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9b11 @ 0x9b11..0x9bde (205 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE block: sector 0xA4BA, cmd 0xA4BC, byte_addr 0xA4BD..0xA4C0.
 * Source form: the opcode chain lists 0x20, 0x52 and 0xD8 (as flash_erase_sector_at_addr) and every arm shifts
 *   by 12. Keil merges the 0xD8 arm with the final else and drops its compare; the firmware keeps the load of cmd
 *   for that compare (0x9B3D: MOV DPTR,#0xA4BC; MOVX A,@DPTR).
 */
extern unsigned char volatile xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low, reg_flash_spi_write_opcode;
extern unsigned char volatile xdata reg_flash_spi_format, reg_flash_fifo_port, reg_flash_fifo_wdata;
extern void flash_begin_access(void);
extern void flash_end_access(void);
extern void flash_send_cmd(unsigned char cmd);
extern unsigned char flash_send_cmd_read_byte(unsigned char cmd);
extern void lib_printf517(void *fmt, ...) large;

#define FLASH_CMD_READ_STATUS    0x05
#define FLASH_CMD_WRITE_ENABLE   0x06
#define FLASH_CMD_ERASE_4K       0x20
#define FLASH_CMD_ERASE_32K      0x52
#define FLASH_CMD_ERASE_D8       0xd8
#define FLASH_STATUS_BUSY        0x01
#define FLASH_STATUS_WEL         0x02
#define SECTOR_SHIFT             12    /* sector numbers count 4 KB, whatever the erase command */
#define SPI_MODE_KEEP_BUS        0x0c  /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_TRANSFER        0x41
#define SPI_FORMAT_WITH_ADDRESS  3
#define ADDRESS_BYTES            3     /* the command is followed by address bits 23..0 */
#define SPI_START_TRANSFER       0x01  /* reg_flash_spi_start bit 0: set to start, clears when done */

/*
 * flash_erase_sector - send one erase command to the SPI flash for the block at sector * 4 KB.
 *   sector  4 KB sector number
 *   cmd     the erase command sent (FLASH_CMD_ERASE_4K, _32K or 0xD8)
 * Sets the write-enable latch and waits for it, sends the command with address bits 23..0, waits until the
 * flash is no longer busy and prints "sector erase\t%04lX!!" with the address. Unlike
 * flash_erase_sector_at_addr, the address is sector << 12 for every command.
 * Only caller: fwupd_run_flash_loop (update mailbox command FWUPD_CMD_ERASE, cmd = MBOX_ARG0).
 */
void flash_erase_sector(unsigned int sector, unsigned char cmd)
{
    unsigned long byte_addr;

    flash_begin_access();
    flash_send_cmd(FLASH_CMD_WRITE_ENABLE);
    while (!(flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL)) ;
    if (cmd == FLASH_CMD_ERASE_4K) byte_addr = (unsigned long)sector << SECTOR_SHIFT;
    else if (cmd == FLASH_CMD_ERASE_32K) byte_addr = (unsigned long)sector << SECTOR_SHIFT;
    else if (cmd == FLASH_CMD_ERASE_D8) byte_addr = (unsigned long)sector << SECTOR_SHIFT;
    else byte_addr = (unsigned long)sector << SECTOR_SHIFT;
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
    while (flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY) ;
    lib_printf517((void code *)0xc919, byte_addr);   /* "sector erase\t%04lX!!\r\n" */
    flash_end_access();
}

/* flash_chip_erase  (FUN_CODE_dca7)
 *
 * Erase the whole SPI flash and wait until bit 1 (write enable) of its status byte is clear.
 * Note: Not called anywhere.
 * Name basis: proven - opcodes 06h Write Enable, C7h Chip Erase, 05h status poll; no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dca7 @ 0xdca7..0xdcbb (20 B)
 */
#define FLASH_CMD_READ_STATUS   0x05
#define FLASH_CMD_WRITE_ENABLE  0x06
#define FLASH_CMD_CHIP_ERASE    0xc7
#define FLASH_STATUS_WEL        0x02   /* bit 1 of the status byte */

extern void flash_send_cmd(unsigned char cmd);
extern unsigned char flash_send_cmd_read_byte(unsigned char cmd);

/* Send write enable and chip erase, then read the status byte repeatedly
 * until its bit 1 is clear. Nothing in the bank calls it. */
void flash_chip_erase(void)
{
    flash_send_cmd(FLASH_CMD_WRITE_ENABLE);
    flash_send_cmd(FLASH_CMD_CHIP_ERASE);
    while (flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL) ;
}

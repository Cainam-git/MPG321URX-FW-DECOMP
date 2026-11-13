/* flash_write_extended_addr  (FUN_CODE_d81c)
 *
 * Write the SPI flash extended address register (address bits 24 and up)
 *   ext: high address byte
 * Name basis: proven - opcodes 06h Write Enable, 05h status poll, C5h Write Extended Address Register
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d81c @ 0xd81c  Options: OPTIMIZE(8,SPEED) REGFILE(R.ORC) (bank 1 is built with the
 * Keil register-file option).
 * Source form: the (char) cast is what the original has. The value is kept in R6 across the status polls and is
 * passed by way of R7 (MOV R7,R6; MOV R5,R7). Without the conversion Keil keeps it in R5 directly; only a cast
 * through another type reproduces the detour.
 */
#define FLASH_CMD_READ_STATUS    0x05
#define FLASH_CMD_WRITE_ENABLE   0x06
#define FLASH_CMD_WRITE_EXT_ADDR 0xc5  /* write extended address register */
#define FLASH_STATUS_BUSY        0x01
#define FLASH_STATUS_WEL         0x02

extern void flash_send_cmd(unsigned char cmd);
extern unsigned char flash_send_cmd_read_byte(unsigned char cmd);
extern void flash_write_command_byte(unsigned char cmd, unsigned char val);

/*
 * Write the SPI flash extended address register with 'ext': write enable, wait until the status shows the
 * write-enable latch, send the C5h command with the value, then wait until the busy bit of the status clears.
 */
void flash_write_extended_addr(unsigned char ext)
{
    flash_send_cmd(FLASH_CMD_WRITE_ENABLE);
    while (!(flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL)) ;
    flash_write_command_byte(FLASH_CMD_WRITE_EXT_ADDR, (char)ext);
    while (flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY) ;
}

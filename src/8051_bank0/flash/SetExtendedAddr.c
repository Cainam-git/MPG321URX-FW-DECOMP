/* SetExtendedAddr  (FUN_CODE_180d)
 *
 * Set the flash chip's extended address register, which selects the upper or lower 16 MiB.
 * Name basis: proven - prints 'SetExtendedAddr' (original name); write enable, then command 0xC5
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form: the message is passed as its CODE address and lib_printf is the last call (a tail jump in the
 * firmware).
 */

#define FLASH_CMD_READ_STATUS   0x05
#define FLASH_CMD_WRITE_ENABLE  0x06
#define FLASH_CMD_WRITE_EXT_ADDR 0xc5   /* followed by the new extended address byte */
#define FLASH_STATUS_BUSY       0x01    /* waited for to clear after the write */
#define FLASH_STATUS_WEL        0x02    /* set after FLASH_CMD_WRITE_ENABLE; waited for before the write */

extern void lib_printf(void *fmt, ...);
void flash_send_command(unsigned char cmd);
unsigned char flash_read_command_byte(unsigned char cmd);
void flash_write_command_byte(unsigned char cmd, unsigned char value);

/* SetExtendedAddr
 *
 * Writes ext_addr to the flash chip's extended address register: write enable, wait for the WEL status bit,
 * command 0xC5 with the byte, wait until the busy bit clears, then print "SetExtendedAddr=%02bX".
 *   ext_addr: the new register value
 * Called by startup_load_partition_table with byte 0 of partition record 0 when that byte is not 0, and by
 * flash_identify with 0 (size code 5, register found not 0; the boot then stops).
 */
void SetExtendedAddr(unsigned char ext_addr)
{
    flash_send_command(FLASH_CMD_WRITE_ENABLE);
    while (!(flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL));
    flash_write_command_byte(FLASH_CMD_WRITE_EXT_ADDR, ext_addr);
    while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY);
    lib_printf((void code *)0x15a3, ext_addr);  /* "SetExtendedAddr=%02bX\r\n" */
}

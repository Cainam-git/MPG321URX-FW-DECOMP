/* flash_restore_status  (FUN_CODE_b456)
 *
 * Write the saved status registers back to the SPI flash.
 *   status: saved status bytes
 * Name basis: proven - Write Status Register with the bytes saved by flash_unprotect
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b456, OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC), Keil C51 9.57.
 * Source form: the flash family is derived from the chip id by a '?:' with two identical outcomes. Keil merges them
 * late and keeps a temporary register copy that nothing reads; this is the only form that gives the firmware's
 * bytes. The compared constant does not appear in the firmware (any value gives the same bytes; -1 is used). The
 * '?:' behaves exactly like 'family = chip_code & 0xf0'. The family test '(char)family == 0x50' is a register compare.
 */
extern unsigned char xdata startup_share_flash_chip_index;
extern void flash_send_cmd(unsigned char cmd);
extern unsigned char flash_send_cmd_read_byte(unsigned char cmd);
extern void flash_spi_transfer(unsigned int n, unsigned char *buf, unsigned int a, unsigned char *b);

/*
 * flash_restore_status - write two saved status bytes back to the SPI flash with a Write Status Register command.
 *   status: the two saved bytes (status[0], status[1])
 * Steps: Write Enable, wait for the write-enable bit (Read Status bit 1), build {0x01, status[0], status[1]}, wait
 * for the write-enable bit again, send the command (2 bytes long when the flash family, the high nibble of the
 * code at XDATA 0x3066, is 0x50, else 3 bytes), then wait until the busy bit (bit 0) and the write-enable bit
 * (bit 1) are clear. Counterpart of flash_unprotect's save.
 * Callers: DoBlockErase and fwupd_run_flash_loop, each followed by flash_end_access.
 */
void flash_restore_status(unsigned char *status)
{
    unsigned char chip_code;
    unsigned char buf[8];
    unsigned char family;

    chip_code = startup_share_flash_chip_index;
    flash_send_cmd(6);
    while (!(flash_send_cmd_read_byte(5) & 2)) ;
    buf[0] = 1;
    buf[1] = status[0];
    buf[2] = status[1];
    while (!(flash_send_cmd_read_byte(5) & 2)) ;
    family = ((char)chip_code == -1) ? (chip_code & 0xf0) : (chip_code & 0xf0);
    if ((char)family == 0x50)
        flash_spi_transfer(2, buf, 0, buf + 3);
    else
        flash_spi_transfer(3, buf, 0, buf + 3);
    while (flash_send_cmd_read_byte(5) & 1) ;
    while (flash_send_cmd_read_byte(5) & 2) ;
}

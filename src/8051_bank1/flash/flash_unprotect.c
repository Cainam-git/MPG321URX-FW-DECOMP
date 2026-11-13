/* flash_unprotect  (FUN_CODE_7765)
 *
 * Save the flash status registers and clear their write-protect bits.
 *   save: where the status bytes are kept
 * Name basis: proven - Read/Write Status Register sequence; prints 'error flash!!!'; restored later by
 *   flash_restore_status
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * Input: save (R1..R3, generic pointer). LARGE block: save 0xA4C6..0xA4C8, wrsr_bytes[4] 0xA4C9..0xA4CC, chip_index
 *   0xA4CD. The group test is repeated in full for every arm (no shared group variable), as in the firmware.
 */

/* Flash commands and status bits (names as in the other flash routines of both 8051 programs). */
#define FLASH_CMD_WRITE_STATUS   0x01  /* opcode followed by one or two status bytes */
#define FLASH_CMD_READ_STATUS    0x05
#define FLASH_CMD_WRITE_ENABLE   0x06
#define FLASH_CMD_READ_STATUS2   0x35
#define FLASH_CMD_READ_0X15      0x15  /* group 0x30 only; its answer is kept as the second status byte */
#define FLASH_STATUS_BUSY        0x01
#define FLASH_STATUS_WEL         0x02

/* Chip groups: high nibble of the boot loader's chip index (share block kind 5, first byte). Names and kept bits
 * as in the boot loader's flash_setup_bus_mode. */
#define CHIP_GROUP_MASK          0xf0
#define CHIP_GROUP_MAKER_C2      0x30
#define CHIP_GROUP_MAKER_EF      0x40
#define CHIP_GROUP_MAKER_1C      0x50
#define CHIP_GROUP_MAKER_C8      0x80
#define STATUS1_QUAD_ENABLE      0x40
#define STATUS2_QUAD_ENABLE      0x02

extern unsigned char xdata startup_share_flash_chip_index;
extern void flash_send_cmd(unsigned char cmd);
extern unsigned char flash_send_cmd_read_byte(unsigned char cmd);
extern void flash_spi_transfer(unsigned int wn, unsigned char *wbuf, unsigned int rn, unsigned char *rbuf);
extern void lib_printf517(void *fmt, ...) large;

/* Lift the write protection of the SPI flash before a write or erase, keeping the old status bytes.
 *   save: two bytes; save[0] = status byte 1, save[1] = the second status byte (not read for group 0x50).
 *         flash_restore_status writes them back after the job.
 * Callers: flash_program, DoBlockErase and command 6 of fwupd_run_flash_loop.
 *
 * The chip group (high nibble of the chip index at XDATA 0x3066) decides which second status byte is read and
 * which bits survive the rewrite:
 *   group 0x30: second byte by command 0x15; written back: status 1 with only bit 6 kept, 0;
 *   group 0x40 and 0x80: second byte by command 0x35; written back: 0, status 2 with only bit 1 kept;
 *   group 0x50: no second byte read; only the command and a 0 are sent (two bytes);
 *   any other group: prints "error flash!!!" and stops here for good.
 * The kept bits are the quad-enable bits of the boot loader's flash_setup_bus_mode; every other bit of the
 * status bytes is written as 0.
 * Sequence: Write Enable, wait for the write-enable bit, wait for it once more, Write Status (three bytes, two for
 * group 0x50), wait until the flash is no longer busy, then until the write-enable bit is clear.
 */
void flash_unprotect(unsigned char *save)
{
    unsigned char wrsr_bytes[4];
    unsigned char chip_index;

    chip_index = startup_share_flash_chip_index;
    save[0] = flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS);
    if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_C2) save[1] = flash_send_cmd_read_byte(FLASH_CMD_READ_0X15);
    else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_EF) save[1] = flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS2);
    else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_1C) ;
    else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_C8) save[1] = flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS2);
    else {
        lib_printf517((void code *)0xa31b);    /* "error flash!!!\r\n" */
        for (;;) ;
    }
    flash_send_cmd(FLASH_CMD_WRITE_ENABLE);
    while (!(flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL)) ;

    /* Build the Write Status command: only the quad-enable bit of each group survives. */
    wrsr_bytes[0] = FLASH_CMD_WRITE_STATUS;
    if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_C2) {
        wrsr_bytes[1] = save[0] & STATUS1_QUAD_ENABLE;
        wrsr_bytes[2] = 0;
    } else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_EF) {
        wrsr_bytes[1] = 0;
        wrsr_bytes[2] = save[1] & STATUS2_QUAD_ENABLE;
    } else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_1C) {
        wrsr_bytes[1] = 0;
        wrsr_bytes[2] = save[1];
    } else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_C8) {
        wrsr_bytes[1] = 0;
        wrsr_bytes[2] = save[1] & STATUS2_QUAD_ENABLE;
    } else {
        wrsr_bytes[1] = 0;
        wrsr_bytes[2] = 0;
    }
    while (!(flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL)) ;
    if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_1C)
        flash_spi_transfer(2, wrsr_bytes, 0, wrsr_bytes + 3);
    else
        flash_spi_transfer(3, wrsr_bytes, 0, wrsr_bytes + 3);
    while (flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY) ;
    while (flash_send_cmd_read_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL) ;
}

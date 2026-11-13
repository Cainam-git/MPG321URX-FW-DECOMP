/* fwupd_svc_set_write_protect  (FUN_CODE_ceee)
 *
 * Set or clear the flash chip's write-protect bits through the main chip.
 *   on: 1 protect, 0 unprotect
 * Name basis: derived - service packets 09 53 (Write Enable / EWSR, then Write Status Register with block-
 *   protect bits) to slave 0x6E
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. The same code is also in src/8051_bank2/fwupd/fwupd_svc_write_protect_off.c, behind
 * fwupd_svc_write_protect_off (keep the two the same).
 */
extern unsigned char xdata fwupd_svc_packet[];
/* fwupd_flash_chip_row (0x0640) is byte 0 of the chip's row of flash_chip_table, DAT_EXTMEM_0641 byte 1,
 * fwupd_flash_size_code (0x0644) byte 4. */
extern unsigned char xdata fwupd_flash_chip_row, DAT_EXTMEM_0641, fwupd_flash_size_code;
unsigned char fwupd_svc_read_flash_status(void);
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);

#define SVC_ADDRESS             0x6e
#define SVC_PACKET_BYTES        10
#define SVC_COUNT_BYTE          0x09    /* first packet byte: the count of bytes after it */
#define SVC_CMD_FLASH           0x53    /* the byte after it is a flash command */
#define FLASH_CMD_WRITE_ENABLE  0x06
#define FLASH_CMD_50            0x50    /* sent instead of WRITE_ENABLE when byte 1 of the chip row is set */
#define FLASH_CMD_WRITE_STATUS  0x01
#define PACKET_LAST_FIRST       1       /* packet byte 9 of the first packet */
#define PACKET_LAST_SECOND      2       /* packet byte 9 of the second packet */
#define CHIP_ROW_KIND_3         3       /* byte 0 of the chip row */
#define SIZE_CODE_80            0x80
#define KEEP_BITS_KIND_3        0x63    /* status bits kept for chip row kind 3 (size code not 0x80) */
#define SET_BITS_KIND_3         0x9c    /* status bits set when protecting, same chips */
#define KEEP_BITS_OTHER         0x43
#define SET_BITS_OTHER          0xb4
#define PROTECT_ON              1
#define SVC_WAIT                0x0fa0  /* fwupd_wait_ready_line limit after each packet */

/* fwupd_svc_set_write_protect: write a new status byte to the flash chip through the service link.
 *
 * on: PROTECT_ON (1) sets the bits SET_BITS_*; any other value leaves them clear.
 *
 * The flash status comes first (fwupd_svc_read_flash_status). Then two packets of SVC_PACKET_BYTES go to
 * SVC_ADDRESS, each followed by a wait for the ready line:
 *   1. 09 53 <FLASH_CMD_WRITE_ENABLE or FLASH_CMD_50> 00 .. 00 01
 *   2. 09 53 01 <new status> 00 .. 00 02
 * The new status keeps the bits KEEP_BITS_* of the old one. The *_KIND_3 pair is used when byte 0 of
 * fwupd_flash_chip_row is 3 and fwupd_flash_size_code is not 0x80, the *_OTHER pair otherwise.
 * Callers: fwupd_svc_write_protect_off, fwupd_run_isp_write, fwupd_step_port_state. */
void fwupd_svc_set_write_protect(unsigned char on)
{
    unsigned char status;
    unsigned char i;
    status = fwupd_svc_read_flash_status();
    for (i = 0; i < SVC_PACKET_BYTES; i++) fwupd_svc_packet[i] = 0;
    fwupd_svc_packet[0] = SVC_COUNT_BYTE;
    fwupd_svc_packet[1] = SVC_CMD_FLASH;
    if (DAT_EXTMEM_0641) fwupd_svc_packet[2] = FLASH_CMD_50; else fwupd_svc_packet[2] = FLASH_CMD_WRITE_ENABLE;
    fwupd_svc_packet[9] = PACKET_LAST_FIRST;
    i2c_write_packet(SVC_ADDRESS, SVC_PACKET_BYTES, fwupd_svc_packet);
    fwupd_wait_ready_line(SVC_WAIT);
    fwupd_svc_packet[2] = FLASH_CMD_WRITE_STATUS;
    if (on == PROTECT_ON) {
        if (fwupd_flash_chip_row == CHIP_ROW_KIND_3 && fwupd_flash_size_code != SIZE_CODE_80) fwupd_svc_packet[3] = (status & KEEP_BITS_KIND_3) | SET_BITS_KIND_3;
        else fwupd_svc_packet[3] = (status & KEEP_BITS_OTHER) | SET_BITS_OTHER;
    } else {
        if (fwupd_flash_chip_row == CHIP_ROW_KIND_3 && fwupd_flash_size_code != SIZE_CODE_80) fwupd_svc_packet[3] = status & KEEP_BITS_KIND_3;
        else fwupd_svc_packet[3] = status & KEEP_BITS_OTHER;
    }
    fwupd_svc_packet[9] = PACKET_LAST_SECOND;
    i2c_write_packet(SVC_ADDRESS, SVC_PACKET_BYTES, fwupd_svc_packet);
    fwupd_wait_ready_line(SVC_WAIT);
}

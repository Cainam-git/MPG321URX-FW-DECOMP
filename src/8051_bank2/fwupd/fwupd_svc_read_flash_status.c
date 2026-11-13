/* fwupd_svc_read_flash_status  (FUN_CODE_de9a)
 *
 * Ask the main chip for the status of the flash chip.
 * Returns: status
 * Name basis: derived - service packet 09 53 05 .. 11 to I2C address 0x6E, wait, read the answer, then a
 *   register read
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) (OPTIMIZE(8,SPEED) LARGE gives the same bytes). The clear loop is the same
 * 'for (i = 0; i < 10; i++) buf[i] = 0;' as in fwupd_svc_set_write_protect; at level 8 it gives MOV R7,#10 / CLR A
 * hoisted / MOVX / INC DPTR / DJNZ. The final 'return fwupd_svc_read_register(...);' stays 'LCALL e105; RET' (Keil
 * turns a returned call into an LJMP only as a plain statement).
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void timer_delay_units(unsigned char n);
unsigned char fwupd_svc_read_register(unsigned int reg);

#define SVC_ADDRESS            0x6e
#define SVC_PACKET_BYTES       10
#define SVC_COUNT_BYTE         0x09     /* first packet byte: the count of bytes after it */
#define SVC_CMD_FLASH          0x53     /* the byte after it is a flash command */
#define FLASH_CMD_READ_STATUS  0x05
#define SVC_REG_F880           0xf880   /* main chip register read for the answer */

/* fwupd_svc_read_flash_status: send the flash command FLASH_CMD_READ_STATUS through the service link and return
 * main chip register 0xF880.
 *
 * Packet to SVC_ADDRESS: 09 53 05 00 00 00 00 00 00 11 (the meaning of the last byte, 0x11, is not shown). Then a
 * wait for the ready line (limit 100), the reply is read into fwupd_svc_packet (its result is not used), and after
 * timer_delay_units(5) register 0xF880 is read with fwupd_svc_read_register.
 * Caller: fwupd_svc_set_write_protect, which keeps some bits of the result in the new status byte it writes to the
 * flash chip. */
unsigned char fwupd_svc_read_flash_status(void)
{
    unsigned char i;
    for (i = 0; i < SVC_PACKET_BYTES; i++) fwupd_svc_packet[i] = 0;
    fwupd_svc_packet[0] = SVC_COUNT_BYTE;
    fwupd_svc_packet[1] = SVC_CMD_FLASH;
    fwupd_svc_packet[2] = FLASH_CMD_READ_STATUS;
    fwupd_svc_packet[9] = 0x11;
    i2c_write_packet(SVC_ADDRESS, SVC_PACKET_BYTES, fwupd_svc_packet);
    fwupd_wait_ready_line(100);
    i2c_read_packet(SVC_ADDRESS, fwupd_svc_packet);
    timer_delay_units(5);
    return fwupd_svc_read_register(SVC_REG_F880);
}

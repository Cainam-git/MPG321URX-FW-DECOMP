/* fwupd_svc_query_cmd_0x25  (FUN_CODE_e3ab)
 *
 * Send service command 0x25 and read the answer.
 * Name basis: descriptive - service packet 01 25, wait up to 4000 units
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e3ab @ 0xe3ab, OPTIMIZE(8,SPEED).
 * Source form: the result of i2c_write_packet is not kept.
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char n);
void timer_delay_base(void);

#define SVC_ADDRESS         0x6e    /* I2C slave address of every service packet */
#define SVC_CMD_25          0x25    /* 01 25 */
#define SVC_WAIT            0x0fa0  /* fwupd_wait_ready_line limit (4000) */

/* Send the packet 01 25, wait on the ready line and read the reply into fwupd_svc_packet.
 * Only caller: fwupd_svc_spi_transfer, after it has written the SPI registers 0xF0C0..0xF0C6 and the bytes to send
 * into the window at 0xA700, and before it reads the window back. */
void fwupd_svc_query_cmd_0x25(void)
{
    fwupd_svc_packet[0] = 1;
    fwupd_svc_packet[1] = SVC_CMD_25;
    i2c_write_packet(SVC_ADDRESS, 2, fwupd_svc_packet);
    fwupd_wait_ready_line(SVC_WAIT);
    fwupd_svc_read_reply(fwupd_svc_packet);
}

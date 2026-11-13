/* fwupd_svc_send_cmd_0xa3  (FUN_CODE_e24d)
 *
 * Send service command 0xA3 with one byte to the main chip.
 * Name basis: descriptive - service packet 02 A3 <byte> to I2C address 0x6E
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e24d @ 0xe24d, OPTIMIZE(8,SPEED) LARGE.
 * Source form: the result of i2c_write_packet is stored in a local that is never read (the firmware has the
 * store); fwupd_svc_read_reply is reached with a tail jump.
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply_entry(void);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char t);
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);

#define SVC_ADDRESS         0x6e    /* I2C slave address of every service packet */
#define SVC_CMD_A3          0xa3    /* 02 A3 <value> */
#define SVC_WAIT_SHORT      100     /* fwupd_wait_ready_line limit */

/* Send the packet 02 A3 <value>, wait on the ready line and read the reply into fwupd_svc_packet.
 * Only caller: fwupd_run_isp_write (modes 0x10 / 0x11) with 0xF3, right after fwupd_svc_set_isp_mode(1). */
void fwupd_svc_send_cmd_0xa3(unsigned char value)
{
    unsigned char write_status;     /* stored, never read */
    fwupd_svc_packet[0] = 2;
    fwupd_svc_packet[1] = SVC_CMD_A3;
    fwupd_svc_packet[2] = value;
    write_status = i2c_write_packet(SVC_ADDRESS, 3, fwupd_svc_packet);
    fwupd_wait_ready_line(SVC_WAIT_SHORT);
    fwupd_svc_read_reply(fwupd_svc_packet);
}

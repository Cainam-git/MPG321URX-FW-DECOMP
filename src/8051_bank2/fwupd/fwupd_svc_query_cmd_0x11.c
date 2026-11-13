/* fwupd_svc_query_cmd_0x11  (FUN_CODE_e2da)
 *
 * Send service command 0x11 and read the answer.
 * Name basis: descriptive - service packet 01 11, wait 100 units
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e2da @ 0xe2da, OPTIMIZE(8,SPEED) LARGE.
 * Source form: the result of i2c_write_packet is stored in a local that is never read (the firmware has the
 * store).
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char n);
void timer_delay_base(void);

#define SVC_ADDRESS         0x6e    /* I2C slave address of every service packet */
#define SVC_CMD_11          0x11    /* 01 11 */
#define SVC_WAIT_SHORT      100     /* fwupd_wait_ready_line limit */

/* Send the packet 01 11, wait on the ready line and read the reply into fwupd_svc_packet.
 * Only caller: flash_identify_chip, in each id try after it has written register 0xF068 and before it reads the
 * three id bytes from registers 0xF064..0xF066. */
void fwupd_svc_query_cmd_0x11(void)
{
    unsigned char write_status;     /* stored, never read */
    fwupd_svc_packet[0] = 1;
    fwupd_svc_packet[1] = SVC_CMD_11;
    write_status = i2c_write_packet(SVC_ADDRESS, 2, fwupd_svc_packet);
    fwupd_wait_ready_line(SVC_WAIT_SHORT);
    fwupd_svc_read_reply(fwupd_svc_packet);
}

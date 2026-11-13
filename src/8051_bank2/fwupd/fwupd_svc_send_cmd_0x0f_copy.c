/* fwupd_svc_send_cmd_0x0f_copy  (FUN_CODE_e27c)
 *
 * Send service command 0x0F with one byte to the main chip and read the answer (second copy).
 * Name basis: descriptive - same packet as fwupd_svc_send_cmd_0x0f
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e27c @ 0xe27c, OPTIMIZE(8,SPEED) LARGE.
 * Same code as fwupd_svc_send_cmd_0xa3 (fwupd_svc_send_cmd_0xa3) with the command byte 0x0F; the same source form (status
 * stored in a local that is never read, tail jump to fwupd_svc_read_reply).
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
#define SVC_CMD_0F          0x0f    /* 02 0F <value> */
#define SVC_WAIT_SHORT      100     /* fwupd_wait_ready_line limit */

/* Send the packet 02 0F <value>, wait on the ready line and read the reply into fwupd_svc_packet.
 * The erase, block write and DUALFW tag code sends the same packet through fwupd_svc_send_cmd_0x0f; this copy has
 * one caller, fwupd_pick_valid_region, which sends 0 before it reads the tag bytes of the two regions. */
void fwupd_svc_send_cmd_0x0f_copy(unsigned char value)
{
    unsigned char write_status;     /* stored, never read */
    fwupd_svc_packet[0] = 2;
    fwupd_svc_packet[1] = SVC_CMD_0F;
    fwupd_svc_packet[2] = value;
    write_status = i2c_write_packet(SVC_ADDRESS, 3, fwupd_svc_packet);
    fwupd_wait_ready_line(SVC_WAIT_SHORT);
    fwupd_svc_read_reply(fwupd_svc_packet);
}

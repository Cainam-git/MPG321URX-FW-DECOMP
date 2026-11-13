/* fwupd_svc_send_cmd_0x99  (FUN_CODE_e331)
 *
 * Send service command 0x99 with one byte to the main chip and read the answer.
 * Name basis: descriptive - service packet 02 99 <byte>, wait up to 4000 units
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e331 @ 0xe331, OPTIMIZE(8,SPEED).
 * Source form: the result of i2c_write_packet is not kept; fwupd_svc_read_reply is reached with a tail jump.
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);

#define SVC_ADDRESS         0x6e    /* I2C slave address of every service packet */
#define SVC_CMD_99          0x99    /* 02 99 <value> */
#define SVC_WAIT            0x0fa0  /* fwupd_wait_ready_line limit (4000) */

/* Send the packet 02 99 <value>, wait on the ready line and read the reply into fwupd_svc_packet.
 * Callers: fwupd_svc_erase_flash (second-half erase: 8 for flash size code 0x10, else 0),
 * fwupd_svc_erase_second_half (size code 0x10 only: 0, or 8 when its argument is not 0) and
 * fwupd_svc_send_0x99_and_record (0). */
void fwupd_svc_send_cmd_0x99(unsigned char value)
{
    fwupd_svc_packet[0] = 2;
    fwupd_svc_packet[1] = SVC_CMD_99;
    fwupd_svc_packet[2] = value;
    i2c_write_packet(SVC_ADDRESS, 3, fwupd_svc_packet);
    fwupd_wait_ready_line(SVC_WAIT);
    fwupd_svc_read_reply(fwupd_svc_packet);
}

/* hdmi_tx_write_avi_payload  (FUN_a0092500)
 *
 * Write AVI InfoFrame payload bytes into an HDMI TX port.
 *   port: HDMI TX port
 *   packet
 * Name basis: derived - regs 0x144.. from buf + 4
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0092500 @ 0xa0092500 (-mcpu=v8 -Os -g)
 * The target does `sll %o2, 0x10, %o2; srl %o2, 0x10, %o2` which is a 16-bit mask on the register number; this
 * matches `(unsigned short)(i + 0x144)`. The loop index `i` is used both for the register number and as
 * pointer index, which matches the `add %i1, %l0, %l0` (pointer + index) and `ldub [%l0 + 4]` pattern.
 */
extern void hdmi_tx_reg_write8(unsigned int, unsigned int, unsigned int, unsigned int);

#define AVI_REG_HEADER 0x140            /* three header bytes at 0x140..0x142 */
#define AVI_REG_CHECKSUM 0x143
#define AVI_REG_PAYLOAD 0x144           /* payload bytes from 0x144 */
#define AVI_PACKET_PAYLOAD_OFFSET 4     /* payload starts at packet[4] */

/*
 * Write an AVI InfoFrame packet into HDMI TX 'port' (bank 0).
 *
 * packet[0..2] go to registers 0x140..0x142; packet[2] is also the number of payload bytes. Payload byte i
 * (packet[4 + i]) goes to register 0x144 + i and is added to an 8-bit sum. The negated sum goes to register
 * 0x143. packet[3] is not used.
 */
void hdmi_tx_write_avi_payload(unsigned int port, unsigned char *packet)
{
    unsigned char i;
    unsigned char sum;

    hdmi_tx_reg_write8(port & 0xff, 0, AVI_REG_HEADER, packet[0]);
    hdmi_tx_reg_write8(port & 0xff, 0, AVI_REG_HEADER + 1, packet[1]);
    hdmi_tx_reg_write8(port & 0xff, 0, AVI_REG_HEADER + 2, packet[2]);

    sum = 0;
    for (i = 0; i < packet[2]; i++) {
        hdmi_tx_reg_write8(port & 0xff, 0, ((unsigned short)(i + AVI_REG_PAYLOAD)), packet[i + AVI_PACKET_PAYLOAD_OFFSET]);
        sum += packet[i + AVI_PACKET_PAYLOAD_OFFSET];
    }

    hdmi_tx_reg_write8(port & 0xff, 0, AVI_REG_CHECKSUM, (unsigned char)(-sum));
}

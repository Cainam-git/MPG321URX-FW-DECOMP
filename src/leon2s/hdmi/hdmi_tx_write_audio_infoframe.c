/* hdmi_tx_write_audio_infoframe  (FUN_a0093084)
 *
 * Write an audio InfoFrame header and checksum into an HDMI TX port.
 *   port: HDMI TX port
 *   packet
 * Note: Each payload register 0x184 + i gets the length byte packet[2], not the payload byte packet[4 + i];
 *   only the checksum sums the payload bytes.
 * Name basis: derived - header to 0x180..0x182, the length byte to 0x184.., checksum (minus the payload sum)
 *   to 0x183
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0093084 @ 0xa0093084-0xa0093138 (45 words), flags -mcpu=v8 -Os -g.
 * Same code shape as hdmi_tx_write_extra_infoframe (registers 0x160..).
 * The loop re-reads packet[2] on every pass (the call may change memory). The 4th argument of the loop's write
 * is packet[2] (the firmware passes the %o3 that holds the loop-test load of packet[2], not packet[4 + i]);
 * hdmi_tx_reg_write8 has the prototype (u8, u8, u16, u8).
 */
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

#define AUDIO_REG_HEADER 0x180          /* three header bytes at 0x180..0x182 */
#define AUDIO_REG_CHECKSUM 0x183
#define AUDIO_REG_PAYLOAD 0x184

/*
 * Write a packet into the 0x180 slot of HDMI TX 'port' (bank 0).
 *
 * packet[0..2] go to registers 0x180..0x182; packet[2] is the loop count. For i below packet[2] the value
 * packet[2] (not packet[4 + i]) is written to register 0x184 + i, and packet[4 + i] is added to an 8-bit sum.
 * The negated sum goes to register 0x183.
 */
void hdmi_tx_write_audio_infoframe(unsigned char port, unsigned char *packet)
{
    unsigned char i;
    unsigned char sum;

    hdmi_tx_reg_write8(port, 0, AUDIO_REG_HEADER, packet[0]);
    hdmi_tx_reg_write8(port, 0, AUDIO_REG_HEADER + 1, packet[1]);
    hdmi_tx_reg_write8(port, 0, AUDIO_REG_HEADER + 2, packet[2]);
    sum = 0;
    for (i = 0; i < packet[2]; i++) {
        hdmi_tx_reg_write8(port, 0, i + AUDIO_REG_PAYLOAD, packet[2]);
        sum += packet[i + 4];
    }
    hdmi_tx_reg_write8(port, 0, AUDIO_REG_CHECKSUM, -sum);
}

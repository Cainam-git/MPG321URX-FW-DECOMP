/* hdmi_tx_write_extra_infoframe  (FUN_a009262c)
 *
 * Write a packet header and checksum into the 0x160 InfoFrame slot of an HDMI TX port.
 *   port: HDMI TX port
 *   packet
 * Note: Each payload register 0x164 + i gets the length byte packet[2], not the payload byte packet[4 + i];
 *   only the checksum sums the payload bytes.
 * Name basis: descriptive - header to 0x160..0x162, the length byte to 0x164.., checksum (minus the payload
 *   sum) to 0x163
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009262c @ 0xa009262c-0xa00926e0 (45 words), flags -mcpu=v8 -Os -g.
 * Same code shape as hdmi_tx_write_audio_infoframe (registers 0x180..).
 * The loop re-reads packet[2] on every pass. The 4th argument of the loop's write is packet[2] (the firmware
 * passes the %o3 that holds the loop-test load); hdmi_tx_reg_write8 has the prototype (u8, u8, u16, u8).
 */
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

#define EXTRA_REG_HEADER 0x160          /* three header bytes at 0x160..0x162 */
#define EXTRA_REG_CHECKSUM 0x163
#define EXTRA_REG_PAYLOAD 0x164

/*
 * Write a packet into the 0x160 slot of HDMI TX 'port' (bank 0).
 *
 * packet[0..2] go to registers 0x160..0x162; packet[2] is the loop count. For i below packet[2] the value
 * packet[2] (not packet[4 + i]) is written to register 0x164 + i, and packet[4 + i] is added to an 8-bit sum.
 * The negated sum goes to register 0x163.
 */
void hdmi_tx_write_extra_infoframe(unsigned char port, unsigned char *packet)
{
    unsigned char i;
    unsigned char sum;

    hdmi_tx_reg_write8(port, 0, EXTRA_REG_HEADER, packet[0]);
    hdmi_tx_reg_write8(port, 0, EXTRA_REG_HEADER + 1, packet[1]);
    hdmi_tx_reg_write8(port, 0, EXTRA_REG_HEADER + 2, packet[2]);
    sum = 0;
    for (i = 0; i < packet[2]; i++) {
        hdmi_tx_reg_write8(port, 0, i + EXTRA_REG_PAYLOAD, packet[2]);
        sum += packet[i + 4];
    }
    hdmi_tx_reg_write8(port, 0, EXTRA_REG_CHECKSUM, -sum);
}

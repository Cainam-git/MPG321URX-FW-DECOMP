/* hdmi_tx_write_vtem_payload  (FUN_a0092cec)
 *
 * Write the VTEM packet bytes into page 3 of an HDMI TX port.
 *   port: HDMI TX port
 *   packet
 * Name basis: derived - page-3 twin of hdmi_tx_write_pps_packet
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0092cec @ 0xa0092cec-0xa0092db8 (204 bytes, 51 words), flags -mcpu=v8 -Os -g.
 * One counter variable (%l0) serves all three loops. The firmware sets no %i0 (void) and masks the port with
 * 'and 0xff' (u8).
 */
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

#define HDMI_TX_BANK_VTEM 3             /* bank holding the VTEM packet */

/*
 * Write the first 14 bytes of a VTEM packet into bank 3 of HDMI TX 'port': packet[n] goes to register n + 3
 * for n = 0 .. 0xD, in runs of 3, 7 and 4 bytes. Counterpart of hdmi_tx_write_pps_packet for bank 2.
 */
void hdmi_tx_write_vtem_payload(unsigned char port, unsigned char *packet)
{
    unsigned char i;

    for (i = 0; i < 3; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_VTEM, i + 3, packet[i]);
    for (i = 0; i < 7; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_VTEM, i + 6, packet[i + 3]);
    for (i = 0; i < 4; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_VTEM, i + 0xd, packet[i + 0xa]);
}

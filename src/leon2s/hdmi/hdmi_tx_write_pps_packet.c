/* hdmi_tx_write_pps_packet  (FUN_a0092944)
 *
 * Write a 161-byte compression parameter (PPS) packet into bank 2 of an HDMI TX port.
 *   port: HDMI TX port
 *   packet: 161-byte block
 * Name basis: derived - bank 2 registers from 3 on in packet-sized runs; only caller hdmi_tx_build_pps_packet
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0092944 @ 0xa0092944-0xa0092cec (936 bytes, 234 words), flags -mcpu=v8 -Os -g.
 * One counter variable i serves all loops (the firmware re-uses %i3). No volatile.
 * Source form: the run at register 0x63 (packet + 0x60) is the only one whose firmware address add is
 * 'add i, packet' (the others are 'add packet, i'): it is written in the integer address form
 * (u32)i + (u32)packet + 0x60. &packet[i + 0x60] gives 'add packet, i' there.
 */
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

#define HDMI_TX_BANK_PPS 2              /* bank holding the PPS packet */
#define PPS_FIRST_REG 3                 /* register of packet byte 0; packet byte n goes to register n + 3 */

/*
 * Write a 0xA1-byte compression parameter (PPS) packet into bank 2 of HDMI TX 'port': packet[n] goes to register
 * n + 3, for n = 0 .. 0xA0. The writes are made in 20 runs (12 counted loops and 8 single writes) in the order of
 * the packet.
 */
void hdmi_tx_write_pps_packet(unsigned char port, unsigned char *packet)
{
    unsigned char i;

    for (i = 0; i < 3; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x3, packet[i]);
    for (i = 0; i < 7; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x6, packet[i + 0x3]);
    for (i = 0; i < 21; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0xd, packet[i + 0xa]);
    for (i = 0; i < 3; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x22, packet[i + 0x1f]);
    for (i = 0; i < 28; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x25, packet[i + 0x22]);
    for (i = 0; i < 3; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x41, packet[i + 0x3e]);
    for (i = 0; i < 28; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x44, packet[i + 0x41]);
    for (i = 0; i < 3; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x60, packet[i + 0x5d]);
    for (i = 0; i < 28; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x63, *(unsigned char *)((unsigned int)i + (unsigned int)packet + 0x60));
    for (i = 0; i < 3; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x7f, packet[i + 0x7c]);
    for (i = 0; i < 23; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x82, packet[i + 0x7f]);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 0x99, packet[0x96]);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 0x9a, packet[0x97]);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 0x9b, packet[0x98]);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 0x9c, packet[0x99]);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 0x9d, packet[0x9a]);
    for (i = 0; i < 3; i++)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, i + 0x9e, packet[i + 0x9b]);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 0xa1, packet[0x9e]);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 0xa2, packet[0x9f]);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 0xa3, packet[0xa0]);
}

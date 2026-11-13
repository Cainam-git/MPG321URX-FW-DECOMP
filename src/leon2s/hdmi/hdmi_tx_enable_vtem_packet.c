/* hdmi_tx_enable_vtem_packet  (FUN_a0092890)
 *
 * Switch sending of the VTEM packet of an HDMI TX port.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: derived - EMP page 3 (VTEM, built from the 0x7F/0xC0 header with data set tag 1); page-3 twin of
 *   the page-2 enable
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0092890 @ 0xa0092890-0xa0092944, -mcpu=v8 -Os -g.
 */
struct hdmi_tx_channel_record { unsigned char pad[0x18]; unsigned short half_0x18; unsigned char pad2[2]; };
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_tx_set_vtem_enable_state(unsigned char, unsigned char, unsigned char);

#define HDMI_TX_BANK_VTEM 3             /* bank holding the VTEM packet (see hdmi_tx_write_vtem_payload) */

/*
 * Switch the VTEM packet of HDMI TX 'port' on or off (bank 3). Counterpart of hdmi_tx_enable_pps_packet
 * for bank 2.
 *
 * on = 1: write the two bytes of the channel record's halfword at +0x18 to registers 1 (low byte) and 2
 * (high byte), set bit 0 of register 0xBD, clear bit 0 of register 0xBE, then hdmi_tx_set_vtem_enable_state(port, 1, 0).
 * on = 0: set bit 0 of register 0xBE, then hdmi_tx_set_vtem_enable_state(port, 0, 0).
 */
void hdmi_tx_enable_vtem_packet(unsigned char port, unsigned char on)
{
    if (on) {
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_VTEM, 1, hdmi_tx_output_records[port].half_0x18);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_VTEM, 2, hdmi_tx_output_records[port].half_0x18 >> 8);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_VTEM, 0xbd, 1, 1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_VTEM, 0xbe, 1, 0);
        hdmi_tx_set_vtem_enable_state(port, 1, 0);
    } else {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_VTEM, 0xbe, 1, 1);
        hdmi_tx_set_vtem_enable_state(port, 0, 0);
    }
}

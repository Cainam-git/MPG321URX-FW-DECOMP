/* hdmi_tx_enable_pps_packet  (FUN_a009270c)
 *
 * Switch sending of the compression parameter (PPS) packet of an HDMI TX port on or off.
 *   port: HDMI TX port
 *   on: 1 = on
 * Note: On: registers 1 and 2 of bank 2 get the low and high byte of halfword +0x18 of the channel record (its
 *   meaning is not shown), then bit 0 of 0xBD and bits 0..1 of register 0 are set.
 * Name basis: proven - the caller prints 'PPS Packet Enable' right after the call with on = 1; bank 2 holds
 *   the packet written by hdmi_tx_write_pps_packet
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009270c @ 0xa009270c-0xa00927a0 (37 words), flags -mcpu=v8 -Os -g.
 * Base hdmi_tx_output_records (0x1c-byte records: sll 3, sub, sll 2). The two calls of the 'on' arm and the final one
 * are cross-jumped into one sibcall with %i4 = 1 / clr %i4.
 * Source form: the last argument is a constant in each arm (not 'on != 0'); the record is indexed directly
 * (a local record pointer moves the head schedule).
 */
struct hdmi_tx_channel_record { unsigned char pad[0x18]; unsigned short half_0x18; unsigned char pad2[2]; };
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);

#define HDMI_TX_BANK_PPS 2              /* bank holding the PPS packet (see hdmi_tx_write_pps_packet) */

/*
 * Switch the compression parameter (PPS) packet of HDMI TX channel 'port' on or off (bank 2).
 *
 * on = 1: write the two bytes of the channel record's halfword at +0x18 to registers 1 (low byte) and 2
 * (high byte), set bit 0 of register 0xBD, then set bits 1..0 of register 0.
 * on = 0: clear bits 1..0 of register 0.
 */
void hdmi_tx_enable_pps_packet(unsigned char port, unsigned char on)
{

  if (on) {
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 1, hdmi_tx_output_records[port].half_0x18);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PPS, 2, hdmi_tx_output_records[port].half_0x18 >> 8);
    hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PPS, 0xbd, 1, 1);
    hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PPS, 0, 3, 1);
  } else
  hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PPS, 0, 3, 0);
}

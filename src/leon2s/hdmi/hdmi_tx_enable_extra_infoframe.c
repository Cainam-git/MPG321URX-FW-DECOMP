/* hdmi_tx_enable_extra_infoframe  (FUN_a0092608)
 *
 * Switch sending of the InfoFrame in the 0x160 slot of an HDMI TX port.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - reg 0x13E bits 2..3; filled from DP inputs with a 27-byte payload
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0092608 @ 0xa0092608 (-mcpu=v8 -Os -g)
 */
extern int hdmi_tx_reg_update_bits();

#define PACKET_ENABLE_REG 0x13e         /* packet enable bits, bank 0 */
#define EXTRA_INFOFRAME_ENABLE_MASK 0xc /* bits 3..2: the packet in the 0x160 slot */

/* Set (on = 1) or clear (on = 0) bits 3..2 of register 0x13E of HDMI TX 'port'. */
void hdmi_tx_enable_extra_infoframe(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,0,PACKET_ENABLE_REG,EXTRA_INFOFRAME_ENABLE_MASK,on);
  return;
}

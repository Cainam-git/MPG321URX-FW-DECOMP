/* hdmi_tx_enable_packet_bits67  (FUN_a00925e4)
 *
 * Set or clear the packet enable bits 6..7 of HDMI TX register 0x13E.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - fourth enable pair of reg 0x13E
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00925e4 @ 0xa00925e4 (-mcpu=v8 -Os -g)
 */
extern int hdmi_tx_reg_update_bits();

#define PACKET_ENABLE_REG 0x13e         /* packet enable bits, bank 0 */
#define PACKET_ENABLE_BITS67_MASK 0xc0  /* bits 7..6 */

/* Set (on = 1) or clear (on = 0) bits 7..6 of register 0x13E of HDMI TX 'port'. */
void hdmi_tx_enable_packet_bits67(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,0,PACKET_ENABLE_REG,PACKET_ENABLE_BITS67_MASK,on);
  return;
}

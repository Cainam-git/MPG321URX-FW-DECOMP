/* hdmi_tx_enable_avi_packet  (FUN_a00924dc)
 *
 * Switch sending of the AVI InfoFrame of an HDMI TX port on or off.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: derived - reg 0x13E bits 0..1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00924dc @ 0xa00924dc (-mcpu=v8 -Os -g)
 */
extern int hdmi_tx_reg_update_bits();

#define PACKET_ENABLE_REG 0x13e         /* packet enable bits, bank 0 */
#define AVI_PACKET_ENABLE_MASK 3        /* bits 1..0: the AVI InfoFrame */

/* Set (on = 1) or clear (on = 0) the AVI InfoFrame enable bits, bits 1..0 of register 0x13E, of HDMI TX 'port'. */
void hdmi_tx_enable_avi_packet(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,0,PACKET_ENABLE_REG,AVI_PACKET_ENABLE_MASK,on);
  return;
}

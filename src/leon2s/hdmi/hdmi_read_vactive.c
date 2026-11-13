/* hdmi_read_vactive  (FUN_a0090078)
 *
 * Return the active height of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: lines
 * Name basis: derived - reg 0x50; stored as the VDE field of the link timing record
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090078 @ 0xa0090078 (-mcpu=v8 -Os -g)
 * Source form: the callee is declared without a prototype and returns int.
 */

#define RX_VACTIVE  0x50

extern int hdmi_reg_read16_stable();

/* Reads the active height from register 0x50 (read until two reads agree). hdmi_save_link_timing stores it in
   the record as vactive. */
unsigned short hdmi_read_vactive(unsigned int port)

{
  port = port & 0xff;
  return hdmi_reg_read16_stable(port,RX_VACTIVE);
}

/* hdmi_read_vback_porch  (FUN_a0090160)
 *
 * Return the vertical back porch measured by an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - reg 0x61 (+0xA2); input_read_port_timing adds it to the sync width for the first
 *   active line
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090160 @ 0xa0090160 (-mcpu=v8 -Os -g)
 * Source form: the callee is declared without a prototype and returns int.
 */

#define RX_VBACK_PORCH  0x61

extern int hdmi_reg_read16_stable();

/* Reads register 0x61 (read until two reads agree). hdmi_save_link_timing stores it in the record as
   vback_porch; input_read_port_timing adds the saved value to the vertical sync width. */
unsigned short hdmi_read_vback_porch(unsigned int port)

{
  port = port & 0xff;
  return hdmi_reg_read16_stable(port,RX_VBACK_PORCH);
}

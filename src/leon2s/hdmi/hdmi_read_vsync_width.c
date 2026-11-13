/* hdmi_read_vsync_width  (FUN_a0090180)
 *
 * Return the vertical sync width measured by an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - reg 0x63 (+0xA4); reported as the vertical sync field by input_read_port_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090180 @ 0xa0090180 (-mcpu=v8 -Os -g)
 * Source form: the callee is declared without a prototype and returns int.
 */

#define RX_VSYNC_WIDTH  0x63

extern int hdmi_reg_read16_stable();

/* Reads register 0x63 (read until two reads agree). hdmi_save_link_timing stores it in the record as
   vsync_width, and input_read_port_timing reports it as the vertical sync width. */
unsigned short hdmi_read_vsync_width(unsigned int port)

{
  port = port & 0xff;
  return hdmi_reg_read16_stable(port,RX_VSYNC_WIDTH);
}

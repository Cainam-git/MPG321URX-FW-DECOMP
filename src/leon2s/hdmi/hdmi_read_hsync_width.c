/* hdmi_read_hsync_width  (FUN_a0090140)
 *
 * Return the horizontal sync width measured by an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - reg 0x5B (+0x9C); reported as the horizontal sync field next to the vertical one by
 *   input_read_port_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090140 @ 0xa0090140 (-mcpu=v8 -Os -g)
 * Source form: the callee is declared without a prototype and returns int.
 */

#define RX_HSYNC_WIDTH  0x5b

extern int hdmi_reg_read16_stable();

/* Reads register 0x5B (read until two reads agree). hdmi_save_link_timing stores it in the record as
   hsync_width, and input_read_port_timing reports it as the horizontal sync width. */
unsigned short hdmi_read_hsync_width(unsigned int port)

{
  port = port & 0xff;
  return hdmi_reg_read16_stable(port,RX_HSYNC_WIDTH);
}

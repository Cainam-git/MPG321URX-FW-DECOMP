/* hdmi_read_hfront_porch  (FUN_a0090120)
 *
 * Return the horizontal front porch measured by an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - reg 0x59, saved in the receiver record at +0x9A by hdmi_save_link_timing;
 *   hdmi_get_saved_hback_porch subtracts it from the line length
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090120 @ 0xa0090120 (-mcpu=v8 -Os -g)
 * Source form: the callee is declared without a prototype and returns int.
 */

#define RX_HFRONT_PORCH  0x59

extern int hdmi_reg_read16_stable();

/* Reads register 0x59 (read until two reads agree). hdmi_save_link_timing stores it in the record as
   hfront_porch, and hdmi_get_saved_hback_porch subtracts it from the line length. */
unsigned short hdmi_read_hfront_porch(unsigned int port)

{
  port = port & 0xff;
  return hdmi_reg_read16_stable(port,RX_HFRONT_PORCH);
}

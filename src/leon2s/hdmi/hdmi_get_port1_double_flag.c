/* hdmi_get_port1_double_flag  (FUN_a008fff0)
 *
 * Return the horizontal doubling flag of HDMI receiver 1.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - byte 0xA8078C08 for port 1; doubles hdmi_read_htotal / hdmi_read_hactive
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fff0 @ 0xa008fff0 (-mcpu=v8 -Os -g)
 * Source form: the flag is copied through an int local.
 */

extern unsigned char hdmi_port1_double_flag;

/* Returns the doubling flag when "port" is 1 and 0 for every other port.
   hdmi_read_hactive and hdmi_read_htotal double their result when it is not 0. The only routine that writes the
   flag is hdmi_clear_port1_double_flag, which stores 0. */
unsigned char hdmi_get_port1_double_flag(unsigned char port)

{
  int flag;
  
  flag = 0;
  if (port == '\x01') {
    flag = hdmi_port1_double_flag;
  }
  return flag;
}

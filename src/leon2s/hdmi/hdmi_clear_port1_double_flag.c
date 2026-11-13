/* hdmi_clear_port1_double_flag  (FUN_a0090374)
 *
 * Clear the horizontal doubling flag of HDMI receiver 1.
 * Name basis: descriptive - byte 0xA8078C08 = 0; read by hdmi_get_port1_double_flag
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090374 @ 0xa0090374 (-mcpu=v8 -Os -g)
 */

extern unsigned char hdmi_port1_double_flag;

/* Stores 0 in the flag that hdmi_get_port1_double_flag returns for receiver 1. The link state machine calls it
   in STABLE, before it reads the timing again. It is the only routine that writes the flag. */
void hdmi_clear_port1_double_flag(void)

{
  hdmi_port1_double_flag = 0;
}

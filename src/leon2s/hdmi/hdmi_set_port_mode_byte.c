/* hdmi_set_port_mode_byte  (FUN_a0077e68)
 *
 * Store the per-port mode byte of an HDMI receiver.
 *   phy: port
 *   value
 * Name basis: descriptive - byte array 0xA8078978[port]; pair of hdmi_get_port_mode_byte
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0077e68 @ 0xa0077e68, flags -mcpu=v8 -Os -g.
 */
extern unsigned char hdmi_only_scramble_guess_mode[];   /* one byte per PHY; printed by the firmware as bHDMI_ONLYSCRAMBLE_GUESSMODE */

/* Stores a value in the PHY's byte of hdmi_only_scramble_guess_mode (printed as bHDMI_ONLYSCRAMBLE_GUESSMODE).
 *   phy:   PHY index (low 8 bits used)
 *   value: the new byte */
void hdmi_set_port_mode_byte(unsigned int phy,unsigned char value)

{
  hdmi_only_scramble_guess_mode[(phy & 0xff)] = value;
  return;
}
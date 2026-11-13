/* hdmi_get_port_mode_byte  (FUN_a007517c)
 *
 * Return the per-port mode byte of an HDMI receiver.
 *   phy: port
 * Name basis: descriptive - byte array 0xA8078978[port]; read by the link state machine and the EQ scan steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007517c @ 0xa007517c, flags -mcpu=v8 -Os -g.
 */
extern unsigned char hdmi_only_scramble_guess_mode[];   /* one byte per PHY; printed by the firmware as bHDMI_ONLYSCRAMBLE_GUESSMODE */

/* Returns the PHY's byte of hdmi_only_scramble_guess_mode (printed as bHDMI_ONLYSCRAMBLE_GUESSMODE).
 *   phy: PHY index (low 8 bits used) */
unsigned char hdmi_get_port_mode_byte(unsigned int phy)

{
  return hdmi_only_scramble_guess_mode[(phy & 0xff)];
}
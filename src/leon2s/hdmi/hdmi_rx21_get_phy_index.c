/* hdmi_rx21_get_phy_index  (FUN_a00961e8)
 *
 * Return the PHY number (2 or 3) of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: PHY index
 * Name basis: derived - 3 for receiver 1, else 2; PHYs 2/3 are the HDMI 2.1 PHYs
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00961e8 @ 0xa00961e8-0xa0096204 (7 words), flags -mcpu=v8 -Os -g. Leaf (retl).
 * Returns ((u8 port == 1) + 2) & 7; the firmware computes the compare with xor/cmp/subx, adds 2 and masks with 7 in
 * the retl delay slot.
 * Source form: a u8 local 'phy = 2; phy += (port == 1); return phy & 7;' (every one-expression form lets gcc prove
 * the value is below 8 and drop the 'and 7', or turns it into a 3/2 select).
 */
#define PHY_RX21_0 2                    /* PHY number of HDMI 2.1 receiver 0; receiver 1 is the next one */

/*
 * Return the PHY number of an HDMI 2.1 receiver: 2 for receiver 0, 3 for receiver 1.
 *   port: HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_get_phy_index(unsigned char port)
{
  unsigned char phy = PHY_RX21_0;

  phy += (port == 1);
  return phy & 7;
}

/* hdmi_phy_set_power_flag  (FUN_a0073c24)
 *
 * Record the power state of a PHY in its link table entry.
 *   phy
 *   on: 1 = on
 * Name basis: derived - byte 0 of the 24-byte table 0xA807CC64; TMDS_PowerOn sets 1, TMDS_PowerOff 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073c24 @ 0xa0073c24, flags -mcpu=v8 -Os -g.
 */
#define PHY_RECORD_SIZE 24      /* bytes per entry of hdmi_phy_records */

extern unsigned char hdmi_phy_records[];

/* Stores the power state in byte 0 of the PHY's 24-byte record (TMDS_PowerOn sets 1, TMDS_PowerOff 0).
 *   phy: PHY index (low 8 bits used)
 *   on:  1 = on */
void hdmi_phy_set_power_flag(unsigned int phy,unsigned char on)

{
  hdmi_phy_records[(phy & 0xff) * PHY_RECORD_SIZE] = on;
  return;
}
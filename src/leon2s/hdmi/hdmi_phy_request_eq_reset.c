/* hdmi_phy_request_eq_reset  (FUN_a00734d8)
 *
 * Set the EQ reset request byte (+2) of the PHY record of a port.
 *   phy
 * Note: DRV_HDMI_EQDetect_Timer sees the byte, puts the equaliser state machine back to its first state and
 *   clears it.
 * Name basis: proven - byte +2 of the 24-byte PHY records at 0xA807CC64; DRV_HDMI_EQDetect_Timer prints
 *   'Port%c EQ reset, set state to INIT state' when it is 1; set by TMDS_PowerOn and by a command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00734d8 @ 0xa00734d8, flags -mcpu=v8 -Os -g.
 */
#define PHY_RECORD_SIZE 24      /* bytes per entry of hdmi_phy_records */

extern unsigned char hdmi_phy_records[];

/* Sets byte +2 of the PHY's 24-byte record to 1.
 *   phy: PHY index (low 8 bits used) */
void hdmi_phy_request_eq_reset(unsigned int phy)

{
  hdmi_phy_records[(phy & 0xff) * PHY_RECORD_SIZE + 2] = 1;
  return;
}

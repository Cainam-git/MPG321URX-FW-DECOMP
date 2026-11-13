/* hdmi_eq_clear_scan_records  (FUN_a0073500)
 *
 * Clear the EQ scan records of the four HDMI PHYs.
 * Name basis: derived - memset of 0x30 bytes at 0xA807CCC4 = four 12-byte EQ scan records (state word read by
 *   hdmi_eq_run_scan_fsm); caller DRV_HDMIRx_Phy_Init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073500 @ 0xa0073500, flags -mcpu=v8 -Os -g.
 * Source form: lib_memset is declared without a parameter list and takes the address as a number.
 */
extern int lib_memset();

/* Clears the 0x30 bytes starting at 0xa807ccc4, which is where the array of 12-byte equaliser scan
 * records (hdmi_eq_scan_records) starts. Called by DRV_HDMIRx_Phy_Init. */
void hdmi_eq_clear_scan_records(void)

{
  lib_memset(0xa807ccc4,0,0x30);
  return;
}
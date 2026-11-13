/* hdmi_phy_reset_error_counters  (FUN_a007f8a4)
 *
 * Clear bit 7 and set bit 6 of PHY register 0x1EA0 and pulse bit 18 of register 0x1F08.
 *   port: PHY
 * Note: Register 0x1EA0 is read elsewhere as an error count; that these writes reset the counters is not
 *   shown.
 * Name basis: descriptive - bits 7/6 of error register 0x1EA0 and a pulse of bit 18 of 0x1F08; callers the
 *   port restart routines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007f8a4 @ 0xa007f8a4, flags -mcpu=v8 -Os -g.
 * Source form: the extern is declared without a prototype, as the decompiler wrote it.
 */
extern void hdmi_phy_write_bit();

#define PHY_REG_ERR_COUNT_A 0x1ea0

/*
 * Clear bit 7 and set bit 6 of PHY register 0x1EA0, then set and clear bit 18 of PHY register 0x1F08.
 *   port: PHY index. Called by hdmi_tmds_restart_port and hdmi_rx21_restart_port.
 */
void hdmi_phy_reset_error_counters(unsigned char port)
{
  hdmi_phy_write_bit(0, 7, port, PHY_REG_ERR_COUNT_A);
  hdmi_phy_write_bit(1, 6, port, PHY_REG_ERR_COUNT_A);
  hdmi_phy_write_bit(1, 0x12, port, 0x1f08);
  hdmi_phy_write_bit(0, 0x12, port, 0x1f08);
}

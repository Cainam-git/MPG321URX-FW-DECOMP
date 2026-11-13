/* TMDS_PowerOn  (TMDS_PowerOn)
 *
 * Power on the receiver PHY of an HDMI port.
 *   port: PHY
 * Name basis: proven - original name printed: 'TMDS_PowerOn %d'
 *
 * Matching notes
 * --------------
 * leon2s TMDS_PowerOn @ 0xa0074c78, flags -mcpu=v8 -Os (no -g).
 * Source form: the printf-style call passes the port as it is; the six callee calls have no prototypes.
 */
extern int dbg_printf();
extern void hdmi_phy_request_eq_reset();
extern void hdmi_phy_set_power();
extern void hdmi_phy_set_power_flag();
extern void hdmi_phy_write_bit();
extern void hdmi_phy_update_reg();

#define PHY_BIT_SET 1           /* mode of hdmi_phy_write_bit: set the bit */
#define PHY_POWER_ON 1          /* argument of hdmi_phy_set_power and hdmi_phy_set_power_flag */

/*
 * Power on the receiver of an HDMI port, in this order: print the line "TMDS_PowerOn <port>"; run the PHY
 * power-on sequence (hdmi_phy_set_power); set bit 7 of PHY registers 0x1C04 and 0x2C04; set the low byte of
 * PHY register 0x1000 to 0xF9; record the port as powered (hdmi_phy_set_power_flag); set byte 2 of the PHY
 * link table entry (hdmi_phy_request_eq_reset).
 *   port: PHY
 */
void TMDS_PowerOn(unsigned char port)

{
  
  dbg_printf("TMDS_PowerOn  %d  \r\n",port);
  hdmi_phy_set_power(port,PHY_POWER_ON);
  hdmi_phy_write_bit(PHY_BIT_SET,7,port,0x1c04);
  hdmi_phy_write_bit(PHY_BIT_SET,7,port,0x2c04);
  hdmi_phy_update_reg(port,0x1000,0xffffff00,0xf9);
  hdmi_phy_set_power_flag(port,PHY_POWER_ON);
  hdmi_phy_request_eq_reset(port);
  return;
}

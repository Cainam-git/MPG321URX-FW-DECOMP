/* DRV_HDMI_PHY_Clr_EQ_Err  (DRV_HDMI_PHY_Clr_EQ_Err)
 *
 * Clear the equaliser error state of an HDMI port.
 *   port: PHY
 * Name basis: proven - original name printed: '[EQ]: Port%c DRV_HDMI_PHY_Clr_EQ_Err'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_PHY_Clr_EQ_Err @ 0xa0074e38, flags -mcpu=v8 -Os -g.
 * Source form: the callees are declared without parameter lists; the print format is the data object
 * DAT_a0066a78; the third write sequence value 199 is 0xc7.
 */
#define HDMI_MSG_EQ_FLOW 2      /* debug message bit: '[EQ]' lines (dbg_hdmi_message_flags) */
#define PHY_REG_ERR_COUNT_A 0x1ea0   /* 16-bit error count per channel, low 15 bits */

extern unsigned int DAT_a0066a78;
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf();
extern void hdmi_phy_write_bit();
extern void hdmi_phy_update_reg();

/* Sets bit 29 of PHY register 0x1e94 and bits 5 and 13 of 0x1e98, then writes the low byte of
 * register 0x1ea0 three times (0x87, 0xc7, 0x87), which sets bit 6 of that byte and clears it again.
 *   port: PHY page (the letter in the print is 'A' + port) */
void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int port)

{
  unsigned int phy;
  
  phy = port & 0xff;
  if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0) {
    dbg_printf(&DAT_a0066a78,(char)(port + 'A'),
                 "DRV_HDMI_PHY_Clr_EQ_Err");
  }
  hdmi_phy_write_bit(1,0x1d,phy,0x1e94);
  hdmi_phy_write_bit(1,5,phy,0x1e98);
  hdmi_phy_write_bit(1,0xd,phy,0x1e98);
  hdmi_phy_update_reg(phy,PHY_REG_ERR_COUNT_A,0xffffff00,0x87);
  hdmi_phy_update_reg(phy,PHY_REG_ERR_COUNT_A,0xffffff00,199);
  hdmi_phy_update_reg(phy,PHY_REG_ERR_COUNT_A,0xffffff00,0x87);
  return;
}
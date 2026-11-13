/* _hdmi_PHY_Set_CTLE  (hdmi_PHY_Set_CTLE)
 *
 * Set the fixed CTLE equaliser values of an HDMI port.
 *   port: PHY
 * Name basis: proven - original name printed: '_hdmi_PHY_Set_CTLE'
 *
 * Matching notes
 * --------------
 * leon2s hdmi_PHY_Set_CTLE @ 0xa0075278, flags -mcpu=v8 -Os -g.
 * Source form: the function name is a separate static const char[]; the port is kept in an unsigned int copy
 * for the register calls and as the original byte for the print and the PHY test.
 */
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf();
extern int hdmi_is_hdmi21_phy();
extern void hdmi_phy_update_reg();

#define HDMI_MSG_EQ_FLOW 2      /* dbg_hdmi_message_flags bit 1: the "[EQ]" lines */

static const char function_name[] = "_hdmi_PHY_Set_CTLE";   /* function name kept as a separate .rodata object by the firmware */

/*
 * Set the fixed CTLE equaliser values of an HDMI PHY. Prints "[EQ]: Port<A..>  _hdmi_PHY_Set_CTLE" when the EQ
 * debug messages are on. Then, through hdmi_phy_update_reg:
 *   - only when the PHY belongs to an HDMI 2.1 receiver: register 0x3604 byte 3 = 0x21;
 *   - register 0x1F44 bytes 1, 2 and 3 = 0x11 (three writes, one byte each);
 *   - register 0x1F48 byte 0 = 0x11;
 *   - register 0x1020 byte 3 = 0xA2.
 *   port: PHY
 */
void _hdmi_PHY_Set_CTLE(unsigned char port)

{
  unsigned int is_hdmi21;
  unsigned int phy;
  
  phy = port & 0xff;
  if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0) {
    dbg_printf("[EQ]: Port%c  %s\012",(char)(port + 'A'),
                 function_name);
  }
  is_hdmi21 = hdmi_is_hdmi21_phy(port);
  if ((is_hdmi21 & 0xff) != 0) {
    hdmi_phy_update_reg(phy,0x3604,0xffffff,0x21000000);
  }
  hdmi_phy_update_reg(phy,0x1f44,0xffff00ff,0x1100);
  hdmi_phy_update_reg(phy,0x1f44,0xff00ffff,0x110000);
  hdmi_phy_update_reg(phy,0x1f44,0xffffff,0x11000000);
  hdmi_phy_update_reg(phy,0x1f48,0xffffff00,0x11);
  hdmi_phy_update_reg(phy,0x1020,0xffffff,0xa2000000);
  return;
}

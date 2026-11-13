/* hdcp_tx_hdmi_disable  (FUN_a00cc974)
 *
 * Switch the protection of an HDMI output off.
 * Name basis: descriptive - four switch-off calls
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cc974 @ 0xa00cc974 (-mcpu=v8 -Os -g)
 * Source form: arg3 to arg6 are forwarded to the last call, as the firmware does.
 */
extern void hdcp_tx_hdmi_set_enable();
extern void hdcp_tx_hdmi_set_reg27_bit0();
extern int hdcp_tx_hdmi_set_reg4_bit7();
extern int hdcp_tx_set_encryption_bit();

/*
 * Switch the protection of an HDMI output off: clear bit 0 of register 0x27, switch the protection off
 * (hdcp_tx_hdmi_set_enable), clear bit 7 of register 4 and clear the encryption bit. Called with the output
 * number (0 or 1) by hdcp_tx_disable_output.
 * arg2 to arg6 are not used; arg3 to arg6 are passed on to the last call only because the exact build does so.
 */
void hdcp_tx_hdmi_disable(unsigned char port,unsigned int arg2,unsigned int arg3,unsigned int arg4,
                 unsigned int arg5,unsigned int arg6)
{
  hdcp_tx_hdmi_set_reg27_bit0(port,0);
  hdcp_tx_hdmi_set_enable(port,0);
  hdcp_tx_hdmi_set_reg4_bit7(port,0);
  hdcp_tx_set_encryption_bit(port,0,arg3,arg4,arg5,arg6);
  return;
}

/* hdcp_tx_disable_output  (FUN_a00ccad4)
 *
 * Switch the protection of an output off.
 * Name basis: derived - HDMI outputs 0 and 1, else the DisplayPort output
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ccad4 @ 0xa00ccad4 (-mcpu=v8 -Os -g)
 */
extern int hdcp_tx_hdmi_disable();
extern int hdcp_tx_dp_set_enable();

/*
 * Switch the protection of an output off: the HDMI outputs (0 and 1) through hdcp_tx_hdmi_disable, any other
 * output (the DisplayPort output, 2) through hdcp_tx_dp_set_enable(0).
 */
void hdcp_tx_disable_output(unsigned char output)
{
  if (output < 2) {
    hdcp_tx_hdmi_disable(output);
    return;
  }
  hdcp_tx_dp_set_enable(0);
  return;
}

/* hdmi_tx_dsc_setup  (FUN_a00dd37c)
 *
 * Write the compression timing and rate values of an HDMI transmitter.
 * Name basis: derived - the two routines above; called from hdmi_tx_run_step
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dd37c, flags -mcpu=v8 -Os -g.
 * Source form: the routine keeps the decompiler's six-parameter form; the second call passes all six on.
 */
extern int hdmi_tx_dsc_write_timing();
extern int hdmi_tx_dsc_write_rate();

/*
 * Set up the compression (DSC) values of an HDMI transmitter: write the timing values
 * (hdmi_tx_dsc_write_timing), then the rate value (hdmi_tx_dsc_write_rate). Called by hdmi_tx_run_step.
 *   port: HDMI TX port
 * The other five parameters are only passed on to hdmi_tx_dsc_write_rate.
 */
void hdmi_tx_dsc_setup(unsigned char port,unsigned int param_2,unsigned int param_3,unsigned int param_4,
                 unsigned int param_5,unsigned int param_6)

{
  hdmi_tx_dsc_write_timing(port);
  hdmi_tx_dsc_write_rate(port,param_2,param_3,param_4,param_5,param_6);
  return;
}

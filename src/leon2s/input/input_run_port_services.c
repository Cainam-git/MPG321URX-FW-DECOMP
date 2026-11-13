/* input_run_port_services  (FUN_a00c6730)
 *
 * Run the per-input services once, including the copy-protection service of the outputs.
 * Name basis: derived - four service calls, then input_update_port_records; called from
 *   input_poll_port_services
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c6730 @ 0xa00c6730, flags -mcpu=v8 -Os -g.
 * Source form: Ghidra's six-argument parameter list is kept; the callees are declared without a prototype.
 */

extern int hdcp_rx_hdmi_task();
extern int hdcp_rx_hdmi21_task();
extern int hdcp_rx_dp_task();
extern int input_update_port_records();
extern int hdcp_tx_task();

/*
 * Run the services of the inputs once: the protection tasks of the HDMI 2.0, HDMI 2.1 and DisplayPort receivers
 * and of the outputs, then input_update_port_records, which gets the six arguments of this routine unchanged.
 * Called from input_poll_port_services.
 */
void input_run_port_services(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)
{
  hdcp_rx_hdmi_task();
  hdcp_rx_hdmi21_task();
  hdcp_rx_dp_task();
  hdcp_tx_task();
  input_update_port_records(arg1, arg2, arg3, arg4, arg5, arg6);
}

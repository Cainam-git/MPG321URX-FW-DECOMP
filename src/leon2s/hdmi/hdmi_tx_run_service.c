/* hdmi_tx_run_service  (FUN_a0095ea4)
 *
 * Run the regular HDMI TX tasks: hot-plug, pending requests and set-up steps.
 * Name basis: derived - calls hdmi_tx_service_port, hdmi_tx_apply_pending_request, hdmi_tx_run_setup_steps for
 *   ports 0 and 1
 *
 * Matching notes
 * --------------
 * FUN_a0095ea4 (leon2s 0xa0095ea4-0xa0095ef8, 84 bytes; includes the unreachable ret/restore tail at 0xa0095ef0),
 * flags -mcpu=v8 -Os -g.
 * Source form: the argument 1 of the final call (a tail call) is set in %o0 in the delay slot of the first call.
 */
extern unsigned char hdmi_tx_stop_unless_enabled(void);
extern void hdmi_tx_service_port(unsigned char);
extern void hdmi_tx_apply_pending_request(unsigned char);
extern void hdmi_tx_run_setup_steps(unsigned char);

/*
 * Regular HDMI TX work, once per call. When hdmi_tx_stop_unless_enabled does not stop anything (a port is
 * enabled), for port 0 and then port 1 in each group: hot-plug and stop (hdmi_tx_service_port), then the
 * requests from the main processor (hdmi_tx_apply_pending_request), then the set-up steps
 * (hdmi_tx_run_setup_steps).
 * Called by input_poll_port_services.
 */
void hdmi_tx_run_service(void)
{
    if (hdmi_tx_stop_unless_enabled() == 0) {
        hdmi_tx_service_port(0);
        hdmi_tx_service_port(1);
        hdmi_tx_apply_pending_request(0);
        hdmi_tx_apply_pending_request(1);
        hdmi_tx_run_setup_steps(0);
        hdmi_tx_run_setup_steps(1);
    }
}

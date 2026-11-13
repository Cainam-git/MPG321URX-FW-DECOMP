/* hdmi_rx21_poll_frl_rate_change  (FUN_a009f654)
 *
 * Check both HDMI 2.1 receivers for an FRL rate change.
 * Name basis: derived - hdmi_rx21_flag_frl_rate_change(0) and (1); registered as a callback by
 *   _hdmi21_Initialize on early chips
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009f654, flags -mcpu=v8 -Os -g (section default). The second call also passes the incoming
 * argument registers on, as the firmware does.
 */
extern int hdmi_rx21_flag_frl_rate_change();

/*
 * Run hdmi_rx21_flag_frl_rate_change for receiver 0 and then receiver 1. Called by _hdmi21_Initialize (it
 * takes the address of this routine). The six parameters are not used; they are only handed on to the
 * second call.
 */
void hdmi_rx21_poll_frl_rate_change(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                    unsigned int arg5, unsigned int arg6)
{
    hdmi_rx21_flag_frl_rate_change(0);
    hdmi_rx21_flag_frl_rate_change(1, arg2, arg3, arg4, arg5, arg6);
}

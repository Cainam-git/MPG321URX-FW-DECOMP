/* hdmi_rx21_set_frl_clock_wrapper  (FUN_a009ec20)
 *
 * Set the HDMI 2.1 receiver clock for an FRL rate.
 *   port: receiver 0/1
 *   frl_rate: FRL rate 1..6
 * Name basis: proven - forwards to hdmi_rx21_set_frl_clock
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009ec20, flags -mcpu=v8 -Os -g (section default).
 */
extern int hdmi_rx21_set_frl_clock();

/*
 * Pass `port` and `frl_rate` on to hdmi_rx21_set_frl_clock and return. Called by DRV_HDMI_EQDetect_Timer,
 * DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err and hdmi_eq_check_clock_detect.
 *   port      HDMI 2.1 receiver 0/1
 *   frl_rate  FRL rate 1..6
 */
void hdmi_rx21_set_frl_clock_wrapper(unsigned char port, unsigned char frl_rate)
{
    hdmi_rx21_set_frl_clock(port, frl_rate);
}

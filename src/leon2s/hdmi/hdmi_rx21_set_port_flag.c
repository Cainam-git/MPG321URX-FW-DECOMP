/* hdmi_rx21_set_port_flag  (FUN_a00962ec)
 *
 * Store a flag byte of an HDMI 2.1 receiver.
 *   port: receiver
 *   value
 * Name basis: descriptive - byte table 0xA8079110
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00962ec @ 0xa00962ec (-mcpu=v8 -Os -g)
 * Source form: the receiver number is masked to a byte.
 */
extern unsigned char hdmi_rx21_port_started_flags[];    /* one byte per HDMI 2.1 receiver */

/*
 * Store the flag byte of an HDMI 2.1 receiver. hdmi_rx21_start_port stores 1 and hdmi_rx21_stop_port stores 0;
 * the link-training state machine (hdmi_rx21_run_rx_detect_fsm) and FLT_no_retrain skip a receiver whose flag is 0.
 *   port: HDMI 2.1 receiver 0/1
 *   value: the flag
 */
void hdmi_rx21_set_port_flag(unsigned int port, unsigned char value)

{
  hdmi_rx21_port_started_flags[(port & 0xff)] = value;
  return;
}

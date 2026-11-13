/* hdmi_rx21_set_mode_change_flag  (FUN_a009e9a4)
 *
 * Set the mode-change flag of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: derived - byte +0xa of the 0xA807D650 record, the flag hdmi_rx21_detect_timing_change treats as
 *   a mode change
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009e9a4 @ 0xa009e9a4 (-mcpu=v8 -Os -g)
 * The base is hdmi_rx21_mode_detect_states = 0xa807d650 (not 0xa807d65a): the +0xa offset is written in the index.
 */
#define MODE_DETECT_STATE_BYTES  0x18   /* bytes per receiver in hdmi_rx21_mode_detect_states */
#define MODE_CHANGE_FLAG         0xa    /* byte of the record */

extern unsigned char hdmi_rx21_mode_detect_states[];    /* 24-byte records */

/*
 * Set the mode-change flag (byte +0xA of the mode-detect record) of an HDMI 2.1 receiver to 1. hdmi_rx21_detect_timing_change
 * reads it and prints 'Int Set Mode Change' when it is set.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_service_sync_events.
 */
void hdmi_rx21_set_mode_change_flag(unsigned int port)
{
  hdmi_rx21_mode_detect_states[(port & 0xff) * MODE_DETECT_STATE_BYTES + MODE_CHANGE_FLAG] = 1;
  return;
}

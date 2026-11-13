/* hdmi_rx21_update_connect_state  (FUN_a00a1a80)
 *
 * Copy the connect flag of both HDMI 2.1 receivers and restart mode detection on connected ones.
 * Name basis: derived - record byte +3 = connected -> byte +2; hdmi_rx21_modedet_restart_standby /
 *   _reset_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1a80, flags -mcpu=v8 -Os -g (section default). The base is hdmi_rx21_input_records (not 0xa807d7e1); the
 * `!= 0` arm comes first in the source; the record address is recomputed after the call.
 */
/* Offsets in the 400-byte record of a receiver (hdmi_rx21_input_records). */
#define RX21_MODE_DETECTED  1           /* 1 after DRV_HDMI_ModeDetect_FSM_Complete; cleared here */
#define RX21_RECORD_BYTE_2  2           /* copy of RX21_CONNECTED, made here */
#define RX21_CONNECTED      3           /* set to 1 by hdmi_rx21_set_connected, cleared by DRV_HDMI_IF_Disconnect */

extern unsigned char hdmi_rx21_input_records[];
extern void hdmi_rx21_modedet_restart_standby(unsigned char);
extern void hdmi_rx21_modedet_reset_state(unsigned char);

/*
 * For each HDMI 2.1 receiver: when its record is marked connected, copy that to byte 2 and restart the
 * mode detection - into standby if a mode had been detected, otherwise back to its first state - and clear
 * the mode-detected flag; when it is not connected, clear byte 2. Called by hdmi_rx21_set_connected and
 * DRV_HDMI_IF_Disconnect.
 */
void hdmi_rx21_update_connect_state(void)
{
  unsigned char port;

  for (port = 0; port <= 1; port++) {
    if (hdmi_rx21_input_records[port * 400 + RX21_CONNECTED] != 0) {
      hdmi_rx21_input_records[port * 400 + RX21_RECORD_BYTE_2] = 1;
      if (hdmi_rx21_input_records[port * 400 + RX21_MODE_DETECTED] == 1)
        hdmi_rx21_modedet_restart_standby(port);
      else
        hdmi_rx21_modedet_reset_state(port);
      hdmi_rx21_input_records[port * 400 + RX21_MODE_DETECTED] = 0;
    } else
      hdmi_rx21_input_records[port * 400 + RX21_RECORD_BYTE_2] = 0;
  }
}

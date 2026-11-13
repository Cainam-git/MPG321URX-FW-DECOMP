/* hdmi_rx21_modedet_restart_standby  (FUN_a009e9cc)
 *
 * Put the mode detection of an HDMI 2.1 receiver into the standby state.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: derived - state word = 5 (FSM_MODE_DETECT_STANDBY in table 0xA00B4258), counter byte +5 = 15
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009e9cc @ 0xa009e9cc (-mcpu=v8 -Os -g)
 * Same form as hdmi_rx21_set_mode_change_flag: the byte store is written before the word store.
 */
#define MODE_DETECT_STATE_BYTES  0x18   /* bytes per receiver in hdmi_rx21_mode_detect_states */
#define MODEDET_STATE_STANDBY    5      /* FSM_MODE_DETECT_STANDBY, index in the table at 0xA00B4258 */
#define STABLE_COUNT             5      /* byte of the record: 'Sync Stable Count' */
#define STABLE_COUNT_START       0xf

extern unsigned char hdmi_rx21_mode_detect_states[];    /* 24-byte records */

/*
 * Put the mode detection of an HDMI 2.1 receiver back into the standby state: byte +5 of its mode-detect record
 * (the sync stable count) is set to 15 and the state word (+0) to 5.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_service_packet_events and hdmi_rx21_update_connect_state.
 */
void hdmi_rx21_modedet_restart_standby(unsigned int port)
{
  hdmi_rx21_mode_detect_states[(port & 0xff) * MODE_DETECT_STATE_BYTES + STABLE_COUNT] = STABLE_COUNT_START;
  *(unsigned int *)(hdmi_rx21_mode_detect_states + (port & 0xff) * MODE_DETECT_STATE_BYTES) = MODEDET_STATE_STANDBY;
  return;
}

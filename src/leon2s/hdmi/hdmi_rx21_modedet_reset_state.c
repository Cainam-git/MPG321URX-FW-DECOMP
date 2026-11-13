/* hdmi_rx21_modedet_reset_state  (FUN_a009e9fc)
 *
 * Set the mode-detect state of an HDMI 2.1 receiver back to the start.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: derived - state word = 0 (wait for EQ end); callers the port shut-down and hot-plug paths
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009e9fc, flags -mcpu=v8 -Os -g (section default). The state word is cleared through a word store at
 * table address + (port & 0xff) * 0x18.
 */
#define MODEDET_STATE_WAIT_EQ_END 0     /* state 0 of the mode-detect state table */

/* Mode-detect state of one HDMI 2.1 receiver (24 bytes per receiver). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* +0: index of the state the mode-detect machine runs next */
    unsigned char rest[0x14];
};
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];

/*
 * Put the mode-detect state of HDMI 2.1 receiver `port` back to its first state (wait for the end of EQ).
 * Called by hdmi_rx21_stop_port, and by hdmi_rx21_update_connect_state when no mode had been detected.
 */
void hdmi_rx21_modedet_reset_state(unsigned int port)
{
    hdmi_rx21_mode_detect_states[port & 0xff].state = MODEDET_STATE_WAIT_EQ_END;
}

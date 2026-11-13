/* hdmi_rx21_reset_rx_detect_state  (FUN_a00a29ec)
 *
 * Set the link-training state of an HDMI 2.1 receiver back to the start.
 *   receiver
 * Name basis: derived - state word 0xA807D648 = 0 (DRV_HDMI21_RXDetect_FSM_Init); mailbox command 0x12
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a29ec @ 0xa00a29ec, flags -mcpu=v8 -Os -g.
 */
extern unsigned int hdmi_rx21_rx_detect_states[];

/* Store 0 (the first state, RX_DETECT_INIT) in the link-training state word of the receiver (0 or 1). */
void hdmi_rx21_reset_rx_detect_state(unsigned int receiver)
{
    hdmi_rx21_rx_detect_states[receiver & 0xff] = 0;
}

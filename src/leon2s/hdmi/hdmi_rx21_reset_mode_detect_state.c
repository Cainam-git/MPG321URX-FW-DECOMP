/* hdmi_rx21_reset_mode_detect_state  (FUN_a0096a6c)
 *
 * Reset the mode-detect state of both HDMI 2.1 receivers.
 * Name basis: derived - clears the state word of the 24-byte records 0xA807D650/668; caller DRV_HDMI_IF_Init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0096a6c @ 0xa0096a6c (-mcpu=v8 -Os -g)
 * Source form: the offset is computed as receiver * 24 and divided by 4 for the word index; the loop is a do/while on
 * a byte counter.
 */
#define MODE_DETECT_STATE_BYTES 24      /* bytes per receiver in hdmi_rx21_mode_detect_states */

extern unsigned int hdmi_rx21_mode_detect_states[];     /* 24-byte records; word 0 of each is the state */

/*
 * Set the mode-detect state of both HDMI 2.1 receivers back to 0 (the first word of each of their 24-byte
 * records).
 * Called by DRV_HDMI_IF_Init.
 */
void hdmi_rx21_reset_mode_detect_state(void)
{
    unsigned char receiver = 0;
    unsigned int offset;
    
    do {
        offset = receiver * MODE_DETECT_STATE_BYTES;
        receiver = receiver + 1;
        hdmi_rx21_mode_detect_states[offset / 4] = 0;
    } while (receiver <= 1);
}

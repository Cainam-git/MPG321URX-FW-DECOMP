/* hdcp_rx_step_hdcp2_bytes  (FUN_a00c224c)
 *
 * Step the first 8 bytes of an HDCP 2 byte table on: shift down by one, last = old first + 1.
 * Note: When the old first byte is 0xFF the seventh byte is incremented and the last set to 0.
 * Name basis: descriptive - eight bytes: p[1..7] to p[0..6], p[7] = old p[0] + 1; called with
 *   hdcp_rx_hdmi_hdcp2_bytes / hdcp_rx_dp_hdcp2_bytes just before the bytes are written to the receiver
 *
 * Matching notes
 * --------------
 * FUN_a00c224c (leon2s 0xa00c224c-0xa00c22a0, 84 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
#define STEP_BYTES 8                            /* bytes stepped on */

/*
 * Step an 8-byte table on by one: bytes 1..7 move down to 0..6, and the old first byte plus 1 becomes the last
 * byte. When the old first byte was 0xFF, byte 6 (the moved old last byte) is incremented and the last byte
 * becomes 0.
 *
 * Called by the HDMI 2.0, HDMI 2.1 and DisplayPort protection tasks (hdcp_rx_hdmi_task, hdcp_rx_hdmi21_task,
 * hdcp_rx_dp_task) with the start of hdcp_rx_hdmi_hdcp2_bytes or hdcp_rx_dp_hdcp2_bytes, before those eight
 * bytes are written to the receiver.
 */
void hdcp_rx_step_hdcp2_bytes(unsigned char *table)
{
    unsigned char first = table[0];
    unsigned char i;

    for (i = 0; i < STEP_BYTES - 1; i++)
        table[i] = table[i + 1];
    if (first != 0xff) {
        table[STEP_BYTES - 1] = first + 1;
    } else {
        table[STEP_BYTES - 2]++;
        table[STEP_BYTES - 1] = 0;
    }
}

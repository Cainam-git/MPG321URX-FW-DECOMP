/* hdmi_tx_set_status_bit31  (FUN_a0091ac4)
 *
 * Set bit 31 of word 1 of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - caller the FRL training step that lowers the rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091ac4 @ 0xa0091ac4 (-mcpu=v8 -Os -g)
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_WORDS 7                 /* 28-byte record per HDMI TX channel, as 32-bit words */

/* Set status_bit31, bit 31 of word 1 (+4) of the record of HDMI TX channel 'port'. Ports above 1 are ignored. */
void hdmi_tx_set_status_bit31(unsigned int port)
{
    unsigned int idx = port & 0xff;
    unsigned int *record = &hdmi_tx_output_records[idx * CHANNEL_WORDS];

    if (idx > 1) {
        return;
    }
    record[1] |= 0x80000000;
}

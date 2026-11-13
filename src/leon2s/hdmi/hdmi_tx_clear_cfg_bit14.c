/* hdmi_tx_clear_cfg_bit14  (FUN_a0091a88)
 *
 * Clear bit 14 of word 5 of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - caller an FRL training state step
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091a88 @ 0xa0091a88 (-mcpu=v8 -Os -g)
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_WORDS 7                 /* 28-byte record per HDMI TX channel, as 32-bit words */

/* Clear bit 14 (0x4000, cfg_bit14) of word 5 (+0x14) of the record of HDMI TX channel 'port'. Ports above 1 are ignored. */
void hdmi_tx_clear_cfg_bit14(unsigned int port)
{
    unsigned int idx = port & 0xff;
    unsigned int *record = &hdmi_tx_output_records[idx * CHANNEL_WORDS];
    
    if (idx <= 1) {
        record[5] &= 0xffffbfff;
    }
}

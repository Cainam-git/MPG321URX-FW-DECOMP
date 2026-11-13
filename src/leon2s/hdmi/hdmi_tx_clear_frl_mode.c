/* hdmi_tx_clear_frl_mode  (FUN_a0091988)
 *
 * Switch an HDMI TX channel record back from FRL to TMDS.
 *   port: HDMI TX port 0/1
 * Name basis: derived - clears word 0 bit 4; callers the FRL training steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091988 @ 0xa0091988 (-mcpu=v8 -Os -g)
 * The offset is computed as index * 7 * 4 (sll / sub); the source writes it as (index * 0x1c) / 4 as a word
 * index.
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_SIZE 0x1c               /* bytes per HDMI TX channel record */

/* Clear frl_mode, bit 4 of word 0 of the record of HDMI TX channel 'port'. */
void hdmi_tx_clear_frl_mode(unsigned int port)
{
    unsigned int offset;
    
    offset = (port & 0xff) * CHANNEL_SIZE;
    hdmi_tx_output_records[offset / 4] &= 0xffffffef;
    return;
}

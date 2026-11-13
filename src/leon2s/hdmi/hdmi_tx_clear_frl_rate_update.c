/* hdmi_tx_clear_frl_rate_update  (FUN_a00919b0)
 *
 * Clear the 'update FRL rate' bit (word 5 bit 13) of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: derived - called by hdmi_tx_run_setup_steps right after it prints 'Update FRL Rate !!!' for a
 *   set bit
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00919b0 @ 0xa00919b0 (-mcpu=v8 -Os -g)
 * The byte offset port * 0x1c is computed first (sll/sub/sll: x8, -1, x4) and the word array is indexed with
 * offset / 4 + 5.
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_SIZE 0x1c               /* bytes per HDMI TX channel record */

/* Clear bit 13 (0x2000, frl_rate_update) of word 5 (+0x14) of the record of HDMI TX channel 'port'. */
void hdmi_tx_clear_frl_rate_update(unsigned int port)
{
    unsigned int offset;
    
    offset = (port & 0xff) * CHANNEL_SIZE;
    hdmi_tx_output_records[offset / 4 + 5] &= 0xffffdfff;
    return;
}

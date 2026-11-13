/* hdmi_tx_set_frl_rate_update  (FUN_a00919e0)
 *
 * Set the 'update FRL rate' bit (word 5 bit 13) of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: derived - hdmi_tx_run_setup_steps prints 'Update FRL Rate !!!' when the bit is set and clears
 *   it; set by DRV_HDMI21_TXDetect_FSM_LTS_4
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00919e0 @ 0xa00919e0 (-mcpu=v8 -Os -g)
 * Same array form as hdmi_tx_clear_frl_mode.
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_SIZE 0x1c               /* bytes per HDMI TX channel record */

/* Set bit 13 (0x2000, frl_rate_update) of word 5 (+0x14) of the record of HDMI TX channel 'port'. */
void hdmi_tx_set_frl_rate_update(unsigned int port)
{
    unsigned int offset;
    
    offset = (port & 0xff) * CHANNEL_SIZE;
    hdmi_tx_output_records[offset / 4 + 5] |= 0x2000;
    return;
}

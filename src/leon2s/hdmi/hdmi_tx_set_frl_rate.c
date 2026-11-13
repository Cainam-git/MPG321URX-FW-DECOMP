/* hdmi_tx_set_frl_rate  (FUN_a0091918)
 *
 * Store the FRL rate (1..6) of an HDMI TX channel.
 *   port: HDMI TX port
 *   rate: FRL rate
 * Name basis: derived - record byte +0x15 given to hdmi_tx_set_frl_clock; lowered by the FRL training steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091918 @ 0xa0091918 (-mcpu=v8 -Os -g)
 */
extern unsigned char hdmi_tx_output_records[];

#define CHANNEL_SIZE 28                 /* bytes per HDMI TX channel record */
#define CHANNEL_FRL_RATE 0x15           /* byte offset of frl_rate in the record */

/* Store 'rate' as frl_rate (record byte +0x15) of HDMI TX channel 'port'. */
void hdmi_tx_set_frl_rate(unsigned int port, unsigned char rate)
{
    hdmi_tx_output_records[(port & 0xff) * CHANNEL_SIZE + CHANNEL_FRL_RATE] = rate;
}

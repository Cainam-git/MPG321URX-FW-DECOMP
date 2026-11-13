/* hdmi_tx_is_frl_mode  (FUN_a0091960)
 *
 * Return whether an HDMI TX channel uses FRL instead of TMDS.
 *   port: HDMI TX port 0/1
 * Name basis: derived - word 0 bit 4, the 'frl' argument of the video_clk routine and hdmi_tx_setup_clock_path
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091960 @ 0xa0091960 (-mcpu=v8 -Os -g)
 */
extern unsigned char hdmi_tx_output_records[];

#define CHANNEL_SIZE 0x1c               /* bytes per HDMI TX channel record */

/* Return frl_mode, bit 4 of word 0 of the record of HDMI TX channel 'port' (1 = FRL, 0 = TMDS). */
unsigned int hdmi_tx_is_frl_mode(unsigned int port)

{
  return *(unsigned int *)((port & 0xff) * CHANNEL_SIZE + (int)hdmi_tx_output_records) >> 4 & 1;
}

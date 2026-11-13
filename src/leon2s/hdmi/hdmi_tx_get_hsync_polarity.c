/* hdmi_tx_get_hsync_polarity  (FUN_a0091c10)
 *
 * Return the requested horizontal sync polarity of an HDMI TX channel.
 *   port: HDMI TX port 0/1
 * Returns: 1 = positive
 * Name basis: proven - word 0 bit 7; hdmi_tx_set_sync_polarity prints 'Desired H Polarity +/-' from it
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091c10 @ 0xa0091c10 (-mcpu=v8 -Os -g)
 */
extern unsigned char hdmi_tx_output_records[];

#define CHANNEL_SIZE 0x1c               /* bytes per HDMI TX channel record */

/* Return hsync_positive, bit 7 of word 0 of the record of HDMI TX channel 'port' (1 = positive). */
unsigned int hdmi_tx_get_hsync_polarity(unsigned int port)

{
  return *(unsigned int *)((port & 0xff) * CHANNEL_SIZE + (int)hdmi_tx_output_records) >> 7 & 1;
}

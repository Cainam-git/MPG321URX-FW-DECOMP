/* hdmi_tx_clear_status_bit31  (FUN_a0091b00)
 *
 * Clear bit 31 of word 1 of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - caller an FRL training state step
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091b00 @ 0xa0091b00-0xa0091b3c (60 bytes, 15 words), flags -mcpu=v8 -Os -g.
 * The table base 0xa807d580 is the firmware 'or %g1, 0x180'.
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_WORDS 7                 /* 28-byte record per HDMI TX channel, as 32-bit words */

/* Clear status_bit31, bit 31 of word 1 (+4) of the record of HDMI TX channel 'port'. Ports above 1 are ignored. */
void hdmi_tx_clear_status_bit31(unsigned char port)
{
  unsigned int *record = &hdmi_tx_output_records[port * CHANNEL_WORDS];

  if (port <= 1)
    record[1] &= 0x7fffffff;
}

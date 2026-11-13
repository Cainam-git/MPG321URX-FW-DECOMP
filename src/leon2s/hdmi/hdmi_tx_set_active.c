/* hdmi_tx_set_active  (FUN_a0091b3c)
 *
 * Mark an HDMI TX channel as set up and running.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - word 4 bit 1, set at the end of the TX set-up; a set bit makes the disable path
 *   power the TX down
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091b3c @ 0xa0091b3c-0xa0091b74 (56 bytes, 14 words), flags -mcpu=v8 -Os -g.
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_WORDS 7                 /* 28-byte record per HDMI TX channel, as 32-bit words */
#define CHANNEL_ACTIVE 2                /* word 4 (+0x10), bit 1: active */

/* Set active, bit 1 of word 4 (+0x10) of the record of HDMI TX channel 'port'. Ports above 1 are ignored. */
void hdmi_tx_set_active(unsigned char port)
{
  unsigned int *record = &hdmi_tx_output_records[port * CHANNEL_WORDS];

  if (port <= 1)
    record[4] |= CHANNEL_ACTIVE;
}

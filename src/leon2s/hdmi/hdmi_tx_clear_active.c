/* hdmi_tx_clear_active  (FUN_a0091b74)
 *
 * Mark an HDMI TX channel as not running.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - word 4 bit 1; callers the TX handler and the FRL training steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091b74 @ 0xa0091b74-0xa0091bac (56 bytes, 14 words), flags -mcpu=v8 -Os -g.
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_WORDS 7                 /* 28-byte record per HDMI TX channel, as 32-bit words */
#define CHANNEL_ACTIVE 2                /* word 4 (+0x10), bit 1: active */

/* Clear active, bit 1 of word 4 (+0x10) of the record of HDMI TX channel 'port'. Ports above 1 are ignored. */
void hdmi_tx_clear_active(unsigned char port)
{
  unsigned int *record = &hdmi_tx_output_records[port * CHANNEL_WORDS];

  if (port <= 1)
    record[4] &= ~CHANNEL_ACTIVE;
}

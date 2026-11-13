/* hdmi_tx_get_ctrl_bit30  (FUN_a0091c5c)
 *
 * Return bit 30 of word 0 of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - selects codes 4..7 in hdmi_tx_select_link_source
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091c5c @ 0xa0091c5c (-mcpu=v8 -Os -g)
 */
extern unsigned char hdmi_tx_output_records[];

#define CHANNEL_SIZE 0x1c               /* bytes per HDMI TX channel record */

/* Return ctrl_bit30, bit 30 of word 0 of the record of HDMI TX channel 'port'. */
unsigned int hdmi_tx_get_ctrl_bit30(unsigned int port)

{
  return *(unsigned int *)((port & 0xff) * CHANNEL_SIZE + (int)hdmi_tx_output_records) >> 0x1e & 1;
}

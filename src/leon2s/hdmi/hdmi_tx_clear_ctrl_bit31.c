/* hdmi_tx_clear_ctrl_bit31  (FUN_a0091540)
 *
 * Clear bit 31 of word 0 of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - ports 0/1; first step of hdmi_tx_reset_channel
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091540 @ 0xa0091540-0xa0091578 (14 words, leaf), flags -mcpu=v8 -Os -g.
 * Source form: hdmi_tx_output_records as a u32 array indexed [port * 7] gives the firmware's [base + offset] operand
 * order; byte arithmetic swaps it.
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_WORDS 7                         /* 28-byte record per HDMI TX channel, as 32-bit words */
#define CHANNEL_CTRL_BIT31 0x7fffffff           /* word 0 without bit 31 (ctrl_bit31) */

/* Clear ctrl_bit31, bit 31 of word 0 of the record of HDMI TX channel 'port'. Ports above 1 are ignored. */
void hdmi_tx_clear_ctrl_bit31(unsigned char port)
{
    if (port < 2)
        hdmi_tx_output_records[port * CHANNEL_WORDS] &= CHANNEL_CTRL_BIT31;
}

/* hdmi_tx_get_status_bit31  (FUN_a0095ef8)
 *
 * Return bit 31 of word 1 of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - bit set by hdmi_tx_set_status_bit31; mailbox command 0x46
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0095ef8 @ 0xa0095ef8 (-mcpu=v8 -Os -g)
 * Compiles to: mask, multiply by 7 (sll/sub), shift left 2, add base, load word at +4, shift right 31, return.
 */
extern unsigned int hdmi_tx_output_records[];     /* channel records of the HDMI TX ports, 7 words each */

/*
 * Return bit 31 of word 1 (the word at +4) of the channel record of an HDMI TX port.
 *   port: HDMI TX port 0/1
 * Called by ipc_dispatch_command for mailbox command 0x46, whose reply carries the bit.
 */
unsigned int hdmi_tx_get_status_bit31(unsigned int port)
{
    return hdmi_tx_output_records[(port & 0xff) * 7 + 1] >> 31;
}

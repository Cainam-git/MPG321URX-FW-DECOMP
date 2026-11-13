/* hdmi_tx_get_frl_rate  (FUN_a009193c)
 *
 * Return the FRL rate of an HDMI TX channel.
 *   port: HDMI TX port 0/1
 * Name basis: derived - record byte +0x15
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009193c @ 0xa009193c (-mcpu=v8 -Os -g)
 * The table base 0xA807D580 is built as 0xA807D400 | 0x180 by sethi/or. The multiplication by 28 compiles to
 * the sll/sub/sll sequence.
 */
extern unsigned char hdmi_tx_output_records[];

#define CHANNEL_SIZE 28                 /* bytes per HDMI TX channel record */
#define CHANNEL_FRL_RATE 0x15           /* byte offset of frl_rate in the record */

/* Return frl_rate (record byte +0x15) of HDMI TX channel 'port'. */
unsigned char hdmi_tx_get_frl_rate(unsigned int port)
{
    return hdmi_tx_output_records[(port & 0xff) * CHANNEL_SIZE + CHANNEL_FRL_RATE];
}

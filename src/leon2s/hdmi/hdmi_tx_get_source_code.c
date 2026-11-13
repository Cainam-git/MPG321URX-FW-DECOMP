/* hdmi_tx_get_source_code  (FUN_a0091c38)
 *
 * Return the input source code of an HDMI TX channel.
 *   port: HDMI TX port 0/1
 * Name basis: derived - record byte +1, printed as 'HDMITX_LINK_Source_Selection' by
 *   hdmi_tx_select_link_source
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091c38 @ 0xa0091c38 (-mcpu=v8 -Os -g)
 * Same code as hdmi_tx_get_frl_rate with other constants.
 */
extern unsigned char hdmi_tx_output_records[];

#define CHANNEL_SIZE 28                 /* bytes per HDMI TX channel record */
#define CHANNEL_SOURCE_CODE 1           /* byte offset of source_code in the record */

/* Return source_code (record byte +1) of HDMI TX channel 'port'. */
unsigned char hdmi_tx_get_source_code(unsigned int port)
{
    return hdmi_tx_output_records[(port & 0xff) * CHANNEL_SIZE + CHANNEL_SOURCE_CODE];
}

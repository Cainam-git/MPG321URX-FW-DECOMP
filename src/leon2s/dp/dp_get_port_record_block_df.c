/* dp_get_port_record_block_df  (FUN_a00b035c)
 *
 * Return the address of the block at +0xDF of a DisplayPort input's record.
 * Returns: address
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b035c @ 0xa00b035c (-mcpu=v8 -Os -g)
 * Source form: the result is an int computed as the masked port times 300 plus the signed constant -0x57f82309
 * (that is 0xA807DCF7 = 0xA807DC18 + 0xDF).
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */
#define RECORD_TABLE_PLUS_0xDF (-0x57f82309)    /* 0xA807DC18 + 0xDF as a signed int */

/*
 * Return the address of the block that starts at byte 0xDF of the DP input record of a port.
 * CONV2HDMITX_UpdatePacket passes it to hdmi_tx_build_audio_infoframe_from_sdp.
 *   port: DP receiver (0 or 1)
 */
int dp_get_port_record_block_df(unsigned int port)

{
  return (port & 0xff) * DP_INPUT_RECORD_SIZE + RECORD_TABLE_PLUS_0xDF;
}

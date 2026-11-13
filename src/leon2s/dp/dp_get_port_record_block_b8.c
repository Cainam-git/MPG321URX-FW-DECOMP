/* dp_get_port_record_block_b8  (FUN_a00b02f0)
 *
 * Return the address of the block at +0xB8 of a DisplayPort input's record.
 * Returns: address
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b02f0 @ 0xa00b02f0 (-mcpu=v8 -Os -g)
 * Source form: the result is an int computed as the masked port times 300 plus the signed constant -0x57f82330
 * (that is 0xA807DCD0 = 0xA807DC18 + 0xB8).
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */
#define RECORD_TABLE_PLUS_0xB8 (-0x57f82330)    /* 0xA807DC18 + 0xB8 as a signed int */

/*
 * Return the address of the block that starts at byte 0xB8 of the DP input record of a port.
 * CONV2HDMITX_UpdatePacket passes it to hdmi_tx_build_infoframe_from_sdp.
 *   port: DP receiver (0 or 1)
 */
int dp_get_port_record_block_b8(unsigned int port)

{
  return (port & 0xff) * DP_INPUT_RECORD_SIZE + RECORD_TABLE_PLUS_0xB8;
}

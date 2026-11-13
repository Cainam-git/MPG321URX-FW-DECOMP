/* dp_get_port_record_byte_127  (FUN_a00b048c)
 *
 * Return byte 0x127 of a DisplayPort input's record.
 * Returns: byte
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b048c @ 0xa00b048c (-mcpu=v8 -Os -g)
 * Same code as dp_get_port_record_byte_b5 with another offset. Source form: the table is a char array indexed
 * with the masked port times 300 plus the offset.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern unsigned char dp_input_records[];

/*
 * Return byte 0x127 of the DP input record of a port. CONV2HDMITX_UpdatePacket passes it to
 * hdmi_tx_fill_packet_defaults when it builds the VTEM packet (the call is made with the receiver number
 * masked to 0 or 1).
 *   port: DP receiver (0 or 1)
 */
unsigned char dp_get_port_record_byte_127(unsigned int port)
{
    return dp_input_records[(port & 0xff) * DP_INPUT_RECORD_SIZE + 0x127];
}

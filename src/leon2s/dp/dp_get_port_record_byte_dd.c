/* dp_get_port_record_byte_dd  (FUN_a00b029c)
 *
 * Return byte 0xDD of a DisplayPort input's record.
 * Returns: byte
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b029c @ 0xa00b029c (-mcpu=v8 -Os -g)
 * Source form: the table is a char array indexed with the masked port times 300 plus the offset.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern unsigned char dp_input_records[];

/*
 * Return byte 0xDD of the DP input record of a port. CONV2HDMITX_UpdatePacket copies it into the pending field
 * of the extra packet state of the matching output.
 *   port: DP receiver (0 or 1)
 */
unsigned char dp_get_port_record_byte_dd(unsigned int port)
{
    return dp_input_records[(port & 0xff) * DP_INPUT_RECORD_SIZE + 0xdd];
}

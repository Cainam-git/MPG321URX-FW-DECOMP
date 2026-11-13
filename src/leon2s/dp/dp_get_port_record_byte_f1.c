/* dp_get_port_record_byte_f1  (FUN_a00b0340)
 *
 * Return byte 0xF1 of a DisplayPort input's record.
 * Returns: byte
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0340 @ 0xa00b0340 (-mcpu=v8 -Os -g)
 * Same code as dp_get_port_record_byte_b5 with another offset. Source form: the table is a char array indexed
 * with the masked port times 300 plus the offset.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern unsigned char dp_input_records[];

/*
 * Return byte 0xF1 of the DP input record of a port. CONV2HDMITX_UpdatePacket copies it into byte_2 of the
 * audio packet state of the matching output.
 *   port: DP receiver (0 or 1)
 */
unsigned char dp_get_port_record_byte_f1(unsigned int port)
{
    return dp_input_records[(port & 0xff) * DP_INPUT_RECORD_SIZE + 0xf1];
}

/* dp_get_port_record_byte_f2  (FUN_a00b0374)
 *
 * Return byte 0xF2 of a DisplayPort input's record.
 * Returns: byte
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0374 @ 0xa00b0374 (-mcpu=v8 -Os -g)
 * Same code as dp_get_port_record_byte_b5 with another offset. Source form: the table is a char array indexed
 * with the masked port times 300 plus the offset.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern unsigned char dp_input_records[];

/*
 * Return byte 0xF2 of the DP input record of a port. CONV2HDMITX_UpdateInterface reads bytes 0xF2 to 0xF5 into
 * the four entries of its dp_format array, in that order.
 *   port: DP receiver (0 or 1)
 */
unsigned char dp_get_port_record_byte_f2(unsigned int port)
{
    return dp_input_records[(port & 0xff) * DP_INPUT_RECORD_SIZE + 0xf2];
}

/* dp_get_port_record_byte_125  (FUN_a00b0470)
 *
 * Return byte 0x125 of a DisplayPort input's record.
 * Returns: byte
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0470 @ 0xa00b0470 (-mcpu=v8 -Os -g)
 * Same code as dp_get_port_record_byte_b5 with another offset. Source form: the table is a char array indexed
 * with the masked port times 300 plus the offset.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern unsigned char dp_input_records[];

/*
 * Return byte 0x125 of the DP input record of a port (the byte that dp_set_port_record_byte_125 stores).
 * dp_run_link_state tests it for 0 before it selects and resets the MST port.
 *   port: DP receiver (0 or 1)
 */
unsigned char dp_get_port_record_byte_125(unsigned int port)
{
    return dp_input_records[(port & 0xff) * DP_INPUT_RECORD_SIZE + 0x125];
}

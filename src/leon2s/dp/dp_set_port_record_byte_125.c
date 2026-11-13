/* dp_set_port_record_byte_125  (FUN_a00b0454)
 *
 * Store byte 0x125 of a DisplayPort input's record.
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0454 @ 0xa00b0454 (-mcpu=v8 -Os -g)
 * Source form: the table is a char array indexed with the masked port times 300 plus the offset.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern unsigned char dp_input_records[];

/*
 * Store value in byte 0x125 of the DP input record of a port. dp_run_link_state stores bit 7 of the port record's
 * flags word here (dp_get_port_record_byte_125 reads it back).
 *   port: DP receiver (0 or 1)
 *   value: new byte
 */
void dp_set_port_record_byte_125(unsigned int port, unsigned char value)
{
    dp_input_records[(port & 0xff) * DP_INPUT_RECORD_SIZE + 0x125] = value;
}

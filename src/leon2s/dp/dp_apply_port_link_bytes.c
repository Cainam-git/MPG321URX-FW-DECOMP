/* dp_apply_port_link_bytes  (FUN_a00ae3a0)
 *
 * Apply three link setting bytes of a port's record to its link block and register 0xC8.
 * Name basis: descriptive - bytes 0x118, 0x11A and one more
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae3a0 @ 0xa00ae3a0 (-mcpu=v8 -Os -g)
 * Source form: the record address is computed once into a pointer; the last call is a tail call.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern void dp_write_reg_ab(int, unsigned char);
extern void dp_set_lane_switches(int, unsigned char);
extern void dp_reg_update_bits(int, int, int, unsigned char);
extern char dp_input_records[];

/*
 * Pass the three link setting bytes of a port's record on: byte 0x118 to dp_write_reg_ab, byte 0x11A to
 * dp_set_lane_switches, and byte 0x11B into bits 4 and 5 (mask 0x30) of register 0xC8.
 *   port: DP receiver (0 or 1)
 * The bytes are stored by mailbox command 0x2E, which then calls this routine. It is also called by
 * dp_stop_port and dp_start_port.
 */
void dp_apply_port_link_bytes(unsigned int port)
{
    char *record;

    port = port & 0xff;
    record = &dp_input_records[port * DP_INPUT_RECORD_SIZE];
    dp_write_reg_ab(port, record[0x118]);
    dp_set_lane_switches(port, record[0x11a]);
    dp_reg_update_bits(port, 200, 0x30, record[0x11b]);
}

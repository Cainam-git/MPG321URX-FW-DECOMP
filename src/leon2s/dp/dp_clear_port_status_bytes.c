/* dp_clear_port_status_bytes  (FUN_a00aba14)
 *
 * Clear eight status bytes of a DP port record.
 *   port: DP receiver 0/1
 * Name basis: descriptive - caller dp_run_link_state
 *
 * Matching notes
 * --------------
 * FUN_a00aba14 (leon2s), flags -mcpu=v8 -Os -g. Leaf.
 * Source form: the stores keep this order; the scheduler moves the offset 6 store up.
 */
extern unsigned char dp_input_records[][300];       /* one 300-byte record per port */

/*
 * Clear eight bytes of the record of a DP port: offsets 0, 0x2E, 0xB5, 0xDC, 0xEF, 2, 4 and 6.
 * dp_run_link_state calls it when the port's link leaves the READY state.
 *   port: DP receiver 0 or 1
 */
void dp_clear_port_status_bytes(unsigned char port)
{
    dp_input_records[port][0] = 0;
    dp_input_records[port][0x2e] = 0;
    dp_input_records[port][0xb5] = 0;
    dp_input_records[port][0xdc] = 0;
    dp_input_records[port][0xef] = 0;
    dp_input_records[port][2] = 0;
    dp_input_records[port][4] = 0;
    dp_input_records[port][6] = 0;
}

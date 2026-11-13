/* dp_mst_get_rx_chunk_address  (FUN_a00d66bc)
 *
 * Return the address of the received-chunk row that the current port reads next.
 * Returns: address; 0 unless the arguments are (0, 1)
 * Note: Row (read index & 0xF) of the port's sixteen 0x30-byte rows at 0xA807963D + 0x300 x port; the row
 *   starts with the chunk header.
 * Name basis: derived - address arithmetic on the port's read index; dp_mst_parse_chunk_header unpacks the
 *   chunk header at the returned address
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d66bc @ 0xa00d66bc (-mcpu=v8 -Os -g)
 * The `bne,a` (branch always with annul) for the second check means the delay slot instruction `clr %o0`
 * executes only if the branch is taken, setting up the return value. The final `b` to the common return
 * point is also needed.
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_rx_read_indexes[];
extern unsigned char DAT_a8079400[];

/* Return the address of the received-chunk row (0x30 bytes) that the current port reads next: row
 * (read index & 0xf) of the 16 rows of that port, in the table that starts at 0xA807963D (rows of port p
 * begin at 0x300 * p). Returns 0 unless `kind` is 0 and `which` is 1; both callers pass their own
 * arguments on. */
unsigned int dp_mst_get_rx_chunk_address(unsigned int kind, unsigned int which)
{
    unsigned int port;
    unsigned int row;
    
    if ((kind & 0xff) == 0) {
        if ((which & 0xff) == 1) {
            port = dp_mst_message_state_port;
            row = (dp_mst_message_state_rx_read_indexes[port] & 0xf);
            row = row * 3;
            port = port * 3;
            return (port << 8) + (row << 4) + 0xa8079400 + 0x23d;
        }
    }
    return 0;
}

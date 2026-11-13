/* dp_mst_parse_chunk_header  (FUN_a00d6890)
 *
 * Unpack the header of a received chunk when it starts a message.
 * Name basis: derived - dp_mst_get_rx_chunk_address, then dp_mst_unpack_header
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d6890 @ 0xa00d6890 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept; the callees are declared without prototype, so
 * the unused argument words are passed on.
 */
extern int dp_mst_get_rx_chunk_address(); /* 0xa00d66bc */
extern int dp_mst_unpack_header(); /* 0xa00d6724 */

/* Unpack the header of the received chunk row that dp_mst_get_rx_chunk_address(kind, which) selects into the
 * buffer `header`. When it returns 0 (no such chunk) nothing is unpacked and `header` is returned.
 * Otherwise bit 5 (0x20) of the buffer's byte +0x12 is set first and the result of dp_mst_unpack_header
 * is returned. The other parameters are passed on to it unchanged. */
int dp_mst_parse_chunk_header(unsigned int header, unsigned int kind, unsigned int which,
                 unsigned int param_4, unsigned int param_5, unsigned int param_6)
{
    kind = dp_mst_get_rx_chunk_address(kind & 0xff, which & 0xff);
    if (kind == 0) {
        return header;
    }
    *(volatile unsigned char *)(header + 0x12) |= 0x20;
    return dp_mst_unpack_header(header, kind, which, param_4, param_5, param_6);
}

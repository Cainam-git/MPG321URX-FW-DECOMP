/* dp_mst_find_message_bounds  (FUN_a00d7cd0)
 *
 * Scan the received chunks of the current port for the end slot of the first complete message.
 * Name basis: derived - flag bits 0x80 (start) and 0x40 (end) of the chunk headers
 *
 * Matching notes
 * --------------
 * FUN_a00d7cd0 (leon2s 0xa00d7cd0-0xa00d7e6c, 412 bytes), flags -mcpu=v8 -Os -g.
 * Only caller dp_mst_receive_task, which masks the result with 0xff.
 * Source form: the packet address is written row + (slot * 3 << 4) for byte 0 and the bit-7 test; the second flag
 * byte read goes through the unsigned char row index x = slot * 3 and the unsigned short byte offset o = x << 4
 * into dp_mst_chunk_rings[port] (the firmware's 'sll; and 0x3f0': the zero-extended byte index keeps a mask after the
 * shift); the port byte and the read index are named directly in the loop (the firmware reloads them before the
 * loop).
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_rx_read_indexes[];
extern unsigned char dp_mst_message_state_rx_write_indexes[];
extern unsigned char dp_mst_chunk_rings[][0x300];

/* Looks through the received chunks of the current port for the end of the first complete message.
 *
 * Each port has a ring of 16 chunk slots of 0x30 bytes (dp_mst_chunk_rings[port]); the read index and the write index
 * of the ring are in dp_mst_message_state_rx_read_indexes / _rx_write_indexes. The routine scans the cnt waiting
 * slots from the read index. The flag byte of a chunk is packet byte off + 2, where off follows from the
 * nibble count in the high nibble of packet byte 0: k = count - 1, off = k / 2, plus 1 when k is odd. Bit 7 of
 * the flag byte marks the start of a message, bit 6 its end. A bit 7 in slot 0 is remembered (first). The scan
 * stops at the first slot with bit 6 set (found unless first was set), or at a later slot with bit 7 set (a new
 * message starts there: found, and the end is the slot before it).
 *
 * Returns (index of the stopping slot) | 0x40 when an end was found; the index alone when the scan stopped at
 * a bit 6 slot without a found end; 0x80 when all waiting slots were passed. Called by dp_mst_receive_task.
 */
int dp_mst_find_message_bounds(void)
{
    unsigned char read_index, write_index, i, off, flags, first, found;
    unsigned char cnt;
    unsigned char *row, *p;
    unsigned int slot;
    int k;
    unsigned char x;
    unsigned short o;

    write_index = dp_mst_message_state_rx_write_indexes[dp_mst_message_state_port];
    read_index = dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port];
    found = 0;
    first = 0;
    /* Number of waiting slots in the ring of 16. */
    if (write_index < read_index)
        cnt = 0x10 - (read_index - write_index);
    else
        cnt = write_index - read_index;
    for (i = 0; i < cnt; i++) {
        slot = (dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port] + i) & 0xf;
        row = dp_mst_chunk_rings[dp_mst_message_state_port];
        x = slot * 3;
        k = ((row + (slot * 3 << 4))[0] >> 4) - 1;
        off = k / 2;
        if (k & 1)
            off++;
        if (i == 0 && (signed char)(row + (slot * 3 << 4))[off + 2] < 0)
            first = 1;
        o = x << 4;
        flags = dp_mst_chunk_rings[dp_mst_message_state_port][o + off + 2];
        if (flags & 0x40) {
            if (!first)
                found = 1;
            break;
        }
        if ((flags & 0x80) && i != 0) {
            i--;
            found = 1;
            break;
        }
    }
    if (i < cnt) {
        if (found)
            return ((dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port] + i) & 0xf) | 0x40;
        return (dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port] + i) & 0xf;
    }
    return 0x80;
}

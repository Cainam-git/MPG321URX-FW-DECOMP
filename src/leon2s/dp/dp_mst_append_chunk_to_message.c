/* dp_mst_append_chunk_to_message  (FUN_a00d985c)
 *
 * Append the body bytes of a received chunk to the message being assembled.
 * Name basis: derived - length from the chunk header (6 bits)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d985c (0xa00d985c-0xa00d9988, 300 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the copy loop is an inlined helper put(dst_row, addr_bytes, chunk, count) with count an unsigned
 * int that reads (chunk + addr_bytes)[i + 3] inside the loop (this gives the register copy of chunk +
 * addr_bytes before the loop); the caller reads the length byte through length_ptr = &ring[slot][addr_bytes].
 */

#define MST_REQUEST_ENUM_PATH_RESOURCES 0x10    /* 0x10 and 0x11 (ALLOCATE_PAYLOAD) clear the state byte */
#define CHUNK_LENGTH_MASK               0x3f    /* body length: low 6 bits of the byte after the address bytes */
#define FIRST_ROW_BYTE                  3       /* the chunk header is addr_bytes + 3 bytes long */

extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_rx_read_indexes[];
extern unsigned char dp_mst_message_state_byte_0x4f;
extern unsigned char dp_mst_message_state_fwd_write_index;
/* Received chunks: 16 slots of 0x30 bytes per port (dp_mst_chunk_rings). */
extern unsigned char dp_mst_chunk_rings[][16][0x30];
/* Forward rows: 16 rows of 0x30 bytes, addressed here as 3 rows of 16 per message (dp_mst_forward_rows). */
extern unsigned char dp_mst_forward_rows[][16];
extern unsigned char dp_mst_forward_messages[];
extern unsigned char dp_mst_get_request_number(void);

/* Copy count body bytes of the chunk into the forward row, to the same positions. */
static inline void put(unsigned int dst_row, unsigned char addr_bytes, unsigned char *chunk, unsigned int count)
{
    unsigned char i;

    for (i = 0; i < count; i++)
        dp_mst_forward_rows[dst_row][i + addr_bytes + FIRST_ROW_BYTE] = (chunk + addr_bytes)[i + FIRST_ROW_BYTE];
}

/*
 * Copy the body of the received chunk at the read index of the current port into the forward row at the
 * forward write index, and put that row in the forward ring. Called by dp_mst_receive_task right after
 * dp_mst_queue_short_message has stored the changed header of the same message in that row; no parameters, no
 * result.
 *
 * The header length is addr_bytes + 3: addr_bytes follows from the link count in the high nibble of chunk byte 0
 * (count - 1 address nibbles, two to a byte, rounded up); the body length is the low 6 bits of the byte after
 * the address bytes. dp_mst_forward_messages[] gets the total length (header + body) of the row.
 *
 * Requests 0x10 and 0x11 (as returned by dp_mst_get_request_number) also clear the state byte +0x4F.
 */
void dp_mst_append_chunk_to_message(void)
{
    unsigned char (*ring)[0x30];
    unsigned int slot;
    unsigned char *length_ptr;
    unsigned char i, body_len, addr_bytes;
    unsigned int index;
    unsigned int dst_row;
    int nibbles, half;

    if ((unsigned char)(dp_mst_get_request_number() - MST_REQUEST_ENUM_PATH_RESOURCES) <= 1)
        dp_mst_message_state_byte_0x4f = 0;
    ring = dp_mst_chunk_rings[dp_mst_message_state_port];
    slot = dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port] & 0xf;
    nibbles = (ring[slot][0] >> 4) - 1;
    dst_row = (dp_mst_message_state_fwd_write_index & 0xf) * 3;
    half = nibbles / 2;
    addr_bytes = half;
    if (nibbles & 1)
        addr_bytes = half + 1;
    length_ptr = &ring[slot][addr_bytes];
    body_len = length_ptr[1] & CHUNK_LENGTH_MASK;
    put(dst_row, addr_bytes, ring[slot], body_len);
    index = dp_mst_message_state_fwd_write_index;
    dp_mst_forward_messages[index] = addr_bytes + body_len + 3;
    dp_mst_message_state_fwd_write_index = (index + 1) & 0xf;
}

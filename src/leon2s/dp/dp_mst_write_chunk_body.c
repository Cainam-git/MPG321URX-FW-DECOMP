/* dp_mst_write_chunk_body  (FUN_a00da030)
 *
 * Write the next body bytes of the outgoing message and their checksum to the port's registers.
 * Name basis: derived - up to cnt bytes from a 0x30-byte window of the 0x200-byte body ring, then
 *   dp_mst_crc8_data
 *
 * Matching notes
 * --------------
 * FUN_a00da030 (leon2s 0xa00da030-0xa00da288, 600 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the header entry byte is read as '*(dp_mst_reply_header_entries[port] + read_index * 11)'; the dp_mst_crc8_data
 * result goes through the unsigned char 'checksum' before the store; the register block pointer is
 * dp_mst_msg_reg_blocks[dp_mst_message_state_port], reloaded at every store (volatile word pointers).
 */

#define REPLY_BODY_RING_MASK  0x1ff     /* the body ring of a port is 0x200 bytes */
#define BODY_WINDOW_BYTES     0x30      /* bytes copied from the ring at each call */
#define BODY_WORD_FIRST_AREA  3         /* first area of the register block: body starts behind the header */
#define BODY_WORD_SECOND_AREA 0x33      /* second area starts at word 0x30 */
#define HEADER_ENTRY_BYTES    11        /* size of one packed header entry */

extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_max_body_bytes;
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned short dp_mst_message_state_reply_offsets[];
extern unsigned char dp_mst_reply_bodies[][0x200];
/* Packed header entries of the outgoing messages: 16 entries of 11 bytes per port (dp_mst_reply_header_entries). */
extern unsigned char dp_mst_reply_header_entries[][0xb0];
extern unsigned char dp_mst_reply_chunk_rows[][0x10];
extern volatile unsigned int *dp_mst_msg_reg_blocks[];
extern unsigned char dp_mst_crc8_data(unsigned char *, int, int, int);

/*
 * Write the body of the next outgoing chunk of the current port into the message area of the port's registers.
 * Called by dp_mst_send_down_reply_step right after dp_mst_write_chunk_header has written the header.
 *   cnt: body bytes still to send; at most dp_mst_message_state_max_body_bytes of them are written now.
 *
 * The bytes come from the port's body ring (0x200 bytes) at the current position. The register block has two
 * message areas, a word per byte: the area is chosen by the kind of the message (dp_mst_reply_chunk_rows), the
 * first for kind 0 and the second, which starts at word 0x30, otherwise. The body is written right behind the
 * header of the message, which is addr_bytes + 3 bytes long (addr_bytes follows from the count in the high nibble
 * of the first header byte, as in dp_mst_pack_header), and the checksum byte (dp_mst_crc8_data over the bytes
 * written) follows the body. Finally the position in the ring moves on by the bytes written.
 */
void dp_mst_write_chunk_body(unsigned char cnt)
{
    unsigned char buf[0x30];
    unsigned char port;
    unsigned short ring_pos;
    unsigned char i;
    int nibbles;
    unsigned char addr_bytes;
    unsigned char chunk_len;
    unsigned char kind;
    unsigned char checksum;

    port = dp_mst_message_state_port;
    ring_pos = dp_mst_message_state_reply_offsets[port];
    for (i = 0; i < BODY_WINDOW_BYTES; i++)
        buf[i] = dp_mst_reply_bodies[port][(ring_pos + i) & REPLY_BODY_RING_MASK];
    nibbles = (*(dp_mst_reply_header_entries[port] + dp_mst_message_state_reply_read_indexes[port] * HEADER_ENTRY_BYTES) >> 4) - 1;
    kind = dp_mst_reply_chunk_rows[port][dp_mst_message_state_reply_read_indexes[port]];
    addr_bytes = nibbles / 2;
    if (nibbles & 1)
        addr_bytes++;
    if (cnt > dp_mst_message_state_max_body_bytes)
        chunk_len = dp_mst_message_state_max_body_bytes;
    else
        chunk_len = cnt;
    if (kind == 0) {
        for (i = 0; i < chunk_len; i++)
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][addr_bytes + i + BODY_WORD_FIRST_AREA] = buf[i];
        checksum = dp_mst_crc8_data(buf, chunk_len, 0, 0x30);
        dp_mst_msg_reg_blocks[dp_mst_message_state_port][addr_bytes + chunk_len + BODY_WORD_FIRST_AREA] = checksum;
    } else {
        for (i = 0; i < chunk_len; i++)
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][addr_bytes + i + BODY_WORD_SECOND_AREA] = buf[i];
        checksum = dp_mst_crc8_data(buf, chunk_len, 0, 0x30);
        dp_mst_msg_reg_blocks[dp_mst_message_state_port][addr_bytes + chunk_len + BODY_WORD_SECOND_AREA] = checksum;
    }
    dp_mst_message_state_reply_offsets[dp_mst_message_state_port] = (dp_mst_message_state_reply_offsets[dp_mst_message_state_port] + chunk_len) & REPLY_BODY_RING_MASK;
}

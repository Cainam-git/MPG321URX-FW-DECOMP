/* dp_mst_write_chunk_header  (FUN_a00d9edc)
 *
 * Build the header of the next outgoing chunk and write it to the port's registers.
 * Name basis: descriptive - three bit-fields set in the 11-byte record
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d9edc @ 0xa00d9edc-0xa00da030, -mcpu=v8 -Os -g.
 * The packed header and the message kind are read through the port and read index (re-read for every
 * access). The register block is reached through volatile pointers; table and index are reloaded on every pass.
 * Same buffer, record and destination handling as dp_mst_trim_up_message_record.
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned char dp_mst_reply_chunk_rows[][16];
extern unsigned char dp_mst_reply_header_entries[][16][11];
extern volatile unsigned int *dp_mst_msg_reg_blocks[];
extern void dp_mst_unpack_header(unsigned char *, unsigned char *);
extern unsigned char dp_mst_pack_header(unsigned char *, unsigned char *);
/* Word 4 of the unpacked header: the top 10 bits are byte +0x10 and bits 7 and 6 of byte +0x11; then the length
 * field (low 6 bits of byte +0x11), the start flag (bit 7 of byte +0x12), the end flag (bit 6) and the rest. */
struct header_flags { unsigned int high10 : 10; unsigned int length : 6; unsigned int start_flag : 1; unsigned int end_flag : 1; unsigned int rest : 14; };
struct unpacked_header { unsigned int w[4]; struct header_flags f; unsigned int w5; };
union header_buf { struct unpacked_header m; unsigned char b[24]; };

/*
 * Write the header of the next chunk of the down reply at the head of the reply ring into the message registers
 * of the current port.
 *   start:  1 for the first chunk of a message (start flag)
 *   end:    1 for the last chunk of a message (end flag)
 *   length: chunk length byte, stored in the 6-bit length field
 * The packed header of the message (11-byte entry dp_mst_reply_header_entries[port][reply read index]) is unpacked, the length,
 * start flag and end flag are set, and the header is packed again into the same entry. The packed bytes are then
 * copied, one byte to each 32-bit word, to the message register block of the port: from word 0 when the message
 * kind (dp_mst_reply_chunk_rows) is 0, from word 0x30 otherwise. Called by dp_mst_send_down_reply_step.
 */
void dp_mst_write_chunk_header(unsigned char start, unsigned char end, unsigned char length)
{
    union header_buf header;
    unsigned char *packed;
    unsigned char kind, i, packed_length;

    packed = dp_mst_reply_header_entries[dp_mst_message_state_port][dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port]];
    kind = dp_mst_reply_chunk_rows[dp_mst_message_state_port][dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port]];
    dp_mst_unpack_header(header.b, packed);
    header.m.f.length = length;
    header.m.f.start_flag = start;
    header.m.f.end_flag = end;
    packed_length = dp_mst_pack_header(header.b, packed);
    if (kind == 0) {
        for (i = 0; i < packed_length; i++)
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][i] = packed[i];
    } else {
        for (i = 0; i < packed_length; i++)
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][i + 0x30] = packed[i];
    }
}

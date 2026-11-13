/* dp_mst_trim_up_message_record  (FUN_a00da6ac)
 *
 * Write a stored message from the output to the port's registers, its address part shortened by one.
 * Name basis: derived - low nibble of header byte 0 decremented, nibble bytes shifted down, header packed
 *   again
 *
 * Matching notes
 * --------------
 * FUN_a00da6ac (leon2s, 0xa00da6ac-0xa00da838, 396 bytes), flags -mcpu=v8 -Os -g.
 * The unpack buffer is 24 bytes (frame -128: buffer at %fp-32; 17..24 bytes give the same frame). The low
 * nibble is decremented as a word read-modify-write (ld/andn/or/st = bit-field store).
 * volatile on the copy DESTINATION only: the dp_mst_msg_reg_blocks[] entries are register-block pointers
 * (other users, e.g. dp_mst_handle_clear_payload_table, write registers +0x2ac/+0x2b0 through them; one word per
 * byte is a register file). Without volatile the code does not match (the store sinks into the bcs delay slot).
 */
extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_up_message_kinds[];
extern unsigned char dp_mst_up_message_rows[][0x30];
extern volatile unsigned int *dp_mst_msg_reg_blocks[];
extern void dp_mst_unpack_header(unsigned char *, unsigned char *);
extern unsigned char dp_mst_pack_header(unsigned char *, unsigned char *);
/* Byte 0 of the unpacked header: count (high nibble) and low nibble. */
struct header_byte0 { unsigned int count : 4; unsigned int low_nibble : 4; unsigned int rest : 24; };
union header_buf { struct header_byte0 h; unsigned char b[24]; };

/*
 * Write the stored up message (down reply or up request from the output) at the up read index into the
 * message registers of the current port, with its address part shortened: the low nibble of the count byte
 * is lowered by one and, unless the count (high nibble) is 1, the address nibbles are moved down by one place.
 *
 * The record is the row dp_mst_up_message_rows[up read index]; dp_mst_up_message_kinds[index] is its kind. The header
 * is unpacked; unless the count is 1, the nibble entries 1.. are moved down one place for low nibble - 1
 * entries and the next entry is set to 1. The header is packed again into the record and the packed bytes are
 * copied, one byte to each 32-bit word, to the message register block of the port: from word 0 when the kind
 * is 0, from word 0x30 otherwise. Called by dp_mst_send_up_message_step.
 */
void dp_mst_trim_up_message_record(void)
{
    union header_buf header;
    unsigned char *record;
    unsigned char kind, i, packed_length;

    record = dp_mst_up_message_rows[dp_mst_message_state_up_read_index];
    kind = dp_mst_up_message_kinds[dp_mst_message_state_up_read_index];
    dp_mst_unpack_header(header.b, record);
    if ((header.b[0] & 0xf0) != 0x10) {
        for (i = 0; i < (header.b[0] & 0xf) - 1; i++)
            header.b[i + 1] = header.b[i + 2];
        header.b[i + 1] = 1;
    }
    header.h.low_nibble--;
    packed_length = dp_mst_pack_header(header.b, record);
    if (kind == 0) {
        for (i = 0; i < packed_length; i++)
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][i] = record[i];
    } else {
        for (i = 0; i < packed_length; i++)
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][i + 0x30] = record[i];
    }
}

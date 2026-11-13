/* dp_mst_is_reply_unmatched  (FUN_a00da288)
 *
 * Return 1 when the waiting reply's request number differs from the last request noted for it.
 * Returns: 1 = the caller drops the reply, else 0
 * Note: Also needs low nibble < count and bit 7 of the header byte after the address bytes clear.
 * Name basis: derived - compares the reply's first body byte (bits 0..6) with
 *   dp_mst_last_request_numbers[sequence bit]; dp_mst_send_down_reply_step steps past the reply on 1
 *
 * Matching notes
 * --------------
 * FUN_a00da288 (leon2s 0xa00da288-0xa00da388, 256 bytes), flags -mcpu=v8 -Os -g.
 * Source form: first_body_byte holds the unmasked ring byte (the '& 0x7f' is in the compare); flag is computed
 * before bit.
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned short dp_mst_message_state_reply_offsets[];
extern unsigned char dp_mst_reply_header_entries[][16][11];
extern unsigned char dp_mst_reply_bodies[][0x200];
extern unsigned char dp_mst_last_request_numbers[];
/*
 * Tell whether the message at the head of the reply ring of the current port is to be dropped; returns 1 for
 * yes, 0 for no. Called by dp_mst_send_down_reply_step before the first chunk of a message.
 *
 * The packed header is the 11-byte entry at the read index in the row dp_mst_reply_header_entries[port]; byte 0 holds the
 * count (high nibble) and a low nibble. With address_bytes = (count - 1) / 2, plus one when count - 1 is odd,
 * the header byte address_bytes + 1 gives flag (its bit 7) and the byte address_bytes + 2 gives bit (its
 * bit 4). The first body byte is the byte of the port's body ring (0x200 bytes) at the position
 * dp_mst_message_state_reply_offsets[port].
 * The result is 1 when dp_mst_last_request_numbers[bit] differs from the first body byte (bits 0..6), the low nibble is below
 * the count and flag is 0.
 */
int dp_mst_is_reply_unmatched(void)
{
    unsigned char port = dp_mst_message_state_port;
    unsigned char *entry = (unsigned char *)dp_mst_reply_header_entries + port * 0xb0 + dp_mst_message_state_reply_read_indexes[port] * 11;
    unsigned char first = entry[0];
    unsigned char count = first >> 4;
    unsigned int first_body_byte = dp_mst_reply_bodies[port][dp_mst_message_state_reply_offsets[port] & 0x1ff];
    unsigned char low_nibble = first & 0xf;
    int nibbles = count - 1;
    unsigned char address_bytes = nibbles / 2;
    unsigned char bit;
    unsigned char *after_address;
    unsigned char flag;

    if (nibbles & 1)
        address_bytes = nibbles / 2 + 1;
    after_address = entry + address_bytes;
    flag = after_address[1] >> 7;
    bit = after_address[2] & 0x10;
    bit = bit != 0;
    if (dp_mst_last_request_numbers[bit] != (first_body_byte & 0x7f) && low_nibble < count && flag == 0)
        return 1;
    return 0;
}

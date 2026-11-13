/* dp_mst_is_record_changed  (FUN_a00da9e8)
 *
 * Return whether a table byte selected by the record differs from the record.
 * Returns: 0 or 1
 * Name basis: descriptive - nibbles of record byte 0
 *
 * Matching notes
 * --------------
 * FUN_a00da9e8 (leon2s 0xa00da9e8-0xa00daa98, 176 bytes), flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_up_message_rows[][0x30];
extern unsigned char dp_mst_last_request_numbers[];
/*
 * Compare the stored up request at the up read index with the table dp_mst_last_request_numbers; returns 1 or 0.
 *
 * Byte 0 of the record (row dp_mst_up_message_rows[up read index]) holds the count (high nibble) and a low nibble. With
 * address_bytes = (count - 1) / 2, plus one when count - 1 is odd, bit is bit 4 of record byte
 * address_bytes + 2. The result is 1 when dp_mst_last_request_numbers[(count - low nibble) * 2 + bit] differs from bits 0..6
 * of record byte address_bytes + 3 and the low nibble is below the count, otherwise 0.
 * Called by dp_mst_send_up_message_step for a record with the start flag.
 */
int dp_mst_is_record_changed(void)
{
    unsigned char *record = dp_mst_up_message_rows[dp_mst_message_state_up_read_index];
    unsigned char first = record[0];
    unsigned char count = first >> 4;
    unsigned char low_nibble = first & 0xf;
    int nibbles = count - 1;
    unsigned char address_bytes = nibbles / 2;
    unsigned char bit;

    if (nibbles & 1)
        address_bytes = nibbles / 2 + 1;
    bit = record[address_bytes + 2] & 0x10;
    bit = bit != 0;
    return dp_mst_last_request_numbers[(count - low_nibble) * 2 + bit] != (record[address_bytes + 3] & 0x7f) && low_nibble < count;
}

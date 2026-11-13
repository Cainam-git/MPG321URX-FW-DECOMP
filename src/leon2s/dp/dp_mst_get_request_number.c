/* dp_mst_get_request_number  (FUN_a00d95e4)
 *
 * Return the request number of the message that is being handled.
 * Returns: request number
 * Name basis: derived - byte of the current record; the value the dispatcher switches on
 *
 * Matching notes
 * --------------
 * FUN_a00d95e4 (leon2s 0xa00d95e4-0xa00d9698, 180 bytes), flags -mcpu=v8 -Os -g.
 * Source form: byte 0 is read as ring[slot][0]; the record pointer is taken after address_bytes (taking it
 * before the byte 0 read, or indexing ring[slot][address_bytes + 2] directly, changes the add operands and
 * registers).
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_rx_read_indexes[];
extern unsigned char dp_mst_chunk_rings[][16][0x30];
extern unsigned char dp_mst_last_request_numbers[];
/*
 * Return the request number of the received message at the read index of the current port.
 *
 * The received chunks of a port are 16 rows of 0x30 bytes (dp_mst_chunk_rings[port][slot]); the row is selected by
 * dp_mst_message_state_rx_read_indexes[port] & 0xf. Byte 0 of a row holds the count (high nibble) and a low
 * nibble. The address part is count - 1 nibbles, two to a byte, so it takes address_bytes = (count - 1) / 2
 * bytes, plus one when count - 1 is odd. The request number is the row byte address_bytes + 3.
 *
 * When the count is above the low nibble, the request number is also stored in dp_mst_last_request_numbers[low nibble * 2 + bit],
 * where bit is bit 4 of row byte address_bytes + 2. Called by dp_mst_dispatch_request and
 * dp_mst_append_chunk_to_message.
 */
unsigned char dp_mst_get_request_number(void)
{
    unsigned char port = dp_mst_message_state_port;
    unsigned char slot = dp_mst_message_state_rx_read_indexes[port] & 0xf;
    unsigned char (*ring)[0x30] = dp_mst_chunk_rings[port];
    unsigned char first = ring[slot][0];
    unsigned char count = (first & 0xf0) >> 4;
    unsigned char low_nibble = first & 0xf;
    int nibbles = count - 1;
    unsigned char address_bytes = nibbles / 2;
    unsigned char bit;
    unsigned char *row;

    if (nibbles & 1)
        address_bytes++;
    row = ring[slot];
    bit = (row[address_bytes + 2] & 0x10) >> 4;
    if (count > low_nibble)
        dp_mst_last_request_numbers[low_nibble * 2 + bit] = row[address_bytes + 3];
    return row[address_bytes + 3];
}

/* dp_mst_find_up_message_end  (FUN_a00d9d50)
 *
 * Find the first stored message row from the output that carries the end flag of a message.
 * Returns: row index 0..15, or 0xFF when no used row has the flag
 * Name basis: derived - scan of the used 0x30-byte rows (read index up to the write index) for bit 6 of the
 *   header byte after the address bytes
 *
 * Matching notes
 * --------------
 * FUN_a00d9d50 (leon2s 0xa00d9d50-0xa00d9e44, 244 bytes), flags -mcpu=v8 -Os -g.
 * Source form: both record reads index dp_mst_up_message_rows[slot] directly (a record pointer local moves the address
 * add); the final test and sum use an unsigned int copy of i and an unsigned int copy of the reloaded read
 * index (unsigned char operands give the reversed add operand order and other registers).
 */
extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_message_state_up_write_index;
extern unsigned char dp_mst_up_message_rows[][0x30];
#define NO_PENDING_UP    0xff   /* result: no complete up message waiting */
#define UP_FLAG_END_BIT  0x40   /* bit 6 of the second flag byte of a record: last chunk of a message */

/*
 * Find the first stored up request that ends a message.
 *
 * The stored messages fetched from the output are 16 records of 0x30 bytes (dp_mst_up_message_rows) with 4-bit indexes;
 * the used ones run from the read index (dp_mst_message_state_up_read_index) up to, not including, the write
 * index. Byte 0 of a record holds the count in its high nibble; the address part takes address_bytes =
 * (count - 1) / 2 bytes, plus one when count - 1 is odd, and the flag byte is the record byte
 * address_bytes + 2.
 *
 * Returns the index (0..15) of the first used record whose flag byte has bit 6 (end flag) set, or 0xFF when
 * the ring is empty (read index = write index) or no used record has it. Called by dp_mst_transmit_task.
 */
unsigned char dp_mst_find_up_message_end(void)
{
    unsigned char write_index = dp_mst_message_state_up_write_index;
    unsigned char read_index = dp_mst_message_state_up_read_index;
    unsigned char used;
    unsigned char i;
    unsigned char slot;
    unsigned char address_bytes;
    int nibbles;
    unsigned int found;
    unsigned int first;

    if (write_index < read_index)
        used = 0x10 - (read_index - write_index);
    else if (write_index == read_index)
        return NO_PENDING_UP;
    else
        used = write_index - read_index;
    for (i = 0; i < used; i++) {
        slot = (dp_mst_message_state_up_read_index + i) & 0xf;
        nibbles = (dp_mst_up_message_rows[slot][0] >> 4) - 1;
        address_bytes = nibbles / 2;
        if (nibbles & 1)
            address_bytes++;
        if (dp_mst_up_message_rows[slot][address_bytes + 2] & UP_FLAG_END_BIT)
            break;
    }
    found = i;
    if (found < used) {
        first = dp_mst_message_state_up_read_index;
        return (first + found) & 0xf;
    }
    return NO_PENDING_UP;
}

/* dp_mst_write_record_tail  (FUN_a00da838)
 *
 * Copy the remaining bytes of the current record to the port's registers.
 * Name basis: descriptive - one byte per register word
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00da838 @ 0xa00da838-0xa00da960, -mcpu=v8 -Os -g.
 * The register block is reached through volatile pointers; table and index are reloaded on every pass.
 */
extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_up_message_kinds[];
extern unsigned char dp_mst_up_message_rows[][0x30];
extern volatile unsigned int *dp_mst_msg_reg_blocks[];
/*
 * Write the body of the stored up request at the up read index into the message registers of the current port.
 *
 * The record is the row dp_mst_up_message_rows[up read index] (kind in dp_mst_up_message_kinds). Byte 0 holds the count
 * in its high nibble; with address_bytes = (count - 1) / 2, plus one when count - 1 is odd, the record byte
 * address_bytes + 1 holds the body length in its low 6 bits. Those body bytes, starting at record byte
 * address_bytes + 3, are copied one byte to each 32-bit word of the port's message register block, to the same
 * word numbers: from word address_bytes + 3 when the kind is 0, from word address_bytes + 0x33 otherwise.
 * Called by dp_mst_send_up_message_step after dp_mst_trim_up_message_record has written the header.
 */
void dp_mst_write_record_tail(void)
{
    unsigned char *record;
    unsigned char kind, i, body_length, address_bytes;
    int nibbles, half;

    record = dp_mst_up_message_rows[dp_mst_message_state_up_read_index];
    nibbles = (record[0] >> 4) - 1;
    half = nibbles / 2;
    kind = dp_mst_up_message_kinds[dp_mst_message_state_up_read_index];
    address_bytes = half;
    if (nibbles & 1)
        address_bytes = half + 1;
    body_length = record[address_bytes + 1] & 0x3f;
    if (kind == 0) {
        for (i = 0; i < body_length; i++)
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][address_bytes + i + 3] = record[address_bytes + i + 3];
    } else {
        for (i = 0; i < body_length; i++)
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][address_bytes + i + 0x33] = record[address_bytes + i + 3];
    }
}

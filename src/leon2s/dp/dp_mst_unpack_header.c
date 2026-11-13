/* dp_mst_unpack_header  (FUN_a00d6724)
 *
 * Unpack the header of an MST message chunk.
 * Name basis: proven - nibble-packed link count and address, length, start / end flags and sequence number
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d6724 @ 0xa00d6724-0xa00d6890, -mcpu=v8 -Os -g (leaf).
 * Callers: dp_mst_parse_chunk_header, dp_mst_write_chunk_header, dp_mst_send_up_message_step and
 * dp_mst_trim_up_message_record.
 * Source form: byte-wide bit-fields copied field by field (each copy is a separate load/and/or/store). Bit-fields
 * are listed from the top bit down.
 */
struct mst_header_byte0 { unsigned char count : 4; unsigned char low_nibble : 4; };
struct mst_header_byte_0x11 { unsigned char bit7 : 1; unsigned char bit6 : 1; unsigned char low6 : 6; };
struct mst_header_byte_0x12 { unsigned char bit7 : 1; unsigned char bit6 : 1; unsigned char bit5_kept : 1; unsigned char bit4 : 1; unsigned char low4 : 4; };
/* Unpacked header, 24 bytes: byte 0, then one nibble per byte, then the two flag bytes at +0x11 and +0x12. */
struct mst_header { struct mst_header_byte0 byte0; unsigned char nibbles[16]; struct mst_header_byte_0x11 byte_0x11; struct mst_header_byte_0x12 byte_0x12; unsigned char pad[5]; };

/* Unpack the header of a message chunk from `packed` into `header`. Byte 0 is copied as its two nibbles.
 * The high nibble (count) gives count - 1 nibbles that follow in packed[1..], two per byte with the high
 * nibble first; they go one per byte into header->nibbles (the other entries are cleared). The two bytes
 * after them (at packed[off + 1] and packed[off + 2], off = (count - 1) / 2 rounded up) are copied field
 * by field into header->byte_0x11 and header->byte_0x12 (bit 5 of byte_0x12 is left as it was). */
void dp_mst_unpack_header(struct mst_header *header, unsigned char *packed)
{
    unsigned char i, off;
    int k;
    struct mst_header_byte_0x11 *p11;
    struct mst_header_byte_0x12 *p12;

    for (i = 0; i <= 0xf; i++)
        header->nibbles[i] = 0;
    header->byte0.count = ((struct mst_header_byte0 *)packed)->count;
    header->byte0.low_nibble = ((struct mst_header_byte0 *)packed)->low_nibble;
    k = header->byte0.count - 1;
    off = k / 2;
    if (k & 1)
        off = k / 2 + 1;
    for (i = 0; i < header->byte0.count - 1; i++) {
        if ((i & 1) == 0)
            header->nibbles[i] = packed[1 + (i >> 1)] >> 4;
        else
            header->nibbles[i] = packed[1 + (i >> 1)] & 0xf;
    }
    p11 = (struct mst_header_byte_0x11 *)&packed[off + 1];
    p12 = (struct mst_header_byte_0x12 *)&packed[off + 2];
    header->byte_0x11.bit7 = p11->bit7;
    header->byte_0x11.bit6 = p11->bit6;
    header->byte_0x11.low6 = p11->low6;
    header->byte_0x12.bit7 = p12->bit7;
    header->byte_0x12.bit6 = p12->bit6;
    header->byte_0x12.bit4 = p12->bit4;
    header->byte_0x12.low4 = p12->low4;
}

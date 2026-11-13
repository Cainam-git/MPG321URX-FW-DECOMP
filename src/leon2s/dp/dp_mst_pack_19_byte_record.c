/* dp_mst_pack_19_byte_record  (FUN_a00d7648)
 *
 * Pack the 19-byte descriptor into the byte stream of an MST reply.
 * Name basis: descriptive - header fields masked; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * FUN_a00d7648 (leon2s 0xa00d7648-0xa00d76ac, 100 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The source header is read through bit-fields (big-endian: the first field is the most significant bit).
 * Source form: every output byte is appended as 'out[pos++] = ...', the last one (0xa00d76a8) included; the
 * post-increment of the last append gives the running index its own register copy (%o4 beside %o5,
 * 0xa00d7664).
 */
struct record19_head {
    unsigned char bit7_of_byte0 : 1;
    unsigned char low7_of_byte0 : 7;
    unsigned char high_nibble_of_byte1 : 4;
    unsigned char low_nibble_of_byte1 : 4;
};

/* Pack the 19-byte record `src` into the byte stream `out` (19 bytes): out[0] = low 7 bits of src byte 0,
 * out[1] = high nibble of src byte 1 (in the high nibble), out[2..17] = src bytes 2..17, out[18] = low 7
 * bits of src byte 0x12. Called from dp_mst_send_reply. */
void dp_mst_pack_19_byte_record(struct record19_head *src, unsigned char *out)
{
    unsigned char i;
    unsigned char pos;
    unsigned char *bytes = (unsigned char *)src;

    pos = 0;
    out[pos++] = src->low7_of_byte0;
    out[pos++] = src->high_nibble_of_byte1 << 4;
    for (i = 0; i < 16; i++)
        out[pos++] = bytes[i + 2];
    out[pos++] = bytes[0x12] & 0x7f;
}

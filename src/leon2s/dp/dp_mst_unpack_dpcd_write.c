/* dp_mst_unpack_dpcd_write  (FUN_a00d6e94)
 *
 * Unpack the remote DPCD write fields from a received MST message.
 * Name basis: derived - port, address, count and the data bytes; body offset from the header length nibble;
 *   called from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * FUN_a00d6e94 (leon2s 0xa00d6e94-0xa00d6f70, 220 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: big-endian bit-fields for word 0 (first field = most significant bit), two separate
 * read-modify-writes of word 0; the copy loop reads out->count as its limit and indexes src with
 * body_start + i + 8.
 */
/* Output record of the remote DPCD write unpack: word 0 holds the 7-bit field at bits 24..30 and the
 * 4-bit field at bits 20..23, word 1 a 20-bit value, then the byte count and the data bytes. */
struct dpcd_write_fields {
    unsigned int bit31 : 1, field_24_30 : 7, field_20_23 : 4, rest : 20;
    unsigned int value_20bit;
    unsigned char count;
    unsigned char data[];
};

/* Unpack the remote DPCD write fields from the body of the received chunk `src` into `out`.
 * With body_start = ((src[0] >> 4) - 1) / 2 rounded up and p = src + body_start:
 *   field_24_30 = p[3] & 0x7f,  field_20_23 = high nibble of p[4],
 *   value_20bit = (p[4] & 0xf) << 16 | p[5] << 8 | p[6],  count = p[7],
 *   data[0 .. count - 1] = p[8 ...].
 * Called from dp_mst_parse_request. */
void dp_mst_unpack_dpcd_write(struct dpcd_write_fields *out, unsigned char *src)
{
    int nibbles = (src[0] >> 4) - 1;
    unsigned char body_start = nibbles / 2;
    unsigned char *p;
    unsigned char i;

    if (nibbles & 1)
        body_start = nibbles / 2 + 1;
    p = src + body_start;
    out->field_24_30 = p[3] & 0x7f;
    out->field_20_23 = p[4] >> 4;
    out->value_20bit = ((p[4] & 0xf) << 16) | (p[5] << 8) | p[6];
    out->count = p[7];
    for (i = 0; i < out->count; i++)
        out->data[i] = src[body_start + i + 8];
}

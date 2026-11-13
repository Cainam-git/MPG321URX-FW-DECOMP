/* dp_mst_unpack_19_byte_record  (FUN_a00d6b98)
 *
 * Unpack the 19-byte record from a received MST message.
 * Name basis: descriptive - masked header fields in the first bytes; body offset from the header length
 *   nibble; called from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * FUN_a00d6b98 (leon2s, 0xa00d6b98-0xa00d6c98, 256 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Same code shape as dp_mst_unpack_10_byte_record. src[n + 0x15] is re-read for each of the dst[0x12] fields
 * (dst[0x12] is kept in a register).
 * Forms: the masked source byte of the 0x7f, 0xf0, 0x40 and 0x07 fields is a u32 temp in its own declaration
 * (src-before-dst operand order); the 0x20 / 0x10 / 0x08 fields are plain expressions.
 */
/* Unpack a 19-byte record from the body of the received chunk `src` into `dst`. The body starts at
 * src[body_start + 3], with body_start = ((src[0] >> 4) - 1) / 2 rounded up. Fields of dst: byte 0 takes
 * the low 7 bits of body byte 0 (bit 7 kept), byte 1 takes the high nibble of body byte 1 (low nibble
 * kept), bytes 2..17 are body bytes 2..17, and the five flag fields of byte 0x12 (mask 0x40, 0x20, 0x10,
 * 0x08, 0x07) come from the same bits of body byte 18. Called from dp_mst_parse_request. */
void dp_mst_unpack_19_byte_record(unsigned char *dst, unsigned char *src)
{
    int nibbles;
    unsigned char body_start, i;

    nibbles = (src[0] >> 4) - 1;
    body_start = nibbles / 2;
    if (nibbles & 1)
        body_start = nibbles / 2 + 1;
    { unsigned int t = src[body_start + 3] & 0x7f; dst[0] = (dst[0] & 0x80) | t; }
    { unsigned int t = src[body_start + 4] & 0xf0; dst[1] = (dst[1] & 0x0f) | t; }
    for (i = 0; i < 16; i++)
        dst[i + 2] = src[body_start + i + 5];
    { unsigned int t = src[body_start + 0x15] & 0x40; dst[0x12] = (dst[0x12] & 0xbf) | t; }
    dst[0x12] = (dst[0x12] & 0xdf) | (src[body_start + 0x15] & 0x20);
    dst[0x12] = (dst[0x12] & 0xef) | (src[body_start + 0x15] & 0x10);
    dst[0x12] = (dst[0x12] & 0xf7) | (src[body_start + 0x15] & 0x08);
    { unsigned int t = src[body_start + 0x15] & 0x07; dst[0x12] = (dst[0x12] & 0xf8) | t; }
}

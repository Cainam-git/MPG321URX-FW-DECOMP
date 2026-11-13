/* dp_mst_unpack_10_byte_record  (FUN_a00d72d8)
 *
 * Unpack the 10-byte record from a received MST message.
 * Name basis: descriptive - masks 0x7F, 0xC0 and 0x04 on some bytes; body offset from the header length
 *   nibble; called from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * FUN_a00d72d8 (leon2s, 0xa00d72d8-0xa00d73b4, 220 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Same code shape as dp_mst_unpack_19_byte_record. src[body_start + 0xc] is re-read for each dst[9] field
 * (dst[9] is kept in a register).
 * Forms: the masked source byte of the 0x7f, 0xc0 and 0x04 fields is a u32 temp in its own declaration (fw
 * 'and 0xc0' instead of QImode 'and -64', and the src-before-dst operand order); the 0x20 / 0x18 fields are
 * plain expressions.
 */
/* Unpack a 10-byte record from the body of the received chunk `src` into `dst`. The body starts at
 * src[body_start + 3], with body_start = ((src[0] >> 4) - 1) / 2 rounded up. dst[0] takes the low 7 bits of
 * body byte 0 (bit 7 kept), dst[1] body byte 1, dst[2..8] body bytes 2..8, and the four fields of dst[9]
 * (masks 0xc0, 0x20, 0x18, 0x04) come from the same bits of body byte 9. Called from
 * dp_mst_parse_request for request 0x38. */
void dp_mst_unpack_10_byte_record(unsigned char *dst, unsigned char *src)
{
    int nibbles;
    unsigned char body_start, i;

    nibbles = (src[0] >> 4) - 1;
    body_start = nibbles / 2;
    if (nibbles & 1)
        body_start = nibbles / 2 + 1;
    { unsigned int t = src[body_start + 3] & 0x7f; dst[0] = (dst[0] & 0x80) | t; }
    dst[1] = src[body_start + 4];
    for (i = 0; i < 7; i++)
        dst[i + 2] = src[body_start + i + 5];
    { unsigned int t = src[body_start + 0xc] & 0xc0; dst[9] = (dst[9] & 0x3f) | t; }
    dst[9] = (dst[9] & 0xdf) | (src[body_start + 0xc] & 0x20);
    dst[9] = (dst[9] & 0xe7) | (src[body_start + 0xc] & 0x18);
    { unsigned int t = src[body_start + 0xc] & 4; dst[9] = (dst[9] & 0xfb) | t; }
}

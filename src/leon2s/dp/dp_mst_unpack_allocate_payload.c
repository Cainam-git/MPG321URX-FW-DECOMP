/* dp_mst_unpack_allocate_payload  (FUN_a00d6cfc)
 *
 * Unpack the payload allocation fields from a received MST message.
 * Name basis: derived - three 16-bit fields: port, stream count / id and payload number; body offset from the
 *   header length nibble; called from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * FUN_a00d6cfc (leon2s, 0xa00d6cfc-0xa00d6dac, 176 bytes, 44 words, leaf).
 * Flags: -mcpu=v8 -Os -g. dst word 0 is kept in a register (three sth). Twin layout of
 * dp_mst_pack_allocate_payload_reply (reverse packing).
 */
/* Unpack the payload allocation fields from the body of the received chunk `src` into the three
 * 16-bit words of `dst`. With p = src + body_start (body_start = ((src[0] >> 4) - 1) / 2 rounded up):
 *   dst[0] bits 8..14 = p[3] & 0x7f, bits 4..7 = p[4] high nibble, bits 0..3 = p[4] low nibble
 *   dst[1] bits 8..14 = p[5] & 0x7f
 *   dst[2] = p[6] << 8 | p[7]
 * Other bits of dst[0] and dst[1] are kept. Called from dp_mst_parse_request. */
void dp_mst_unpack_allocate_payload(unsigned short *dst, unsigned char *src)
{
    unsigned int nibbles;
    short body_start;
    unsigned char *p;

    nibbles = (*src >> 4) - 1;
    body_start = (int)nibbles / 2;
    if ((nibbles & 1) != 0)
        body_start = body_start + 1;
    p = src + (body_start & 0xff);
    *dst = (*dst & 0x80ff) | ((p[3] & 0x7f) << 8);
    *dst = (*dst & 0xff0f) | (p[4] & 0xf0);
    *dst = (*dst & 0xfff0) | (p[4] & 0x0f);
    dst[1] = (dst[1] & 0x80ff) | ((p[5] & 0x7f) << 8);
    dst[2] = (p[6] << 8) | p[7];
}

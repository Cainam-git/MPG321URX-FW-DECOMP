/* dp_mst_unpack_two_byte_fields  (FUN_a00d6c98)
 *
 * Unpack the two packed bytes from a received MST message.
 * Name basis: descriptive - bits merged from two body bytes; body offset from the header length nibble; called
 *   from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d6c98 @ 0xa00d6c98 (-mcpu=v8 -Os -g)
 * Holding the second masked byte in the unsigned int temporary `high_nibble` makes GCC emit and %o5, 0xf0
 * instead of the sign-extended and %o5, -16.
 */
/* Unpack two body bytes of the received chunk `src` into `dst`: dst[0] takes the low 7 bits of body byte 0
 * (bit 7 kept), dst[1] takes the high nibble of body byte 1 (low nibble kept). The body starts at
 * src[body_start + 3], with body_start = ((src[0] >> 4) - 1) / 2 rounded up. Called from
 * dp_mst_parse_request. */
void dp_mst_unpack_two_byte_fields(unsigned char *dst, unsigned char *src)
{
    unsigned int nibbles;
    unsigned char body_start;
    unsigned int high_nibble;

    nibbles = (*src >> 4) - 1;
    body_start = (int)nibbles / 2;
    if ((nibbles & 1) != 0) {
        body_start = body_start + 1;
    }

    *dst = *dst & 0x80 | src[(body_start & 0xff) + 3] & 0x7f;

    high_nibble = src[(body_start & 0xff) + 4] & 0xf0;
    dst[1] = (dst[1] & 0xf) | high_nibble;
}

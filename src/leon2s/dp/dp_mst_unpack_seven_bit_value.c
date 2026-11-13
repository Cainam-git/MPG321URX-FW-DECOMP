/* dp_mst_unpack_seven_bit_value  (FUN_a00d6dac)
 *
 * Unpack the 7-bit value from a received MST message.
 * Name basis: descriptive - dst = (dst & 0x80) | (body & 0x7F); body offset from the header length nibble;
 *   called from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d6dac @ 0xa00d6dac (-mcpu=v8 -Os -g)
 * Same offset rule as dp_mst_unpack_dpcd_write. The mask of the destination byte is written as -128 in a
 * separate statement (source form kept for the exact build).
 */
/* Unpack the first body byte of the received chunk `src` into `dst`: low 7 bits of the body byte, bit 7
 * of *dst kept. The body starts at src[body_start + 3], with body_start = ((src[0] >> 4) - 1) / 2
 * rounded up. Called from dp_mst_parse_request. */
void dp_mst_unpack_seven_bit_value(unsigned char *dst, unsigned char *src)
{
    unsigned int nibbles;
    unsigned char body_start;
    unsigned char old_value, body_byte;

    nibbles = (*src >> 4) - 1;
    body_start = (int)nibbles / 2;
    if ((nibbles & 1) != 0) {
        body_start = body_start + 1;
    }
    body_byte = src[(body_start & 0xff) + 3];
    old_value = *dst;
    body_byte = body_byte & 0x7f;
    old_value = old_value & -128;
    old_value = old_value | body_byte;
    *dst = old_value;
}

/* ddc_tool_calc_checksum  (FUN_a00d0f68)
 *
 * Return the XOR checksum of a factory tool message.
 *   p: message
 *   x: seed
 * Returns: checksum
 * Note: Uncalled copy of the helper inlined in the tool replies (length from byte 1).
 * Name basis: derived - XOR over (p[1] & 0x7F) + 2 bytes, seed 0x50 at the callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d0f68 (0xa00d0f68-0xa00d0fa0, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: an unsigned int count and an unsigned char loop counter.
 */

#define DDC_LENGTH_MASK 0x7f                    /* byte 1 & this = the number of bytes that follow byte 1 */

/*
 * XOR the seed with message bytes 0 .. (p[1] & 0x7F) + 1 and return the result.
 *
 *   p  the message; byte 1 is its length byte (0x80 + the number of bytes behind it, see DDC_LENGTH_BYTE)
 *   x  the seed; the tool replies use 0x50 (DDC_CHECKSUM_SEED)
 *
 * The checksum covers every byte in front of the place where the caller stores it. Nothing calls this copy;
 * the tool replies carry inlined copies.
 */
unsigned char ddc_tool_calc_checksum(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & DDC_LENGTH_MASK) + 2;
    unsigned char i;

    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}

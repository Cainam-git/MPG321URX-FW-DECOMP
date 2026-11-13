/* dp_mst_pack_header  (FUN_a00d68cc)
 *
 * Pack the header of an MST message chunk and add its 4-bit checksum.
 * Returns: header length
 * Name basis: proven - header fields into bytes, CRC over the header nibbles
 *
 * Matching notes
 * --------------
 * FUN_a00d68cc (leon2s 0xa00d68cc-0xa00d6a54, 392 bytes), flags -mcpu=v8 -Os -g.
 * Source form: crc updated in place ('crc <<= 1; ...; if (crc & 0x10) crc ^= 0x13;'), the bit counter reused
 * for the four trailing bits, final 'p[2] = crc | p[2]'.
 */
/* Packs the header of a message chunk and adds a 4-bit check value.
 *
 * src[0] is copied to dst[0]; its high nibble is the number of nibbles (count) that follow in src[1..count].
 * Those nibbles are packed two per byte from dst[1], the even-numbered one in the high nibble. n is half of
 * (count - 1), rounded up; the packed bytes end at dst[n] (with an odd count the last nibble is stored in
 * dst[n + 1] and is overwritten by the next store). Then dst[n + 1] = src[0x11] and
 * dst[n + 2] = src[0x12] & 0xd0. The low nibble of dst[n + 2] receives the check value: a 4-bit CRC with
 * polynomial 0x13, computed over the first (n * 2 + 5) * 4 bits of dst (most significant bit first) followed by
 * four zero bits.
 *
 * src: unpacked header (nibble per byte). dst: packed header. Returns the packed length n + 3. Called by
 * dp_mst_queue_chunk, dp_mst_write_chunk_header and dp_mst_trim_up_message_record.
 */
unsigned char dp_mst_pack_header(unsigned char *src, unsigned char *dst)
{
    int count_less_one;
    unsigned char n, i, j, k, mask;
    unsigned short bits;
    unsigned short shift;
    unsigned char crc;
    unsigned char *p;

    dst[0] = src[0];
    count_less_one = (src[0] >> 4) - 1;
    n = count_less_one / 2;
    if (count_less_one & 1)
        n = count_less_one / 2 + 1;
    j = 1;
    for (i = 0; i < (src[0] >> 4); i++) {
        if (i & 1) {
            dst[j] |= src[i + 1];
            j++;
        } else
            dst[j] = src[i + 1] << 4;
    }
    p = dst + n;
    p[1] = src[0x11];
    { unsigned int t2 = src[0x12] & 0xd0; p[2] = t2; }
    /* CRC over the first bits of dst, most significant bit of each byte first. */
    mask = 0x80;
    shift = 7;
    k = 0;
    bits = (unsigned char)(n * 2 + 5) * 4;
    crc = 0;
    while (bits != 0) {
        crc <<= 1;
        crc |= (dst[k] & mask) >> shift;
        bits--;
        mask >>= 1;
        shift--;
        if (mask == 0) {
            mask = 0x80;
            shift = 7;
            k++;
        }
        if (crc & 0x10)
            crc ^= 0x13;
    }
    /* Four zero bits after the data. */
    bits = 4;
    while (bits != 0) {
        crc <<= 1;
        bits--;
        if (crc & 0x10)
            crc ^= 0x13;
    }
    p[2] = crc | p[2];
    return n + 3;
}

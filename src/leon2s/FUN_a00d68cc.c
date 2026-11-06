/* FUN_a00d68cc (leon2s 0xa00d68cc-0xa00d6a54, 392 bytes), flags -mcpu=v8 -Os -g.
 * Packs src into dst and returns the packed length n + 3. dst[0] = src[0]; the (src[0] >> 4) nibbles src[1..]
 * are packed two per byte from dst[1] (even index in the high nibble); n = half the nibble count minus one,
 * rounded up. dst[n + 1] = src[0x11], dst[n + 2] = src[0x12] & 0xd0. Then a 4-bit CRC (polynomial 0x13) over
 * the first (n * 2 + 5) * 4 bits of dst, most significant bit first, followed by four zero bits, is or-ed into
 * dst[n + 2].
 * Source form: crc updated in place ('crc <<= 1; ...; if (crc & 0x10) crc ^= 0x13;'), the bit counter reused
 * for the four trailing bits, final 'p[2] = crc | p[2]'.
 */
unsigned char FUN_a00d68cc(unsigned char *src, unsigned char *dst)
{
    int v;
    unsigned char n, i, j, k, mask;
    unsigned short bits;
    unsigned short shift;
    unsigned char crc;
    unsigned char *p;

    dst[0] = src[0];
    v = (src[0] >> 4) - 1;
    n = v / 2;
    if (v & 1)
        n = v / 2 + 1;
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

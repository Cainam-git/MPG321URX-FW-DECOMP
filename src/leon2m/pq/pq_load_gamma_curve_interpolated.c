/* pq_load_gamma_curve_interpolated  (FUN_a012ec24)
 *
 * Unpack a curve of 10-bit points, interpolate between them and load it as a gamma table.
 * Name basis: derived - four points between neighbours, eight at the end; written with the gamma table write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012ec24 @ 0xa012ec24-0xa012eeb0 (-mcpu=v8 -O3 -g).
 * Source form: the first byte is read into an unsigned char and then shifted in the 16-bit variable as two
 * statements ('low_bits = c; low_bits >>= 2;'), which gives the firmware's srl / and 0x3f.
 */
extern void pq_gamma_write_primary_lut(int, int, int, unsigned char *);

/*
 * Unpack a curve of 10-bit code points and load it into the primary gamma LUT of one channel.
 *
 *   ch  the channel (0..2)
 *   s   the packed curve (at least 0x140 bytes)
 *
 * The 256 10-bit points are packed five bytes to four points: the first byte of the five holds the low 2 bits of
 * the four points (2 bits each, from the low end up) and the next four bytes hold their high 8 bits. A point
 * value is kept shifted left by 4. For each point b from point 1 to point 254, with a the point before it, four
 * entries (k * b + (4 - k) * a) / 4, k = 0..3, are written (a itself, then three steps towards b). The last
 * point gets 0xF added and is reached in eight steps (k * b + (8 - k) * a) / 8, k = 0..7, of which the eighth is
 * replaced by the last point itself. That makes 1024 entries. Each entry goes to the LUT as the two bytes of the
 * 16-bit value entry << 2, low byte first, written with pq_gamma_write_primary_lut.
 *
 * Caller: pq_load_gamma (gamma number 0x20, once per channel).
 */
void pq_load_gamma_curve_interpolated(unsigned char ch, const unsigned char *s)
{
    unsigned char buf[16];
    unsigned short point[8];
    unsigned short i, k, table_index, low_bits;
    unsigned int prev_point, next_point;

    {
        unsigned char c = s[0];

        prev_point = ((s[1] << 2) + (c & 3)) << 4;
        low_bits = c;
        low_bits >>= 2;
    }
    table_index = 0;    for (i = 2; i < 0x13f; i++) {
        if (i % 5 == 0) {
            /* Start of a fresh five-byte group: take its low-bits byte. */
            low_bits = s[i];
            i++;
        }
        next_point = ((s[i] << 2) + (low_bits & 3)) << 4;
        low_bits >>= 2;
        for (k = 0; k < 4; k++)
            point[k] = (k * next_point + (4 - k) * prev_point) >> 2;
        buf[0] = point[0] << 2;
        buf[1] = point[0] >> 6;
        buf[2] = point[1] << 2;
        buf[3] = point[1] >> 6;
        buf[4] = point[2] << 2;
        buf[5] = point[2] >> 6;
        buf[6] = point[3] << 2;
        buf[7] = point[3] >> 6;
        pq_gamma_write_primary_lut(ch, table_index, 8, buf);
        prev_point = next_point;
        table_index += 4;
    }
    next_point = (((s[0x13f] << 2) + (low_bits & 3)) << 4) + 0xf;
    for (k = 0; k < 8; k++)
        point[k] = (k * next_point + (8 - k) * prev_point) >> 3;
    point[7] = next_point;
    buf[0] = point[0] << 2;
    buf[1] = point[0] >> 6;
    buf[2] = point[1] << 2;
    buf[3] = point[1] >> 6;
    buf[4] = point[2] << 2;
    buf[5] = point[2] >> 6;
    buf[6] = point[3] << 2;
    buf[7] = point[3] >> 6;
    buf[8] = point[4] << 2;
    buf[9] = point[4] >> 6;
    buf[10] = point[5] << 2;
    buf[11] = point[5] >> 6;
    buf[12] = point[6] << 2;
    buf[13] = point[6] >> 6;
    buf[14] = point[7] << 2;
    buf[15] = point[7] >> 6;
    pq_gamma_write_primary_lut(ch, table_index, 16, buf);
}

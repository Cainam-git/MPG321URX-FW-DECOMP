/* FUN_a00cea70 (leon2m 0xa00cea70-0xa00cead4, 100 bytes), flags -mcpu=v8 -O3 -g.
 * Shifts the 8 bits of data (most significant first) into crc: for each bit, crc is shifted left by one and XORed
 * with 0x1021 when the bit shifted out of crc differs from the data bit; returns crc. Called by FUN_a00cfa68,
 * FUN_a00cfacc. Source form: the top bit of crc is taken before the data bit test.
 */
unsigned short FUN_a00cea70(unsigned char data, unsigned short crc)
{
    unsigned short m;

    for (m = 0x80; m != 0; m >>= 1) {
        unsigned int t = crc >> 15;
        unsigned int b = (data & m) != 0;

        crc <<= 1;
        if (t != b)
            crc ^= 0x1021;
    }
    return crc;
}

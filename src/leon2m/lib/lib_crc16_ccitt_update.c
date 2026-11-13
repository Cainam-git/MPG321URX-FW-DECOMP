/* lib_crc16_ccitt_update  (FUN_a00cea70)
 *
 * Add one byte to a CRC-16 (polynomial 0x1021, MSB first)
 *   data: byte
 *   crc: running CRC
 * Returns: new CRC
 * Name basis: proven - polynomial 0x1021 shift loop
 *
 * Matching notes
 * --------------
 * FUN_a00cea70 (leon2m 0xa00cea70-0xa00cead4, 100 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the top bit of crc is taken before the data bit test.
 */
#define CRC16_POLYNOMIAL 0x1021                 /* feedback mask */

/*
 * Feed one byte into a running 16-bit CRC and return the new value.
 *   data: the byte; its bits are taken most significant first.
 *   crc:  the CRC so far.
 * For each bit, crc is shifted left by one and XORed with CRC16_POLYNOMIAL when the bit shifted out of crc differs
 * from the data bit. Callers: ddc_build_crc_reply, ddc_apply_maker_vcp_set.
 */
unsigned short lib_crc16_ccitt_update(unsigned char data, unsigned short crc)
{
    unsigned short mask;

    for (mask = 0x80; mask != 0; mask >>= 1) {
        unsigned int crc_top_bit = crc >> 15;
        unsigned int data_bit = (data & mask) != 0;

        crc <<= 1;
        if (crc_top_bit != data_bit)
            crc ^= CRC16_POLYNOMIAL;
    }
    return crc;
}

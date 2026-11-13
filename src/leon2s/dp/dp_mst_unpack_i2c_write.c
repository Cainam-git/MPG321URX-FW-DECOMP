/* dp_mst_unpack_i2c_write  (FUN_a00d714c)
 *
 * Unpack the remote I2C write fields from a received MST message.
 * Name basis: derived - port, device address, count and the data bytes; body offset from the header length
 *   nibble; called from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * FUN_a00d714c (leon2s 0xa00d714c-0xa00d7210, 196 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the bytes 0..2 of dst are bit-fields (high bits first); the copy loop compares against
 * dst->count.
 */
struct i2c_write_fields {
    unsigned char bit7_of_byte0 : 1;
    unsigned char low7_of_byte0 : 7;
    unsigned char high_nibble_of_byte1 : 4;
    unsigned char low_nibble_of_byte1 : 4;
    unsigned char bit7_of_byte2 : 1;
    unsigned char low7_of_byte2 : 7;
    unsigned char count;
    unsigned char data[];
};

/* Unpack the remote I2C write fields from the body of the received chunk `src` into `dst`. With
 * body_start = ((src[0] >> 4) - 1) / 2 rounded up, from src[body_start + 3] on: low 7 bits of body byte 0
 * into dst byte 0, high nibble of body byte 1 into the high nibble of dst byte 1, low 7 bits of body byte 2
 * into dst byte 2, the count (body byte 3) into dst byte 3, then `count` data bytes into dst byte 4 on.
 * Called from dp_mst_parse_request. */
void dp_mst_unpack_i2c_write(struct i2c_write_fields *dst, unsigned char *src)
{
    int nibbles;
    unsigned char body_start;
    unsigned char i;

    nibbles = (src[0] >> 4) - 1;
    body_start = nibbles / 2;
    if (nibbles & 1)
        body_start = nibbles / 2 + 1;
    dst->low7_of_byte0 = src[body_start + 3];
    dst->high_nibble_of_byte1 = src[body_start + 4] >> 4;
    dst->low7_of_byte2 = src[body_start + 5];
    dst->count = src[body_start + 6];
    for (i = 0; i < dst->count; i++)
        dst->data[i] = src[body_start + i + 7];
}

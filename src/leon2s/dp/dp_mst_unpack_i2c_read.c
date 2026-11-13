/* dp_mst_unpack_i2c_read  (FUN_a00d6f70)
 *
 * Unpack the remote I2C read fields from a received MST message.
 * Name basis: derived - port, the write transactions and the read length, into a 0x1E-byte record; body offset
 *   from the header length nibble; called from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * FUN_a00d6f70 (leon2s 0xa00d6f70-0xa00d714c, 476 bytes), flags -mcpu=v8 -Os -g. Leaf.
 * Source form: the header bytes are read through the running index too ('i = 3; ... i++;'), every read
 * indexes as src[body_start + i] (with i++ where the index advances).
 */
struct mst_low7 { unsigned char bit7 : 1; unsigned char low7 : 7; };
struct i2c_read_byte1 { unsigned char high_nibble : 4; unsigned char bits_2_3 : 2; unsigned char count : 2; };
struct i2c_entry_last { unsigned char bits_5_7 : 3; unsigned char bit4 : 1; unsigned char low_nibble : 4; };
/* One 13-byte entry of the record. */
struct i2c_entry { struct mst_low7 first; unsigned char len; unsigned char data[10]; struct i2c_entry_last last; };
/* The 0x1E-byte record that is filled. */
struct i2c_read_record { struct mst_low7 first; struct i2c_read_byte1 byte1; struct i2c_entry entry[2]; struct mst_low7 byte_0x1c; unsigned char byte_0x1d; };

/* Unpack the remote I2C read fields from the body of the received chunk `src` into `out`. With
 * body_start = ((src[0] >> 4) - 1) / 2 rounded up, the body bytes are read one after the other from
 * src[body_start + 3]:
 *   out->first = low 7 bits of body byte 0
 *   out->byte1 = high nibble and low 2 bits (count) of body byte 1
 *   then `count` entries, each: low 7 bits of a byte, a length byte, that many data bytes, and bit 4 and
 *   the low nibble of one more byte
 *   finally out->byte_0x1c = low 7 bits of the next byte and out->byte_0x1d = the byte after it.
 * Called from dp_mst_parse_request. */
void dp_mst_unpack_i2c_read(struct i2c_read_record *out, unsigned char *src)
{
    unsigned char body_start, e, m;
    unsigned short i;
    int nibbles, half;

    nibbles = (src[0] >> 4) - 1;
    half = nibbles / 2;
    body_start = half;
    if (nibbles & 1)
        body_start = half + 1;
    i = 3;
    out->first.low7 = ((struct mst_low7 *)&src[body_start + i])->low7;
    i++;
    out->byte1.high_nibble = ((struct i2c_read_byte1 *)&src[body_start + i])->high_nibble;
    out->byte1.count = ((struct i2c_read_byte1 *)&src[body_start + i])->count;
    i++;
    for (e = 0; e < out->byte1.count; e++) {
        out->entry[e].first.low7 = ((struct mst_low7 *)&src[body_start + i++])->low7;
        out->entry[e].len = src[body_start + i++];
        for (m = 0; m < out->entry[e].len; m++)
            out->entry[e].data[m] = src[body_start + i++];
        out->entry[e].last.bit4 = ((struct i2c_entry_last *)&src[body_start + i])->bit4;
        out->entry[e].last.low_nibble = ((struct i2c_entry_last *)&src[body_start + i])->low_nibble;
        i++;
    }
    out->byte_0x1c.low7 = ((struct mst_low7 *)&src[body_start + i++])->low7;
    out->byte_0x1d = src[body_start + i];
}

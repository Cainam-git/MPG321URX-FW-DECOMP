/* dp_mst_pack_24_byte_record  (FUN_a00d787c)
 *
 * Pack the 24-byte record into the byte stream of an MST reply.
 * Name basis: descriptive - first three bytes masked, the rest copied unchanged; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * FUN_a00d787c (leon2s 0xa00d787c-0xa00d78d8, 92 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: bytes 1 and 2 are masked in an unsigned int temporary in separate statements (firmware
 * 'and 0xf8' / 'and 0xf9'); a direct 'dst = src & 0xf8' is narrowed to a QImode and with the
 * sign-extended constant (-8 / -7). Byte 0 (0x7f) is the same either way.
 */
/*
 * Copy a 24-byte record to the byte stream of a reply, keeping only some bits of its first three bytes:
 * byte 0 keeps bits 0..6, byte 1 keeps bits 3..7 (mask 0xf8) and byte 2 keeps bits 0 and 3..7 (mask 0xf9).
 * Bytes 3..23 are copied unchanged.
 *
 * Called by dp_mst_send_reply for the reply type 0x38 (QUERY_STREAM_ENC_STATUS), whose reply is 24 bytes long.
 */
void dp_mst_pack_24_byte_record(unsigned char *record, unsigned char *out)
{
    unsigned char i;
    unsigned int masked;

    *out = *record & 0x7f;
    masked = record[1];
    masked &= 0xf8;
    out[1] = masked;
    masked = record[2];
    masked &= 0xf9;
    out[2] = masked;
    out[3] = record[3];

    i = 0;
    do {
        out[(i & 0xff) + 4] = record[(i & 0xff) + 4];
        i = i + 1;
    } while ((i & 0xff) <= 0x13);
}

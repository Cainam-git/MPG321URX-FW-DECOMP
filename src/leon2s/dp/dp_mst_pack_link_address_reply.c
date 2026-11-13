/* dp_mst_pack_link_address_reply  (FUN_a00d74ec)
 *
 * Pack the link address reply into the byte stream of an MST reply.
 * Name basis: proven - header, the 16-byte id and up to 15 port entries of 20 bytes; called from
 *   dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d74ec @ 0xa00d74ec-0xa00d7638, -mcpu=v8 -Os -g.
 * Source form: the kept bits are written as (byte1 >> 5) << 5 and (byte1 >> 6) << 6 (the firmware masks in a
 * word register: and 0xe0 / 0xc0, not the byte constants -32 / -64); the clear-bit arm comes first; the entry
 * count is compared unsigned.
 */
/* One 20-byte port entry of the reply record. */
struct link_address_entry { unsigned char byte0; unsigned char byte1; unsigned char byte2; unsigned char data16[16]; unsigned char last; };
/* Reply record: a header byte, a 16-byte block, the entry count in the low nibble of `count`, then the
 * entries (starting at +0x12). */
struct link_address_reply { unsigned char header; unsigned char block16[16]; unsigned char count; struct link_address_entry entry[1]; };

/* Pack the link address reply `reply` into the byte stream `out`: header & 0x7f, the 16-byte block,
 * count & 0xf, then for each of the `count` entries: byte0; when bit 7 of byte0 is clear, the top 3 bits of
 * byte1, byte2, the 16 data bytes and the last byte; when it is set, only the top 2 bits of byte1.
 * Called from dp_mst_send_reply. */
void dp_mst_pack_link_address_reply(struct link_address_reply *reply, unsigned char *out)
{
    unsigned char i, entry_index, pos;

    out[0] = reply->header & 0x7f;
    pos = 1;
    for (i = 0; i <= 0xf; i++)
        out[pos++] = reply->block16[i];
    out[pos++] = reply->count & 0xf;
    for (entry_index = 0; entry_index < (reply->count & 0xfU); entry_index++) {
        out[pos++] = reply->entry[entry_index].byte0;
        if ((reply->entry[entry_index].byte0 >> 7) == 0) {
            out[pos++] = (reply->entry[entry_index].byte1 >> 5) << 5;
            out[pos++] = reply->entry[entry_index].byte2;
            for (i = 0; i <= 0xf; i++)
                out[pos++] = reply->entry[entry_index].data16[i];
            out[pos++] = reply->entry[entry_index].last;
        } else {
            out[pos++] = (reply->entry[entry_index].byte1 >> 6) << 6;
        }
    }
}

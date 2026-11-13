/* dp_mst_queue_chunk  (FUN_a00d6a54)
 *
 * Pack a chunk header and store it in the reply header ring (queue 1) or the forward ring (queue 3).
 * Name basis: derived - queue chosen by type 1 or 3
 *
 * Matching notes
 * --------------
 * FUN_a00d6a54 (leon2s 0xa00d6a54-0xa00d6b4c, 248 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: switch on queue; the counter is set to 0 before the n != 0 test of each case and the copy is
 * a do-while; the destination pointer is a local of each case block; the first destination is written as
 * byte offsets with entry * 11 first.
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_reply_write_indexes[];
extern unsigned char dp_mst_message_state_fwd_write_index;
extern unsigned char dp_mst_reply_header_entries[][16][11];
extern unsigned char dp_mst_forward_rows[][0x30];
extern int dp_mst_pack_header(void *msg, unsigned char *out);

/* Pack the header `msg` (dp_mst_pack_header) and store the packed bytes in a queue entry:
 *   queue 1: dp_mst_reply_header_entries, entry [write index of the current port] of the 11-byte entries of the current
 *            port (0xb0 bytes per port);
 *   queue 3: dp_mst_forward_rows, the 0x30-byte record selected by the forward write index & 0xf.
 * Other values of `queue` store nothing. `unused` is not used (callers pass it). */
void dp_mst_queue_chunk(void *msg, unsigned char queue, int unused)
{
    unsigned char buf[16];
    unsigned char n;
    unsigned char i;

    n = dp_mst_pack_header(msg, buf);
    switch (queue) {
    case 1:
        i = 0;
        if (n != 0) {
            unsigned char *dst = (unsigned char *)dp_mst_reply_header_entries + dp_mst_message_state_reply_write_indexes[dp_mst_message_state_port] * 11 + dp_mst_message_state_port * 0xb0;
            do {
                dst[i] = buf[i];
                i++;
            } while (i < n);
        }
        break;
    case 3:
        i = 0;
        if (n != 0) {
            unsigned char *dst = dp_mst_forward_rows[dp_mst_message_state_fwd_write_index & 0xf];
            do {
                dst[i] = buf[i];
                i++;
            } while (i < n);
        }
        break;
    }
}

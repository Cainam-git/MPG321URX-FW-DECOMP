/* dp_mst_pack_dpcd_read_reply  (FUN_a00d7744)
 *
 * Pack the remote DPCD read reply into the byte stream of an MST reply.
 * Name basis: derived - port, count and the data bytes; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d7744 @ 0xa00d7744 (-mcpu=v8 -Os -g)
 * The data bytes are copied with an unsigned char counter (the count src[2] is re-read each round).
 */
extern void *memcpy(void *dest, const void *src, unsigned int n); // not used, but for reference

/* Pack the remote DPCD read reply `src` into the byte stream `out`: out[0] = src[0] & 0x7f,
 * out[1] = src[1] & 0xf, out[2] = count = src[2], then `count` data bytes src[3..] to out[3..].
 * Called from dp_mst_send_reply. */
void dp_mst_pack_dpcd_read_reply(unsigned char *src, unsigned char *out)
{
    unsigned char i;
    unsigned char i_copy;

    *out = *src & 0x7f;
    out[1] = src[1] & 0xf;
    out[2] = src[2];

    if (src[2] != 0) {
        i = 0;
        do {
            out[(unsigned char)i + 3] = src[(unsigned char)i + 3];
            i = i + 1;
            i_copy = (unsigned short)i;
        } while ((unsigned char)i_copy < src[2]);
    }
}

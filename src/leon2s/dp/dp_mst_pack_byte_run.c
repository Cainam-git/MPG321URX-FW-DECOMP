/* dp_mst_pack_byte_run  (FUN_a00d78d8)
 *
 * Pack the run of bytes into the byte stream of an MST reply.
 * Name basis: descriptive - byte copy loop with an 8-bit counter; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d78d8 @ 0xa00d78d8 (-mcpu=v8 -Os -g)
 * The loop keeps `i` as the counter, masks it with `& 0xff` at each use (matching the `and %o3, 0xff, %g1`),
 * and compares the masked value against 0x10 (matching `cmp %o5, 0xf; bleu`). The store happens before the
 * increment, putting the `stb` in the branch delay slot as the target shows.
 */
extern void dp_mst_pack_byte_run(unsigned char *param_1, unsigned char *param_2);
/*
 * Copy 19 bytes (0..0x12) to the byte stream of a reply without changing them.
 *
 * Called by dp_mst_send_reply for the reply type 0xf. The only caller of that type is dp_mst_send_nak,
 * which sends exactly 19 bytes.
 */
void dp_mst_pack_byte_run(unsigned char *src, unsigned char *out)
{
    unsigned char i;
    unsigned char value;

    *out = *src;
    i = 0;
    do {
        value = src[(i & 0xff) + 1];
        out[(i & 0xff) + 1] = value;
        i = i + 1;
    } while ((i & 0xff) < 0x10);
    out[0x11] = src[0x11];
    out[0x12] = src[0x12];
    return;
}

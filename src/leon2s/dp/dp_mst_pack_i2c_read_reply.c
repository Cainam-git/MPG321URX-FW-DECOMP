/* dp_mst_pack_i2c_read_reply  (FUN_a00d77c4)
 *
 * Pack the remote I2C read reply into the byte stream of an MST reply.
 * Name basis: derived - three header bytes, then the data bytes; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d77c4 @ 0xa00d77c4 (-mcpu=v8 -Os -g)
 * The loop counter is a byte that is masked with 0xFF after each increment.
 */
typedef unsigned char byte;

/* Pack the remote I2C read reply `in` into the byte stream `out`: out[0] = in[0] & 0x7f,
 * out[1] = in[1] & 0xf, out[2] = count = in[2], then `count` data bytes in[3..] to out[3..].
 * Called from dp_mst_send_reply. */
void dp_mst_pack_i2c_read_reply(byte *in, byte *out)
{
    byte unused;
    byte i;
    
    *out = *in & 0x7f;
    out[1] = in[1] & 0xf;
    out[2] = in[2];
    
    i = 0;
    if (in[2] != 0) {
        do {
            out[i + 3] = in[i + 3];
            i++;
            i = i & 0xff;
        } while (i < in[2]);
    }
    return;
}

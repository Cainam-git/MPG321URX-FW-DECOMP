/* dp_mst_pack_allocate_payload_reply  (FUN_a00d76f4)
 *
 * Pack the payload allocation reply into the byte stream of an MST reply.
 * Name basis: derived - port, stream id and payload number in five bytes; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * FUN_a00d76f4 (leon2s, 0xa00d76f4-0xa00d7734, 64 bytes, 16 words, leaf).
 * Flags: -mcpu=v8 -Os -g. Each word is re-read with lduh.
 * Source form: byte 1 is written as the nibble moved back into place '((w0 >> 4 & 0xf) << 4)'; the plain
 * mask '(u8)(w0 & 0xf0)' gives 'and %g1,-16' (QImode constant), the firmware has 'and 0xf0'.
 */
/* Pack the three 16-bit words of `src` into five bytes of `out`: out[0] = bits 8..14 of word 0,
 * out[1] = bits 4..7 of word 0 (kept in place), out[2] = word 1 >> 9, out[3..4] = word 2 (high byte
 * first). Reverse of dp_mst_unpack_allocate_payload. Called from dp_mst_send_reply. */
void dp_mst_pack_allocate_payload_reply(unsigned short *src, unsigned char *out)
{
    unsigned int word;
    word = src[0];
    out[0] = (unsigned char)((word >> 8) & 0x7f);
    word = src[0];
    out[1] = (unsigned char)((word >> 4 & 0xf) << 4);
    word = src[1];
    out[2] = (unsigned char)(word >> 9);
    word = src[2];
    out[3] = (unsigned char)(word >> 8);
    word = src[2];
    out[4] = (unsigned char)word;
}

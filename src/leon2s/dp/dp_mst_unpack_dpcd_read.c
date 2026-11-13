/* dp_mst_unpack_dpcd_read  (FUN_a00d6df8)
 *
 * Unpack the remote DPCD read fields from a received MST message.
 * Name basis: derived - port, 20-bit address and byte count; body offset from the header length nibble; called
 *   from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d6df8 @ 0xa00d6df8..0xa00d6e94 (156 bytes, 39 words)
 * Flags: -mcpu=v8 -Os -g. The second mask is 0xff0fffff (firmware andn sethi 0xf00000 = clears only bits
 * 20..23).
 */
/* Unpack the remote DPCD read fields from the body of the received chunk `src` into `dst` (words).
 * With k = body_start = ((src[0] >> 4) - 1) / 2 rounded up:
 *   dst[0] bits 24..30 = src[k+3] & 0x7f,  bits 20..23 = high nibble of src[k+4]  (other bits kept)
 *   dst[1] = (src[k+4] & 0xf) << 16 | src[k+5] << 8 | src[k+6]  (a 20-bit value)
 *   byte 8 of dst = src[k+7]
 * Called from dp_mst_parse_request. */
void dp_mst_unpack_dpcd_read(unsigned int *dst, unsigned char *src)
{
    int nibbles;
    unsigned char body_start;
    unsigned int unused;
    
    nibbles = (*src >> 4) - 1;
    body_start = (int)nibbles / 2;
    if ((nibbles & 1) != 0) {
        body_start = body_start + 1;
    }
    body_start = body_start & 0xff;
    *dst = (*dst & 0x80ffffff) | ((src[body_start + 3] & 0x7f) << 0x18);
    *dst = (*dst & 0xff0fffff) | ((src[body_start + 4] >> 4) << 0x14);
    dst[1] = (src[body_start + 4] & 0xf) << 0x10 | (src[body_start + 5] << 8) |
                 src[body_start + 6];
    *(unsigned char *)(dst + 2) = src[body_start + 7];
    return;
}

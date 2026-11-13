/* lib_unpack_longs_to_bytes  (FUN_CODE_8072)
 *
 * Unpack 32-bit words into bytes, most significant byte first.
 *   out: bytes
 *   words
 *   byte_count
 * Name basis: proven - code: (n + 3) / 4 words to bytes
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_8072 @ 0x8072..0x81a9 (311 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: words[i] is read once per byte (four ?C?LLDOPTR calls per word); both pointers are generic.
 */
/*
 * lib_unpack_longs_to_bytes - unpack 32-bit words into bytes, most significant byte first
 * (out[4i] = bits 31..24 of words[i], ..., out[4i + 3] = bits 7..0).
 *   out         receives the bytes
 *   words       the words
 *   byte_count  number of bytes wanted; it is rounded up to whole words, so up to three bytes more are written
 * Only caller: ipc_run_message.
 */
void lib_unpack_longs_to_bytes(unsigned char *out, unsigned long *words, unsigned int byte_count)
{
    unsigned char i;
    unsigned char word_count;

    word_count = (byte_count + 3) >> 2;
    for (i = 0; i < word_count; i++) {
        out[i * 4] = words[i] >> 24;
        out[i * 4 + 1] = words[i] >> 16;
        out[i * 4 + 2] = words[i] >> 8;
        out[i * 4 + 3] = words[i];
    }
}

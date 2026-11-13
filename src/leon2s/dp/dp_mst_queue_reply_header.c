/* dp_mst_queue_reply_header  (FUN_a00d9524)
 *
 * Build the reply header from a received message header and store it in the reply header ring.
 * Note: Count 1 / low nibble 0, or low nibble = count - low nibble - 1; length, start and end flag cleared.
 * Name basis: derived - copies the 0x13-byte header, rewrites the count nibbles, calls dp_mst_queue_chunk with
 *   queue 1 (reply header entries); dp_mst_receive_task calls dp_mst_dispatch_request right after it
 *
 * Matching notes
 * --------------
 * FUN_a00d9524 (leon2s 0xa00d9524-0xa00d95e4, 192 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: big-endian bit-fields in a union (first field = most significant bit); low_nibble and count
 * are copied into unsigned int locals for the compare (unsigned bcs); src is read as a byte of two 4-bit
 * bit-fields (ldub, and 0xff, srl 4 / and 0xf); the count = 1 arm is written first.
 */
extern void *lib_memcpy(void *, const void *, unsigned int);
extern void dp_mst_queue_chunk(union Msg *, int, int);
/* The unpacked header (24 bytes, as written by dp_mst_unpack_header). Word 0 starts with byte 0 = count
 * (high nibble) and low nibble. Word 4 holds the flag bytes: byte +0x11 (bit 7, bit 6, length in bits 0..5) and
 * byte +0x12 (start flag bit 7, end flag bit 6, bits 5 and 4, low 4 bits). */
union chunk_header {
    struct {
        unsigned int count : 4, low_nibble : 4, rest : 24;
        unsigned int w1, w2, w3;
        unsigned int byte_0x10 : 8, byte_0x11_bit7 : 1, byte_0x11_bit6 : 1, length : 6;
        unsigned int start_flag : 1, end_flag : 1, byte_0x12_bit5 : 1, byte_0x12_bit4 : 1, byte_0x12_low4 : 4, tail : 8;
    } h;
    unsigned char b[0x18];
};
/* Byte 0 of the received header read as its two nibbles. */
struct count_and_low {
    unsigned char count : 4, low : 4;
};

/*
 * Copy the unpacked header `src` (0x13 bytes) into a new header, change its count fields and put it into the
 * reply ring of the current port (dp_mst_queue_chunk, queue 1).
 *
 * When the low nibble of src is not below its count, the new header gets count 1 and low nibble 0. Otherwise
 * the new low nibble is count - low nibble - 1 of src (count unchanged). The length, start flag, end flag and
 * the low 4 bits of byte +0x12 are cleared.
 *
 * Called by dp_mst_receive_task for a message addressed to this device; dp_mst_dispatch_request is called
 * right after it.
 */
void dp_mst_queue_reply_header(struct count_and_low *src)
{
    union chunk_header m;
    unsigned int low_nibble, count;

    lib_memcpy(&m, src, 0x13);
    low_nibble = m.h.low_nibble;
    count = m.h.count;
    if (low_nibble >= count) {
        m.h.count = 1;
        m.h.low_nibble = 0;
    } else {
        m.h.low_nibble = src->count - src->low - 1;
    }
    m.h.length = 0;
    m.h.start_flag = 0;
    m.h.end_flag = 0;
    m.h.byte_0x12_low4 = 0;
    dp_mst_queue_chunk(&m, 1, 1);
}

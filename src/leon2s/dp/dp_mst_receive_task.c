/* dp_mst_receive_task  (FUN_a00d9be4)
 *
 * Take the first chunk of a complete received message, dispatch or pass it on, and skip the message.
 * Name basis: derived - dp_mst_find_message_bounds, header unpack, then dp_mst_dispatch_request or
 *   dp_mst_queue_short_message; read index set behind the last chunk
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d9be4 @ 0xa00d9be4-0xa00d9d50 (364 bytes, 91 words), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - bounds is masked with 0xff (the callee returns a u8; the firmware re-masks it into an unsigned int);
 *  - the 'parsed' flag lives in bit 13 of the word at +16 of the unpacked header; it is cleared at entry by a word
 *    load/andn/store and read back after the call as a 16-bit field at bits 8..23 (srl 8; btst 0x20), so that
 *    word is a union of a plain word and that bit-field;
 *  - lo_nibble and the compare with the high nibble are plain unsigned shifts (with bit-fields the compare
 *    becomes signed 'bl'; the firmware has 'bcs');
 *  - 'kind != 0x80 && kind != 0x40' is the first arm (the firmware ANDs the two '!=' values with btst);
 *  - each of the three copies has its own 0x13-byte buffer, copied with lib_memcpy (returns void *); no volatile.
 */

/* Result of dp_mst_find_message_bounds (see there): bits 5..7 select what to do, bits 0..3 are the slot. */
#define BOUNDS_KIND_MASK     0xe0
#define BOUNDS_NONE_YET      0x80   /* no complete message waiting */
#define BOUNDS_SKIP          0x40   /* the chunks up to the slot are not a message: drop them */
#define HEADER_UNPACKED      0x20   /* bit 5 of header byte +0x12, set by dp_mst_parse_chunk_header */
#define MESSAGE_COPY_BYTES   0x13   /* bytes of the unpacked header that are passed on */

/* The unpacked header of the first waiting chunk (dp_mst_unpack_header). Word 0 holds the two count nibbles
 * of header byte 0. The word at +16 holds, in bits 8..23, the 16-bit field whose bit 0x20 is HEADER_UNPACKED. */
struct Msg {
    unsigned int w0;
    unsigned int w[3];
    union { unsigned int w; struct { unsigned int x:8; unsigned int flags:16; unsigned int y:8; } b; } u4;
};
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_rx_write_indexes[];
extern unsigned char dp_mst_message_state_rx_read_indexes[];
extern unsigned char dp_mst_find_message_bounds(void);
extern void dp_mst_parse_chunk_header(struct Msg *, int, int);
extern void dp_mst_queue_reply_header(unsigned char *);
extern void dp_mst_dispatch_request(void);
extern void dp_mst_queue_short_message(unsigned char *);
extern void dp_mst_append_chunk_to_message(void);
extern void *lib_memcpy(void *, const void *, unsigned int);

/*
 * Handle the chunks the receiver has put in the ring of the current port. Called once per round by dp_mst_task;
 * no parameters, no result.
 *
 * Nothing happens when the ring is empty (write index = read index). Otherwise dp_mst_find_message_bounds
 * returns a slot and a kind:
 *  - kind 0x80: no complete message yet; nothing is done and the read index stays;
 *  - kind 0x40: the chunks up to that slot are dropped: the read index moves behind the slot;
 *  - otherwise the chunk at the read index starts a message that ends at the slot. Its header is unpacked
 *    (nothing more happens, and the read index stays, when no header was unpacked). Then, by the two nibbles of
 *    header byte 0 (lo_nibble = low nibble, hi_nibble = high nibble):
 *      lo_nibble == 0, or lo_nibble >= hi_nibble: the message is for this device. The reply header is queued
 *        (dp_mst_queue_reply_header) and the request is dispatched (dp_mst_dispatch_request). For
 *        lo_nibble >= hi_nibble on port 0 the message is also passed on, like the next case; on another port the
 *        routine goes on to the last step;
 *      otherwise the message is passed on to the output: its header with the count lowered by one goes into the
 *        forward ring (dp_mst_queue_short_message) and its body is appended (dp_mst_append_chunk_to_message).
 *    Last, the read index moves behind the slot.
 */
void dp_mst_receive_task(void)
{
    struct Msg s;
    unsigned int v;
    unsigned int m;
    unsigned int lo;

    s.u4.w &= ~(HEADER_UNPACKED << 8);
    if (dp_mst_message_state_rx_write_indexes[dp_mst_message_state_port] == dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port])
        return;
    v = dp_mst_find_message_bounds() & 0xff;
    m = v & BOUNDS_KIND_MASK;
    if (m != BOUNDS_NONE_YET && m != BOUNDS_SKIP) {
        dp_mst_parse_chunk_header(&s, 0, 1);
        if ((s.u4.b.flags & HEADER_UNPACKED) == 0)
            return;
        lo = s.w0 >> 24 & 0xf;
        if (lo == 0) {
            unsigned char b1[MESSAGE_COPY_BYTES];
            lib_memcpy(b1, &s, MESSAGE_COPY_BYTES);
            dp_mst_queue_reply_header(b1);
            dp_mst_dispatch_request();
        } else {
            if (lo >= s.w0 >> 28) {
                unsigned char b2[MESSAGE_COPY_BYTES];
                lib_memcpy(b2, &s, MESSAGE_COPY_BYTES);
                dp_mst_queue_reply_header(b2);
                dp_mst_dispatch_request();
                if (dp_mst_message_state_port != 0)
                    goto store;
            }
            {
                unsigned char b3[MESSAGE_COPY_BYTES];
                lib_memcpy(b3, &s, MESSAGE_COPY_BYTES);
                dp_mst_queue_short_message(b3);
                dp_mst_append_chunk_to_message();
            }
        }
    store:
        dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port] = (v + 1) & 0xf;
    } else if (m == BOUNDS_SKIP) {
        dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port] = (v + 1) & 0xf;
    }
}

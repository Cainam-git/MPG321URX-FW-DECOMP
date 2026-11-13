/* dp_mst_queue_fixed_up_message  (FUN_a00db9d4)
 *
 * Queue a message with fixed header fields.
 * Name basis: descriptive - cleared message with fixed bit-fields
 *
 * Matching notes
 * --------------
 * FUN_a00db9d4 (leon2s 0xa00db9d4-0xa00dba70, 156 bytes), flags -mcpu=v8 -Os -g.
 * The trailing nop after the final call is the -g epilogue.
 */
extern void *lib_memset(void *, int, unsigned int);
extern void dp_mst_queue_chunk(union Msg *, int, int);
/* The unpacked header (24 bytes): byte 0 = count (high nibble) and low nibble; word 4 holds byte +0x11 (bit 7,
 * bit 6, length in bits 0..5) and byte +0x12 (start flag bit 7, end flag bit 6, bits 5 and 4, low 4 bits). */
union chunk_header {
    struct {
        unsigned int count : 4, low_nibble : 4, rest : 24;
        unsigned int w1, w2, w3;
        unsigned int byte_0x10 : 8, byte_0x11_bit7 : 1, byte_0x11_bit6 : 1, length : 6;
        unsigned int start_flag : 1, end_flag : 1, byte_0x12_bit5 : 1, byte_0x12_bit4 : 1, low12 : 12;
    } h;
    unsigned char b[0x18];
};

/*
 * Put a header with fixed contents into the reply ring of the current port (dp_mst_queue_chunk, queue 1).
 * The 0x13 bytes of the header are cleared, then: count 1, low nibble 7, byte +0x11 bit 7 set, bit 6 clear,
 * length 0x14, start flag and end flag set, bit 4 of byte +0x12 clear. Called by dp_mst_notify_task before
 * each call of dp_mst_send_status_message.
 */
void dp_mst_queue_fixed_up_message(void)
{
    union chunk_header m;

    lib_memset(&m, 0, 0x13);
    m.h.count = 1;
    m.h.low_nibble = 7;
    m.h.byte_0x11_bit7 = 1;
    m.h.byte_0x11_bit6 = 0;
    m.h.length = 0x14;
    m.h.start_flag = 1;
    m.h.end_flag = 1;
    m.h.byte_0x12_bit4 = 0;
    dp_mst_queue_chunk(&m, 1, 1);
}

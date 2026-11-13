/* dp_mst_parse_request  (FUN_a00d73b4)
 *
 * Unpack the body of a received MST request by its request type.
 * Name basis: proven - twelve unpack routines chosen by the type code
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d73b4 @ 0xa00d73b4-0xa00d74ec, -mcpu=v8 -Os -g.
 * Each unpack routine is tail-called with (out, src). Source form: 'case 0x1f: return;' keeps 0x1f in the
 * compare tree (it sets the root at 0x18); dp_mst_get_rx_chunk_address's result is used as a byte pointer.
 */
extern unsigned char *dp_mst_get_rx_chunk_address(unsigned int, unsigned int);
extern void dp_mst_unpack_port_byte(void *, unsigned char *);
extern void dp_mst_unpack_19_byte_record(void *, unsigned char *);
extern void dp_mst_unpack_two_byte_fields(void *, unsigned char *);
extern void dp_mst_unpack_allocate_payload(void *, unsigned char *);
extern void dp_mst_unpack_seven_bit_value(void *, unsigned char *);
extern void dp_mst_unpack_dpcd_read(void *, unsigned char *);
extern void dp_mst_unpack_dpcd_write(void *, unsigned char *);
extern void dp_mst_unpack_i2c_read(void *, unsigned char *);
extern void dp_mst_unpack_i2c_write(void *, unsigned char *);
extern void dp_mst_unpack_port_pair(void *, unsigned char *);
extern void dp_mst_unpack_port_pair_copy(void *, unsigned char *);
extern void dp_mst_unpack_10_byte_record(void *, unsigned char *);

/* Unpack the body of a received request into `out`. `request` is the request number: the body bytes of
 * the chunk selected by dp_mst_get_rx_chunk_address(kind, which) are handed to the unpack routine of that number
 * (0x10 .. 0x38 as listed below). Nothing happens when there is no such chunk, for request 0x1f and for any
 * number not listed. */
void dp_mst_parse_request(void *out, unsigned char kind, unsigned char which, unsigned char request)
{
    unsigned char *src = dp_mst_get_rx_chunk_address(kind, which);

    if (src == 0)
        return;
    switch (request) {
    case 0x10: dp_mst_unpack_port_byte(out, src); break;
    case 0x11: dp_mst_unpack_19_byte_record(out, src); break;
    case 0x12: dp_mst_unpack_two_byte_fields(out, src); break;
    case 0x13: dp_mst_unpack_allocate_payload(out, src); break;
    case 0x16: dp_mst_unpack_seven_bit_value(out, src); break;
    case 0x17: dp_mst_unpack_dpcd_read(out, src); break;
    case 0x18: dp_mst_unpack_dpcd_write(out, src); break;
    case 0x19: dp_mst_unpack_i2c_read(out, src); break;
    case 0x1a: dp_mst_unpack_i2c_write(out, src); break;
    case 0x1b: dp_mst_unpack_port_pair(out, src); break;
    case 0x1c: dp_mst_unpack_port_pair_copy(out, src); break;
    case 0x1f: return;
    case 0x38: dp_mst_unpack_10_byte_record(out, src); break;
    }
}

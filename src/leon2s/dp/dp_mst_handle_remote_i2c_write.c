/* dp_mst_handle_remote_i2c_write  (FUN_a00d8f58)
 *
 * Answer the MST request 0x23 (REMOTE_I2C_WRITE).
 * Name basis: proven - case 0x23 = REMOTE_I2C_WRITE, request number of the DisplayPort MST sideband message
 *   set; called from dp_mst_dispatch_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d8f58 @ 0xa00d8f58-0xa00d8fdc (33 words), flags -mcpu=v8 -Os -g.
 * Source form: bit-fields (big-endian, first field = MSB) for both fields of the reply header and the nibble of
 * the request (firmware andn/or sequence); declaration order request before reply (frame slots);
 * lib_memset returns void * (a void prototype moves the 'mov %l0,%o0' out of the call delay slot).
 */
extern void *lib_memset(void *, int, unsigned int);
extern void dp_mst_parse_request(void *, int, int, int);
extern void dp_mst_send_reply(void *, int, int, int, int);
#define MST_REQUEST_REMOTE_I2C_WRITE 0x23   /* request number */
#define MST_UNPACK_I2C_WRITE         0x1a   /* unpack type that dp_mst_parse_request is given */
#define MST_REPLY_I2C_WRITE          10     /* reply type 10: dp_mst_pack_port_reply_copy */

/* First two words of the reply: request number in bits 24..30 (bit 31 is not written), a 4-bit field at
 * bits 20..23 that is left as it was, and the 4-bit field copied from the request at bits 16..19. */
struct reply_header {
    unsigned int bit31 : 1;
    unsigned int request : 7;
    unsigned int field_20 : 4;
    unsigned int field_16 : 4;
    unsigned int low16 : 16;
    unsigned int word1;
};
/* First word of the unpacked request: the 4-bit field at bits 20..23 is the one copied to the reply. */
struct request_word0 {
    unsigned int hi8 : 8;
    unsigned int field_20 : 4;
    unsigned int rest20 : 20;
};
union unpacked_request {
    struct request_word0 w0;
    unsigned int w[65];
};

/*
 * Answer the request REMOTE_I2C_WRITE (0x23). The request body is unpacked into a cleared 260-byte area
 * (unpack type 0x1a); nothing else of it is used. The reply (type 10, 2 bytes) holds the request number and
 * the 4-bit field at bits 20..23 of the unpacked request's first word, which goes to bits 16..19 of the
 * reply header. Called by dp_mst_dispatch_request.
 */
void dp_mst_handle_remote_i2c_write(void)
{
    union unpacked_request request;
    struct reply_header reply;

    lib_memset(&request, 0, 0x104);
    dp_mst_parse_request(&request, 0, 1, MST_UNPACK_I2C_WRITE);
    reply.request = MST_REQUEST_REMOTE_I2C_WRITE;
    reply.field_16 = request.w0.field_20;
    dp_mst_send_reply(&reply, 2, 1, MST_REPLY_I2C_WRITE, 2);
}

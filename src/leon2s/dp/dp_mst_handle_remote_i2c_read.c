/* dp_mst_handle_remote_i2c_read  (FUN_a00d8d20)
 *
 * Answer the MST request 0x22 (REMOTE_I2C_READ).
 * Name basis: proven - case 0x22 = REMOTE_I2C_READ, request number of the DisplayPort MST sideband message
 *   set; called from dp_mst_dispatch_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d8d20 @ 0xa00d8d20-0xa00d8f58 (142 words), flags -mcpu=v8 -Os -g.
 * Source form: the fields of the request's first word are shifts and masks of the word (bit-fields here would
 * merge the first two tests into one masked compare); the reply's first word is a bit-field struct; the last
 * parameter of dp_mst_send_reply is unsigned short.
 */

/* Request type numbers: dp_mst_parse_request unpacks type 0x19 (a remote I2C read) into the record below, and
 * the reply is built with the reply layout selector 9 (dp_mst_send_reply). */
#define MST_REQUEST_REMOTE_I2C_READ  0x22
#define MST_UNPACK_I2C_READ          0x19
#define MST_REPLY_I2C_READ           9

/* Built-in EDID selectors: the port field of the request, and byte 0x117 of the DP port record. */
#define PORT_FIELD_BUILT_IN_EDID     0x80   /* port field 8, seen in bits 20..23 of the first word */
#define PORT_RECORD_EDID_3840X2160   1
#define PORT_RECORD_EDID_3840X1080   2

/* Byte positions in the unpacked request record (dp_mst_unpack_i2c_read). */
#define REQ_WRITE1_DATA0             4      /* first data byte of the first write transaction */
#define REQ_WRITE2_DATA0             17     /* first data byte of the second write transaction */
#define REQ_READ_DEVICE              28     /* device to read from, low 7 bits */
#define REQ_READ_LENGTH              29     /* number of bytes to read */

/* The reply: byte 0 = request number, byte 1 low nibble = port, byte 2 = number of data bytes, data from byte 3.
 * The same layout is used by dp_mst_handle_remote_dpcd_read. */
struct cmd_hdr {
    unsigned int b31 : 1;
    unsigned int type : 7;          /* request number */
    unsigned int b20 : 4;           /* left as it was */
    unsigned int n : 4;             /* port, copied from the request */
    unsigned int cnt : 8;           /* number of data bytes */
    unsigned int lo : 8;            /* first data byte */
};
union cmd {
    struct cmd_hdr h;
    unsigned char b[0x104];
};
/* The unpacked request. First word: bits 20..23 = port, bits 16..17 = number of write transactions, bits 8..14 =
 * device of the first write transaction. */
union rsp {
    unsigned int w0;
    unsigned char b[30];
};
extern unsigned char dp_mst_message_state_port;
extern const unsigned char dp_tx_sink_edid_buffer[];
extern const unsigned char dp_mst_edid_3840x2160[];
extern const unsigned char dp_mst_edid_3840x1080[];
extern void *lib_memset(void *, int, unsigned int);
extern unsigned char dp_get_port_record_byte_117(unsigned char);
extern void dp_mst_parse_request(void *, int, int, int);
extern void dp_mst_send_reply(void *, int, int, int, unsigned short);

/*
 * Answer a remote I2C read request by returning bytes of an EDID. Called by dp_mst_dispatch_request for
 * request 0x22; no parameters, no result.
 *
 * The read starts at the offset taken from the request: the first data byte of the (first) write
 * transaction. When the request has two write transactions, the first one goes to device 0x30 and its data
 * byte is 1, the offset is instead the first data byte of the second write transaction plus 0x100; with another
 * first data byte it is 0.
 *
 * Bytes are supplied only when the device to read is 0x50, 0x51 or 0x53; for any other device the reply data
 * is all zero. They come from the sink EDID buffer of the output; but when the port field of the request is 8
 * they come from a built-in EDID: the 3840x2160 one when byte 0x117 of the DP port record of the current MST
 * port is 1, the 3840x1080 one when it is 2 (with any other value the reply bytes are not written).
 *
 * The reply (request number 0x22, port of the request, number of bytes, data) is queued as a down reply.
 */
void dp_mst_handle_remote_i2c_read(void)
{
    union rsp r;
    union cmd h;
    unsigned short off;
    unsigned char i;
    unsigned char c;

    lib_memset(&r, 0, 0x1e);
    dp_mst_parse_request(&r, 0, 1, MST_UNPACK_I2C_READ);
    off = 0;
    if (((r.w0 >> 16) & 3) == 2 && ((r.w0 >> 8) & 0x7f) == 0x30) {
        if (r.b[REQ_WRITE1_DATA0] == 1)
            off = r.b[REQ_WRITE2_DATA0] + 0x100;
    } else
        off = r.b[REQ_WRITE1_DATA0];
    h.h.type = MST_REQUEST_REMOTE_I2C_READ;
    h.h.n = (r.w0 >> 20) & 0xf;
    h.h.cnt = r.b[REQ_READ_LENGTH];
    c = r.b[REQ_READ_DEVICE] & 0x7f;
    if (c == 0x50 || c == 0x51 || c == 0x53) {
        if (((r.w0 >> 16) & 0xf0) != PORT_FIELD_BUILT_IN_EDID) {
            for (i = 0; i < r.b[REQ_READ_LENGTH]; i++)
                h.b[3 + i] = dp_tx_sink_edid_buffer[off + i];
        } else {
            for (i = 0; i < r.b[REQ_READ_LENGTH]; i++) {
                if (dp_get_port_record_byte_117(dp_mst_message_state_port) == PORT_RECORD_EDID_3840X2160)
                    h.b[3 + i] = dp_mst_edid_3840x2160[off + i];
                else if (dp_get_port_record_byte_117(dp_mst_message_state_port) == PORT_RECORD_EDID_3840X1080)
                    h.b[3 + i] = dp_mst_edid_3840x1080[off + i];
            }
        }
    } else {
        for (i = 0; i < r.b[REQ_READ_LENGTH]; i++)
            h.b[3 + i] = 0;
    }
    dp_mst_send_reply(&h, 2, 1, MST_REPLY_I2C_READ, h.h.cnt + 3);
}

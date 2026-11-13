/* dp_mst_handle_remote_dpcd_read  (FUN_a00d87fc)
 *
 * Answer the MST request 0x20 (REMOTE_DPCD_READ).
 * Name basis: proven - case 0x20 = REMOTE_DPCD_READ, request number of the DisplayPort MST sideband message
 *   set; called from dp_mst_dispatch_request; data read over AUX in 16-byte chunks or copied
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d87fc @ 0xa00d87fc-0xa00d8b90 (916 bytes), flags -mcpu=v8 -Os -g (section default).
 * dp_tx_aux_request_copy is the label func_0xa0f96400.
 * Source forms the exact build depends on:
 *  - request is zero-initialised in its declaration; reply is not initialised;
 *  - offset is one unsigned short for both the AUX chunk offset and the start offset of a range;
 *  - the chunk test is 'count > AUX_CHUNK_MAX' first;
 *  - the copy is one for loop with the condition 'i < count && offset + i < limit';
 *  - the table index is written (table_base & 0x7f) + offset + i and the fixed byte (fixed_bytes + offset)[i].
 */

#define MST_REQUEST_REMOTE_DPCD_READ 0x20   /* request number, written into the reply */
#define MST_UNPACK_DPCD_READ         0x17   /* dp_mst_parse_request: unpack with dp_mst_unpack_dpcd_read */
#define MST_QUEUE_REPLY              2      /* dp_mst_send_reply: every caller passes 2 and 1 */
#define MST_DIRECTION_DOWN           1
#define MST_REPLY_REMOTE_DPCD_READ   7      /* dp_mst_send_reply body format: dp_mst_pack_dpcd_read_reply */

/* Port field of the request (bits 20..23 of its first word). */
#define PORT_FIELD_MASK              0xf00000
#define PORT_FIELD_READ_OVER_AUX     0x100000   /* port 1: the bytes are read from DP output 0 over AUX */

#define DPTX_OUTPUT                  0      /* DP output 0 ('DPTX') */
#define AUX_CMD_READ                 0x90   /* AUX command of the read */
#define AUX_CHUNK_MAX                0x10   /* bytes per AUX read */
#define REPLY_DATA_START             3      /* reply bytes 0..2 = request number, port, count */

/* The reply: byte 0 = request number, byte 1 low nibble = port, byte 2 = number of data bytes, data from byte 3.
 * The same layout as in dp_mst_handle_remote_i2c_read. */
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
/* The unpacked request (dp_mst_unpack_dpcd_read). */
struct dpcd_read_request {
    unsigned int word0;             /* bits 24..30 request number, bits 20..23 port */
    unsigned int address;           /* first DPCD address to read (20 bits) */
    unsigned char count;            /* number of bytes to read */
};
extern unsigned char dp_mst_message_state_port;
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern const unsigned short dp_mst_dpcd_addresses[];
extern unsigned char dp_mst_remote_dpcd_bytes[];
extern void dp_mst_parse_request(void *, int, int, int);
extern unsigned char dp_tx_aux_request_copy(unsigned int, unsigned int, unsigned int, signed char, unsigned char *);
extern void dp_mst_send_reply(void *, int, int, int, unsigned short);

/*
 * Answer a remote DPCD read: return `count` bytes from DPCD address `address` of the port named in the request.
 * No parameters, no result. Called by dp_mst_dispatch_request for request 0x20; the reply goes to the current
 * MST port (dp_mst_message_state_port).
 *
 * Phases, in order:
 *   1. Unpack the request (dp_mst_parse_request, unpack 0x17) and start the reply: request number 0x20, the
 *      port of the request, the requested count.
 *   2a. Port 1: read the bytes from DP output 0 with AUX reads of at most 16 bytes each. A read that fails
 *      leaves zeros in its part of the reply.
 *   2b. Any other port: answer from the current port's own register block (dp_mst_ctl_reg_blocks). Only these
 *      address ranges give bytes; each range has its own place in dp_mst_dpcd_addresses, the table of register
 *      word numbers:
 *          address            start offset         bytes   table entries
 *          0x00..0x0B         address & 0xF         11     0x00..0x0A
 *          0x30..0x3F         address & 0xF         15     0x0F..0x1D
 *          0x100..0x101       address & 0xF          2     0x2D..0x2E
 *          0x68000..0x6802B   address & 0x2F        44     0x79..0xA4
 *          0x0E               0                      1     0x0D
 *          0x60..0x6F         address & 0xF         16     0x1F..0x2E
 *          0x90..0x91         address & 0xF          2     0x2C..0x2D
 *          0x120              0                      1     0x40
 *          0x160              0                      1     0x41
 *          0x2200..0x2210     address & 0x1F        17     0x65..0x75
 *          0x40..0x4F         address & 0xF         16     dp_mst_remote_dpcd_bytes (fixed bytes, no registers)
 *      Copying starts at the start offset and stops after `count` bytes or at the end of the range; the rest of
 *      the reply data is zero. Addresses outside these ranges give all zeros. The addresses 0x0B and 0x3F pass
 *      the range test but lie at the range end, so they give zeros; through the mask 0x2F, 0x68010..0x6801F
 *      start at the same entries as 0x68000..0x6800F.
 *   3. Queue the reply (3 header bytes + count data bytes) with dp_mst_send_reply.
 */
void dp_mst_handle_remote_dpcd_read(void)
{
    struct dpcd_read_request request = {0, 0, 0};
    union cmd reply;
    unsigned short count;
    unsigned short offset;
    unsigned char chunk;
    unsigned char limit;
    unsigned char table_base;
    unsigned char from_fixed_bytes;
    unsigned char *fixed_bytes;
    unsigned char i;

    /* Phase 1: the request and the reply header. */
    dp_mst_parse_request(&request, 0, 1, MST_UNPACK_DPCD_READ);
    reply.h.type = MST_REQUEST_REMOTE_DPCD_READ;
    reply.h.n = (request.word0 >> 20) & 0xf;
    reply.h.cnt = request.count;
    count = request.count;
    table_base = 0;
    fixed_bytes = 0;
    from_fixed_bytes = 0;
    offset = 0;
    if ((request.word0 & PORT_FIELD_MASK) == PORT_FIELD_READ_OVER_AUX) {
        /* Phase 2a: read over AUX from output 0, in pieces of up to 16 bytes. */
        while (count != 0) {
            if (count > AUX_CHUNK_MAX) {
                chunk = AUX_CHUNK_MAX;
                count -= AUX_CHUNK_MAX;
            } else {
                chunk = count;
                count = 0;
            }
            if (dp_tx_aux_request_copy(DPTX_OUTPUT, AUX_CMD_READ, request.address + offset, chunk - 1, &reply.b[REPLY_DATA_START + offset]) == 0) {
                for (i = 0; i < chunk; i++)
                    reply.b[REPLY_DATA_START + offset + i] = 0;
            }
            offset += chunk;
        }
    } else {
        /* Phase 2b: find the range of the address (see the table above). limit is the end of the range,
           counted in the same units as offset. */
        if (request.address <= 0xb) {
            offset = request.address & 0xf;
            limit = 0xb;
        } else if (request.address - 0x30 <= 0xf) {
            offset = request.address & 0xf;
            limit = 0xf;
            table_base = 0xf;
        } else if (request.address - 0x100 <= 1) {
            offset = request.address & 0xf;
            limit = 2;
            table_base = 0x2d;
        } else if (request.address - 0x68000 <= 0x2b) {
            offset = request.address & 0x2f;
            limit = 0x2c;
            table_base = 0x79;
        } else if (request.address == 0xe) {
            limit = 1;
            table_base = 0xd;
        } else if (request.address - 0x60 <= 0xf) {
            offset = request.address & 0xf;
            limit = 0x10;
            table_base = 0x1f;
        } else if (request.address - 0x90 <= 1) {
            offset = request.address & 0xf;
            limit = 2;
            table_base = 0x2c;
        } else if (request.address == 0x120) {
            limit = 1;
            table_base = 0x40;
        } else if (request.address == 0x160) {
            limit = 1;
            table_base = 0x41;
        } else if (request.address - 0x2200 <= 0x10) {
            offset = request.address & 0x1f;
            limit = 0x11;
            table_base = 0x65;
        } else {
            /* Unknown address: nothing to copy, unless it is 0x40..0x4F (fixed bytes). */
            limit = 0;
            offset = 0;
            if (request.address - 0x40 <= 0xf) {
                offset = request.address & 0xf;
                fixed_bytes = dp_mst_remote_dpcd_bytes;
                limit = 0x10;
                from_fixed_bytes = 1;
            }
        }
        for (i = 0; i < count && offset + i < limit; i++) {
            if (from_fixed_bytes == 0)
                reply.b[REPLY_DATA_START + i] = dp_mst_ctl_reg_blocks[dp_mst_message_state_port][dp_mst_dpcd_addresses[(table_base & 0x7f) + offset + i]];
            else
                reply.b[REPLY_DATA_START + i] = (fixed_bytes + offset)[i];
        }
        /* Bytes past the end of the range are answered with zeros. */
        for (; i < count; i++)
            reply.b[REPLY_DATA_START + i] = 0;
    }
    /* Phase 3. */
    dp_mst_send_reply(&reply, MST_QUEUE_REPLY, MST_DIRECTION_DOWN, MST_REPLY_REMOTE_DPCD_READ, reply.h.cnt + REPLY_DATA_START);
}

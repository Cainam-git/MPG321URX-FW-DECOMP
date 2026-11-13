/* dp_mst_handle_query_stream_enc_status  (FUN_a00d90dc)
 *
 * Answer the MST request 0x38 (QUERY_STREAM_ENC_STATUS).
 * Name basis: proven - case 0x38 = QUERY_STREAM_ENC_STATUS, request number of the DisplayPort MST sideband
 *   message set; called from dp_mst_dispatch_request; writes 20 bytes to the encryption status block
 *
 * Matching notes
 * --------------
 * FUN_a00d90dc (leon2s 0xa00d90dc-0xa00d9474, 920 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: the reply header is a big-endian bit-field struct (first field = most significant bit); lead[0]
 * is computed right after the bit-19 store (before the bits 8..15 fields); each flag bit goes through the
 * unsigned int v ('v = x & 2; flag = v != 0'); the byte loop is an if/else-if chain on i (== 0, < 2, < 5, < 7,
 * < 8), each arm with its own OR expression, the stack byte terms first, and its own store of 'v & 0xff'
 * (v unsigned int).
 */

#define MST_REQUEST_QUERY_STREAM_ENC_STATUS 0x38    /* request number; also the unpack type and the reply layout */
#define ENC_STATUS_BYTES                    0x14    /* bytes written to and read back from the block */

/* The reply: byte 0 = request number, bytes 1..3 = fields below (byte 3 = request byte 1), bytes 4..23 = the
 * 20 bytes read back from the block at 0xCF018E00. */
struct hdr38 {
    unsigned int b31 : 1;
    unsigned int type : 7;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;       /* bit 1 of receiver 0 register 0x2a8 */
    unsigned int b20 : 1;       /* bit 3 of receiver 0 register 0x32 */
    unsigned int b19 : 1;       /* always 1 */
    unsigned int f16 : 3;
    unsigned int f13 : 3;       /* always 2 */
    unsigned int f11 : 2;       /* always 1 */
    unsigned int b10 : 1;
    unsigned int b9 : 1;
    unsigned int b8 : 1;        /* always 1 */
    unsigned int lo : 8;        /* byte 1 of the unpacked request */
};
union cmd {
    struct hdr38 h;
    unsigned char b[0x18];
};
/* Registers of the block at 0xCF018E00, named by offset; +0x04 is the one the 20 bytes are written to and read from. */
#define REG_200 (*(volatile unsigned int *)0xcf018e00)
#define REG_204 (*(volatile unsigned int *)0xcf018e04)
#define REG_208 (*(volatile unsigned int *)0xcf018e08)
#define REG_210 (*(volatile unsigned int *)0xcf018e10)
#define REG_214 (*(volatile unsigned int *)0xcf018e14)
#define REG_224 (*(volatile unsigned int *)0xcf018e24)
#define REG_228 (*(volatile unsigned int *)0xcf018e28)
extern void dp_mst_parse_request(void *, int, int, int);
extern void dp_mst_set_reply_ready(void);
extern void dp_mst_clear_busy_bit(void);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_mst_send_reply(void *, int, int, int, unsigned short);

/*
 * Answer a stream encryption status query (request 0x38). Called by dp_mst_dispatch_request; no parameters, no
 * result. The 24-byte reply is queued as a down reply.
 *
 * Order of events: unpack the request (a 10-byte record r, of which bytes 1..8 are used); set the port's
 * reply-ready signal; fill the reply header from two bits of DP receiver 0 registers, fixed bits and r[1]; run
 * the block at 0xCF018E00 through its steps; copy its 20 result bytes into the reply; clear the port's bit
 * 7 of word 0xC0; send.
 *
 * The block's 20 input bytes are each the OR of several terms (a missing term means 0): lead[i] for bytes 0 and 1,
 * r[1] for byte 0, request bytes r[i + 2] for bytes 0..6, receiver 0 registers 0x28c + i for bytes 0..7,
 * 0x280 + i for bytes 0..4 and 0x2df - i for bytes 0..7. Bytes 8..19 are 0. lead[0] is 0x80 plus the header's
 * bits 21, 20 and 19 moved to bits 5, 4 and 3; lead[1] is 0x49.
 */
void dp_mst_handle_query_stream_enc_status(void)
{
    unsigned char r[10] = {0};
    union cmd h;
    unsigned char a[2];     /* lead[] in the comment above */
    unsigned char i;
    unsigned int v;

    dp_mst_parse_request(r, 0, 1, MST_REQUEST_QUERY_STREAM_ENC_STATUS);
    dp_mst_set_reply_ready();
    h.h.type = MST_REQUEST_QUERY_STREAM_ENC_STATUS;
    v = dp_reg_read8(0, 0x2a8) & 2;
    h.h.b21 = v != 0;
    v = dp_reg_read8(0, 0x32) & 8;
    h.h.b20 = v != 0;
    h.h.b19 = 1;
    a[0] = 0x80 | (h.h.b21 << 5) | (h.h.b20 << 4) | (h.h.b19 << 3);
    h.h.f13 = 2;
    h.h.f11 = 1;
    h.h.b8 = 1;
    a[1] = 0x49;
    h.b[3] = r[1];
    /* Step 1: write 0x1f to +0x10 and 0x80 to +0x14, wait for bit 7 of +0x14 to clear. */
    REG_210 = 0x1f;
    REG_214 = 0x80;
    while (REG_214 & 0x80)
        ;
    /* Step 2: set-up, then the 20 input bytes. */
    REG_200 = 0;
    REG_224 = ENC_STATUS_BYTES;
    REG_228 = 0;
    for (i = 0; i < ENC_STATUS_BYTES; i++) {
        if (i == 0) {
            v = a[i] | r[i + 2] | r[1] | dp_reg_read8(0, 0x28c + i) | dp_reg_read8(0, 0x280 + i) | dp_reg_read8(0, 0x2df - i); REG_204 = v & 0xff;
        } else if (i < 2) {
            v = a[i] | r[i + 2] | dp_reg_read8(0, 0x28c + i) | dp_reg_read8(0, 0x280 + i) | dp_reg_read8(0, 0x2df - i); REG_204 = v & 0xff;
        } else if (i < 5) {
            v = r[i + 2] | dp_reg_read8(0, 0x28c + i) | dp_reg_read8(0, 0x280 + i) | dp_reg_read8(0, 0x2df - i); REG_204 = v & 0xff;
        } else if (i < 7) {
            v = r[i + 2] | dp_reg_read8(0, 0x28c + i) | dp_reg_read8(0, 0x2df - i); REG_204 = v & 0xff;
        } else if (i < 8) {
            v = dp_reg_read8(0, 0x28c + i) | dp_reg_read8(0, 0x2df - i); REG_204 = v & 0xff;
        } else {
            REG_204 = 0;
        }
    }
    /* Step 3: one more byte (0x80), start with +0x14 = 1 and wait for bit 0 to clear; then +0x00 = 0x22,
     * +0x08 = 0x80 and wait for bit 7 of +0x08 to clear. */
    REG_204 = 0x80;
    REG_214 = 1;
    while (REG_214 & 1)
        ;
    REG_200 = 0x22;
    REG_208 = 0x80;
    while (REG_208 & 0x80)
        ;
    /* Step 4: the 20 result bytes go to reply bytes 4..23. */
    for (i = 0; i < ENC_STATUS_BYTES; i++)
        h.b[4 + i] = REG_204;
    dp_mst_clear_busy_bit();
    dp_mst_send_reply(&h, 2, 1, MST_REQUEST_QUERY_STREAM_ENC_STATUS, 0x18);
}

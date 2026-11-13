/* dp_mst_queue_clear_payload_table_request  (FUN_a00d9a78)
 *
 * Queue a CLEAR_PAYLOAD_ID_TABLE request (0x14) of its own making in the forward ring.
 * Note: Called by dp_mst_reset_port; link count 1, body = request number and its checksum.
 * Name basis: derived - body byte 0x14 (CLEAR_PAYLOAD_ID_TABLE in the DisplayPort standard) +
 *   dp_mst_crc8_data; dp_mst_queue_chunk queue 3 (forward rows); called by dp_mst_reset_port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d9a78 @ 0xa00d9a78-0xa00d9be4, -mcpu=v8 -Os -g.
 * Source form: the row index is computed as (fwd_write_index & 0xf) * 3 into 16-byte rows (the firmware forms the
 * * 3 early and the * 16 at the loop), before h = k / 2; off = h then
 * 'if (k & 1) off = h + 1'.
 */

#define MST_REQUEST_CLEAR_PAYLOAD_TABLE 0x14    /* CLEAR_PAYLOAD_ID_TABLE, the message this routine builds */
#define MESSAGE_SIZE                    0x13    /* bytes of an unpacked message */
#define BODY_LENGTH                     2       /* request number + checksum */

/* An unpacked message, as dp_mst_pack_header takes it: word 0 = the two count nibbles of the first header byte;
 * word 4 holds the fields of the second and third header byte (b23 / b22 / f16 = bits 7, 6 and the 6-bit length
 * of the second byte; b15 / b14 = the start and end flags of the third byte). */
union Msg {
    struct {
        unsigned int hi : 4, cnt : 4, rest : 24;
        unsigned int w1, w2, w3;
        unsigned int a : 8, b23 : 1, b22 : 1, f16 : 6, b15 : 1, b14 : 1, b13 : 1, b12 : 1, n8 : 4, low : 8;
    } h;
    unsigned char b[0x18];
};
extern unsigned char dp_mst_message_state_fwd_write_index;
extern unsigned char dp_mst_message_state_fwd_queued_flag;
extern unsigned char dp_mst_forward_messages[];
/* Forward rows: 16 rows of 0x30 bytes, addressed here as 3 rows of 16 per message (dp_mst_forward_rows). */
extern unsigned char dp_mst_forward_rows[][16];
extern void *lib_memset(void *, int, unsigned int);
extern void dp_mst_queue_chunk(union Msg *, int, int);
extern unsigned char dp_mst_crc8_data(unsigned char *, int, int, int);

/*
 * Queue a made-up CLEAR_PAYLOAD_ID_TABLE request (0x14) in the forward ring, to be sent on to the output by
 * dp_mst_forward_down_request. Called by dp_mst_reset_port (when dp_tx_get_mode_flag is non-zero); no parameters,
 * no result.
 *
 * The message has a link count of 1 (no address nibbles), a body length of 2 and both the start and the end
 * flag set. dp_mst_queue_chunk packs its header into the forward row at the write index (type 3). The body is
 * then written behind the header: the request number 0x14 and its checksum from dp_mst_crc8_data. The row's
 * length is stored in dp_mst_forward_messages[], the write index steps by one (modulo 16) and the forward
 * queued flag is set (dp_mst_forward_down_request tests it for request 0x14).
 */
void dp_mst_queue_clear_payload_table_request(void)
{
    union Msg m;
    unsigned char t[8];
    unsigned char i, n, off;
    unsigned int d, j;
    int k, h;

    lib_memset(&m, 0, MESSAGE_SIZE);
    m.h.hi = 1;
    m.h.cnt = 0;
    m.h.b23 = 1;
    m.h.b22 = 1;
    m.h.f16 = BODY_LENGTH;
    m.h.b15 = 1;
    m.h.b14 = 1;
    dp_mst_queue_chunk(&m, 3, 1);
    /* Where the body starts in the row: header length = off + 3. */
    k = m.h.hi - 1;
    d = (dp_mst_message_state_fwd_write_index & 0xf) * 3;
    h = k / 2;
    off = h;
    if (k & 1)
        off = h + 1;
    n = m.h.f16;
    t[0] = MST_REQUEST_CLEAR_PAYLOAD_TABLE;
    t[1] = dp_mst_crc8_data(t, 1, 0, 0x30);
    for (i = 0; i < n; i++)
        dp_mst_forward_rows[d][i + off + 3] = t[i];
    j = dp_mst_message_state_fwd_write_index;
    dp_mst_forward_messages[j] = off + n + 3;
    dp_mst_message_state_fwd_write_index = (j + 1) & 0xf;
    dp_mst_message_state_fwd_queued_flag = 1;
}

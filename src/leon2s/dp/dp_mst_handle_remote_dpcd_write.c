/* dp_mst_handle_remote_dpcd_write  (FUN_a00d8b90)
 *
 * Answer the MST request 0x21 (REMOTE_DPCD_WRITE).
 * Name basis: proven - case 0x21 = REMOTE_DPCD_WRITE, request number of the DisplayPort MST sideband message
 *   set; called from dp_mst_dispatch_request; data written over AUX in 16-byte pieces
 *
 * Matching notes
 * --------------
 * FUN_a00d8b90 (leon2s 0xa00d8b90-0xa00d8d20, 400 bytes), flags -mcpu=v8 -Os -g.
 * dp_tx_aux_request, dbg_print_string and lib_memset are the labels func_0xa0f963d4, func_0xa0f834c4 and
 * func_0xa0fc15ac.
 * Source form: remaining = big.n and offset = 0 are set before the field test; the port byte is read through the
 * pointer cur, and the table addresses through the locals tab and ix.
 */
/* Request record: 4-bit field at bits 20..23 of word 0, address (type) at +4, byte count at +8, data from +9. */
struct Big {
    unsigned int a : 8, f20 : 4, rest : 20;
    unsigned int type;
    unsigned char n;
    unsigned char data[0x10c - 9];
};
struct Msg { unsigned int b31 : 1, f24 : 7, h : 4, f16 : 4, low : 16; unsigned int w1; };
extern unsigned char dp_mst_message_state_port;
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern const unsigned short dp_mst_dpcd_addresses[];
extern void *lib_memset(void *, int, unsigned int);
extern void dp_mst_parse_request(void *, unsigned char, unsigned char, unsigned char);
extern unsigned char dp_tx_aux_request(unsigned int, unsigned int, unsigned int, char, unsigned char *);
extern void dbg_print_string(const char *);
extern void dp_mst_set_reply_ready(void);
extern void dp_mst_clear_busy_bit(void);
extern void dp_mst_send_reply(void *, int, int, int, int);

/* Answers the multi-stream request 0x21 (REMOTE_DPCD_WRITE).
 *
 * The request is unpacked into big (cleared first, 0x10c bytes) with dp_mst_parse_request. The reply m carries
 * request number 0x21 and the 4-bit field (bits 20..23) of the request. By that field:
 * - field 1: the big.n data bytes are sent with dp_tx_aux_request(0, 0x80, big.type, length, data) in pieces
 *   of at most 16 bytes. A piece that returns 0 prints "Write DPCD --> FALSE!\r" and the routine returns 0
 *   without a reply.
 * - other values: the data is applied to the current port's register block (dp_mst_ctl_reg_blocks[port]) for two
 *   values of big.type only. 0x160: dp_mst_set_reply_ready(), the first data byte goes to the word
 *   dp_mst_dpcd_addresses[0x82 / 2], then dp_mst_clear_busy_bit(). 0x107: the first data byte goes to the word
 *   dp_mst_dpcd_addresses[0x68 / 2]. Other values write nothing.
 * Then the reply is queued with dp_mst_send_reply(&m, 2, 1, 8, 2) and 1 is returned.
 *
 * Called by dp_mst_dispatch_request.
 */
int dp_mst_handle_remote_dpcd_write(void)
{
    struct Big big;
    struct Msg m;
    unsigned short remaining, offset;
    unsigned char piece;
    volatile unsigned int *regs;
    unsigned int k;
    volatile unsigned int **tab;
    const unsigned short *ix;
    unsigned char *cur;

    lib_memset(&big, 0, 0x10c);
    tab = dp_mst_ctl_reg_blocks;
    ix = dp_mst_dpcd_addresses;
    dp_mst_parse_request(&big, 0, 1, 0x18);
    m.f24 = 0x21;
    m.f16 = big.f20;
    cur = &dp_mst_message_state_port;
    remaining = big.n;
    offset = 0;
    if (m.f16 == 1) {
        while (remaining != 0) {
            if (remaining > 0x10) {
                piece = 0x10;
                remaining -= 0x10;
            } else {
                piece = remaining;
                remaining = 0;
            }
            if (dp_tx_aux_request(0, 0x80, big.type, piece, &big.data[offset]) == 0) {
                dbg_print_string("Write DPCD --> FALSE!\r");
                return 0;
            }
            offset += piece;
        }
        goto out;
    }
    if (big.type == 0x160) {
        regs = tab[*cur];
        k = ix[0x82 / 2];
        dp_mst_set_reply_ready();
        regs[k] = big.data[0];
        dp_mst_clear_busy_bit();
    }
    if (big.type == 0x107)
        tab[*cur][ix[0x68 / 2]] = big.data[0];
out:
    dp_mst_send_reply(&m, 2, 1, 8, 2);
    return 1;
}

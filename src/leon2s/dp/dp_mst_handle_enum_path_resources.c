/* dp_mst_handle_enum_path_resources  (FUN_a00d8300)
 *
 * Answer the MST request 0x10 (ENUM_PATH_RESOURCES).
 * Name basis: proven - case 0x10 = ENUM_PATH_RESOURCES, request number of the DisplayPort MST sideband message
 *   set; called from dp_mst_dispatch_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d8300 @ 0xa00d8300-0xa00d84f4, -mcpu=v8 -Os -g.
 * The request record in is an 8-byte stack record with its first halfword cleared. dp_tx_aux_request_copy is
 * the label func_0xa0f96400.
 * Source form: m is a union of the bit-fields, halfwords and words (the first field test reads the word, the
 * second the halfword).
 */
struct In { unsigned int a : 8, f20 : 4, rest : 20; unsigned int w4; };
struct Bits { unsigned int b31 : 1, f24 : 7, f20 : 4, f17 : 3, b16 : 1, low : 16; unsigned int w4; };
union Msg { struct Bits b; unsigned short h[4]; unsigned int w[2]; };
extern unsigned char dp_mst_message_state_port;
extern unsigned short dp_mst_message_state;
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern const unsigned short dp_mst_dpcd_addresses[];
extern unsigned short dp_mst_path_pbn_table[];
extern void dp_mst_parse_request(void *, unsigned char, unsigned char, unsigned char);
extern unsigned char dp_tx_aux_request_copy(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern void dp_mst_send_reply(void *, int, int, int, int);

/* Answers the multi-stream request 0x10 (ENUM_PATH_RESOURCES).
 *
 * The request is unpacked with dp_mst_parse_request; the reply m carries request number 0x10 and the 4-bit field
 * (bits 20..23) copied from the request. Two values a and b are then fetched, by that field:
 * - field 1: dp_tx_aux_request_copy(0, 0x90, 1, 1, t) fills t[0], t[1] (both 0 when it returns 0); a = t[0],
 *   b = t[1].
 * - otherwise: from the current port's register block (dp_mst_ctl_reg_blocks[port]) at the words
 *   dp_mst_dpcd_addresses[0x5a / 2] (a) and [0x5c / 2] (b); bit 16 of m is set from bit 0 of the word at
 *   dp_mst_dpcd_addresses[0x58 / 2].
 * The table index r is 0, 3, 6, 9, 12 or 15 for a = 6, 10, 0x14, 0x1e, 1 or 4 (0 for any other a), plus 1 when
 * b & 0xf is 2 and plus 2 when it is 4. Halfwords 1 and 2 of m both get dp_mst_path_pbn_table[r]; halfword 2 is
 * 0 instead when the field is 8 and dp_mst_message_state is not 0. The reply is queued with
 * dp_mst_send_reply(&m, 2, 1, 2, 6).
 *
 * Called by dp_mst_dispatch_request.
 */
void dp_mst_handle_enum_path_resources(void)
{
    unsigned char t[2];
    union { struct In s; unsigned short h0; } in;
    union Msg m;
    unsigned char r = 0;
    unsigned char a, b;
    volatile unsigned int *regs;

    in.h0 = 0;
    dp_mst_parse_request(&in, 0, 1, 0x12);
    m.b.f24 = 0x10;
    m.b.f20 = in.s.f20;
    if (((m.w[0] >> 16) & 0xf0) == 0x10) {
        if (dp_tx_aux_request_copy(0, 0x90, 1, 1, t) == 0) {
            t[0] = 0;
            t[1] = 0;
        }
        a = t[0];
        b = t[1];
    } else {
        regs = dp_mst_ctl_reg_blocks[dp_mst_message_state_port];
        a = regs[dp_mst_dpcd_addresses[0x5a / 2]];
        b = regs[dp_mst_dpcd_addresses[0x5c / 2]];
        if (regs[dp_mst_dpcd_addresses[0x58 / 2]] & 1)
            m.b.b16 = 1;
        else
            m.b.b16 = 0;
    }
    /* a selects a group of three table entries, b & 0xf the entry inside it. */
    if (a == 6)
        r = 0;
    else if (a == 10)
        r = 3;
    else if (a == 0x14)
        r = 6;
    else if (a == 0x1e)
        r = 9;
    else if (a == 1)
        r = 0xc;
    else if (a == 4)
        r = 0xf;
    if ((b & 0xf) == 2)
        r++;
    else if ((b & 0xf) == 4)
        r += 2;
    if ((m.h[0] & 0xf0) == 0x80 && dp_mst_message_state != 0) {
        m.h[1] = dp_mst_path_pbn_table[r];
        m.h[2] = 0;
    } else {
        m.h[2] = m.h[1] = dp_mst_path_pbn_table[r];
    }
    dp_mst_send_reply(&m, 2, 1, 2, 6);
}

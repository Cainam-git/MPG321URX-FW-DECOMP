/* dp_mst_handle_allocate_payload  (FUN_a00d84f4)
 *
 * Answer the MST request 0x11 (ALLOCATE_PAYLOAD).
 * Name basis: proven - case 0x11 = ALLOCATE_PAYLOAD, request number of the DisplayPort MST sideband message
 *   set; called from dp_mst_dispatch_request; also writes the payload registers
 *
 * Matching notes
 * --------------
 * FUN_a00d84f4 (leon2s 0xa00d84f4-0xa00d8714, 544 bytes), flags -mcpu=v8 -Os -g.
 * The request record in is 14 bytes (cleared with lib_memset, the label func_0xa0fc15ac). The register blocks
 * are reached through dp_mst_msg_reg_blocks, an array of volatile word pointers.
 * Source form: in the field 1 case each arm repeats the three closing register writes.
 */
struct In { unsigned int a : 8, f20 : 4, b19 : 4, x15 : 1, f8 : 7, lo : 8; unsigned short h4; unsigned char rest[8]; };
union InU { struct In s; unsigned int w; };
struct Msg { unsigned int b31 : 1, f24 : 7, f20 : 4, r16 : 4, f9 : 7, lo : 9; unsigned short h4; unsigned short h6; };
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_byte_0x4f;
extern unsigned short dp_mst_message_state;
extern volatile unsigned int *dp_mst_msg_reg_blocks[];
extern void *lib_memset(void *, int, unsigned int);
extern void dp_mst_parse_request(void *, unsigned char, unsigned char, unsigned char);
extern void dp_mst_send_reply(void *, int, int, int, int);

/* Answers the multi-stream request 0x11 (ALLOCATE_PAYLOAD) and writes the payload registers.
 *
 * The request is unpacked into in (cleared first) with dp_mst_parse_request. The reply m carries request number
 * 0x11, the 4-bit field (bits 20..23) of the request, its 7-bit field of bits 8..14 (stored at bits 9..15 of m)
 * and its halfword at +4. The reply is queued first, with dp_mst_send_reply(&m, 2, 1, 3, 5). Then, by the 4-bit
 * field, with R the register block dp_mst_msg_reg_blocks[port]:
 * - field 8: halfword +4 non-zero: bits 8..14 of the request go to R + 0x284, bit 4 of R + 0x2b0 is set and
 *   cleared, and dp_mst_message_state = the halfword; zero: R + 0x284 and dp_mst_message_state are cleared.
 * - field 1: halfword +4 non-zero sets dp_mst_message_state_byte_0x4f to 1, zero sets it to 0. Both arms set
 *   bit 6 of R + 0x2ac, write R + 0x284 (bits 8..14 of the request, or 0 when the halfword is 0), set and clear
 *   bit 4 of R + 0x2b0, and clear bit 6 of R + 0x2ac.
 * Other values of the field write nothing.
 *
 * Called by dp_mst_dispatch_request.
 */
void dp_mst_handle_allocate_payload(void)
{
    union InU in;
    struct Msg m;
    unsigned int v;

    lib_memset(&in, 0, 0xe);
    dp_mst_parse_request(&in, 0, 1, 0x13);
    m.f24 = 0x11;
    m.f20 = in.s.f20;
    m.f9 = in.s.f8;
    m.h4 = in.s.h4;
    dp_mst_send_reply(&m, 2, 1, 3, 5);
    v = in.w;
    if (((v >> 16) & 0xf0) == 0x80) {
        if (in.s.h4 != 0) {
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x284 / 4] = (v >> 8) & 0x7f;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2b0 / 4] |= 0x10;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2b0 / 4] &= ~0x10;
            dp_mst_message_state = m.h4;
        } else {
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x284 / 4] = 0;
            dp_mst_message_state = 0;
        }
    } else if (((v >> 16) & 0xf0) == 0x10) {
        if (in.s.h4 != 0) {
            dp_mst_message_state_byte_0x4f = 1;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2ac / 4] |= 0x40;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x284 / 4] = (in.w >> 8) & 0x7f;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2b0 / 4] |= 0x10;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2b0 / 4] &= ~0x10;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2ac / 4] &= ~0x40;
        } else {
            dp_mst_message_state_byte_0x4f = 0;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2ac / 4] |= 0x40;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x284 / 4] = 0;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2b0 / 4] |= 0x10;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2b0 / 4] &= ~0x10;
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2ac / 4] &= ~0x40;
        }
    }
}

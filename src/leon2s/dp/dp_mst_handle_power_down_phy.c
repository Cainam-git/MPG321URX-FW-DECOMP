/* dp_mst_handle_power_down_phy  (FUN_a00d904c)
 *
 * Answer the MST request 0x25 (POWER_DOWN_PHY).
 * Name basis: proven - case 0x25 = POWER_DOWN_PHY, request number of the DisplayPort MST sideband message set;
 *   called from dp_mst_dispatch_request
 *
 * Matching notes
 * --------------
 * FUN_a00d904c (leon2s 0xa00d904c-0xa00d90dc, 144 bytes), flags -mcpu=v8 -Os -g.
 * Source form: bit-fields (big-endian, first field = MSB) as in dp_mst_handle_remote_i2c_write; the halfword
 * clears are stores through a halfword view of each union (the firmware uses clrh).
 */
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern unsigned char dp_mst_message_state_port;
extern void dp_mst_parse_request(void *, int, int, int);
extern void dp_mst_send_reply(void *, int, int, int, int);
#define MST_REQUEST_POWER_DOWN_PHY 0x25 /* request number */
#define MST_UNPACK_POWER_DOWN_PHY  0x1c /* unpack type that dp_mst_parse_request is given */
#define MST_REPLY_POWER_DOWN_PHY   0xc  /* reply type 12: dp_mst_pack_port_reply_high_copy */

/* First two words of the reply: request number in bits 24..30 (bit 31 is not written), the 4-bit field copied
 * from the request at bits 20..23, and a 4-bit field at bits 16..19. */
struct reply_header {
    unsigned int bit31 : 1;
    unsigned int request : 7;
    unsigned int field_20 : 4;
    unsigned int field_16 : 4;
    unsigned int low16 : 16;
    unsigned int word1;
};
/* First word of the unpacked request. */
struct request_word0 {
    unsigned int hi8 : 8;
    unsigned int field_20 : 4;
    unsigned int rest20 : 20;
};
union unpacked_request { struct request_word0 w0; unsigned short h[4]; };
union reply { struct reply_header f; unsigned short h[4]; };

/*
 * Answer the request POWER_DOWN_PHY (0x25). Same steps as dp_mst_handle_power_up_phy (unpack type 0x1c, reply
 * type 12 of 2 bytes). After the reply is queued, bit 5 of the first word of the current port's control
 * register block (dp_mst_ctl_reg_blocks[dp_mst_message_state_port]) is set.
 * Called by dp_mst_dispatch_request.
 */
void dp_mst_handle_power_down_phy(void)
{
    union unpacked_request request;
    union reply reply;

    request.h[0] = 0;
    reply.h[0] = 0;
    dp_mst_parse_request(&request, 0, 1, MST_UNPACK_POWER_DOWN_PHY);
    reply.f.request = MST_REQUEST_POWER_DOWN_PHY;
    reply.f.field_20 = request.w0.field_20;
    dp_mst_send_reply(&reply, 2, 1, MST_REPLY_POWER_DOWN_PHY, 2);
    *dp_mst_ctl_reg_blocks[dp_mst_message_state_port] |= 0x20;
}

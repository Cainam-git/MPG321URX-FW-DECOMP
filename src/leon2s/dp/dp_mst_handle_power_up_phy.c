/* dp_mst_handle_power_up_phy  (FUN_a00d8fdc)
 *
 * Answer the MST request 0x24 (POWER_UP_PHY).
 * Name basis: proven - case 0x24 = POWER_UP_PHY, request number of the DisplayPort MST sideband message set;
 *   called from dp_mst_dispatch_request
 *
 * Matching notes
 * --------------
 * FUN_a00d8fdc (leon2s 0xa00d8fdc-0xa00d904c, 112 bytes), flags -mcpu=v8 -Os -g.
 * Source form: bit-fields (big-endian, first field = MSB) as in dp_mst_handle_remote_i2c_write; the halfword
 * clears are stores through a halfword view of each union (the firmware uses clrh).
 */
extern void dp_mst_parse_request(void *, int, int, int);
extern void dp_mst_send_reply(void *, int, int, int, int);
#define MST_REQUEST_POWER_UP_PHY 0x24   /* request number */
#define MST_UNPACK_POWER_UP_PHY  0x1b   /* unpack type that dp_mst_parse_request is given */
#define MST_REPLY_POWER_UP_PHY   0xb    /* reply type 11: dp_mst_pack_port_reply_high */

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
 * Answer the request POWER_UP_PHY (0x24). The request body is unpacked (unpack type 0x1b); the reply (type 11,
 * 2 bytes) holds the request number and the 4-bit field at bits 20..23 of the unpacked request's first word,
 * copied to the same bit positions of the reply header. The first halfword of both is cleared first.
 * Called by dp_mst_dispatch_request.
 */
void dp_mst_handle_power_up_phy(void)
{
    union unpacked_request request;
    union reply reply;

    request.h[0] = 0;
    reply.h[0] = 0;
    dp_mst_parse_request(&request, 0, 1, MST_UNPACK_POWER_UP_PHY);
    reply.f.request = MST_REQUEST_POWER_UP_PHY;
    reply.f.field_20 = request.w0.field_20;
    dp_mst_send_reply(&reply, 2, 1, MST_REPLY_POWER_UP_PHY, 2);
}

/* dp_mst_handle_clear_payload_table  (FUN_a00d8714)
 *
 * Answer the MST request 0x14 (CLEAR_PAYLOAD_ID_TABLE).
 * Name basis: proven - case 0x14 = CLEAR_PAYLOAD_ID_TABLE, request number of the DisplayPort MST sideband
 *   message set; called from dp_mst_dispatch_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d8714 @ 0xa00d8714-0xa00d87fc (58 words), flags -mcpu=v8 -Os -g.
 * Source form: a 7-bit bit-field for the stack byte; the register block is reached through
 * 'volatile unsigned int *dp_mst_msg_reg_blocks[]' (same pointers as dp_mst_trim_up_message_record; the firmware
 * reads and writes +0x2ac / +0x2b0 twice per pass); every access after the first re-indexes the table (firmware
 * reloads). volatile only on the register blocks behind dp_mst_msg_reg_blocks[].
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned short dp_mst_message_state;
extern unsigned short dp_mst_message_state_half_2;
extern volatile unsigned int *dp_mst_msg_reg_blocks[];
extern void dp_mst_send_reply(void *, int, int, int, int);
#define MST_REQUEST_CLEAR_PAYLOAD_TABLE 0x14    /* request number */
#define MST_REPLY_ONE_BYTE              6       /* reply type 6: dp_mst_pack_request_number_copy packs one byte */

/* The reply byte: request number in bits 0..6; bit 7 is not written (whatever the stack held). */
struct request_byte {
    unsigned char bit7 : 1;
    unsigned char request : 7;
};

/*
 * Answer the request CLEAR_PAYLOAD_ID_TABLE (0x14).
 *
 * The two halfwords at the start of the MST message state (dp_mst_message_state and dp_mst_message_state_half_2)
 * are cleared. Then, for i = 0..3, the message register block of the current port is stepped through:
 * the low byte at +0x2AC is saved, bits 6..7 of it are set to i + 1, +0x284 is written 0, bit 4 of +0x2B0 is set
 * and cleared again, and the saved byte is written back to +0x2AC. The reply is one byte holding the request
 * number. Called by dp_mst_dispatch_request.
 */
void dp_mst_handle_clear_payload_table(void)
{
    struct request_byte reply;
    unsigned char i;
    unsigned char saved;
    volatile unsigned int *regs;

    reply.request = MST_REQUEST_CLEAR_PAYLOAD_TABLE;
    dp_mst_message_state_half_2 = 0;
    dp_mst_message_state = 0;
    for (i = 0; i < 4; i++) {
        regs = dp_mst_msg_reg_blocks[dp_mst_message_state_port];
        saved = regs[0x2ac / 4];
        regs[0x2ac / 4] = (saved & 0x3f) | ((i + 1) << 6);
        dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x284 / 4] = 0;
        dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2b0 / 4] |= 0x10;
        dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2b0 / 4] &= ~0x10;
        dp_mst_msg_reg_blocks[dp_mst_message_state_port][0x2ac / 4] = saved;
    }
    dp_mst_send_reply(&reply, 2, 1, MST_REPLY_ONE_BYTE, 1);
}

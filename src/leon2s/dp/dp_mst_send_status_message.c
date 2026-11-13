/* dp_mst_send_status_message  (FUN_a00dba70)
 *
 * Build a message from 16 register bytes and two status reads and send it.
 * Name basis: descriptive - control bits set from two reads or cleared
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dba70 @ 0xa00dba70-0xa00dbc8c, -mcpu=v8 -Os -g.
 * Source form: the message is a 24-byte union (byte view and big-endian bit-fields, first field = most
 * significant bit), as in dp_mst_queue_reply_header; the register-block pointers are volatile (as in dp_mst_trim_up_message_record); the
 * three branches on the version byte keep their repeated stores.
 */
/* Down-reply message under construction: word 0 holds a 7-bit field (set to 2) and a 4-bit field (set to 1); word 4 holds the status bits. */
union Msg {
    struct {
        unsigned int b31 : 1, f24 : 7, f20 : 4, rest : 20;
        unsigned int w1, w2, w3;
        unsigned int a : 8, b23 : 1, b22 : 1, f16 : 6, b15 : 1, b14 : 1, b13 : 1, b12 : 1, n8 : 4, low : 8;
    } h;
    unsigned char b[0x18];
};
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_byte_0x4e;
extern unsigned char dp_mst_message_state_byte_0x4b;
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern unsigned char dp_tx_aux_request_copy(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern void dp_mst_send_reply(void *, int, int, int, int);

/*
 * Send the connection-status message for the current MST port, or return 0 without sending.
 *
 * The message body is the 16 bytes read (low byte of each word) from words 0x340..0x34f of the port's
 * register block. When all 16 are zero nothing is sent and the result is 0.
 *
 * on == 1: read the byte at address 0 and the byte at address 0x21 of output 0 with AUX read
 *   requests and keep them in the MST message state. Bit 13 of word 4 is set and bit 14 cleared. The
 *   nibble at bits 8..11 is 3 when the first byte is 0x11 or less, otherwise 2; in that case bit 12 is
 *   also set when bit 0 of the second byte is set. Bit 0 of register word 0x814/4 is set.
 * on != 1: bits 8..14 of word 4 are cleared and bit 0 of register word 0x814/4 is cleared.
 *
 * Either way the message goes to dp_mst_send_reply as type 0x11, 0x13 bytes long. Returns 1 when sent.
 * Called by dp_mst_notify_task, which passes 1 for its "connected" step and 0 for the other.
 */
int dp_mst_send_status_message(unsigned char on)
{
    union Msg m;
    unsigned char t; /* receives the byte of each AUX read */
    volatile unsigned int *regs;
    unsigned char i;

    /* Fixed header fields. */
    m.h.f24 = 2;
    m.h.f20 = 1;
    regs = dp_mst_ctl_reg_blocks[dp_mst_message_state_port];
    /* Message bytes 2..17 come from the register block. */
    for (i = 0; i <= 0xf; i++)
        m.b[2 + i] = regs[0x340 + i];
    for (i = 0; i <= 0xf; i++)
        if (m.b[2 + i] != 0)
            break;
    if (i > 0xf) /* all 16 bytes zero: nothing to send */
        return 0;
    if (on == 1) {
        dp_tx_aux_request_copy(0, 0x90, 0, 0, &t);
        dp_mst_message_state_byte_0x4e = t;
        dp_tx_aux_request_copy(0, 0x90, 0x21, 0, &t);
        dp_mst_message_state_byte_0x4b = t;
        if (dp_mst_message_state_byte_0x4e <= 0x11) { /* first read (address 0) */
            m.h.b14 = 0;
            m.h.b13 = 1;
            m.h.b12 = 0;
            m.h.n8 = 3;
        } else if (t & 1) { /* t is the second read (address 0x21) */
            m.h.b14 = 0;
            m.h.b13 = 1;
            m.h.b12 = 1;
            m.h.n8 = 2;
        } else {
            m.h.b14 = 0;
            m.h.b13 = 1;
            m.h.b12 = 0;
            m.h.n8 = 2;
        }
        dp_mst_ctl_reg_blocks[dp_mst_message_state_port][0x814 / 4] |= 1;
    } else {
        m.h.b14 = 0;
        m.h.b13 = 0;
        m.h.b12 = 0;
        m.h.n8 = 0;
        dp_mst_ctl_reg_blocks[dp_mst_message_state_port][0x814 / 4] &= ~1;
    }
    dp_mst_send_reply(&m, 2, 1, 0x11, 0x13);
    return 1;
}

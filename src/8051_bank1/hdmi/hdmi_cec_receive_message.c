/* hdmi_cec_receive_message  (FUN_CODE_78ba)
 *
 * Take one received HDMI CEC message and answer or flag it.
 * Returns: status code (5, 6 or the handled state)
 * Note: Standby, Active Source, Inactive Source and User Control requests are queued as bits 1..4 of
 *   hdmi_cec_request_flags (0xA758).
 * Name basis: proven - CEC opcodes: 0x83 -> reply 0x84 (physical address), 0x91 -> 0x32 'eng' (menu language),
 *   0x8F -> 0x90, 0x36/0x82/0x9D flags
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * LARGE local: msg[16] at XDATA 0xA474; header in R7, loop counter in R6.
 * volatile on reg_hdmi_cec_status: read again for the bit-0 test.
 * Source forms: the case bodies are written in the firmware's code order (the ?C?CCASE table itself is sorted);
 *   the first switch lists STANDBY before ACTIVE_SOURCE; the bit-0 test wraps the rest of the function so
 *   'return CEC_RX_NONE' is the shared tail; the sys_is_on_crystal_clock test is negated (first arm stores 0).
 */

/* Bits of reg_hdmi_cec_status; a bit is cleared by writing it back. */
#define CEC_STATUS_RECEIVED      0x01  /* a message is waiting in the receive registers */
#define CEC_STATUS_BITS_3_5      0x38  /* any of them ends the call with CEC_RX_STATUS_BITS */

/* Return values. */
#define CEC_RX_HANDLED           1     /* hdmi_cec_poll_request then looks at hdmi_cec_request_flags */
#define CEC_RX_STATUS_BITS       5
#define CEC_RX_NONE              6     /* nothing received, or a receive with a count of 0 */

#define CEC_INITIATOR_SHIFT      4     /* header bits 7..4 = sender, bits 3..0 = destination */
#define CEC_DEST_MASK            0x0f
#define CEC_DEST_0F              0x0f  /* destination of the messages of the first switch */

/* Opcodes (first data byte) handled here; the names follow the bits of hdmi_cec_request_flags and the replies. */
#define CEC_OP_USER_CONTROL      0x44  /* operand byte kept in hdmi_cec_operand */
#define CEC_OP_STANDBY           0x36
#define CEC_OP_ACTIVE_SOURCE     0x82
#define CEC_OP_INACTIVE_SOURCE   0x9d
#define CEC_OP_ASK_PHYS_ADDR     0x83  /* answered with CEC_OP_PHYS_ADDR */
#define CEC_OP_PHYS_ADDR         0x84
#define CEC_OP_ASK_LANGUAGE      0x91  /* answered with CEC_OP_LANGUAGE "eng" */
#define CEC_OP_LANGUAGE          0x32
#define CEC_OP_8F                0x8f  /* answered with 0x90 and the crystal-clock state */
#define CEC_REPLY_90             0x90
#define CEC_OP_0F                0x0f  /* answered with 00 02 */
#define CEC_OP_93                0x93  /* answered with 00 00 00, as 0xFF */
#define CEC_OP_FF                0xff

/* Bits of hdmi_cec_request_flags (bit 0 is not set here). */
#define CEC_REQ_STANDBY          0x02
#define CEC_REQ_ACTIVE_SOURCE    0x04
#define CEC_REQ_INACTIVE_SOURCE  0x08
#define CEC_REQ_USER_CONTROL     0x10

#define CEC_MSG_BYTES            16

extern unsigned char volatile xdata reg_hdmi_cec_status;
extern unsigned char xdata reg_hdmi_cec_rx_count;
extern unsigned char xdata reg_hdmi_cec_rx_header;
extern unsigned char xdata reg_hdmi_cec_rx_data[16];
extern unsigned char xdata reg_hdmi_cec_tx_data[4];
extern unsigned char xdata hdmi_cec_active_source, hdmi_cec_request_flags, hdmi_cec_operand, hdmi_cec_initiator;
extern bit sys_is_on_crystal_clock(void);
extern void hdmi_cec_send_reply(unsigned char header, unsigned char count);

/* Take one message from the CEC receiver and act on it. Only caller: hdmi_cec_poll_request, which turns the
 * request bits set here into its return value when this routine returns CEC_RX_HANDLED.
 * Order of the checks:
 *   1. Any of status bits 3..5 set: they are cleared, return CEC_RX_STATUS_BITS (nothing is read).
 *   2. Status bit 0 clear: return CEC_RX_NONE. Bit 0 set with a receive count of 0: bit 0 is cleared, return
 *      CEC_RX_NONE.
 *   3. Otherwise header and the 16 data bytes are copied, the sender (header bits 7..4) is kept in
 *      hdmi_cec_initiator, and the opcode decides:
 *      - destination 0x0F: Standby and Active Source only set request bits (Active Source also records the
 *        sender in hdmi_cec_active_source, and sets its bit only when the first operand byte is not 0);
 *      - any other destination: Inactive Source, Standby and User Control set request bits (User Control keeps its
 *        operand); 0x83, 0x91, 0x8F, 0x0F, 0x93 and 0xFF are answered at once through hdmi_cec_send_reply, the
 *        0x83 answer to destination 0x0F, the others to the sender.
 *      Other opcodes are dropped. Bit 0 is cleared and CEC_RX_HANDLED returned.
 */
unsigned char hdmi_cec_receive_message(void)
{
    unsigned char msg[16];
    unsigned char header;
    unsigned char i;

    if (reg_hdmi_cec_status & CEC_STATUS_BITS_3_5) {
        reg_hdmi_cec_status = CEC_STATUS_BITS_3_5;
        return CEC_RX_STATUS_BITS;
    }
    if (reg_hdmi_cec_status & CEC_STATUS_RECEIVED) {
        if (reg_hdmi_cec_rx_count == 0) {
            reg_hdmi_cec_status = CEC_STATUS_RECEIVED;
            return CEC_RX_NONE;
        }
        header = reg_hdmi_cec_rx_header;
        for (i = 0; i < CEC_MSG_BYTES; i++)
            msg[i] = reg_hdmi_cec_rx_data[i];
        hdmi_cec_initiator = (header & 0xf0) >> CEC_INITIATOR_SHIFT;
        if ((header & CEC_DEST_MASK) == CEC_DEST_0F) {
            switch (msg[0]) {
            case CEC_OP_STANDBY:
                hdmi_cec_request_flags |= CEC_REQ_STANDBY;
                break;
            case CEC_OP_ACTIVE_SOURCE:
                hdmi_cec_active_source = hdmi_cec_initiator;
                if (msg[1])
                    hdmi_cec_request_flags |= CEC_REQ_ACTIVE_SOURCE;
                break;
            }
        } else {
            switch (msg[0]) {
            case CEC_OP_INACTIVE_SOURCE:
                hdmi_cec_request_flags |= CEC_REQ_INACTIVE_SOURCE;
                break;
            case CEC_OP_ASK_PHYS_ADDR:
                reg_hdmi_cec_tx_data[0] = CEC_OP_PHYS_ADDR;
                reg_hdmi_cec_tx_data[1] = 0x00;
                reg_hdmi_cec_tx_data[2] = 0x00;
                reg_hdmi_cec_tx_data[3] = 0x00;
                hdmi_cec_send_reply(CEC_DEST_0F, 4);
                break;
            case CEC_OP_STANDBY:
                hdmi_cec_request_flags |= CEC_REQ_STANDBY;
                break;
            case CEC_OP_ASK_LANGUAGE:
                reg_hdmi_cec_tx_data[0] = CEC_OP_LANGUAGE;
                reg_hdmi_cec_tx_data[1] = 0x65;    /* 'e' */
                reg_hdmi_cec_tx_data[2] = 0x6e;    /* 'n' */
                reg_hdmi_cec_tx_data[3] = 0x67;    /* 'g' */
                hdmi_cec_send_reply(hdmi_cec_initiator, 4);
                break;
            case CEC_OP_8F:
                /* 1 on the crystal clock (set by power saving and power off), else 0. */
                reg_hdmi_cec_tx_data[0] = CEC_REPLY_90;
                if (!sys_is_on_crystal_clock())
                    reg_hdmi_cec_tx_data[1] = 0x00;
                else
                    reg_hdmi_cec_tx_data[1] = 0x01;
                hdmi_cec_send_reply(hdmi_cec_initiator, 2);
                break;
            case CEC_OP_0F:
                reg_hdmi_cec_tx_data[0] = 0x00;
                reg_hdmi_cec_tx_data[1] = 0x02;
                hdmi_cec_send_reply(hdmi_cec_initiator, 2);
                break;
            case CEC_OP_93:
            case CEC_OP_FF:
                reg_hdmi_cec_tx_data[0] = 0x00;
                reg_hdmi_cec_tx_data[1] = 0x00;
                reg_hdmi_cec_tx_data[2] = 0x00;
                hdmi_cec_send_reply(hdmi_cec_initiator, 3);
                break;
            case CEC_OP_USER_CONTROL:
                hdmi_cec_operand = msg[1];
                hdmi_cec_request_flags |= CEC_REQ_USER_CONTROL;
                break;
            }
        }
        reg_hdmi_cec_status = CEC_STATUS_RECEIVED;
        return CEC_RX_HANDLED;
    }
    return CEC_RX_NONE;
}

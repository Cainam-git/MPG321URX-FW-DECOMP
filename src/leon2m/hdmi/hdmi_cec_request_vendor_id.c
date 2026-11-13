/* hdmi_cec_request_vendor_id  (FUN_a00fce40)
 *
 * Clear the stored vendor id answer and send CEC message 0x8C (give device vendor id).
 * Note: Goes to the stored peer address, or to addresses 8 and 4 when that is 0xF; the answer is stored later
 *   by the receive routine.
 * Name basis: derived - opcode 0x8C (give device vendor id); clears the four answer bytes at 0xA802C978
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fce40 @ 0xa00fce40, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the send steps are a static helper that the compiler inlines; the four
 * answer bytes are cleared in descending index order.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Registers of the CEC block at 0xCF012000 (the same names as in hdmi_cec_receive_and_reply). */
#define CEC_STATUS          0xcf012034
#define CEC_TX_LENGTH       0xcf012040  /* number of message bytes to send */
#define CEC_TX_DEST         0xcf012080  /* destination address of the message to send */
#define CEC_TX_DATA0        0xcf012084  /* first byte of the message to send (the message code) */
#define CEC_STATUS_SEND     0x2e        /* the send waits for one of these bits */
#define CEC_SEND_TIMEOUT_TICKS 1000     /* longest wait for the end of a send, in timer_get_ticks16 ticks */

#define CEC_DEST_0F         0xf
#define CEC_GIVE_VENDOR_ID  0x8c        /* message code written to CEC_TX_DATA0 */

extern void (*hdmi_cec_send_hook)(int, int);
extern unsigned char hdmi_cec_peer_address;
extern unsigned char hdmi_cec_rx_word[4];
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern void ipc_signal_alive(void);

/* Send the message already written to CEC_TX_DATA0 (one byte) to address `dest`. The same steps as in
   hdmi_cec_send_user_control: the send hook gets dest and the length 1 when it is set; the wait is bounded by
   CEC_SEND_TIMEOUT_TICKS. */
static void cec_send_one_byte(unsigned char dest)
{
    unsigned short start;

    R(CEC_STATUS) = CEC_STATUS_SEND;
    if (hdmi_cec_send_hook != 0)
        hdmi_cec_send_hook(dest, 1);
    else {
        R(CEC_TX_DEST) = dest;
        R(CEC_TX_LENGTH) = 1;
    }
    start = timer_get_ticks16();
    while (!(R(CEC_STATUS) & CEC_STATUS_SEND)) {
        ipc_signal_alive();
        if (timer_ticks_since(start) > CEC_SEND_TIMEOUT_TICKS)
            break;
    }
    (void)R(CEC_STATUS);
    R(CEC_STATUS) = CEC_STATUS_SEND;
}

/*
 * Ask a device for its vendor id: send the one-byte message 0x8C.
 * The destination is hdmi_cec_peer_address (the high nibble of the address byte of the last received message).
 * When that is 0xF, the message is sent twice, first to address 8, then to address 4.
 * The four answer bytes (hdmi_cec_rx_word) are cleared before the send. The reply is stored there by
 * hdmi_cec_receive_and_reply when a message 0x87 arrives, and read back with hdmi_cec_get_message_word.
 * Called by hdmi_cec_api_send_action (action 5).
 */
void hdmi_cec_request_vendor_id(void)
{
    unsigned char dest;

    R(CEC_TX_DATA0) = CEC_GIVE_VENDOR_ID;
    hdmi_cec_rx_word[3] = 0;
    hdmi_cec_rx_word[2] = 0;
    hdmi_cec_rx_word[1] = 0;
    hdmi_cec_rx_word[0] = 0;
    dest = hdmi_cec_peer_address;
    if (dest == CEC_DEST_0F) {
        cec_send_one_byte(8);
        cec_send_one_byte(4);
    } else
        cec_send_one_byte(dest);
}

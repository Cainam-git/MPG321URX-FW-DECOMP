/* hdmi_cec_send_user_control  (FUN_a00fd074)
 *
 * Send CEC message 0x44 with one operand.
 * Name basis: derived - opcode 0x44 (user control pressed)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fd074 @ 0xa00fd074, flags -mcpu=v8 -O3 -g.
 * Source form: the send steps are a static helper that the compiler inlines; the final status read is a plain
 * volatile read whose value is dropped.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Registers of the CEC block at 0xCF012000 (the same names as in hdmi_cec_receive_and_reply). */
#define CEC_STATUS          0xcf012034
#define CEC_TX_LENGTH       0xcf012040  /* number of message bytes to send */
#define CEC_TX_DEST         0xcf012080  /* destination address of the message to send */
#define CEC_TX_DATA0        0xcf012084  /* first byte of the message to send (the message code) */
#define CEC_TX_DATA1        0xcf012088
#define CEC_STATUS_SEND     0x2e        /* the send waits for one of these bits */
#define CEC_SEND_TIMEOUT_TICKS 1000     /* longest wait for the end of a send, in timer_get_ticks16 ticks */

#define CEC_DEST_0F         0xf
#define CEC_USER_CONTROL    0x44        /* message code written to CEC_TX_DATA0 */

extern void (*hdmi_cec_send_hook)(int, int);
extern unsigned char hdmi_cec_peer_address;
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern void ipc_signal_alive(void);

/* Send the message already written to CEC_TX_DATA0.. (two bytes) to address `dest`. The same steps as in
   hdmi_cec_send_message_first: the send hook gets dest and the length 2 when it is set; the wait is bounded by
   CEC_SEND_TIMEOUT_TICKS. */
static void cec_send_two_bytes(unsigned char dest)
{
    unsigned short start;

    R(CEC_STATUS) = CEC_STATUS_SEND;
    if (hdmi_cec_send_hook != 0)
        hdmi_cec_send_hook(dest, 2);
    else {
        R(CEC_TX_DEST) = dest;
        R(CEC_TX_LENGTH) = 2;
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
 * Send message code 0x44 with one operand byte `operand`.
 * The destination is hdmi_cec_peer_address (the high nibble of the address byte of the last received
 * message). When that is 0xF, the message is sent twice, first to address 8, then to address 4.
 * Called by hdmi_cec_api_send_action (action 6 passes 0x6D).
 */
void hdmi_cec_send_user_control(unsigned char operand)
{
    unsigned char dest;

    R(CEC_TX_DATA0) = CEC_USER_CONTROL;
    R(CEC_TX_DATA1) = operand;
    dest = hdmi_cec_peer_address;
    if (dest == CEC_DEST_0F) {
        cec_send_two_bytes(8);
        cec_send_two_bytes(4);
    } else
        cec_send_two_bytes(dest);
}

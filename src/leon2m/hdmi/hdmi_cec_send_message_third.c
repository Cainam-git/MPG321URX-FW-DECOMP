/* hdmi_cec_send_message_third  (FUN_a00fcbec)
 *
 * Send the third of three fixed CEC messages and wait for it to go out.
 * Name basis: descriptive - twin of hdmi_cec_send_message_first with other constants
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fcbec @ 0xa00fcbec, flags -mcpu=v8 -O3 -g.
 * Source form: the three message routines are the same code with one constant different (0x36 / 0x82 / 0x86).
 * The final status read is a plain volatile read whose value is dropped.
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* Registers of the CEC block at 0xCF012000 (the same names as in hdmi_cec_receive_and_reply). */
#define CEC_STATUS          0xcf012034  /* the bits of CEC_STATUS_SEND are written to it before and after a send */
#define CEC_TX_LENGTH       0xcf012040  /* number of message bytes to send */
#define CEC_TX_DEST         0xcf012080  /* destination address of the message to send */
#define CEC_TX_DATA0        0xcf012084  /* first byte of the message to send (the message code) */
#define CEC_STATUS_SEND     0x2e        /* the send waits for one of these bits */
#define CEC_SEND_TIMEOUT_TICKS 1000     /* longest wait for the end of a send, in timer_get_ticks16 ticks */
#define CEC_DEST_0F         0xf         /* destination address used here */

extern void (*hdmi_cec_send_hook)(int, int);
extern unsigned short timer_get_ticks16(void);
extern void ipc_signal_alive(void);
extern unsigned short timer_ticks_since(unsigned short);

/*
 * Send the third of the three fixed one-byte CEC messages, message code 0x86, to address 0xF and wait for it to
 * go out. Called by hdmi_cec_api_send_action (action 3). Same steps as the first message; only the code differs.
 *
 * Steps: write the code to CEC_TX_DATA0; write CEC_STATUS_SEND to CEC_STATUS; start the send through the send
 * hook (hdmi_cec_set_send_hook) when one is set, else by writing destination and length to the CEC block;
 * then wait until a CEC_STATUS_SEND bit shows, calling ipc_signal_alive meanwhile, but at most
 * CEC_SEND_TIMEOUT_TICKS ticks; finally read CEC_STATUS and write CEC_STATUS_SEND back.
 */
void hdmi_cec_send_message_third(void)
{
    unsigned short start;

    REG(CEC_TX_DATA0) = 0x86;
    REG(CEC_STATUS) = CEC_STATUS_SEND;
    if (hdmi_cec_send_hook != 0)
        hdmi_cec_send_hook(CEC_DEST_0F, 1);
    else {
        REG(CEC_TX_DEST) = CEC_DEST_0F;
        REG(CEC_TX_LENGTH) = 1;
    }
    start = timer_get_ticks16();
    while (!(REG(CEC_STATUS) & CEC_STATUS_SEND)) {
        ipc_signal_alive();
        if (timer_ticks_since(start) > CEC_SEND_TIMEOUT_TICKS)
            break;
    }
    REG(CEC_STATUS);
    REG(CEC_STATUS) = CEC_STATUS_SEND;
}

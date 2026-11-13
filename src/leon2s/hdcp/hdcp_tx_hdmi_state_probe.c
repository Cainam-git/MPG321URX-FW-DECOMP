/* hdcp_tx_hdmi_state_probe  (FUN_a00ccd20)
 *
 * State handler: probe the receiver and go on or give up.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ccd20 @ 0xa00ccd20-0xa00ccdb4 (148 bytes, 37 words)
 * Flags: -mcpu=v8 -Os -g.
 */
/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records). */
struct hdcp_tx_record {
    unsigned int f31 : 1;               /* bit 31 */
    unsigned int f30 : 1;
    unsigned int f29 : 1;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int b20 : 1;
    unsigned int b19 : 1;
    unsigned int b18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, written by the state handlers */
    unsigned char state;                /* +2: state of the handshake, the case value of the run_state switch */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9: 0xFF = none */
    unsigned char bytes_0xa_0xb[2];
    unsigned int word_0xc;
    unsigned int word_0x10;
    unsigned char byte_0x14;
    unsigned char byte_0x15;
    unsigned short halfword_0x16;
};
/* Result of a state handler, read by hdcp_tx_select_next_state. STEP_AGAIN keeps the state until the time limit of
   the state has run out (hdcp_tx_service_port then turns it into STEP_BACK). */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern void hdcp_tx_disable_output(unsigned char);
extern unsigned int hdcp_tx_hdmi_probe_receiver(unsigned char);
extern void hdcp_tx_hdmi_set_reg27_bit0(unsigned char, int);

#define PROBE_RESULT_0x22       0x22    /* return value of hdcp_tx_hdmi_probe_receiver that gives STEP_OTHER */

/*
 * State 1 of hdcp_tx_hdmi_run_state: switch the output's protection off and probe the receiver.
 *
 * step_result is STEP_NEXT first. If hdcp_tx_hdmi_probe_receiver returns 0 it becomes STEP_AGAIN. Otherwise bit 0
 * of register 0x27 of the output's block is cleared, and the result is STEP_OTHER when the return value is 0x22
 * (any other non-zero value leaves STEP_NEXT).
 */
void hdcp_tx_hdmi_state_probe(unsigned char port)
{
    unsigned char probe;

    hdcp_tx_disable_output(port);
    hdcp_tx_records[port].step_result = STEP_NEXT;
    probe = hdcp_tx_hdmi_probe_receiver(port);
    if (probe == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
    } else {
        hdcp_tx_hdmi_set_reg27_bit0(port, 0);
        if (probe == PROBE_RESULT_0x22)
            hdcp_tx_records[port].step_result = STEP_OTHER;
    }
}

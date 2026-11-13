/* hdcp_tx_hdmi_state_stay_copy  (FUN_a00cc8d4)
 *
 * State handler: set the result to 3 (stay in this state).
 * Note: Identical copy of hdcp_tx_hdmi_state_stay.
 * Name basis: derived - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_hdmi_run_state; result field = 3
 *
 * Matching notes
 * --------------
 * FUN_a00cc8d4 (leon2s 0xa00cc8d4-0xa00cc900, 44 bytes, leaf), flags -mcpu=v8 -Os -g.
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

/*
 * State 0x4E of hdcp_tx_hdmi_run_state: report STEP_AGAIN (step_result 3) for the output and do nothing else.
 * Same body as hdcp_tx_dp_state_stay and hdcp_tx_dp_state_stay_copy.
 */
void hdcp_tx_hdmi_state_stay_copy(unsigned char port)
{
    hdcp_tx_records[port].step_result = STEP_AGAIN;
}

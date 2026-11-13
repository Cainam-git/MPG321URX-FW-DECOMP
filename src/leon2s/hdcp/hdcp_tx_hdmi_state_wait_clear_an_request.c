/* hdcp_tx_hdmi_state_wait_clear_an_request  (FUN_a00d01f4)
 *
 * State handler: stay while timer port + 8 runs, then clear the An request bit of the output.
 * Name basis: derived - state 0x10 of hdcp_tx_hdmi_run_state; hdcp_tx_get_timer(port + 8), then
 *   hdcp_tx_hdmi_clear_an_request (bit 3 of register 0x0F)
 *
 * Matching notes
 * --------------
 * FUN_a00d01f4 (leon2s, 0xa00d01f4-0xa00d0260, 108 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the step result is the 2-bit bit-field of the record (the firmware does a word read-modify-write
 * for it); the last call is a tail call.
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
extern int hdcp_tx_get_timer(unsigned int);
extern void hdcp_tx_hdmi_clear_an_request(unsigned int);

#define TIMER_PORT_BASE         8               /* timer number = port + 8 */

/*
 * State 0x10 of hdcp_tx_hdmi_run_state: wait for the timer of the output.
 *
 * Sets step_result to STEP_NEXT. While timer port + 8 is not 0, step_result becomes STEP_AGAIN and the routine
 * ends. When it has run out, hdcp_tx_hdmi_clear_an_request(port) is called (it clears bit 3 of register 0x0F of
 * the output's block).
 */
void hdcp_tx_hdmi_state_wait_clear_an_request(unsigned char port)
{
    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (hdcp_tx_get_timer(port + TIMER_PORT_BASE) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_hdmi_clear_an_request(port);
}

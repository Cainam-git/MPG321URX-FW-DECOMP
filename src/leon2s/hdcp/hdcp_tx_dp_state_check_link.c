/* hdcp_tx_dp_state_check_link  (FUN_a00d0798)
 *
 * State handler: set the step result from the sink check, then start a timer and switch protection off.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00d0798 (leon2s 0xa00d0798-0xa00d0828, 144 bytes), flags -mcpu=v8 -Os -g.
 * Source form: step_result is set to 1 first and again after the timer call, as in the firmware.
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
extern unsigned char dp_tx_is_connected(unsigned int);
extern void hdcp_tx_set_timer(unsigned int, unsigned int);
extern void hdcp_tx_dp_set_enable(unsigned char);

#define TIMER_DP_WAIT           10      /* timer number: port 2 + 8, the one hdcp_tx_dp_state_wait_timer waits for */
#define TIMER_DP_WAIT_TICKS     300

/*
 * State 0 of hdcp_tx_dp_run_state: start of the DisplayPort handshake.
 *
 * Sets step_result to STEP_NEXT. If the DisplayPort output has no sink (dp_tx_is_connected(0) returns 0) the
 * step result becomes STEP_BACK and the routine ends. Otherwise timer 10 is set to 300 ticks, step_result is set
 * to STEP_NEXT again and the protection is switched off (hdcp_tx_dp_set_enable(0)).
 */
void hdcp_tx_dp_state_check_link(unsigned char port)
{
    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (dp_tx_is_connected(0) == 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    hdcp_tx_set_timer(TIMER_DP_WAIT, TIMER_DP_WAIT_TICKS);
    hdcp_tx_records[port].step_result = STEP_NEXT;
    hdcp_tx_dp_set_enable(0);
}

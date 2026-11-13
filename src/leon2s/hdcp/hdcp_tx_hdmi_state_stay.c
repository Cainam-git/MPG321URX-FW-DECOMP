/* hdcp_tx_hdmi_state_stay  (FUN_a00c8aec)
 *
 * State handler: set the result to 3 (stay in this state).
 * Name basis: derived - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_hdmi_run_state; result field = 3, on which hdcp_tx_select_next_state returns at once
 *
 * Matching notes
 * --------------
 * FUN_a00c8aec (leon2s 0xa00c8aec-0xa00c8b18, 44 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
/* Output record of hdcp_tx_records (24 bytes). Word 0 bit-fields, most significant bit first. */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;                  /* bit 28 */
    unsigned int tries_left : 4;                /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;               /* bits 16..17: STEP_* */
    unsigned int state : 8;                     /* byte +2: state of hdcp_tx_hdmi_run_state */
    unsigned char device_count;                 /* +3 */
    unsigned char level;                        /* +4 */
    unsigned char count_overflow;               /* +5 */
    unsigned char level_overflow;               /* +6 */
    unsigned char pad[17];
};
/* Result of a state handler (step_result), read by hdcp_tx_select_next_state. */
enum { STEP_BACK = 0, STEP_NEXT = 1, STEP_OTHER = 2, STEP_AGAIN = 3 };
extern struct hdcp_tx_record hdcp_tx_records[];

/*
 * State 18 of hdcp_tx_hdmi_run_state: set the step result of the output record to STEP_AGAIN (3).
 */
void hdcp_tx_hdmi_state_stay(unsigned char port)
{
    hdcp_tx_records[port].step_result = STEP_AGAIN;
}

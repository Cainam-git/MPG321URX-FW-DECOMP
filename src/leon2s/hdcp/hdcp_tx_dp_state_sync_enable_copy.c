/* hdcp_tx_dp_state_sync_enable_copy  (FUN_a00cf980)
 *
 * State handler: set the result to 'next' and bring the enable bit to the wanted value.
 * Note: Same body as hdcp_tx_dp_state_sync_enable; state 0x4F of hdcp_tx_dp_run_state.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine; called from
 *   hdcp_tx_dp_run_state (state 0x4F); hdcp_tx_dp_set_enable when the wanted value differs from
 *   hdcp_tx_dp_get_enable_bit
 *
 * Matching notes
 * --------------
 * FUN_a00cf980 (leon2s, 0xa00cf980-0xa00cf9e8, 26 words incl. the shared nop/ret/restore tail).
 * Flags -mcpu=v8 -Os -g.
 * Source form: dp_tx_option_enabled_stub_copy2 takes the port as its argument (the firmware computes 'and
 * %i0,0xff,%o0' straight into %o0 and keeps it there up to the call); the record is addressed as words, index
 * port * 6.
 */
extern unsigned int hdcp_tx_records[];
extern unsigned int dp_tx_option_enabled_stub_copy2(unsigned char);
extern unsigned int hdcp_tx_dp_get_enable_bit(void);
extern void hdcp_tx_dp_set_enable(unsigned int);

#define RECORD_WORDS            6       /* a record is 24 bytes = 6 words */
#define STEP_RESULT_SHIFT       16
#define STEP_RESULT_MASK        (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17 */
#define STEP_NEXT_BITS          (1 << STEP_RESULT_SHIFT)

/*
 * State 0x4F of hdcp_tx_dp_run_state: set step_result to STEP_NEXT, then call hdcp_tx_dp_set_enable with the
 * value of dp_tx_option_enabled_stub_copy2 (always 1) when that differs from hdcp_tx_dp_get_enable_bit.
 * Same body as hdcp_tx_dp_state_sync_enable.
 */
void hdcp_tx_dp_state_sync_enable_copy(unsigned char port)
{
    unsigned int base = port * RECORD_WORDS;
    unsigned char wanted;

    hdcp_tx_records[base] = (hdcp_tx_records[base] & ~STEP_RESULT_MASK) | STEP_NEXT_BITS;
    wanted = dp_tx_option_enabled_stub_copy2(port);
    if (wanted != (unsigned char)hdcp_tx_dp_get_enable_bit())
        hdcp_tx_dp_set_enable(wanted);
}

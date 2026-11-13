/* hdcp_tx_dp_state_sync_enable  (FUN_a00cdc74)
 *
 * Set the enable bit to the value of dp_tx_option_enabled_stub_copy2 (always 1) when it differs from the
 * current bit.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_dp_run_state; same body as hdcp_tx_dp_state_sync_enable_copy
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cdc74 @ 0xa00cdc74-0xa00cdcdc (26 words incl. the unreachable ret/restore pair
 * FUN_a00cdcd4), flags -mcpu=v8 -Os -g.
 * Source form: dp_tx_option_enabled_stub_copy2 takes the port as its argument (the zero-extended port stays in
 * %o0 up to the call); word 0 of the record is handled as a whole.
 */
/* Word 0 of a copy-protection record (24 bytes, array hdcp_tx_records), used as a whole. Its bits 16..17 hold the
   step result: 0 = STEP_BACK, 1 = STEP_NEXT, 2 = STEP_OTHER, 3 = STEP_AGAIN. */
struct hdcp_tx_record_words {
    unsigned int word0;
    unsigned char rest[0x14];
};

#define STEP_RESULT_SHIFT       16
#define STEP_RESULT_MASK        (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17 */
extern struct hdcp_tx_record_words hdcp_tx_records[];
extern unsigned char dp_tx_option_enabled_stub_copy2(unsigned char);
extern unsigned char hdcp_tx_dp_get_enable_bit(void);
extern void hdcp_tx_dp_set_enable(unsigned char);

#define STEP_NEXT               1

/*
 * State 0x18 of hdcp_tx_dp_run_state: set step_result to STEP_NEXT, then call hdcp_tx_dp_set_enable with the
 * value of dp_tx_option_enabled_stub_copy2 (always 1) when that differs from hdcp_tx_dp_get_enable_bit.
 */
void hdcp_tx_dp_state_sync_enable(unsigned char port)
{
    unsigned char wanted;

    hdcp_tx_records[port].word0 = (hdcp_tx_records[port].word0 & ~STEP_RESULT_MASK) | (STEP_NEXT << STEP_RESULT_SHIFT);
    wanted = dp_tx_option_enabled_stub_copy2(port);
    if (wanted != hdcp_tx_dp_get_enable_bit())
        hdcp_tx_dp_set_enable(wanted);
}

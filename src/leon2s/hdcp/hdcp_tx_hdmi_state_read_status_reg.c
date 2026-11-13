/* hdcp_tx_hdmi_state_read_status_reg  (FUN_a00c8a80)
 *
 * State handler: read a status register and choose the next state.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00c8a80 (leon2s 0xa00c8a80-0xa00c8aec, 27 words), flags -mcpu=v8 -Os -g.
 * Source form: a record struct indexed by port; the clear arm ('(status & 2) == 0') comes first (the firmware
 * falls through into it); the store of step 1 before the register read is in the firmware. No volatile (RAM).
 */
/* Output record of hdcp_tx_records (24 bytes): only word 0 is used here. */
struct hdcp_tx_record_word0 { unsigned int word0; unsigned char pad[0x14]; };
extern struct hdcp_tx_record_word0 hdcp_tx_records[];
extern unsigned char hdmi_tx_reg_read8(unsigned char, unsigned int, unsigned int);

#define STEP_RESULT_CLEAR 0xfffcffff            /* clears bits 16..17 of word 0 (step_result) */
#define STEP_NEXT_BITS    0x10000               /* step_result 1 */

/*
 * State 0 of hdcp_tx_hdmi_run_state. Sets the step result of the output record to 1 (STEP_NEXT), then reads
 * register 9 of HDMI output `port`: when bit 1 of it is clear the step result becomes 0 (STEP_BACK), otherwise
 * it stays 1.
 */
void hdcp_tx_hdmi_state_read_status_reg(unsigned char port)
{
    hdcp_tx_records[port].word0 = (hdcp_tx_records[port].word0 & STEP_RESULT_CLEAR) | STEP_NEXT_BITS;
    if ((hdmi_tx_reg_read8(port, 0, 9) & 2) == 0)
        hdcp_tx_records[port].word0 = hdcp_tx_records[port].word0 & STEP_RESULT_CLEAR;
    else
        hdcp_tx_records[port].word0 = (hdcp_tx_records[port].word0 & STEP_RESULT_CLEAR) | STEP_NEXT_BITS;
}

/* hdcp_tx_dp_state_read_caps  (FUN_a00ccf0c)
 *
 * State handler: switch protection off and read the receiver's capability byte over AUX.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_dp_run_state; DPCD 0x6921D (HDCP 2.x capability)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ccf0c @ 0xa00ccf0c-0xa00ccfa8 (39 words), flags -mcpu=v8 -Os -g.
 * Source form: word 0 of the record is handled as a whole; the mask 0xfffcffff stays in one register for all
 * three uses. The record stride is 0x18 bytes (an index of port * 6 words gives the same code).
 */
/* Word 0 of a copy-protection record (24 bytes, array hdcp_tx_records), used as a whole. Its bits 16..17 hold the
   step result: 0 = STEP_BACK, 1 = STEP_NEXT, 2 = STEP_OTHER, 3 = STEP_AGAIN. */
struct hdcp_tx_record_words {
    unsigned int word0;
    unsigned char rest[0x14];
};

#define STEP_RESULT_SHIFT       16
#define STEP_RESULT_MASK        (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17 */
extern int hdcp_tx_dp_set_enable();
extern int dp_tx_aux_request_copy();
extern struct hdcp_tx_record_words hdcp_tx_records[];
extern unsigned char hdcp_tx_message_buffer;

#define AUX_CMD_READ            0x90    /* AUX command of the reads here */
#define AUX_ADDR_0x6921D        0x6921d
#define STEP_BACK               0
#define STEP_NEXT               1
#define STEP_OTHER              2
#define BUFFER_VALUE_0x2        2       /* byte value that gives STEP_OTHER */

/*
 * State 1 of hdcp_tx_dp_run_state: switch the protection of the DisplayPort output off and read AUX address
 * 0x6921d into hdcp_tx_message_buffer.
 *
 * step_result is STEP_NEXT first. If the low byte of the AUX call's return value is 0 it becomes STEP_BACK;
 * otherwise it becomes STEP_OTHER when the byte read is 2 and stays STEP_NEXT for any other byte.
 */
void hdcp_tx_dp_state_read_caps(unsigned int port_arg)
{
    unsigned int result;
    unsigned int port;

    hdcp_tx_dp_set_enable(0);
    port = (port_arg & 0xff) ;
    hdcp_tx_records[port].word0 = (hdcp_tx_records[port].word0 & ~STEP_RESULT_MASK) | (STEP_NEXT << STEP_RESULT_SHIFT);

    result = dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_ADDR_0x6921D, 0, &hdcp_tx_message_buffer);

    if ((result & 0xff) == 0) {
        result = hdcp_tx_records[port].word0 & ~STEP_RESULT_MASK;
        hdcp_tx_records[port].word0 = result;
    } else if (hdcp_tx_message_buffer == BUFFER_VALUE_0x2) {
        result = (hdcp_tx_records[port].word0 & ~STEP_RESULT_MASK) | (STEP_OTHER << STEP_RESULT_SHIFT);
        hdcp_tx_records[port].word0 = result;
    }
}

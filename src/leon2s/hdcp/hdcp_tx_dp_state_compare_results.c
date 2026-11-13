/* hdcp_tx_dp_state_compare_results  (FUN_a00cdcdc)
 *
 * State handler: compare two 32-byte results and choose the next step.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cdcdc @ 0xa00cdcdc-0xa00cdde0, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the clear call is a tail call after the first difference; bytes +3..+9
 * are plain unsigned char members.
 */
#define BLOCK_SIZE          0x20        /* bytes compared */
#define STEP_LENGTH         0x400       /* length argument of the three engine calls */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_20_22 : 3;
    unsigned int bit19 : 1;             /* set here once the first comparison has passed; the comparison is
                                           skipped while it is set */
    unsigned int bit18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9: engine unit of the output, passed to the engine routines */
    unsigned char pad[14];
};
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_result_block[];
extern unsigned char hdcp_tx_work_block[];
extern unsigned char hdcp_tx_message_body[];
extern void hdcp_tx_engine_load_table(unsigned char port);
extern void hdcp_tx_engine_write_bank3_block(unsigned char, unsigned char *, unsigned short);
extern void hdcp_tx_engine_run_step_first(unsigned char, unsigned short);
extern void hdcp_tx_engine_read_384_bytes(unsigned int, unsigned short);
extern void hdcp_tx_clear_ksv_table(unsigned char port);

/*
 * State 0x42 of the DisplayPort output: check the engine's 32-byte result against the 32-byte work block, once,
 * then start the next engine round.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x42. It reports through step_result (STEP_*).
 *
 *   1. step_result = STEP_NEXT.
 *   2. While bit 19 of the record is clear: hdcp_tx_engine_load_table(engine_unit) runs, then the 32 bytes of
 *      hdcp_tx_result_block are compared with hdcp_tx_work_block (a block that hdcp_tx_dp_state_compare_aux_block
 *      and hdcp_tx_dp_state_exchange_third fill from the receiver). At the first difference the result is
 *      STEP_BACK, the stored ids are cleared (hdcp_tx_clear_ksv_table(port)) and the routine ends.
 *   3. Bit 19 is set (so later passes skip step 2). The engine unit gets the message body
 *      (hdcp_tx_message_body, from byte 6 of the message buffer; load_3_bytes), then hdcp_tx_engine_run_step_first
 *      and hdcp_tx_engine_read_384_bytes, each with length 0x400.
 *
 * Same steps as the second half of hdcp_tx_hdmi_state_compare_results, without the receiver-id handling.
 */
void hdcp_tx_dp_state_compare_results(unsigned char port)
{
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (hdcp_tx_records[port].bit19 == 0) {
        hdcp_tx_engine_load_table(hdcp_tx_records[port].engine_unit);
        for (i = 0; i < BLOCK_SIZE; i++) {
            if (hdcp_tx_result_block[i] != hdcp_tx_work_block[i]) {
                hdcp_tx_records[port].step_result = STEP_BACK;
                hdcp_tx_clear_ksv_table(port);
                return;
            }
        }
    }
    hdcp_tx_records[port].bit19 = 1;
    hdcp_tx_engine_write_bank3_block(hdcp_tx_records[port].engine_unit, hdcp_tx_message_body, STEP_LENGTH);
    hdcp_tx_engine_run_step_first(hdcp_tx_records[port].engine_unit, STEP_LENGTH);
    hdcp_tx_engine_read_384_bytes(hdcp_tx_records[port].engine_unit, STEP_LENGTH);
}

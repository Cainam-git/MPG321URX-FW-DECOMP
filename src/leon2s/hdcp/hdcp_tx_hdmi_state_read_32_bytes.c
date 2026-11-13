/* hdcp_tx_hdmi_state_read_32_bytes  (FUN_a00caf78)
 *
 * State handler: run the fixed block, read 32 bytes from the receiver, compare them with the result.
 * Note: When the fixed block fails it first waits 50 times 10 delay units; a read error or a difference gives
 *   step result 0.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state; calls hdcp_tx_hdmi_run_fixed_block and compares with
 *   hdcp_tx_result_block
 *
 * Matching notes
 * --------------
 * FUN_a00caf78 (leon2s, 0xa00caf78-0xa00cb1d4, 604 bytes), flags -mcpu=v8 -Os -g.
 * Word 0 of the record is a group of bit-fields (big-endian, first field = bit 31). Source forms: the wait loop
 * condition is 'ok != 0 && t != 0 && step_result == STEP_NEXT' (flag arithmetic for the first two tests) with the
 * decrement first in the body; the state is tested with '== 1' on entry, not at the end.
 */
/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records); word 0 is a group of bit-fields,
   bit 31 first. */
struct hdcp_tx_record {
    unsigned int bit31 : 1;
    unsigned int bit30 : 1;
    unsigned int bit29 : 1;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bit22 : 1;
    unsigned int bit21 : 1;
    unsigned int bit20 : 1;
    unsigned int bit19 : 1;
    unsigned int bit18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: result of the state handler (STEP_*) */
    unsigned char state;                /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9 */
    unsigned char pad_a[6];
    unsigned int word_0x10;
    unsigned char pad_14[4];
};

/* Result of a state handler; hdcp_tx_select_next_state picks the next state from it. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_status_bytes[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_work_block[];
extern unsigned char hdcp_tx_result_block[];
extern unsigned char hdcp_tx_hdmi_run_fixed_block(unsigned char);
extern unsigned char hdcp_tx_hdmi_read_rx_status(unsigned char, unsigned char *);
extern unsigned char hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned char hdmi_tx_ddc_read(unsigned char, unsigned char *, unsigned char);
extern void hdcp_tx_clear_ksv_table(unsigned char);
extern void timer_delay_long_units(unsigned int);

#define WAIT_TRIES           50         /* waits of timer_delay_long_units(10) after a failed fixed block */
#define WAIT_UNITS           10
#define LENGTH_HIGH_MASK     3          /* the length is ((status[1] & 3) << 8) + status[0] */
#define STATUS_HIGH_BITS_2_3 0xc        /* any of these bits in status[1] gives STEP_BACK */
#define HDCP_DDC_DEVICE      0x74       /* device address of the receiver on the output's DDC channel */
#define DDC_READ_OFFSET      0x80       /* offset read from */
#define DDC_READ_LENGTH      0x21       /* bytes read: buffer[0] and 32 data bytes */
#define BLOCK_SIZE           0x20

/*
 * State handler of an HDMI output (state 69 = 0x45 of hdcp_tx_hdmi_run_state). port = output 0 or 1.
 *
 * Reads a 32-byte block from the receiver and compares it with hdcp_tx_result_block. Unlike the other handlers
 * it does not set step_result on entry, so it sees the value left by the previous pass: STEP_NEXT on the first
 * pass, STEP_AGAIN on a repeat. The result is left in step_result: STEP_NEXT sets tries_left to 5 and moves the
 * output to state 0x47 when bit 29 is set and 0x46 otherwise; STEP_AGAIN keeps the state so the handler runs
 * again; STEP_BACK sends the output to state 0x40.
 *
 * Decisions in order:
 *  1. Only when step_result is STEP_NEXT (so not on a repeat): hdcp_tx_hdmi_run_fixed_block(port) runs. If it returns 1 (a failure),
 *     the routine waits 50 times timer_delay_long_units(10) and then sets STEP_AGAIN; the code below still runs.
 *  2. The receiver's two status bytes are read into hdcp_tx_status_bytes; a read error, or any of bits 2..3 of
 *     status[1], gives STEP_BACK. A length ((status[1] & 3) << 8) + status[0] of 0 gives STEP_AGAIN (nothing to
 *     read yet).
 *  3. The DDC master is set up for 0x21 bytes (device 0x74, offset 0x80) and they are read into
 *     hdcp_tx_message_buffer; an error in either step gives STEP_BACK.
 *  4. hdcp_tx_message_buffer[1..0x20] are copied to hdcp_tx_work_block and step_result is set to STEP_NEXT.
 *     If hdcp_tx_work_block differs from hdcp_tx_result_block, the result is STEP_BACK and the stored ids are
 *     cleared (hdcp_tx_clear_ksv_table(port)).
 */
void hdcp_tx_hdmi_state_read_32_bytes(unsigned char port)
{
    unsigned char ok = 1;
    unsigned char tries = WAIT_TRIES;
    unsigned char status_high;
    unsigned short message_length;
    unsigned char i;

    if (hdcp_tx_records[port].step_result == STEP_NEXT)
        ok = hdcp_tx_hdmi_run_fixed_block(port);
    while (ok != 0 && tries != 0 && hdcp_tx_records[port].step_result == STEP_NEXT) {
        tries--;
        timer_delay_long_units(WAIT_UNITS);
        if (tries == 0) {
            hdcp_tx_records[port].step_result = STEP_AGAIN;
            break;
        }
    }
    if (hdcp_tx_hdmi_read_rx_status(port, hdcp_tx_status_bytes)) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    status_high = hdcp_tx_status_bytes[1];
    message_length = ((status_high & LENGTH_HIGH_MASK) << 8) + hdcp_tx_status_bytes[0];
    if (status_high & STATUS_HIGH_BITS_2_3) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if (message_length == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if (hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, DDC_READ_OFFSET, DDC_READ_LENGTH) || hdmi_tx_ddc_read(port, hdcp_tx_message_buffer, DDC_READ_LENGTH)) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    for (i = 0; i < BLOCK_SIZE; i++)
        hdcp_tx_work_block[i] = hdcp_tx_message_buffer[i + 1];
    hdcp_tx_records[port].step_result = STEP_NEXT;
    for (i = 0; i < BLOCK_SIZE; i++) {
        if (hdcp_tx_result_block[i] != hdcp_tx_work_block[i]) {
            hdcp_tx_records[port].step_result = STEP_BACK;
            hdcp_tx_clear_ksv_table(port);
            break;
        }
    }
}

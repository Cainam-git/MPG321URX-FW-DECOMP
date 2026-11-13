/* hdcp_tx_hdmi_state_compare_results  (FUN_a00cab10)
 *
 * State handler: compare the engine's 32 result bytes, write the receiver id, store the repeater flag.
 * Note: Also writes the receiver id and message bytes to registers and clears the stored ids;
 *   hdcp_tx_select_next_state picks the next state.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state; compares hdcp_tx_result_block with the engine buffer
 *   at +0x160
 *
 * Matching notes
 * --------------
 * FUN_a00cab10 (leon2s, 0xa00cab10-0xa00cad8c, 636 bytes), flags -mcpu=v8 -Os -g.
 * Word 0 of the record is a group of bit-fields (big-endian, first field = bit 31). Source form: the last test is
 * written '!= 2' with the STEP_BACK arm first; the call to hdcp_tx_engine_read_384_bytes is the last statement
 * (a tail call).
 */
/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records); word 0 is a group of bit-fields,
   bit 31 first. */
struct hdcp_tx_record {
    unsigned int bit31 : 1;
    unsigned int bit30 : 1;
    unsigned int receiver_id_known : 1; /* bit 29: the stored row for this output equals the receiver id just read */
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bit22 : 1;
    unsigned int bit21 : 1;
    unsigned int bit20 : 1;
    unsigned int bit19 : 1;             /* set here once the first comparison has passed; the comparison is skipped
                                           while it is set */
    unsigned int bit18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: result of the state handler (STEP_*) */
    unsigned char state;                /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9: engine unit given to the output */
    unsigned char pad_a[14];
};

/* Result of a state handler; hdcp_tx_select_next_state picks the next state from it. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_result_block[];
extern unsigned char hdcp_tx_engine_buffer[];
extern unsigned char hdcp_tx_ksv_table[][5];
extern unsigned char hdcp_tx_receiver_ids[][5];
extern unsigned char hdcp_tx_message_buffer[];
extern void hdcp_tx_engine_load_table(unsigned char);
extern void hdcp_tx_clear_ksv_table(unsigned char);
extern void hdmi_tx_reg_write8(unsigned char, int, unsigned short, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern void hdcp_tx_engine_write_bank3_block(unsigned char, unsigned char *, unsigned short);
extern void hdcp_tx_engine_run_step_first(unsigned char, unsigned short);
extern void hdcp_tx_engine_read_384_bytes(unsigned char, unsigned short);

#define RESULT_SIZE          0x20       /* bytes compared with hdcp_tx_result_block */
#define RESULT_OFFSET        0x160      /* ... starting here in hdcp_tx_engine_buffer */
#define RECEIVER_ID_SIZE     5
#define RECEIVER_ID_REG      0x10       /* HDMI transmitter registers 0x10..0x14 receive the receiver id */
#define BLOCK_FIRST          0x8b       /* buffer bytes 0x8b..0x95 go to register 1 of the output's block */
#define BLOCK_END            0x96
#define BLOCK_CHECK_BYTE     0x93       /* must be 2 */
#define BLOCK_CHECK_VALUE    2
#define BLOCK_REPEATER_BYTE  0x95       /* 1 = repeater */
#define ENGINE_COMMAND_3     3
#define COMMAND_LENGTH       0x8000
#define KEY_BLOCK_OFFSET     6          /* buffer bytes 6.. are the 3 bytes given to the engine */
#define KEY_BLOCK_LENGTH     0x400      /* length argument of the three engine calls at the end */

/*
 * State handler of an HDMI output (state 66 = 0x42 of hdcp_tx_hdmi_run_state). port = output 0 or 1.
 *
 * Compares the 32 bytes of hdcp_tx_result_block with the engine's read-back, records whether the receiver id is the stored
 * one, passes the receiver id and buffer bytes 0x8b..0x95 on, and starts the next engine round. The result is
 * left in step_result: STEP_NEXT moves the output to state 0x44 when bit 29 is set and to 0x43 otherwise;
 * STEP_BACK returns it to state 0.
 *
 * Decisions in order:
 *  1. Bit 19 clear (first pass): hdcp_tx_engine_load_table(engine_unit) runs; if any of the 32 bytes of
 *     hdcp_tx_result_block differs from hdcp_tx_engine_buffer[0x160..0x17f], the result is STEP_BACK, the
 *     stored ids are cleared (hdcp_tx_clear_ksv_table(port)) and the routine ends.
 *  2. Bit 19 and bit 29 are set. Bit 29 is cleared again when the 5 bytes of the output's row in
 *     hdcp_tx_ksv_table differ from its row in hdcp_tx_receiver_ids.
 *  3. The 5 bytes of the output's row in hdcp_tx_receiver_ids go to HDMI transmitter registers 0x10..0x14. Engine
 *     command 3 (length 0x8000) starts, and hdcp_tx_message_buffer[0x8b..0x95] are written to register 1 of the output's
 *     block.
 *  4. hdcp_tx_message_buffer[0x93] must be 2, else STEP_BACK. Otherwise bit 28 is set when [0x95] is 1 and
 *     cleared if not; then the 3 bytes at [6] are loaded into the engine and
 *     hdcp_tx_engine_run_step_first and hdcp_tx_engine_read_384_bytes run (length 0x400).
 */
void hdcp_tx_hdmi_state_compare_results(unsigned char port)
{
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (hdcp_tx_records[port].bit19 == 0) {
        hdcp_tx_engine_load_table(hdcp_tx_records[port].engine_unit);
        for (i = 0; i < RESULT_SIZE; i++) {
            if (hdcp_tx_result_block[i] != hdcp_tx_engine_buffer[i + RESULT_OFFSET]) {
                hdcp_tx_records[port].step_result = STEP_BACK;
                hdcp_tx_clear_ksv_table(port);
                return;
            }
        }
    }
    hdcp_tx_records[port].bit19 = 1;
    hdcp_tx_records[port].receiver_id_known = 1;
    for (i = 0; i < RECEIVER_ID_SIZE; i++) {
        if (hdcp_tx_ksv_table[port][i] != hdcp_tx_receiver_ids[port][i]) {
            hdcp_tx_records[port].receiver_id_known = 0;
            break;
        }
    }
    for (i = 0; i < RECEIVER_ID_SIZE; i++)
        hdmi_tx_reg_write8(port, 0, i + RECEIVER_ID_REG, hdcp_tx_receiver_ids[port][i]);
    hdcp_tx_engine_start_command(port, ENGINE_COMMAND_3, COMMAND_LENGTH);
    for (i = BLOCK_FIRST; i < BLOCK_END; i++)
        hdcp_tx_reg_write(port, 1, hdcp_tx_message_buffer[i]);
    if (hdcp_tx_message_buffer[BLOCK_CHECK_BYTE] != BLOCK_CHECK_VALUE)
        hdcp_tx_records[port].step_result = STEP_BACK;
    else {
        hdcp_tx_records[port].repeater = 0;
        if (hdcp_tx_message_buffer[BLOCK_REPEATER_BYTE] == 1)
            hdcp_tx_records[port].repeater = 1;
        hdcp_tx_engine_write_bank3_block(hdcp_tx_records[port].engine_unit, &hdcp_tx_message_buffer[KEY_BLOCK_OFFSET], KEY_BLOCK_LENGTH);
        hdcp_tx_engine_run_step_first(hdcp_tx_records[port].engine_unit, KEY_BLOCK_LENGTH);
        hdcp_tx_engine_read_384_bytes(hdcp_tx_records[port].engine_unit, KEY_BLOCK_LENGTH);
    }
}

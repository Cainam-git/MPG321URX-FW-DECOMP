/* hdcp_tx_dp_state_read_hdcp2_messages  (FUN_a00cfd38)
 *
 * State handler: read the message blocks at DPCD 0x69000 into the work buffers.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state; DPCD 0x69000 is the HDCP 2.x message area
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cfd38 @ 0xa00cfd38-0xa00d00e0, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the AUX address base is a variable set before each block loop
 * (addr + k * 16); in the two 5-byte copies the receiver-id / tail array is stored first, then the message
 * buffer; bytes +2..+9 of the record are plain unsigned char members.
 */
#define AUX_CMD_READ        0x90
#define AUX_ID_BLOCK        0x6900b     /* 5 bytes: the receiver id */
#define AUX_MESSAGE_BLOCKS  0x69010     /* 8 blocks of 16 bytes */
#define AUX_TAIL_BLOCK      0x69090     /* 5 bytes */
#define AUX_TABLE_BLOCKS    0x69095     /* 24 blocks of 16 bytes = the 0x180 bytes of the engine buffer */
#define AUX_STATUS_BLOCK    0x69215     /* 11 bytes, written to the engine */
#define STATUS_CHECK_INDEX  8           /* status byte that must be 2 (else STEP_BACK) */
#define STATUS_REPEATER_INDEX 10        /* status byte 3 = repeater */
#define STATUS_REPEATER     3
#define STATUS_CHECK_VALUE  2
#define ENGINE_CMD_3        3           /* hdcp_tx_engine_start_command code */
#define PROT_REG_DATA       1           /* protection block register: bytes to the engine */
#define TIMER_10            10          /* hdcp_tx_get_timer number, not tied to the output */
#define OUTPUT_DP           2           /* row of hdcp_tx_receiver_ids / hdcp_tx_ksv_table used here */
#define KSV_LENGTH          5
#define ENGINE_BLOCK_LENGTH 0xc00       /* length argument of hdcp_tx_engine_write_block (0x180 bytes) */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bit31 : 1;
    unsigned int bit30 : 1;
    unsigned int receiver_id_known : 1; /* bit 29: set here when the receiver id equals the stored one */
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bit22 : 1;
    unsigned int bit21 : 1;
    unsigned int bit20 : 1;
    unsigned int bit19 : 1;             /* set by hdcp_tx_dp_state_compare_results once its comparison has passed */
    unsigned int bit18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned char state;                /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9 */
    unsigned char pad_a[14];
};
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_receiver_ids[][5];
extern unsigned char hdcp_tx_message_tail[];
extern unsigned char hdcp_tx_ksv_table[3][5];
extern unsigned char hdcp_tx_engine_buffer[];
extern int hdcp_tx_get_timer(int);
extern int dp_tx_aux_request_copy(int, int, int, int, unsigned char *);
extern void hdcp_tx_engine_write_block(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_hash_message_buffer(unsigned char *);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);

/*
 * State 0x41 of the DisplayPort output: read the receiver's id, message blocks and table blocks over AUX into the
 * work buffers, hand the table to the engine, and read the receiver's status block.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x41. It reports through step_result (STEP_*). All AUX reads use
 * channel 0.
 *
 *   1. Timer 10 not run out: STEP_AGAIN and the routine ends. Otherwise step_result = STEP_NEXT.
 *   2. 5 bytes at 0x6900B go to row 2 of hdcp_tx_receiver_ids and to hdcp_tx_message_buffer[1..5]. Bit 29 of the
 *      record (receiver_id_known) is set, and cleared when these bytes differ from row 2 of hdcp_tx_ksv_table.
 *   3. 8 blocks of 16 bytes from 0x69010 go to hdcp_tx_message_buffer[6..0x85].
 *   4. 5 bytes at 0x69090 go to hdcp_tx_message_tail and to hdcp_tx_message_buffer[0x86..0x8a].
 *   5. 24 blocks of 16 bytes from 0x69095 go to hdcp_tx_engine_buffer.
 *   6. While bit 19 of the record is clear: hdcp_tx_engine_buffer goes to the output's engine unit
 *      (hdcp_tx_engine_write_block, mode 0, length 0xC00) and hdcp_tx_hash_message_buffer runs.
 *   7. Engine command 3 (length 0x8000); the 11 bytes at 0x69215 are written to register 1 of the output's
 *      protection block. Byte 8 of them not equal to 2 gives STEP_BACK; otherwise bit 28 (repeater) is set
 *      when byte 10 is 3 and cleared when it is not.
 */
void hdcp_tx_dp_state_read_hdcp2_messages(unsigned char port)
{
    unsigned char buf[16];
    unsigned char i;
    unsigned char k;
    unsigned int addr;

    if (hdcp_tx_get_timer(TIMER_10) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_records[port].step_result = STEP_NEXT;
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_ID_BLOCK, KSV_LENGTH - 1, buf);
    for (i = 0; i < KSV_LENGTH; i++) {
        hdcp_tx_receiver_ids[OUTPUT_DP][i] = buf[i];
        hdcp_tx_message_buffer[i + 1] = buf[i];
    }
    hdcp_tx_records[port].receiver_id_known = 1;
    for (i = 0; i < KSV_LENGTH; i++) {
        if (buf[i] != hdcp_tx_ksv_table[OUTPUT_DP][i]) {
            hdcp_tx_records[port].receiver_id_known = 0;
            break;
        }
    }
    addr = AUX_MESSAGE_BLOCKS;
    for (k = 0; k < 8; k++) {
        dp_tx_aux_request_copy(0, AUX_CMD_READ, addr + k * 16, 0xf, buf);
        for (i = 0; i < 16; i++)
            hdcp_tx_message_buffer[k * 16 + i + 6] = buf[i];
    }
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_TAIL_BLOCK, KSV_LENGTH - 1, buf);
    for (i = 0; i < KSV_LENGTH; i++) {
        hdcp_tx_message_tail[i] = buf[i];
        hdcp_tx_message_buffer[i + 0x86] = buf[i];
    }
    addr = AUX_TABLE_BLOCKS;
    for (k = 0; k < 0x18; k++) {
        dp_tx_aux_request_copy(0, AUX_CMD_READ, addr + k * 16, 0xf, buf);
        for (i = 0; i < 16; i++)
            hdcp_tx_engine_buffer[k * 16 + i] = buf[i];
    }
    if (hdcp_tx_records[port].bit19 == 0) {
        hdcp_tx_engine_write_block(hdcp_tx_records[port].engine_unit, hdcp_tx_engine_buffer, 0, 0, ENGINE_BLOCK_LENGTH);
        hdcp_tx_hash_message_buffer(&hdcp_tx_message_buffer[1]);
    }
    hdcp_tx_engine_start_command(port, ENGINE_CMD_3, 0x8000);
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_STATUS_BLOCK, 10, buf);
    for (i = 0; i < 11; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, buf[i]);
    if (buf[STATUS_CHECK_INDEX] != STATUS_CHECK_VALUE)
        hdcp_tx_records[port].step_result = STEP_BACK;
    else if (buf[STATUS_REPEATER_INDEX] == STATUS_REPEATER)
        hdcp_tx_records[port].repeater = 1;
    else
        hdcp_tx_records[port].repeater = 0;
}

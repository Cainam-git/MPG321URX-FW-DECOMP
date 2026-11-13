/* hdcp_tx_dp_state_send_stream_manage  (FUN_a00cf7b4)
 *
 * State handler: write 4 result bytes to AUX 0x693F0 and the stream byte pairs to 0x693F5 onwards.
 * Note: DPCD 0x693F0..0x693F5 is the stream management message of HDCP 2.x; without bit 22 of word 0 it gives
 *   'again'.
 * Name basis: derived - one state handler of the per-port copy-protection state machine, called from
 *   hdcp_tx_dp_run_state; AUX writes to 0x693F0 and 0x693F5 + i * 16
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cf7b4 @ 0xa00cf7b4-0xa00cf954, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the loop bound byte_0x14 is read again at each test; the AUX base
 * 0x693f5 sits in a local set before the loop (the firmware keeps it in a register); the AUX count is
 * (signed char)(k * 2 - 1) with k the loop variable left at cnt by the inner loop; word 0 of the record is a
 * bit-field group, bytes +2..+9 and +0x14 plain unsigned char members.
 */
#define AUX_CMD_READ        0x90
#define AUX_CMD_WRITE       0x80
#define AUX_RXSTATUS        0x69493     /* one byte, read and not used */
#define AUX_HEAD            0x693f0     /* 4 bytes, from hdcp_tx_result_block */
#define AUX_PAIRS           0x693f5     /* byte pairs, written in groups of up to 8 pairs */
#define HEAD_BYTES          4
#define GROUP_PAIRS         8

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bit31 : 1;
    unsigned int bit30 : 1;
    unsigned int bit29 : 1;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bit22 : 1;             /* set by hdcp_tx_init_port_record, cleared by hdcp_tx_dp_state_wait_timer */
    unsigned int bit21 : 1;
    unsigned int bit20 : 1;
    unsigned int bit19 : 1;
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
    unsigned char pad_a[6];
    unsigned int word_0x10;
    unsigned char byte_0x14;            /* 0x1F after hdcp_tx_init_port_record; the number of byte pairs sent here */
    unsigned char pad_15[3];
};
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_result_block[];
extern int dp_tx_aux_request(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int dp_tx_aux_request_copy(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);

/*
 * State 0x4C of the DisplayPort output: write the first 4 bytes of the engine's result block and then
 * byte_0x14 pairs of bytes of the message buffer to the receiver.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x4C. It reports through step_result (STEP_*). Nothing is read
 * back: the one AUX read (the status byte at 0x69493) is not used.
 *
 *   1. Bit 22 of the record clear: STEP_AGAIN and the routine ends.
 *   2. step_result = STEP_NEXT. Read the status byte (AUX 0x69493, channel 0) and drop it.
 *   3. Write hdcp_tx_result_block[0..3] over AUX to 0x693F0.
 *   4. For i = 0, 8, 16 .. while i < byte_0x14: take cnt = 8 pairs, or byte_0x14 - i when fewer are left, copy
 *      the pairs hdcp_tx_message_buffer[2 * (i + k)] and [2 * (i + k) + 1] (k < cnt) to a 16-byte buffer, and
 *      write its 2 * cnt bytes over AUX to 0x693F5 + i * 16.
 */
void hdcp_tx_dp_state_send_stream_manage(unsigned char port)
{
    unsigned char buf[16];
    unsigned char i;
    unsigned char cnt;
    unsigned short k;
    unsigned int addr;

    if (!hdcp_tx_records[port].bit22) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_records[port].step_result = STEP_NEXT;
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_RXSTATUS, 0, buf);
    dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_HEAD, HEAD_BYTES, hdcp_tx_result_block);
    addr = AUX_PAIRS;
    for (i = 0; i < hdcp_tx_records[port].byte_0x14; i += GROUP_PAIRS) {
        cnt = GROUP_PAIRS;
        if (i + GROUP_PAIRS > hdcp_tx_records[port].byte_0x14)
            cnt = hdcp_tx_records[port].byte_0x14 - i;
        for (k = 0; k < cnt; k++) {
            buf[k * 2] = hdcp_tx_message_buffer[(k + i) * 2];
            buf[k * 2 + 1] = hdcp_tx_message_buffer[(k + i) * 2 + 1];
        }
        dp_tx_aux_request(0, AUX_CMD_WRITE, addr + i * 16, (signed char)(k * 2 - 1), buf);
    }
}

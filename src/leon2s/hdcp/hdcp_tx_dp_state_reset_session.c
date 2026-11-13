/* hdcp_tx_dp_state_reset_session  (FUN_a00d0550)
 *
 * State handler: clear the session data of a port and write the start blocks over AUX.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d0550 @ 0xa00d0550-0xa00d0798, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the hdcp_owner_byte test is an if/else whose else arm sets
 * step_result = STEP_AGAIN and returns; bytes +2..+9 of the record are plain unsigned char members; the eleven
 * stores to hdcp_tx_message_buffer are separate statements; the control register is a volatile word.
 */
#define AUX_CMD_WRITE       0x80
#define AUX_START_BLOCK     0x69000     /* 11 bytes written here (count argument 10) */
#define TIMER_10            10          /* hdcp_tx_get_timer / hdcp_tx_set_timer number, not tied to the output */
#define TIMER_10_TICKS      100         /* started at the end; hdcp_tx_dp_state_read_hdcp2_messages waits for it */
#define ENGINE_UNIT_DP      3           /* record byte +9 while this output holds the engine */
#define KEY_STATE_FREE      0xff        /* hdcp_owner_byte: nobody holds the engine */
#define ENGINE_CMD_11       0x11        /* hdcp_tx_engine_start_command codes */
#define ENGINE_CMD_1        1
#define PROT_REG_DATA       1           /* protection block register: bytes to the engine */
#define PROT_REG_4          4
#define START_ZERO_BYTES    0x18
#define START_KEY_BYTES     0x10        /* first bytes of hdcp_stored_key_header */
#define START_BLOCK_LENGTH  11

/* Register 0xcf018d00 (reg_hdcp_tx_dp_control): bits 0 and 1 are cleared here (bit 1 is the enable bit of
   hdcp_tx_dp_set_enable). */
#define REG_HDCP_TX_DP_CONTROL (*(volatile unsigned int *)0xcf018d00)

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
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
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned char state;                /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9 */
    unsigned char pad_a[2];
    unsigned int word_0xc;              /* message_counter in the other handlers */
    unsigned int word_0x10;             /* 24-bit counter */
    unsigned char pad_14[4];
};
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_owner_byte;
extern unsigned char hdcp_stored_key_header[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned int hdcp_tx_get_timer(int);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void timer_delay_units(unsigned int);
extern int dp_tx_aux_request(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int hdcp_tx_set_timer(int, int);

/*
 * State 0x40 of the DisplayPort output: take the engine for this output, reset the output's counters and
 * session registers, and write the start block to the receiver.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x40, the entry state of the second form of the handshake. It
 * reports through step_result (STEP_*).
 *
 *   1. Timer 10 not run out, or hdcp_owner_byte naming another output (it is neither 0xFF nor port):
 *      STEP_AGAIN and the routine ends.
 *   2. The output takes the engine: engine_unit = 3, word_0xc and word_0x10 = 0, hdcp_owner_byte = port. Bits 0
 *      and 1 of the control register 0xCF018D00 are cleared. Protection register 4 gets 0x17, then after one
 *      delay unit 0x11; engine command 0x11 (length 0x8000).
 *   3. Register 1 of the output's protection block gets 0x18 zero bytes and the first 16 bytes of
 *      hdcp_stored_key_header.
 *   4. hdcp_tx_message_buffer[0..10] = 1, 2, 3, 4, 5, 6, 7, 8, 2, 0, 0. Engine command 1 (length 0x8000); these 11
 *      bytes go to register 1 and over AUX (channel 0) to 0x69000.
 *   5. step_result = STEP_NEXT and timer 10 is started with 100 ticks (hdcp_tx_dp_state_read_hdcp2_messages,
 *      state 0x41, waits for it).
 */
void hdcp_tx_dp_state_reset_session(unsigned char port)
{
    unsigned short k;

    if (hdcp_tx_get_timer(TIMER_10) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if (hdcp_owner_byte == KEY_STATE_FREE || hdcp_owner_byte == port) {
        hdcp_tx_records[port].engine_unit = ENGINE_UNIT_DP;
        hdcp_tx_records[port].word_0xc = 0;
        hdcp_tx_records[port].word_0x10 = 0;
        hdcp_owner_byte = port;
        REG_HDCP_TX_DP_CONTROL &= ~3;
        hdcp_tx_reg_write(port, PROT_REG_4, 0x17);
        timer_delay_units(1);
        hdcp_tx_reg_write(port, PROT_REG_4, 0x11);
        hdcp_tx_engine_start_command(port, ENGINE_CMD_11, 0x8000);
    } else {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    for (k = 0; k < START_ZERO_BYTES; k++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
    for (k = 0; k < START_KEY_BYTES; k++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_stored_key_header[k]);
    hdcp_tx_message_buffer[0] = 1;
    hdcp_tx_message_buffer[1] = 2;
    hdcp_tx_message_buffer[2] = 3;
    hdcp_tx_message_buffer[3] = 4;
    hdcp_tx_message_buffer[4] = 5;
    hdcp_tx_message_buffer[5] = 6;
    hdcp_tx_message_buffer[6] = 7;
    hdcp_tx_message_buffer[7] = 8;
    hdcp_tx_message_buffer[8] = 2;
    hdcp_tx_message_buffer[9] = 0;
    hdcp_tx_message_buffer[0xa] = 0;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_1, 0x8000);
    for (k = 0; k <= 0xa; k++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[k]);
    dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_START_BLOCK, 0xa, hdcp_tx_message_buffer);
    hdcp_tx_records[port].step_result = STEP_NEXT;
    hdcp_tx_set_timer(TIMER_10, TIMER_10_TICKS);
}

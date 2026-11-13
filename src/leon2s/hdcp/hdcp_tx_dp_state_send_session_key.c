/* hdcp_tx_dp_state_send_session_key  (FUN_a00cec18)
 *
 * State handler: send 16 engine bytes and 8 fixed bytes over AUX to 0x69318 and 0x69328.
 * Note: DPCD 0x69318 / 0x69328 take the encrypted key and its companion value of HDCP 2.x (SKE_Send_Eks);
 *   nothing is compared.
 * Name basis: derived - one state handler of the per-port copy-protection state machine, called from
 *   hdcp_tx_dp_run_state; AUX writes to 0x69318 (16 bytes), 0x69328 (8 bytes) and 0x69494 (one byte 0)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cec18 @ 0xa00cec18-0xa00cef6c, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: unsigned short loop counters; the fill loop stores buf[i],
 * buf[i + 8], buf[i + 16] in that order; dp_tx_aux_request returns int (the void form moves the first argument
 * out of the call delay slot); bytes +3..+8 are plain unsigned char members; the final step_result = STEP_NEXT
 * store is kept even though step_result already holds it.
 */
#define AUX_CMD_WRITE       0x80
#define AUX_PATTERN_FIRST   0x69318     /* 16 bytes written here */
#define AUX_PATTERN_SECOND  0x69328     /* 8 bytes written here */
#define AUX_CLEAR_BYTE      0x69494     /* one byte, written 0 */
#define PATTERN_BYTES       24          /* 0..7 three times */
#define ENGINE_CMD_11       0x11        /* hdcp_tx_engine_start_command codes */
#define ENGINE_CMD_0A       10
#define ENGINE_CMD_0B       0xb
#define ENGINE_LENGTH       0x8000
#define PROT_REG_DATA       1           /* protection block register: bytes to and from the engine */
#define PROT_REG_6          6
#define PROT_REG_6_VALUE    10          /* written to register 6, which is then read until bit 3 clears */
#define PROT_REG_6_BUSY     8

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char pad[15];
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
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);
extern void hdcp_tx_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern int hdmi_tx_ddc_write(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

extern int dp_tx_aux_request(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int dp_tx_aux_write_byte(int, int, int, int);

/*
 * State 0x49 of the DisplayPort output: send the engine a 24-byte test pattern, pass 16 bytes it returns and the
 * rest of the pattern on to the receiver, and, for a receiver that is not a repeater, load the engine with the
 * receiver id and start the counters at 1.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x49. It reports through step_result (STEP_*). Nothing is compared:
 * the bytes read back from the engine are only forwarded.
 *
 *   1. step_result = STEP_NEXT. The pattern is 0..7 three times (24 bytes).
 *   2. Engine command 0x11 (length 0x8000); the 24 bytes go to register 1 of the output's protection block.
 *      Register 6 gets 10 and is read until its bit 3 has cleared.
 *   3. Engine command 10 (length 0x8000); 16 bytes read from register 1 replace pattern bytes 0..15. Over AUX
 *      (channel 0) bytes 0..15 are written to 0x69318 and bytes 16..23 (still the pattern) to 0x69328.
 *   4. Repeater bit set: STEP_OTHER, and nothing more.
 *   5. Repeater bit clear: bit 23 is cleared; engine command 0x0B (0x8000) gets 0xB6 zero bytes, 2, 0x10 and
 *      three zeros; engine command 0x0B with 0x4015 gets the 5 bytes of the output's row in hdcp_tx_receiver_ids,
 *      then 2, 0x10, three zeros and 0x80. device_count and level are set to 1 and the overflow flags and bytes
 *      +7, +8 to 0. Engine command 0 (0x8000). One byte, 0, is written over AUX to 0x69494. step_result =
 *      STEP_NEXT.
 */
void hdcp_tx_dp_state_send_session_key(unsigned char port)
{
    unsigned char buf[PATTERN_BYTES];
    unsigned short i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    for (i = 0; i < 8; i++) {
        buf[i] = i;
        buf[i + 8] = i;
        buf[i + 16] = i;
    }
    hdcp_tx_engine_start_command(port, ENGINE_CMD_11, ENGINE_LENGTH);
    for (i = 0; i < PATTERN_BYTES; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, buf[i]);
    hdcp_tx_reg_write(port, PROT_REG_6, PROT_REG_6_VALUE);
    while (hdcp_tx_reg_read(port, PROT_REG_6) & PROT_REG_6_BUSY)
        ;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0A, ENGINE_LENGTH);
    for (i = 0; i < 16; i++)
        buf[i] = hdcp_tx_reg_read(port, PROT_REG_DATA);
    dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_PATTERN_FIRST, 0xf, buf);
    dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_PATTERN_SECOND, 7, buf + 16);
    if (hdcp_tx_records[port].repeater == 0) {
        hdcp_tx_records[port].bit23 = 0;
        hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, ENGINE_LENGTH);
        for (i = 0; i < 0xb6; i++)
            hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 2);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0x10);
        for (i = 0; i < 3; i++)
            hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x4015);
        for (i = 0; i < 5; i++)
            hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_receiver_ids[port][i]);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 2);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0x10);
        for (i = 0; i < 3; i++)
            hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0x80);
        hdcp_tx_records[port].device_count = 1;
        hdcp_tx_records[port].level = 1;
        hdcp_tx_records[port].count_overflow = 0;
        hdcp_tx_records[port].level_overflow = 0;
        hdcp_tx_records[port].byte_0x7 = 0;
        hdcp_tx_records[port].byte_0x8 = 0;
        hdcp_tx_engine_start_command(port, 0, ENGINE_LENGTH);
        buf[0] = 0;
        dp_tx_aux_write_byte(0, AUX_CMD_WRITE, AUX_CLEAR_BYTE, 0);
        hdcp_tx_records[port].step_result = STEP_NEXT;
    } else
        hdcp_tx_records[port].step_result = STEP_OTHER;
}

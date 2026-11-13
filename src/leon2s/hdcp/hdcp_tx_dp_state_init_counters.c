/* hdcp_tx_dp_state_init_counters  (FUN_a00cdb0c)
 *
 * State handler: for a plain receiver clear the device counters and load its BKSV; then count both up.
 * Note: Device count stops at 0x7F and level at 7; above that the overflow flags are set.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state; register words 0x6350..0x6354
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cdb0c @ 0xa00cdb0c-0xa00cdc40, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: bytes +3..+6 are plain unsigned char members; the 'set the overflow
 * flag' arm comes first in each of the last two tests, as in hdcp_tx_hdmi_state_start_engine.
 */

#define ENGINE_CMD_0B       0xb         /* hdcp_tx_engine_start_command code */
#define PROT_REG_DATA       1           /* protection block register: bytes to the engine */
#define REG_WORD(index) (0xcf000000 | ((index) << 2))
#define DP_REG_BKSV         0x6350      /* register words 0x6350..0x6354: the receiver's BKSV, stored by
                                           hdcp_tx_dp_state_read_bksv */
#define KSV_LENGTH          5
#define MAX_DEVICE_COUNT    0x7f
#define MAX_LEVEL           7

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2 */
    unsigned char device_count;         /* +3: counts up to MAX_DEVICE_COUNT */
    unsigned char level;                /* +4: counts up to MAX_LEVEL */
    unsigned char count_overflow;       /* +5: set when device_count was already at its maximum */
    unsigned char level_overflow;       /* +6: set when level was already at its maximum */
    unsigned char pad[17];
};
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern void hdcp_tx_reg_write(unsigned char, unsigned char, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);

/*
 * State 0x16 of the DisplayPort output: for a receiver that is not a repeater, give the engine the receiver's
 * BKSV; then count the receiver as one more device and one more level.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x16 (state 0x13 goes on to 0x16 when the repeater bit is clear).
 * It always reports STEP_NEXT.
 * The DisplayPort counterpart of hdcp_tx_hdmi_state_start_engine, which differs in where the five bytes come
 * from and in not clearing bit 23.
 *
 * With the repeater bit clear: device_count, level and both overflow flags are cleared; the engine gets
 * command 0x0B with 0x4015; the five BKSV bytes (register words 0x6350..0x6354, written by
 * hdcp_tx_dp_state_read_bksv) go one by one into register 1 of the output's protection block; the engine gets
 * command 0 with 0.
 * In every case device_count and level then go up by one; a counter that is already at its maximum (0x7f and 7)
 * sets its overflow flag instead.
 */
void hdcp_tx_dp_state_init_counters(unsigned char port)
{
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (hdcp_tx_records[port].repeater == 0) {
        hdcp_tx_records[port].device_count = 0;
        hdcp_tx_records[port].level = 0;
        hdcp_tx_records[port].count_overflow = 0;
        hdcp_tx_records[port].level_overflow = 0;
        hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x4015);
        for (i = 0; i < KSV_LENGTH; i++)
            hdcp_tx_reg_write(port, PROT_REG_DATA, *(volatile unsigned int *)REG_WORD(i + DP_REG_BKSV) & 0xff);
        hdcp_tx_engine_start_command(port, 0, 0);
    }
    if (hdcp_tx_records[port].device_count >= MAX_DEVICE_COUNT)
        hdcp_tx_records[port].count_overflow = 1;
    else
        hdcp_tx_records[port].device_count++;
    if (hdcp_tx_records[port].level >= MAX_LEVEL)
        hdcp_tx_records[port].level_overflow = 1;
    else
        hdcp_tx_records[port].level++;
}

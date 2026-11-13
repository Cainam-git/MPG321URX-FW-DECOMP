/* hdcp_tx_service_port  (FUN_a00d12e4)
 *
 * Check and update the state of one output's copy-protection handshake and run its handler.
 * Name basis: derived - state fields of the port record, CP_IRQ check, then the state handlers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d12e4 @ 0xa00d12e4-0xa00d17a8 (1220 bytes), flags -mcpu=v8 -Os -g (the section default).
 * Source forms the exact build depends on:
 *  - void function of an unsigned char port; every record access indexes hdcp_tx_records with the variable
 *    port (no pointer local);
 *  - last_state and above_0x14 are two 3-byte stack arrays, both cleared on entry;
 *  - the first condition is one ?: expression;
 *  - each of the two step-result blocks reads step_result into its own block-local int and compares
 *    (unsigned char)result with STEP_AGAIN and STEP_NEXT; the STEP_BACK test reads the field again.
 */

/* Protection record of an output (24 bytes, three records from hdcp_tx_records; docs/DATA.md). Word 0 is a
   group of bit-fields, bit 31 first. Names follow the other files of the output state machine. */
struct hdcp_tx_record {
    unsigned int active : 1;            /* bit 31: set by hdcp_tx_init_port_record, cleared by hdcp_tx_task */
    unsigned int time_limited : 1;      /* bit 30: set by hdcp_tx_select_next_state for states with a time limit */
    unsigned int receiver_id_known : 1; /* bit 29 */
    unsigned int repeater : 1;          /* bit 28: the receiver is a repeater */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bit22 : 1;
    unsigned int bit21 : 1;
    unsigned int bit20 : 1;
    unsigned int bit19 : 1;
    unsigned int bit18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, written by the state handlers */
    unsigned char state;                /* +2: the state hdcp_tx_hdmi_run_state / _dp_run_state dispatch on */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9: 0xFF = none */
    unsigned char bytes_0xa_0xb[2];
    unsigned int message_counter;       /* +0xC */
    unsigned int word_0x10;             /* 24-bit counter, see hdcp_tx_hdmi_state_send_stream_manage */
    unsigned char byte_0x14;
    unsigned char byte_0x15;
    unsigned short timer_ticks;         /* +0x16: ticks the state's timer is started with */
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_dp_bypass_flag;
extern unsigned char hdmi_tx_is_active(unsigned char);
extern unsigned char dp_tx_is_link_active(int);
extern unsigned char dp_tx_get_reg70_bit4(int);
extern unsigned int dp_tx_get_hpd_event_bits(int);
extern int dbg_printf(const char *, ...);
extern void hdcp_tx_disable_output(unsigned char);
extern void hdcp_tx_init_port_record(unsigned char, unsigned char);
extern void hdcp_tx_hdmi_update_record(unsigned char);
extern unsigned char hdcp_tx_hdmi_check_reauth_request(unsigned char);
extern void hdcp_tx_dp_state_read_receiver_ids(unsigned char);
extern unsigned char hdcp_tx_check_cp_irq(unsigned char);
extern int hdcp_tx_get_timer(int);
extern void hdcp_tx_dp_run_state(unsigned char);
extern void hdcp_tx_hdmi_run_state(unsigned char);
extern void hdcp_tx_select_next_state(unsigned char);

/* Result of a state handler (word 0 bits 16..17); hdcp_tx_select_next_state picks the next state from it. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

#define OUTPUT_DP           2           /* outputs 0, 1 are HDMI, output 2 is DisplayPort */
#define LAST_HDMI_OUTPUT    1
#define DP_TX_LINK_0        0           /* the link number all DP calls here use */
#define HPD_EVENT_BIT2      4           /* third bit of dp_tx_get_hpd_event_bits(0) (dp_tx_hpd_event_bits bit 2) */
#define STATE_GROUP_1X      0x10        /* state bit 4: states 0x10..0x18 */
#define STATE_GROUP_4X      0x40        /* state bit 6: states 0x40..0x4F */
#define TIMER_STATE_BASE    0xb         /* hdcp_tx_get_timer number of an output = port + 0xB */
#define TRIES_RESTART       10
#define COUNTER_LIMIT       0xffffff    /* highest value of the 24-bit counter word_0x10 */
#define KEEP_LISTS          0           /* hdcp_tx_init_port_record flag: keep bytes +3..+8 */

/*
 * One pass of the copy-protection handshake of one video output. Called by hdcp_tx_task for each output for
 * which input_get_port_option is non-zero and whose sink is attached.
 *
 *   port  the output, 0..2 (0 and 1 HDMI, 2 DisplayPort)
 *
 * Phases, in order:
 *   1. Early stop. For an HDMI output while hdmi_tx_is_active(port) returns 0 (bit 1 of word +0x10 of its TX
 *      channel record clear), and for the DisplayPort output while dp_tx_is_link_active(0) and
 *      dp_tx_get_reg70_bit4(0) both return 1, the state byte decides:
 *        0x10, 0x11              return;
 *        0x12..0x17              go on;
 *        0x18                    hdcp_tx_disable_output, the record is initialised (hdcp_tx_init_port_record
 *                                with 0), return;
 *        0x40..0x4E              return;
 *        0x4F                    hdcp_tx_disable_output, the record is initialised, go on;
 *        0x00, 0x01              go on.
 *   2. A record whose active bit (31) is clear stops here.
 *   3. HDMI outputs, time_limited clear and state above 0x43: in state 0x4F with the repeater bit set,
 *      hdcp_tx_hdmi_update_record runs here (it is the handler of state 0x4A) and its result is taken over:
 *      STEP_AGAIN becomes STEP_NEXT, STEP_NEXT sets state 0x4A, STEP_BACK initialises the record; then
 *      hdcp_tx_select_next_state moves the state on. In all other cases hdcp_tx_hdmi_check_reauth_request
 *      reads the receiver's two status bytes; when bit 3 of the second one is set, "InitHDCPMSG(Txlinkidx,
 *      FALSE)" is printed and the record is initialised (the check has already done that once).
 *   4. DisplayPort output, when bit 2 of dp_tx_get_hpd_event_bits(0) is set and either time_limited is clear or
 *      the state is above 0x4A: in states above 0x4A with the repeater bit set, the same as in phase 3 with
 *      hdcp_tx_dp_state_read_receiver_ids (the DisplayPort handler of state 0x4A); otherwise the record is
 *      initialised when hdcp_tx_check_cp_irq(0) returns 1.
 *   5. Run the handler of the current state: hdcp_tx_dp_run_state for output 2 (only while
 *      hdcp_tx_dp_bypass_flag is set), hdcp_tx_hdmi_run_state for outputs 0 and 1.
 *   6. Limits. With time_limited set, STEP_AGAIN after timer port + 0xB has run out, or any result once
 *      tries_left is 0, becomes STEP_BACK; in state 0x4D it becomes STEP_OTHER instead while word_0x10 is not
 *      0xFFFFFF. With time_limited clear and tries_left 0, tries_left is set to 10 and the result to STEP_BACK.
 *   7. hdcp_tx_select_next_state picks the next state from the result.
 *
 * Both stack arrays are cleared on every call: above_0x14[port] is always 1 when the state is 0x18 in phase 1,
 * and last_state is written but never read.
 */
void hdcp_tx_service_port(unsigned char port)
{
    unsigned char last_state[3] = {0, 0, 0};
    unsigned char above_0x14[3] = {0, 0, 0};

    /* 1. Early stop in some states, under the condition given above. */
    if (port != OUTPUT_DP ? hdmi_tx_is_active(port) == 0
                          : dp_tx_is_link_active(DP_TX_LINK_0) != 0 && dp_tx_get_reg70_bit4(DP_TX_LINK_0) == 1) {
        if (hdcp_tx_records[port].state & STATE_GROUP_1X) {
            if (hdcp_tx_records[port].state <= 0x11)
                return;
            if (hdcp_tx_records[port].state > 0x14)
                above_0x14[port] = 1;
            if (hdcp_tx_records[port].state == 0x18 && above_0x14[port] == 1) {
                above_0x14[port] = 0;
                hdcp_tx_disable_output(port);
                hdcp_tx_init_port_record(port, KEEP_LISTS);
                return;
            }
        }
        if (hdcp_tx_records[port].state & STATE_GROUP_4X) {
            if (hdcp_tx_records[port].state <= 0x4e)
                return;
            if (hdcp_tx_records[port].state == 0x4f) {
                hdcp_tx_disable_output(port);
                hdcp_tx_init_port_record(port, KEEP_LISTS);
            }
        }
    }
    /* 2. Nothing more for a record that is not active. */
    if (hdcp_tx_records[port].active == 0)
        return;
    /* 3. HDMI output: the downstream message in state 0x4F, or a request from the receiver. */
    if (port <= LAST_HDMI_OUTPUT && hdcp_tx_records[port].time_limited == 0 && hdcp_tx_records[port].state > 0x43) {
        if (hdcp_tx_records[port].repeater && hdcp_tx_records[port].state == 0x4f) {
            int result;

            hdcp_tx_hdmi_update_record(port);
            result = hdcp_tx_records[port].step_result;
            if ((unsigned char)result == STEP_AGAIN)
                hdcp_tx_records[port].step_result = STEP_NEXT;
            else if ((unsigned char)result == STEP_NEXT)
                hdcp_tx_records[port].state = 0x4a;
            else if (hdcp_tx_records[port].step_result == STEP_BACK)
                hdcp_tx_init_port_record(port, KEEP_LISTS);
            hdcp_tx_select_next_state(port);
        } else if (hdcp_tx_hdmi_check_reauth_request(port)) {
            dbg_printf("\nInitHDCPMSG(Txlinkidx, FALSE)");
            hdcp_tx_init_port_record(port, KEEP_LISTS);
        }
    }
    /* 4. DisplayPort output: the same, started by hot-plug event bit 2. */
    if (port == OUTPUT_DP && (dp_tx_get_hpd_event_bits(DP_TX_LINK_0) & HPD_EVENT_BIT2)) {
        if (hdcp_tx_records[port].time_limited == 0 || hdcp_tx_records[port].state > 0x4a) {
            if (hdcp_tx_records[port].repeater && hdcp_tx_records[port].state > 0x4a) {
                int result;

                hdcp_tx_dp_state_read_receiver_ids(port);
                result = hdcp_tx_records[port].step_result;
                if ((unsigned char)result == STEP_AGAIN)
                    hdcp_tx_records[port].step_result = STEP_NEXT;
                else if ((unsigned char)result == STEP_NEXT)
                    hdcp_tx_records[port].state = 0x4a;
                else if (hdcp_tx_records[port].step_result == STEP_BACK)
                    hdcp_tx_init_port_record(port, KEEP_LISTS);
                hdcp_tx_select_next_state(port);
            } else if (hdcp_tx_check_cp_irq(DP_TX_LINK_0)) {
                hdcp_tx_init_port_record(port, KEEP_LISTS);
            }
        }
    }
    if (last_state[port] != hdcp_tx_records[port].state)
        last_state[port] = hdcp_tx_records[port].state;
    /* 5. Handler of the current state. */
    if (port == OUTPUT_DP) {
        if (hdcp_tx_dp_bypass_flag)
            hdcp_tx_dp_run_state(port);
    } else if (port <= LAST_HDMI_OUTPUT) {
        hdcp_tx_hdmi_run_state(port);
    }
    /* 6. Time limit and tries: turn the result into STEP_BACK (STEP_OTHER in state 0x4D). */
    if (hdcp_tx_records[port].time_limited) {
        if ((hdcp_tx_records[port].step_result == STEP_AGAIN && hdcp_tx_get_timer(port + TIMER_STATE_BASE) == 0)
            || hdcp_tx_records[port].tries_left == 0) {
            hdcp_tx_records[port].step_result = STEP_BACK;
            if (hdcp_tx_records[port].state == 0x4d && hdcp_tx_records[port].word_0x10 != COUNTER_LIMIT)
                hdcp_tx_records[port].step_result = STEP_OTHER;
        }
    }
    if (hdcp_tx_records[port].time_limited == 0 && hdcp_tx_records[port].tries_left == 0) {
        hdcp_tx_records[port].tries_left = TRIES_RESTART;
        hdcp_tx_records[port].step_result = STEP_BACK;
    }
    /* 7. Next state. */
    hdcp_tx_select_next_state(port);
}

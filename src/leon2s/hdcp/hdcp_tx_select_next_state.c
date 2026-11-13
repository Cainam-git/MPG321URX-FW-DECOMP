/* hdcp_tx_select_next_state  (FUN_a00d0d78)
 *
 * Pick the next state of an output's handshake from the step result and start that state's timer.
 * Note: Does nothing on step result 3; also sets the tries counter, the time-limit flag and the timer ticks of
 *   the new state.
 * Name basis: derived - switch over the state byte with the step result of the state handler; ends with
 *   hdcp_tx_set_timer(port + 0xB, ticks); called three times by the routine that runs the state handlers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d0d78 @ 0xa00d0d78-0xa00d12e4, flags -mcpu=v8 -Os -g (the section default).
 * Source forms the exact build depends on:
 *  - void function of an unsigned char port (as hdcp_tx_service_port declares it);
 *  - the state byte and the step result are read through the inline helper read_state_and_result(), which
 *    returns them through pointers to the two locals. GCC 3.4 makes no sibling call in a function that takes
 *    the address of a local, so the final hdcp_tx_set_timer call stays a normal call followed by ret/restore,
 *    as in the firmware;
 *  - word 0 of the record is a union of the whole word, the bit-fields (big-endian, the first field is bit 31)
 *    and the bytes; state 0x13 reads the repeater bit through hdcp_tx_records[port], states 0x42 and 0x45 test
 *    bit 29 as 'record->head.word & RECEIVER_ID_KNOWN_BIT';
 *  - the test 'result == STEP_AGAIN' in state 0x40 stays although the routine has returned on that value
 *    before;
 *  - the first switch compiles to a jump table whose entries lie 0xF10000 below the load addresses (the link
 *    offset of this code).
 */

/* Protection record of an output (24 bytes, three records from hdcp_tx_records; docs/DATA.md). Word 0 is seen
   as a whole word, as bit-fields (bit 31 first) and as bytes. Bit names follow the other files of the output
   state machine. */
struct hdcp_tx_record {
    union {
        unsigned int word;
        struct {
            unsigned int active : 1,            /* bit 31: set by hdcp_tx_init_port_record, cleared by
                                                   hdcp_tx_task 5000 ticks after the sink went away; while
                                                   clear hdcp_tx_service_port stops after its first checks */
                time_limited : 1,               /* bit 30: set here for states with a time limit; see
                                                   hdcp_tx_service_port */
                receiver_id_known : 1,          /* bit 29: set by hdcp_tx_hdmi_state_compare_results and
                                                   hdcp_tx_dp_state_read_hdcp2_messages when the receiver id
                                                   equals the stored one */
                repeater : 1,                   /* bit 28: the receiver is a repeater */
                tries_left : 4,                 /* bits 24..27 */
                bit23 : 1,
                : 3,
                bit19 : 1,
                : 1,
                step_result : 2,                /* bits 16..17: STEP_* below, written by the state handlers */
                : 16;
        } bits;
        struct {
            unsigned char byte_0x0, byte_0x1;
            unsigned char state;                /* +2: the state hdcp_tx_hdmi_run_state / _dp_run_state
                                                   dispatch on */
            unsigned char device_count;         /* +3 */
        } bytes;
    } head;
    unsigned char bytes_0x4_0x15[0x12];
    unsigned short timer_ticks;                 /* +0x16: ticks the state's timer is started with */
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern int hdcp_tx_set_timer(unsigned int, unsigned int);

/* Result of a state handler (word 0 bits 16..17). */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3                              /* the state is kept; this routine returns at once */
};

#define RECEIVER_ID_KNOWN_BIT  0x20000000       /* word 0 bit 29 */
#define TIMER_STATE_BASE       0xb              /* hdcp_tx_set_timer number of an output = port + 0xB */

static inline void read_state_and_result(struct hdcp_tx_record *record, unsigned char *state,
                                         unsigned char *result)
{
    *state = record->head.bytes.state;
    *result = record->head.bits.step_result;
}

/*
 * Move the copy-protection handshake of one output to its next state, from the result the state handler left
 * in the record, and start the timer of the new state.
 *
 *   port  the output, 0..2 (0 and 1 HDMI, 2 DisplayPort)
 *
 * Called by hdcp_tx_service_port: once at the end of every pass, and once more right after
 * hdcp_tx_hdmi_update_record / hdcp_tx_dp_state_read_receiver_ids when it runs those itself.
 * The state handlers (called through hdcp_tx_hdmi_run_state and hdcp_tx_dp_run_state) only write a step result
 * into word 0 bits 16..17; this routine is the only place that reads it and changes the state byte.
 *
 * Phases:
 *   1. Read the state byte and the step result. STEP_AGAIN returns at once: state, flags and timer stay as
 *      they are.
 *   2. Set the timer ticks of the record to 100 (the value for states that do not set their own below).
 *   3. Pick the next state from the old state and the result. The table below is complete; a result that is
 *      not listed for a state leaves the state byte unchanged.
 *        state  BACK  NEXT                OTHER              notes
 *        0x00   0     1                   0
 *        0x01   0     0x10                0x40
 *        0x10   1     0x11                1
 *        0x11   1     0x12                1
 *        0x12   0x13  (kept)              (kept)
 *        0x13   1     0x14 / 0x16         0x14 / 0x16        0x14 when the repeater bit is set
 *        0x14   1     0x15                1, bit23 set
 *        0x15   1     0x16                1
 *        0x16   1     0x17, bit23 set     1
 *        0x17   1     0x18, tries 3       1
 *        0x18   1     (kept)              1
 *        0x40   0     0x41, tries 10      0
 *        0x41   0     0x42                0
 *        0x42   0     0x44 / 0x43         0                  bit19 set on NEXT; 0x44 when bit 29 is set
 *        0x43   0x40  0x45                0x40               (0x44 the same)
 *        0x45   0x40  0x47 / 0x46         0x40              tries 5 on NEXT; 0x47 when bit 29 is set
 *        0x46   0x40  0x47                0x40
 *        0x47   0x40  0x48                0x40
 *        0x48   0x40  0x49                0x47, tries - 1
 *        0x49   0x40  0x4E, bit23 set     0x4A
 *        0x4A   0x40  0x4B                0, bit23 set
 *        0x4B   0x40  0x4C, bit23 set     0x4E, bit23 set
 *        0x4C   0x40  0x4D                0x40
 *        0x4D   0x40  0x4E                0x4C
 *        0x4E   0x4F  (kept)              (kept)
 *        0x4F   1     (kept)              0x4A
 *      Other state values are kept.
 *   4. Set up the new state: the time_limited bit, the timer ticks where the state has its own value, and
 *      the tries counter for states 0x11, 0x13, 0x15, 0x40 and 0x42. Any state value without its own case gets
 *      time_limited and 5000 ticks.
 *   5. Start timer port + 0xB with the timer ticks. hdcp_tx_service_port reads it to end a state that keeps
 *      answering STEP_AGAIN while time_limited is set.
 */
void hdcp_tx_select_next_state(unsigned char port)
{
    struct hdcp_tx_record *record = &hdcp_tx_records[port];
    unsigned char state, result;

    /* 1. State and result. */
    read_state_and_result(record, &state, &result);

    if (result == STEP_AGAIN)
        return;
    /* 2. Default timer ticks. */
    record->timer_ticks = 100;
    /* 3. Next state. */
    switch (state) {
    /* Start states. */
    case 0x00:
        if (result == STEP_NEXT)
            record->head.bytes.state = 1;
        else
            record->head.bytes.state = 0;
        break;
    case 0x01:
        /* The two forms of the handshake: NEXT leads to 0x10..0x18, OTHER to 0x40..0x4F. */
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x10;
        else if (result == STEP_OTHER)
            record->head.bytes.state = 0x40;
        else
            record->head.bytes.state = 0;
        break;
    /* States 0x10..0x18: most results other than the expected one go back to state 1. */
    case 0x10:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x11;
        else
            record->head.bytes.state = 1;
        break;
    case 0x11:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x12;
        else
            record->head.bytes.state = 1;
        break;
    case 0x12:
        /* Here STEP_BACK is the one that moves on. */
        if (result == STEP_BACK)
            record->head.bytes.state = 0x13;
        break;
    case 0x13:
        if (result == STEP_NEXT || result == STEP_OTHER) {
            /* A repeater goes through 0x14 and 0x15 first. */
            if (hdcp_tx_records[port].head.bits.repeater)
                record->head.bytes.state = 0x14;
            else
                record->head.bytes.state = 0x16;
        } else
            record->head.bytes.state = 1;
        break;
    case 0x14:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x15;
        else if (result == STEP_OTHER) {
            record->head.bytes.state = 1;
            record->head.bits.bit23 = 1;
        } else
            record->head.bytes.state = 1;
        break;
    case 0x15:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x16;
        else
            record->head.bytes.state = 1;
        break;
    case 0x16:
        if (result == STEP_NEXT) {
            record->head.bytes.state = 0x17;
            record->head.bits.bit23 = 1;
        } else
            record->head.bytes.state = 1;
        break;
    case 0x17:
        if (result == STEP_NEXT) {
            record->head.bytes.state = 0x18;
            record->head.bits.tries_left = 3;
        } else
            record->head.bytes.state = 1;
        break;
    case 0x18:
        /* The last state of this form: STEP_NEXT stays in it. */
        if (result != STEP_NEXT)
            record->head.bytes.state = 1;
        break;
    /* States 0x40..0x4F: most results other than the expected ones go back to 0x40 (from 0x40..0x42 to 0). */
    case 0x40:
        if (result == STEP_NEXT) {
            record->head.bytes.state = 0x41;
            record->head.bits.tries_left = 10;
        } else if (result == STEP_AGAIN)
            return;
        else
            record->head.bytes.state = 0;
        break;
    case 0x41:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x42;
        else
            record->head.bytes.state = 0;
        break;
    case 0x42:
        if (result == STEP_NEXT) {
            record->head.bits.bit19 = 1;
            /* When the receiver id equals the stored one, 0x44 is used instead of 0x43. */
            if (record->head.word & RECEIVER_ID_KNOWN_BIT)
                record->head.bytes.state = 0x44;
            else
                record->head.bytes.state = 0x43;
        } else
            record->head.bytes.state = 0;
        break;
    case 0x43:
    case 0x44:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x45;
        else
            record->head.bytes.state = 0x40;
        break;
    case 0x45:
        if (result == STEP_NEXT) {
            record->head.bits.tries_left = 5;
            /* When the receiver id equals the stored one, 0x46 is skipped. */
            if (record->head.word & RECEIVER_ID_KNOWN_BIT)
                record->head.bytes.state = 0x47;
            else
                record->head.bytes.state = 0x46;
        } else
            record->head.bytes.state = 0x40;
        break;
    case 0x46:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x47;
        else
            record->head.bytes.state = 0x40;
        break;
    case 0x47:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x48;
        else
            record->head.bytes.state = 0x40;
        break;
    case 0x48:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x49;
        else if (result == STEP_OTHER) {
            /* Back to 0x47 for another try. */
            record->head.bytes.state = 0x47;
            record->head.bits.tries_left--;
        } else
            record->head.bytes.state = 0x40;
        break;
    case 0x49:
        if (result == STEP_NEXT) {
            record->head.bytes.state = 0x4e;
            record->head.bits.bit23 = 1;
        } else if (result == STEP_OTHER)
            record->head.bytes.state = 0x4a;
        else
            record->head.bytes.state = 0x40;
        break;
    case 0x4a:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x4b;
        else if (result == STEP_OTHER) {
            record->head.bytes.state = 0;
            record->head.bits.bit23 = 1;
        } else
            record->head.bytes.state = 0x40;
        break;
    case 0x4b:
        if (result == STEP_NEXT) {
            record->head.bytes.state = 0x4c;
            record->head.bits.bit23 = 1;
        } else if (result == STEP_OTHER) {
            record->head.bytes.state = 0x4e;
            record->head.bits.bit23 = 1;
        } else
            record->head.bytes.state = 0x40;
        break;
    case 0x4c:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x4d;
        else
            record->head.bytes.state = 0x40;
        break;
    case 0x4d:
        if (result == STEP_NEXT)
            record->head.bytes.state = 0x4e;
        else if (result == STEP_OTHER)
            record->head.bytes.state = 0x4c;
        else
            record->head.bytes.state = 0x40;
        break;
    case 0x4e:
        /* Here STEP_BACK is the one that moves on. */
        if (result == STEP_BACK)
            record->head.bytes.state = 0x4f;
        break;
    case 0x4f:
        if (result == STEP_OTHER)
            record->head.bytes.state = 0x4a;
        else if (result == STEP_BACK)
            record->head.bytes.state = 1;
        break;
    }
    /* 4. Set up the new state: time limit, timer ticks and tries. */
    switch (record->head.bytes.state) {
    case 0x00:
        record->head.bits.time_limited = 0;
        record->timer_ticks = 500;
        break;
    case 0x01:
        record->head.bits.time_limited = 0;
        break;
    case 0x10:
        record->head.bits.time_limited = 0;
        break;
    case 0x11:
        record->head.bits.time_limited = 0;
        record->head.bits.tries_left = 10;
        break;
    case 0x12:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 100;
        break;
    case 0x13:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 5000;
        record->head.bits.tries_left = 10;
        break;
    case 0x14:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 5000;
        break;
    case 0x15:
        record->head.bits.time_limited = 0;
        record->head.bits.tries_left = 3;
        break;
    case 0x16:
        record->head.bits.time_limited = 0;
        break;
    case 0x17:
        record->head.bits.time_limited = 0;
        break;
    case 0x18:
        record->head.bits.time_limited = 0;
        break;
    case 0x40:
        record->head.bits.time_limited = 0;
        record->head.bits.tries_left = 5;
        break;
    case 0x41:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 100;
        break;
    case 0x42:
        record->head.bits.time_limited = 0;
        record->head.bits.tries_left = 4;
        break;
    case 0x43:
        record->head.bits.time_limited = 0;
        break;
    case 0x44:
        record->head.bits.time_limited = 0;
        break;
    case 0x45:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 1000;
        break;
    case 0x46:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 300;
        break;
    case 0x47:
        record->head.bits.time_limited = 0;
        break;
    case 0x48:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 1000;
        break;
    case 0x49:
        record->head.bits.time_limited = 0;
        break;
    case 0x4a:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 3000;
        break;
    case 0x4b:
        record->head.bits.time_limited = 0;
        record->timer_ticks = 200;
        break;
    case 0x4c:
        record->head.bits.time_limited = 0;
        break;
    case 0x4d:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 150;
        break;
    case 0x4e:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 220;
        break;
    case 0x4f:
        record->head.bits.time_limited = 0;
        record->timer_ticks = 1000;
        break;
    default:
        record->head.bits.time_limited = 1;
        record->timer_ticks = 5000;
        break;
    }
    /* 5. Start the state's timer. */
    hdcp_tx_set_timer(port + TIMER_STATE_BASE, record->timer_ticks);
}

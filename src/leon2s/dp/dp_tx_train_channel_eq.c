/* dp_tx_train_channel_eq  (FUN_a008743c)
 *
 * Run the channel-equalisation phase of link training on the selected outputs.
 * Name basis: derived - pattern 2..4 with drive levels and a status/adjust loop; clears failing outputs from
 *   the mask
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008743c @ 0xa008743c-0xa00876ec (688 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - lo = 0 at its declaration and 'lo = 0; hi = 0;' in the '!all_edp' arm, round = 0 at its declaration
 *    (lo's zero is copied from that register);
 *  - the caps record as unsigned char [][6], as in dp_tx_train_clock_recovery;
 *  - the pattern code set in both arms of the bit 5 test ('else pattern = 2 - no_bit6');
 *  - in the 8/9 and round paths the mask clear comes first ('if (out != 0) { ...; goto next; }');
 *  - the lane count is copied into lane_count before the check, and the check result into code.
 */
/* Link status record filled by dp_tx_read_link_status (as in dp_tx_train_clock_recovery): byte 0 bit 7 = status
 * was read, bytes 4 and 5 the lane status bytes, bytes 8..0xF the level requests. */
struct link_status {
    unsigned char valid : 1;
    unsigned char byte0_rest : 7;
    unsigned char b[15];
};
extern unsigned char dp_tx_edp_last_output;
extern unsigned char dp_tx_edp_first_output;
extern unsigned char dp_tx_sink_caps_records[][6];
extern void dp_tx_set_link_pattern(unsigned char, unsigned char);
extern void dp_tx_set_drive_levels(unsigned char, unsigned char, unsigned char);
extern unsigned char dp_tx_set_pattern_and_levels(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char);
extern void timer_delay_long_units(int);
extern void dp_tx_read_link_status(unsigned char, struct link_status *);

extern void dp_tx_get_max_adjust_request(struct link_status *, unsigned char, unsigned char *, unsigned char *);
extern unsigned char dp_tx_set_lane_drive_levels(unsigned int, unsigned int, unsigned char, unsigned char);
extern unsigned char dp_tx_check_channel_eq(unsigned int, unsigned char *);
extern int dbg_print_string(const char *);
extern unsigned char dp_tx_check_caps_byte1(unsigned int);

/* Sink caps record (dp_tx_sink_caps_records) fields used here, as in dp_tx_read_sink_caps. */
#define CAPS_FLAGS      0
#define CAPS_AUX_WAIT   5       /* training wait value */
#define CAPS_BIT5       0x20    /* selects pattern code 3 */
#define CAPS_BIT6       0x40    /* selects pattern code 2 (else 1) */

/* Results. 5, 8 and 9 come from dp_tx_check_channel_eq; dp_tx_train_links ends the training on 5, halves the
   lane count on 9 and steps the link rate down on 8. */
#define TRAIN_NOTHING_DONE  1
#define TRAIN_FAILED        2       /* a write to the sink failed, or output 0's status could not be read */
#define TRAIN_EQ_DONE       5
#define TRAIN_LOWER_RATE    8
#define TRAIN_FEWER_LANES   9

#define MAX_ROUNDS      5       /* round counts 1 + status reads: an output gives up at its fifth read */
#define CAPS_BYTE1_0x14 1       /* dp_tx_check_caps_byte1: byte 1 of the caps record is 0x14 */

/*
 * Channel-equalisation phase of link training, for output 0 or for all eDP outputs. Runs after
 * dp_tx_train_clock_recovery returned 4.
 *
 *   all_edp  0 = output 0 only; non-zero = dp_tx_edp_first_output..dp_tx_edp_last_output
 *            (dp_tx_train_links passes its first output number)
 *   lanes    lane count being trained
 *   status   one 16-byte link status record per output (indexed by output); on entry it holds the last status
 *            of the clock-recovery phase
 *   mask     bit n set = output n still takes part; the bit of an output that fails is cleared
 *
 * Returns the last result: TRAIN_EQ_DONE when the last output handled finished, TRAIN_FAILED when a write to a
 * sink failed, TRAIN_LOWER_RATE or TRAIN_FEWER_LANES when output 0 gave up, TRAIN_NOTHING_DONE when no output
 * was in the mask; any other code of dp_tx_check_channel_eq can also come back.
 *
 * Phases:
 *   1. Per output in the mask: choose the pattern code from the caps flags (3 with flag bit 5, else 2 with flag
 *      bit 6, else 1), select it in the transmitter and write it to the sink with the highest levels the sink
 *      asked for. A failed write takes the output out of the mask (output 0 returns TRAIN_FAILED).
 *   2. Per output still in the mask, in rounds: wait the output's training wait value, read the link status and
 *      stop on the first of these:
 *        status not read           output 0 returns TRAIN_FAILED, the others go on to the next output;
 *        lanes equalised (5)       next output;
 *        8 or 9                    the output leaves the mask; output 0 prints 'Lost CDR' and returns the code
 *                                  when dp_tx_check_caps_byte1(0) is 1, else TRAIN_LOWER_RATE;
 *        fifth round reached       the output leaves the mask; output 0 returns TRAIN_FEWER_LANES when
 *                                  dp_tx_check_caps_byte1(0) is 1, else TRAIN_LOWER_RATE.
 *      Otherwise the highest requested levels go to the transmitter and to the sink, and the next round starts
 *      as long as that write succeeds (when it fails: TRAIN_FAILED, next output).
 * The swing and pre-emphasis values carry over from one output to the next.
 */
unsigned char dp_tx_train_channel_eq(unsigned char all_edp, unsigned char *lanes, struct link_status *status, unsigned char *mask)
{
    unsigned char swing = 0;
    unsigned char pre_emphasis = 0;
    unsigned char result = TRAIN_NOTHING_DONE;
    unsigned char lo = 0;
    unsigned char hi;
    unsigned char out;
    unsigned char round = 0;
    unsigned char pattern;
    unsigned char no_bit6;
    unsigned char lane_count;
    unsigned char code;
    struct link_status *st;

    if (!all_edp) {
        lo = 0;
        hi = 0;
    } else {
        lo = dp_tx_edp_first_output;
        hi = dp_tx_edp_last_output;
    }

    /* 1. Select and send the pattern with the levels of the last status. */
    for (out = lo; out <= hi; out++) {
        st = &status[out];
        if ((*mask >> out) & 1) {
            no_bit6 = ((dp_tx_sink_caps_records[out][CAPS_FLAGS] >> 6) & 1) ^ 1;
            if (dp_tx_sink_caps_records[out][CAPS_FLAGS] & CAPS_BIT5)
                pattern = 3;
            else
                pattern = 2 - no_bit6;
            dp_tx_set_link_pattern(out, pattern);
            dp_tx_get_max_adjust_request(st, *lanes, &swing, &pre_emphasis);
            if (dp_tx_set_pattern_and_levels(out, pattern, *lanes, swing, pre_emphasis) == 0) {
                *mask &= ~(1 << out);
                if (out == 0)
                    return TRAIN_FAILED;
            }
        }
    }

    /* 2. Status and adjust rounds. */
    for (out = lo; out <= hi; out++) {
        if ((*mask >> out) & 1) {
            st = &status[out];
            round = 1;
            do {
                timer_delay_long_units(dp_tx_sink_caps_records[out][CAPS_AUX_WAIT]);
                dp_tx_read_link_status(out, st);
                round++;
                if (!st->valid) {
                    if (out == 0)
                        return TRAIN_FAILED;
                    goto next;
                }
                lane_count = *lanes;
                result = dp_tx_check_channel_eq(lane_count, (unsigned char *)st);
                code = result;
                if (code == TRAIN_EQ_DONE)
                    goto next;
                if (result == TRAIN_LOWER_RATE || result == TRAIN_FEWER_LANES) {
                    if (out != 0) {
                        *mask &= ~(1 << out);
                        goto next;
                    }
                    dbg_print_string("Lost CDR\r");
                    if (dp_tx_check_caps_byte1(0) == CAPS_BYTE1_0x14)
                        return code;
                    return TRAIN_LOWER_RATE;
                }
                if (round > MAX_ROUNDS) {
                    if (out != 0) {
                        *mask &= ~(1 << out);
                        goto next;
                    }
                    if (dp_tx_check_caps_byte1(0) == CAPS_BYTE1_0x14)
                        return TRAIN_FEWER_LANES;
                    return TRAIN_LOWER_RATE;
                }
                /* Apply the highest requested levels and write them to the sink. */
                dp_tx_get_max_adjust_request(st, lane_count, &swing, &pre_emphasis);
                dp_tx_set_drive_levels(out, pre_emphasis, swing);
            } while (dp_tx_set_lane_drive_levels(out, *lanes, swing, pre_emphasis));
            result = TRAIN_FAILED;
        }
    next:;
    }
    return result;
}

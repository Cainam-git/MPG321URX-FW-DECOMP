/* dp_tx_train_clock_recovery  (FUN_a0087110)
 *
 * Run the clock-recovery phase of link training on the selected outputs.
 * Name basis: derived - pattern 1 with drive levels, status read and adjust loop; clears failing outputs from
 *   the mask
 *
 * Matching notes
 * --------------
 * FUN_a0087110 (leon2s 0xa0087110-0xa0087364, 596 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: lo initialised to 0 at its declaration and assigned again in the
 * '!all_edp' arm as 'hi = 0; lo = 0;' (the firmware's 'mov %l6,%l4' copy of prev's zero register); the
 * per-port loop leaves through 'goto next'; t holds the lane count and later the swing request.
 */
/* Link status record filled by dp_tx_read_link_status: byte 0 bit 7 = status was read, bytes 1..15 = the
 * values it unpacks (bytes 4 and 5 hold the lane status bytes, bytes 8..0xF the level requests). */
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
extern unsigned char dp_tx_check_clock_recovery(unsigned int, struct link_status *);
extern void dp_tx_get_max_adjust_request(struct link_status *, unsigned char, unsigned char *, unsigned char *);
extern unsigned char dp_tx_set_lane_drive_levels(unsigned int, unsigned int, unsigned char, unsigned char);

#define CAPS_AUX_WAIT 5 /* training wait value of the sink caps record */

/*
 * Clock-recovery phase of link training, for output 0 or for all eDP outputs.
 *   all_edp: 0 = output 0 only; non-zero = dp_tx_edp_first_output..dp_tx_edp_last_output
 *   lanes:   lane count being trained
 *   status:  one 16-byte link status record per output (indexed by output), filled here
 *   mask:    bit n set = output n still takes part; the bit of an output that fails is cleared
 * Returns 4 when an output reached clock recovery, 8 or 2 when output 0 failed (see below), otherwise 2 if the
 * last drive-level write to a sink failed, else 1 (nothing done).
 *
 * Pass 1, per output in the mask: select link pattern 0, set the drive levels to 0 and write training pattern 1
 * with zero levels to the sink; if that write fails the output leaves the mask (output 0 returns 8).
 * Pass 2, per output still in the mask, repeat: wait the output's training wait value, read the link status,
 * and stop on the first of these: status unreadable (output leaves the mask; output 0 returns 2); clock
 * recovery done on the lanes (result 4, output stays in the mask); the requested level has not changed for
 * more than 5 rounds, or the previous round's request was above 2 (output leaves the mask; output 0 returns
 * 8). Otherwise the highest swing request (swing) and the highest second request (second) over the lanes
 * are applied to the transmitter and written to the sink, and the round starts again as long as that write
 * succeeds. swing_prev carries over from one output to the next.
 */
unsigned char dp_tx_train_clock_recovery(unsigned char all_edp, unsigned char *lanes, struct link_status *status, unsigned char *mask)
{
    unsigned char swing_prev = 0;
    unsigned char second = 0;
    unsigned char swing = 0;
    unsigned char result = 1;
    unsigned char lo = 0;
    unsigned char hi;
    unsigned char out;
    unsigned char round;
    struct link_status *st;
    unsigned char t;

    if (!all_edp) {
        hi = 0;
        lo = 0;
    } else {
        lo = dp_tx_edp_first_output;
        hi = dp_tx_edp_last_output;
    }
    for (out = lo; out <= hi; out++) {
        if ((*mask >> out) & 1) {
            dp_tx_set_link_pattern(out, 0);
            dp_tx_set_drive_levels(out, 0, second);
            if (dp_tx_set_pattern_and_levels(out, 0, *lanes, 0, 0) == 0) {
                *mask &= ~(1 << out);
                if (out == 0)
                    return 8;
            }
        }
    }
    for (out = lo; out <= hi; out++) {
        if ((*mask >> out) & 1) {
            st = &status[out];
            round = 1;
            do {
                timer_delay_long_units(dp_tx_sink_caps_records[out][CAPS_AUX_WAIT]);
                dp_tx_read_link_status(out, st);
                if (!st->valid) {
                    *mask &= ~(1 << out);
                    if (out == 0)
                        return 2;
                    goto next;
                }
                t = *lanes;
                if (dp_tx_check_clock_recovery(t, st) == 4) {
                    result = 4;
                    goto next;
                }
                dp_tx_get_max_adjust_request(st, t, &swing, &second);
                t = swing;
                if (t != swing_prev)
                    round = 1;
                round++;
                if (round > 5 || swing_prev > 2) {
                    *mask &= ~(1 << out);
                    if (out == 0)
                        return 8;
                    goto next;
                }
                swing_prev = swing;
                dp_tx_set_drive_levels(out, second, t);
            } while (dp_tx_set_lane_drive_levels(out, *lanes, t, second));
            result = 2;
        }
    next:;
    }
    return result;
}

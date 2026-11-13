/* dp_tx_train_links  (TRAINING_NORESPONSE)
 *
 * Train the links of the DP outputs and report each channel's result.
 * Note: The label is one of the routine's own texts: it holds the prints 'TRAINING_NORESPONSE' and
 *   'TRAINING_FAIL' in its retry code.
 * Name basis: proven - prints 'Channel[%02x] is Training done!!' / 'Training fail' / 'is skipped'; clock
 *   recovery then channel EQ
 *
 * Matching notes
 * --------------
 * leon2s TRAINING_NORESPONSE @ 0xa0087824-0xa0087d50 (1324 bytes), flags -mcpu=v8 -Os -g (section default).
 * dp_reset_receiver_flags and dp_mst_wait_downstream_ready are the labels func_0x9f1c649c and func_0x9f1c64ec.
 * Source forms the exact build depends on:
 *  - link_cfg is zero-initialised at its declaration and its two bytes are stored after the range set-up,
 *    lanes first;
 *  - the retry tests read the loop index i left by the channel loop ('if (i)');
 *  - the lane fall-back copies lanes into an unsigned int (lanes is address-taken) and tries the two lane counts
 *    as a search with 'goto found' on the first success and 'goto fail' after the second;
 *  - the rate step is a switch, written out twice.
 */
#define REG_CF018D00 (*(volatile unsigned int *)0xcf018d00)     /* bits 0..1 cleared for each output trained */

/* Link rate codes (dp_tx_limits_others, register 2 of an output). */
#define LINK_RATE_RBR       0x06
#define LINK_RATE_HBR       0x0a
#define LINK_RATE_HBR2      0x14
#define LINK_RATE_HBR3      0x1e

#define MAX_LANES           4

/* link_cfg, filled per output by dp_tx_choose_link_config. */
enum {
    CFG_RATE         = 0,   /* rate code to start with */
    CFG_LANES        = 1,   /* lane count to start with */
    CFG_LOWEST_RATE  = 2,   /* lowest rate code to fall back to */
    CFG_LOWEST_LANES = 3    /* lowest lane count to fall back to */
};

/* Results of dp_tx_train_clock_recovery / dp_tx_train_channel_eq. */
#define TRAIN_DONE          0       /* this routine's own value after TRAIN_EQ_DONE */
#define TRAIN_NOTHING_DONE  1
#define TRAIN_FAILED        2
#define TRAIN_CR_DONE       4       /* clock recovery reached; also dp_tx_check_clock_recovery's 'done' */
#define TRAIN_EQ_DONE       5
#define TRAIN_LOWER_RATE    8
#define TRAIN_FEWER_LANES   9

#define TRAIN_TRIES         2

/* dp_tx_get_link_state values (bit 0 of 0xCF0189E0 set in both). */
#define TX_LINK_STATE_1     1       /* bit 7 of 0xCF013000 set */
#define TX_LINK_STATE_2     2       /* bit 7 of 0xCF013000 clear, bit 1 set */

/* Transmitter register 0x66 of the eDP outputs, chosen by the output's bits per colour (path record +0x15). */
#define TX_REG_0x66         0x66
#define TX_0x66_6BPC        0x00
#define TX_0x66_8BPC        0x20    /* also any other value */
#define TX_0x66_10BPC       0x40

#define SINK_POWER_ON       1       /* dp_tx_set_sink_power: 1 to DPCD 0x600 */
#define CAPS_BYTE1_0x14     1       /* dp_tx_check_caps_byte1: byte 1 of output 0's caps record is 0x14 */
#define TRAINING_PATTERN_OFF 7      /* dp_tx_set_training_pattern: any value above 3 writes 0 to DPCD 0x102 */
#define LINK_PATTERN_TRAINED 4      /* dp_tx_set_link_pattern after a successful training */
#define LINK_PATTERN_DEFAULT 7      /* dp_tx_set_link_pattern after a failed training */

#define LINK_STATUS_BYTES   80      /* 16-byte link status record per output, outputs 0..4 */

extern unsigned char dp_tx_edp_first_output;
extern unsigned char dp_tx_edp_last_output;

extern unsigned char dp_tx_get_link_state(void);
extern unsigned char dp_is_link_trained(unsigned char port);
extern unsigned char dp_tx_get_path_bits_per_colour(unsigned int port);
extern void dp_tx_reg_write8(unsigned int port, unsigned short reg, unsigned int v);
extern void dp_tx_choose_link_config(unsigned char port, unsigned char *cfg);
extern int dp_tx_set_sink_power(int port, int v);
extern void dp_tx_set_link_rate(unsigned int port, unsigned char a, unsigned int b);
extern void dp_tx_set_lane_count(unsigned char port, unsigned int v);
extern int dp_tx_write_link_config(unsigned char port, unsigned char hi, unsigned char lo);
extern unsigned char dp_tx_train_clock_recovery(unsigned char port, unsigned char *lv, unsigned char *buf, unsigned char *caps);
extern unsigned char dp_tx_train_channel_eq(unsigned char port, unsigned char *lv, unsigned char *buf, unsigned char *caps);
extern unsigned int dbg_print_string(const char *s);
extern unsigned char dp_tx_check_caps_byte1(unsigned int v);
extern unsigned char dp_tx_check_clock_recovery(unsigned int mode, unsigned char *buf);
extern unsigned char dp_tx_set_training_pattern(unsigned int port, unsigned int v);
extern unsigned char dp_tx_get_mode_flag(void);
extern void dp_reset_receiver_flags(void);
extern void dp_mst_wait_downstream_ready(void);
extern unsigned char dp_tx_write_downspread(unsigned char port);
extern void dp_tx_set_lane_routing(unsigned char port);
extern void dp_tx_set_link_pattern(unsigned char bank, unsigned char mode);
extern int dbg_printf(const char *, ...);

/*
 * Train the links of DP output 0 or of the eDP outputs, and set every output of the range to the trained or the
 * failed state. Returns 1 when the training succeeded, else 0.
 *
 *   all_edp  0: output 0 only; non-zero: outputs dp_tx_edp_first_output..dp_tx_edp_last_output. The callers
 *            pass their first output number (DPTX_IsHPDAction_Off its port, dp_tx_edp_run_hpd_actions its lo),
 *            and the value is handed on to the two training phases as their own all_edp.
 *   mask     bit n set = output n takes part. The training phases clear the bit of an output that fails.
 *
 * Phases, in order:
 *   1. Per output in the mask: output 0 gives up at once (returns 0) when dp_tx_get_link_state() is 2 and
 *      dp_is_link_trained(0) does not return 1. Clear bits 0..1 of register 0xCF018D00; on an eDP output set
 *      transmitter register 0x66 from its bits per colour; choose rate and lane count (dp_tx_choose_link_config)
 *      and switch the sink on. The last output's choice is the one used for all.
 *   2. Up to two tries: program rate and lane count into each output in the mask and into its sink, then run
 *      clock recovery and, when that reached TRAIN_CR_DONE, channel equalisation. TRAIN_EQ_DONE ends the loop
 *      with success.
 *      Any other result uses up one try. The test that decides this reads the loop index i, which the channel
 *      loop leaves at the last output + 1 and so is never 0: the fall-backs written after it (a lower rate
 *      on TRAIN_LOWER_RATE, half the lanes on TRAIN_FEWER_LANES, after a clock-recovery failure a lower rate or
 *      fewer lanes) and the prints "TRAINING_NORESPONSE" / "TRAINING_FAIL" are not reached, so both tries run
 *      at the first rate and lane count.
 *   3. Per output of the range: switch the sink's training pattern off (output 0 returns 0 when that write
 *      fails). After a success, write the spread setting to the sink; on output 0, when the mode flag of path 0
 *      is set and the link state is 1, first dp_reset_receiver_flags and dp_mst_wait_downstream_ready.
 *   4. Per output of the range: set the lane routing and link pattern 4 ('Training done!!', or 'is skipped'
 *      for an output not in the mask) and return 1; after a failure link pattern 7 ('Training fail') and
 *      return 0.
 */
unsigned char dp_tx_train_links(unsigned char all_edp, unsigned char *mask)
{
    unsigned char link_cfg[4] = {0};
    unsigned char link_status[LINK_STATUS_BYTES];
    unsigned char lanes;
    unsigned char tries_left = TRAIN_TRIES;
    unsigned char start = 0;
    unsigned char end = 0;
    unsigned char i;
    unsigned char rate;
    unsigned char result;
    unsigned int lanes_now;
    unsigned int fewer_lanes;

    if (all_edp) {
        start = dp_tx_edp_first_output;
        end = dp_tx_edp_last_output;
    }
    link_cfg[CFG_LANES] = MAX_LANES;
    link_cfg[CFG_RATE] = LINK_RATE_HBR3;

    /* Phase 1: prepare each output in the mask. */
    for (i = start; i <= end; i++) {
        if ((*mask >> i) & 1) {
            if (i == 0 && dp_tx_get_link_state() == TX_LINK_STATE_2 && dp_is_link_trained(0) != 1)
                return 0;
            REG_CF018D00 &= ~3;
            if (i != 0) {
                result = dp_tx_get_path_bits_per_colour(i);
                if (result == 8)
                    dp_tx_reg_write8(i, TX_REG_0x66, TX_0x66_8BPC);
                else if (result == 6)
                    dp_tx_reg_write8(i, TX_REG_0x66, TX_0x66_6BPC);
                else if (result == 10)
                    dp_tx_reg_write8(i, TX_REG_0x66, TX_0x66_10BPC);
                else
                    dp_tx_reg_write8(i, TX_REG_0x66, TX_0x66_8BPC);
            }
            dp_tx_choose_link_config(i, link_cfg);
            dp_tx_set_sink_power(i, SINK_POWER_ON);
        }
    }

    /* Phase 2: the training tries. */
    lanes = link_cfg[CFG_LANES];
    rate = link_cfg[CFG_RATE];
    do {
        for (i = start; i <= end; i++) {
            if ((*mask >> i) & 1) {
                /* Passing the output as the second output too sets up the PHY rate of every output. */
                dp_tx_set_link_rate(i, rate, i);
                dp_tx_set_lane_count(i, lanes);
                dp_tx_write_link_config(i, lanes, rate);
            }
        }
        result = dp_tx_train_clock_recovery(start, &lanes, link_status, mask);
        if (result == TRAIN_CR_DONE) {
            result = dp_tx_train_channel_eq(start, &lanes, link_status, mask);
            if (result != TRAIN_EQ_DONE) {
                /* i = last output + 1, never 0: one try used, the code below is not reached. */
                if (i) {
                    tries_left--;
                    continue;
                }
                if (result == TRAIN_FEWER_LANES) {
                    if (lanes > link_cfg[CFG_LOWEST_LANES]) {
                        lanes = lanes >> 1;
                        continue;
                    }
                    result = TRAIN_LOWER_RATE;
                }
                if (result == TRAIN_LOWER_RATE) {
                    if (rate > link_cfg[CFG_LOWEST_RATE]) {
                        switch (rate) {
                        case LINK_RATE_HBR3:
                            rate = LINK_RATE_HBR2;
                            break;
                        case LINK_RATE_HBR2:
                            rate = LINK_RATE_HBR;
                            break;
                        case LINK_RATE_HBR:
                            rate = LINK_RATE_RBR;
                            break;
                        }
                        lanes = link_cfg[CFG_LANES];
                        continue;
                    }
                    result = TRAIN_NOTHING_DONE;
                }
            }
        } else {
            dbg_print_string("CDR fail\r");
            /* As above: one try used, the fall-backs below are not reached. */
            if (i) {
                tries_left--;
                continue;
            }
            if (rate > link_cfg[CFG_LOWEST_RATE]) {
                switch (rate) {
                case LINK_RATE_HBR3:
                    rate = LINK_RATE_HBR2;
                    break;
                case LINK_RATE_HBR2:
                    rate = LINK_RATE_HBR;
                    break;
                case LINK_RATE_HBR:
                    rate = LINK_RATE_RBR;
                    break;
                }
                continue;
            }
            /* At the lowest rate: try half, then a quarter of the lanes against the last link status. */
            if (dp_tx_check_caps_byte1(0) == CAPS_BYTE1_0x14) {
                lanes_now = lanes;
                if (lanes_now > link_cfg[CFG_LOWEST_LANES]) {
                    fewer_lanes = lanes_now >> 1;
                    if (dp_tx_check_clock_recovery(fewer_lanes, link_status) == TRAIN_CR_DONE)
                        goto found;
                    fewer_lanes = lanes_now >> 2;
                    if (dp_tx_check_clock_recovery(fewer_lanes, link_status) != TRAIN_CR_DONE)
                        goto fail;
                found:
                    lanes = fewer_lanes;
                    rate = link_cfg[CFG_RATE];
                    continue;
                }
            }
        fail:
            result = TRAIN_NOTHING_DONE;
        }
        if (result == TRAIN_FAILED) {
            dbg_print_string("TRAINING_NORESPONSE\r");
            break;
        }
        if (result == TRAIN_NOTHING_DONE) {
            dbg_print_string("TRAINING_FAIL\r");
            break;
        }
        if (result == TRAIN_EQ_DONE) {
            result = TRAIN_DONE;
            break;
        }
    } while (tries_left);

    /* Phase 3: training pattern off in every sink of the range. */
    for (i = start; i <= end; i++) {
        if (!dp_tx_set_training_pattern(i, TRAINING_PATTERN_OFF)) {
            if (i == 0)
                return 0;
        } else if (result == TRAIN_DONE) {
            if (i == 0 && dp_tx_get_mode_flag() == 1 && dp_tx_get_link_state() == TX_LINK_STATE_1) {
                dp_reset_receiver_flags();
                dp_mst_wait_downstream_ready();
            }
            dp_tx_write_downspread(i);
        }
    }

    /* Phase 4: final link pattern and report per output. */
    if (result == TRAIN_DONE) {
        for (i = start; i <= end; i++) {
            dp_tx_set_lane_routing(i);
            dp_tx_set_link_pattern(i, LINK_PATTERN_TRAINED);
            if ((*mask >> i) & 1)
                dbg_printf("Channel[%02x] is Training done!!\r\n", i);
            else
                dbg_printf("Channel[%02x] is skipped\r\n", i);
        }
        return 1;
    }
    for (i = start; i <= end; i++) {
        dp_tx_set_lane_routing(i);
        dp_tx_set_link_pattern(i, LINK_PATTERN_DEFAULT);
        dbg_printf("Channel[%02x] is Training fail\r\n", i);
    }
    return 0;
}

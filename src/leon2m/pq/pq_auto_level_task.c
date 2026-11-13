/* pq_auto_level_task  (FUN_a012a774)
 *
 * Measure the picture and step the brightness level towards the computed target.
 * Name basis: derived - 16 measured sums; level stepped and passed to SetBrightness; called from the main-loop
 *   task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012a774 @ 0xa012a774-0xa012ad64 (1520 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - pq_auto_level_set_weights is a static copy of the routine at 0xa012a1a0 and is inlined here with the weight
 *    table as its argument; write_level (the body of the routine at 0xa012a700), set_level and
 *    step_towards_target are static helpers that GCC inlines;
 *  - the new target is stored and then clamped with LIMIT(pq_auto_level_target, 0, LEVEL_MAX)
 *    (0xa012a9c0-0xa012ad04);
 *  - step_towards_target returns 1 when it handled the step, and the caller then restores the window and returns
 *    in its own branch, although the code after it does the same;
 *  - the difference test is written as two signed compares (cur - tgt > 5 || cur - tgt < -5);
 *  - the target is computed with a 64-bit product of unsigned ints.
 */

/* Bytes of the system configuration record (stSysConfig) read here. */
#define SYS_CONFIG_AUTO_LEVEL_MODE  7       /* 1 = automatic level stepping on */
#define SYS_CONFIG_BRIGHTNESS       8       /* brightness, 0..100 */

#define AUTO_LEVEL_ON           1           /* value of SYS_CONFIG_AUTO_LEVEL_MODE */

/* Level range of the stepping, and the range handed to SetBrightness: LEVEL_MIN .. LEVEL_MIN + LEVEL_RANGE. */
#define LEVEL_MAX               0x3ff
#define LEVEL_MIN               126         /* 0x7e */
#define LEVEL_RANGE             897         /* 0x381 */

#define AUTO_LEVEL_BINS         16          /* measured sums read from the ACE block */
#define AUTO_LEVEL_HOLD_LEVEL   0x20        /* written straight to SetBrightness while the hold is on */
#define AUTO_LEVEL_WAIT_TICKS   10000       /* the 10-second wait before the hold is switched on */
#define LEVEL_STEP              4           /* change of the applied level per call */
#define LEVEL_DEADBAND          5           /* a difference up to this does not start a new ramp */
#define DEFAULT_WEIGHT          0x3a
#define AUTO_LEVEL_WEIGHTS      16

#define MAIN_CHANNEL            0

/* Argument of pq_ace_configure: two bits of the ACE configuration register and the number of sums. */
struct ace_config_arg {
    unsigned char config_bit7;      /* goes to bit 7 of ACE_CONFIG (0xCF00EEC0) */
    unsigned char config_bit6;      /* goes to bit 6 */
    unsigned char sum_count;        /* 8 or 16 sums; any other value gives 4 */
};

/* The fifteen callbacks registered at start-up; only slot 13 is used here. */
struct callback_table {
    unsigned char slots_0_to_12[0x34];
    void (*level_hook)(unsigned short *);   /* slot 13: adjusts a level value in place */
};

extern struct callback_table sys_callback_table;
extern unsigned char sys_config[];
extern unsigned char device_settings_pip_mode;
extern const unsigned char pq_auto_level_weights[16];
extern unsigned char pq_auto_level_weight_values[16];
extern int pq_auto_level_jump_flag;
extern int pq_auto_level_sum;
extern unsigned short pq_auto_level_weight_sum;
extern unsigned char pq_auto_level_active;
extern unsigned short pq_auto_level_ticks;
extern unsigned char pq_auto_level_condition;
extern unsigned char pq_auto_level_stepping;
extern int pq_auto_level_bins[16];
extern unsigned short pq_auto_level_target;
extern unsigned short pq_auto_level_current;

extern unsigned char pq_get_selected_window(void);
extern void pq_ace_read_histogram(unsigned char, int *);
extern void pq_ace_configure(struct ace_config_arg);
extern void pq_select_window(unsigned char);
extern unsigned char input_api_get_channel_format_code(unsigned char);
extern unsigned char input_block_restart_statistics(unsigned char);
extern unsigned char input_block_read_reg43(unsigned char);
extern unsigned char input_block_read_reg44(unsigned char);
extern unsigned char input_block_read_reg45(unsigned char);
extern unsigned char osd_is_enabled(unsigned char);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern void SetBrightness(unsigned short);
extern void gpio_set_aux_bit0_high(void);
extern void gpio_set_aux_bit0_low(void);
extern int abs(int);

#define LIMIT(v, lo, hi) \
    if ((v) <= (lo)) \
        (v) = (lo); \
    else if ((v) > (hi)) \
        (v) = (hi)

/* Scale a level 0..LEVEL_MAX to LEVEL_MIN..LEVEL_MIN + LEVEL_RANGE, let the slot-13 hook adjust it, and write it
   to the panel (SetBrightness writes it as the OLED luminance gain). */
static void write_level(unsigned short level)
{
    level = level * (unsigned)LEVEL_RANGE / LEVEL_MAX + LEVEL_MIN;
    if (sys_callback_table.level_hook != 0)
        sys_callback_table.level_hook(&level);
    SetBrightness(level);
}

/* Make level the applied level at once. With the slot-13 hook set, the hook first lowers or raises the full
   scale, and the level is rescaled from that scale to 0..LEVEL_MAX. */
static void set_level(unsigned short level)
{
    unsigned short full_scale;

    full_scale = LEVEL_MAX;
    if (sys_callback_table.level_hook == 0)
        pq_auto_level_current = level;
    else {
        sys_callback_table.level_hook(&full_scale);
        pq_auto_level_current = level * (unsigned)LEVEL_MAX / full_scale;
    }
    write_level(pq_auto_level_current);
}

/* Copy the 16 weights (or 16 times DEFAULT_WEIGHT when there is no table) and store their sum. */
static void pq_auto_level_set_weights(const unsigned char *weights)
{
    unsigned char i;

    pq_auto_level_weight_sum = 0;
    if (!weights) {
        for (i = 0; i < AUTO_LEVEL_WEIGHTS; i++) {
            pq_auto_level_weight_values[i] = DEFAULT_WEIGHT;
            pq_auto_level_weight_sum += DEFAULT_WEIGHT;
        }
    } else {
        for (i = 0; i < AUTO_LEVEL_WEIGHTS; i++) {
            unsigned char weight = weights[i];

            pq_auto_level_weight_values[i] = weight;
            pq_auto_level_weight_sum += weight;
        }
    }
}

/*
 * One step of the applied level towards the target. A ramp starts when the two differ by more than
 * LEVEL_DEADBAND and then runs, LEVEL_STEP per call, until they are equal. A step down never goes below 0 or
 * below the target. Returns 1 while a ramp runs (including the call that ends it), else 0.
 */
static int step_towards_target(void)
{
    unsigned short cur = pq_auto_level_current;
    unsigned short tgt = pq_auto_level_target;

    if (cur - tgt > LEVEL_DEADBAND || cur - tgt < -LEVEL_DEADBAND || pq_auto_level_stepping != 0) {
        pq_auto_level_stepping = 1;
        if (cur != tgt) {
            if (cur < tgt) {
                cur += LEVEL_STEP;
                if (cur > tgt)
                    pq_auto_level_current = tgt;
                else
                    pq_auto_level_current = cur;
            } else {
                if (cur > LEVEL_STEP)
                    pq_auto_level_current = cur - LEVEL_STEP;
                else
                    pq_auto_level_current = 0;
                if (pq_auto_level_current < pq_auto_level_target)
                    pq_auto_level_current = pq_auto_level_target;
            }
            write_level(pq_auto_level_current);
        } else
            pq_auto_level_stepping = 0;     /* target reached: the ramp ends */
        return 1;
    }
    return 0;
}

/*
 * Automatic brightness level: measure the picture with the ACE block and move the panel level towards a target
 * computed from the measurement.
 *
 *   start  1: (re)start the automatic level; 0: one periodic step
 *
 * Called with start = 1 when the automatic level mode is set to 1 (pq_api_set_auto_level_mode, and command 16 of
 * sys_api_config), and with start = 0 from the 200 ms housekeeping task (sys_main_loop_periodic_task) while a
 * channel is in state 12 (MODE_WAITMODECHANGE). Nothing happens unless system configuration byte 7 is 1.
 *
 * Phases:
 *   1. start = 1 only: clear pq_auto_level_jump_flag and load the 16 weights from pq_auto_level_weights.
 *   2. Return unless the automatic level mode (stSysConfig byte 7) is 1. Remember the selected picture window.
 *   3. Read the 16 ACE sums into pq_auto_level_bins (with start = 1 this only starts a new measurement and the
 *      sums stay as they were) and add them up into pq_auto_level_sum.
 *   4. start = 1: set the ACE block to 16 sums and make the stored brightness (stSysConfig byte 8, 0..100,
 *      scaled to 0..LEVEL_MAX) the applied level at once. Done.
 *   5. start = 0: decide the hold condition from input block registers 0x43..0x45 of channel 0. The rule
 *      depends on bit 0 of the channel's level code (see the code). A switched-on menu layer 0, or a picture
 *      mode other than 0 and 2, clears the condition.
 *   6. Condition clear: restart the 10-second wait; if the hold was on, switch it off (aux GPIO bit 0 high) and
 *      set the level to 0. Condition set for 10 seconds: switch the hold on (level AUTO_LEVEL_HOLD_LEVEL straight
 *      to SetBrightness, aux GPIO bit 0 low).
 *   7. Hold off and a non-zero sum: target = the share of all sums outside bin 0, scaled to 0..LEVEL_MAX; then
 *      one step of the applied level towards it.
 *   8. Select the remembered picture window again.
 */
void pq_auto_level_task(unsigned char start)
{
    unsigned char i, saved_window;
    struct ace_config_arg ace_config;

    /* Phase 1: restart. */
    if (start != 0) {
        pq_auto_level_jump_flag = 0;
        pq_auto_level_set_weights(pq_auto_level_weights);
    }

    /* Phase 2: only in automatic level mode 1. */
    if (sys_config[SYS_CONFIG_AUTO_LEVEL_MODE] != AUTO_LEVEL_ON)
        return;
    saved_window = pq_get_selected_window();

    /* Phase 3: the measured sums. */
    pq_ace_read_histogram(start, pq_auto_level_bins);
    pq_auto_level_sum = 0;
    for (i = 0; i < AUTO_LEVEL_BINS; i++)
        pq_auto_level_sum += pq_auto_level_bins[i];

    if (start != 0) {
        /* Phase 4: 16 sums from now on; begin at the stored brightness. */
        ace_config.sum_count = AUTO_LEVEL_BINS;
        ace_config.config_bit6 = 0;
        ace_config.config_bit7 = 0;
        pq_ace_configure(ace_config);
        set_level((sys_config[SYS_CONFIG_BRIGHTNESS] * (unsigned)LEVEL_MAX + 50) / 100);     /* 0..100 -> 0..LEVEL_MAX, rounded */
    } else {
        unsigned char level_code, reg43, reg44, reg45;
        unsigned short target;

        /* Phase 5: the hold condition. It changes only when the block's statistics restart succeeds, and keeps
           its value between the two thresholds of each rule. */
        level_code = input_api_get_channel_format_code(MAIN_CHANNEL);
        if (input_block_restart_statistics(MAIN_CHANNEL) != 0) {
            reg43 = input_block_read_reg43(MAIN_CHANNEL);
            reg44 = input_block_read_reg44(MAIN_CHANNEL);
            reg45 = input_block_read_reg45(MAIN_CHANNEL);
            if (!(level_code & 1)) {
                /* Even level code: register 0x44 alone decides (set at 0x10 or less, clear above 0x13). */
                if (reg44 <= 0x10)
                    pq_auto_level_condition = 1;
                if (reg44 > 0x13)
                    pq_auto_level_condition = 0;
            } else if (reg43 < 4 && reg44 < 4 && reg45 < 4)
                pq_auto_level_condition = 1;    /* odd level code: all three below 4 set it */
            else if (reg43 > 7 || reg44 > 7 || reg45 > 7)
                pq_auto_level_condition = 0;    /* any of them above 7 clears it */
        }
        if (osd_is_enabled(0) != 0 || (device_settings_pip_mode != 0 && device_settings_pip_mode != 2))
            pq_auto_level_condition = 0;

        /* Phase 6: switch the hold on after 10 seconds of the condition, off as soon as it ends. */
        if (pq_auto_level_condition == 0) {
            pq_auto_level_ticks = timer_get_ticks16();
            if (pq_auto_level_active != 0) {
                pq_auto_level_active = 0;
                gpio_set_aux_bit0_high();
                set_level(0);
            }
        } else if (timer_ticks_since(pq_auto_level_ticks) > AUTO_LEVEL_WAIT_TICKS) {
            pq_auto_level_ticks = timer_get_ticks16();
            if (pq_auto_level_active == 0) {
                pq_auto_level_active = 1;
                SetBrightness(AUTO_LEVEL_HOLD_LEVEL);
                gpio_set_aux_bit0_low();
            }
        }

        /* Phase 7: new target and one ramp step, only while the hold is off. */
        if (pq_auto_level_active == 0 && pq_auto_level_sum != 0) {
            target = (unsigned long long)(unsigned int)(pq_auto_level_sum - pq_auto_level_bins[0]) * LEVEL_MAX
                / (unsigned int)pq_auto_level_sum;
            if (target != pq_auto_level_target) {
                pq_auto_level_target = target;
                LIMIT(pq_auto_level_target, 0, LEVEL_MAX);
            }
            if (step_towards_target()) {
                pq_select_window(saved_window);
                return;
            }
            pq_select_window(saved_window);
            return;
        }
    }

    /* Phase 8. */
    pq_select_window(saved_window);
}

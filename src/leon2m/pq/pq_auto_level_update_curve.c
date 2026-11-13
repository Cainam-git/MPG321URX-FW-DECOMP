/* pq_auto_level_update_curve  (FUN_a012a2f0)
 *
 * Rescale the 16-point curve from the measured values and step the applied curve towards it.
 * Name basis: descriptive - steps of at most 4 per call; curve written through the table write at 0xCF00EEC8;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012a2f0 @ 0xa012a2f0-0xa012a700 (1040 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms: pq_auto_level_set_weights (pq_auto_level_set_weights, called with no table), pq_auto_level_has_scene_changed
 * (pq_auto_level_has_scene_changed) and pq_auto_level_store_reference (pq_auto_level_store_reference) are static copies (inlined); the update test,
 * the step loop and the curve send are a static helper step_and_send(reset, changed, last_point) called with
 * last_point = 0x10; loop optimisation hoists the table addresses in the order the loop bodies use them, so the
 * reset loop stores pq_auto_level_applied_curve before pq_auto_level_target_curve and the scaling loop stores its
 * quotient into pq_auto_level_target_curve[i] first; 'changed' is an int set in both arms; the three tests of
 * step_and_send are nested ifs.
 */
/* A curve for the ACE block, as pq_ace_write_curve takes it: points[0..last_point], 16-bit each. */
struct ace_curve {
    unsigned char last_point;
    unsigned short points[35];
};

#define CURVE_POINTS       16           /* points of the target and the applied curve */
#define CURVE_TOP          0x400        /* top of the curve; the record sent always ends here */
#define CURVE_STEP         0x40         /* straight-line curve: point i = (i + 1) * 0x40 */
#define DEFAULT_WEIGHT     0x3a
#define BIN_DIFF_LIMIT     0x40         /* a measured value differs from the reference by more than this */
#define MAX_STEP           4            /* largest change of an applied point per call */
#define DOMINANT_SHARE_X10 7            /* value * 10 / sum above 7 (a value of 8/10 of the sum or more) gives the
                                           straight line */
#define RUN_SEEN           0x80         /* bit 7 of 'run': two neighbouring values differed */

extern unsigned short pq_auto_level_target_curve[16];
extern unsigned short pq_auto_level_applied_curve[16];
extern unsigned char pq_auto_level_weight_values[16];
extern unsigned short pq_auto_level_weight_sum;
extern int pq_auto_level_bins[16];
extern int pq_auto_level_reference_bins[16];
extern unsigned int pq_auto_level_sum;
extern int pq_auto_level_jump_flag;
extern unsigned char pq_auto_level_curve_moving;
extern int abs(int);
extern void pq_ace_write_curve(struct ace_curve *);

/* The routines below are copies of the firmware's own routines next to this one; every call is inlined. */

/* Set the 16 weights from weights[], or all to 0x3A when it is 0, and keep their sum. */
static void pq_auto_level_set_weights(const unsigned char *weights)
{
    unsigned char i;

    pq_auto_level_weight_sum = 0;
    if (!weights) {
        for (i = 0; i < 16; i++) {
            pq_auto_level_weight_values[i] = DEFAULT_WEIGHT;
            pq_auto_level_weight_sum += DEFAULT_WEIGHT;
        }
    } else {
        for (i = 0; i < 16; i++) {
            unsigned char weight = weights[i];

            pq_auto_level_weight_values[i] = weight;
            pq_auto_level_weight_sum += weight;
        }
    }
}

/* Keep the measured values as the reference for the next comparison. */
static void pq_auto_level_store_reference(void)
{
    unsigned char i;

    for (i = 0; i < 16; i++)
        pq_auto_level_reference_bins[i] = pq_auto_level_bins[i];
}

/*
 * 1 when at least one measured value differs from its reference value by more than 0x40, except when fewer
 * than three differ and two of them are neighbours. 0 when the sum of the measured values is 0.
 */
static unsigned char pq_auto_level_has_scene_changed(void)
{
    unsigned char i, differing, run;
    unsigned short distance;
    int difference;
    int neighbours_differ, few_differ;

    if (pq_auto_level_sum == 0)
        return 0;
    differing = 0;
    run = 0;
    for (i = 0; i < 16; i++) {
        difference = pq_auto_level_reference_bins[i] - pq_auto_level_bins[i];
        distance = abs(difference);
        if (distance > BIN_DIFF_LIMIT) {
            differing++;
            run++;
            if (run > 1)
                run |= RUN_SEEN;
        } else
            run &= RUN_SEEN;            /* the run count starts again; the flag stays */
    }
    neighbours_differ = (run & RUN_SEEN) != 0;
    few_differ = differing < 3;
    if (few_differ & neighbours_differ)
        return 0;
    if (differing != 0)
        return 1;
    return 0;
}

/*
 * Move the applied curve towards the target curve and send it to the ACE block. Nothing is done unless the
 * target has changed, a reset was asked for, or the applied curve is still moving.
 */
static void step_and_send(unsigned char reset, int changed, unsigned char last_point)
{
    unsigned char i, moved;
    struct ace_curve curve;

    if (changed == 0)
        if (reset == 0)
            if (pq_auto_level_curve_moving == 0)
                return;
    {
        moved = 0;
        if (pq_auto_level_jump_flag == 0) {
            /* In steps of at most 4; a point within 4 of its target takes the target. */
            for (i = 0; i < 16; i++) {
                if (pq_auto_level_applied_curve[i] > pq_auto_level_target_curve[i]) {
                    if (pq_auto_level_applied_curve[i] - pq_auto_level_target_curve[i] < 5)
                        pq_auto_level_applied_curve[i] = pq_auto_level_target_curve[i];
                    else
                        pq_auto_level_applied_curve[i] -= MAX_STEP;
                    moved = 1;
                } else if (pq_auto_level_applied_curve[i] < pq_auto_level_target_curve[i]) {
                    if (pq_auto_level_target_curve[i] - pq_auto_level_applied_curve[i] > 4)
                        pq_auto_level_applied_curve[i] += MAX_STEP;
                    else
                        pq_auto_level_applied_curve[i] = pq_auto_level_target_curve[i];
                    moved = 1;
                }
            }
            pq_auto_level_curve_moving = moved;
        } else {
            /* At once. */
            pq_auto_level_curve_moving = 0;
            for (i = 0; i < 16; i++)
                pq_auto_level_applied_curve[i] = pq_auto_level_target_curve[i];
        }
        /* 17 points: 0, applied points 0..14, then 0x400 (applied point 15 is not sent). */
        curve.last_point = last_point;
        curve.points[0] = 0;
        for (i = 1; i < 16; i++)
            curve.points[i] = pq_auto_level_applied_curve[i - 1];
        curve.points[16] = CURVE_TOP;
        pq_ace_write_curve(&curve);
    }
}

/*
 * Work out the curve of the automatic level control from the 16 measured values and pass it, in small
 * steps, to the ACE block.
 *
 *   reset  non-zero: start the target and the applied curve again from the straight line 0x40, 0x80 .. 0x400.
 *
 * No routine calls it directly.
 *
 * Phases, in order:
 *   1. With reset: both curves to the straight line.
 *   2. When the weight sum is 0: all 16 weights to 0x3A (pq_auto_level_set_weights with no table).
 *   3. When the measured values have changed against the reference (pq_auto_level_has_scene_changed): keep
 *      them as the new reference and build the target curve as a running total; point i adds
 *      (0x400 - weight sum) * value i / sum of the values, plus weight i. When one value is 8/10 of the sum
 *      or more (value * 10 / sum above 7), the target becomes the straight line instead.
 *   4. When the target changed, a reset was asked for or the applied curve is still moving: move the applied
 *      curve towards the target (by at most 4 per point, or at once while pq_auto_level_jump_flag is set) and
 *      write it to the ACE block (pq_ace_write_curve).
 */
void pq_auto_level_update_curve(unsigned char reset)
{
    unsigned char i, dominant;
    int changed;

    /* 1. */
    if (reset != 0) {
        for (i = 0; i < 16; i++) {
            pq_auto_level_applied_curve[i] = i * CURVE_STEP + CURVE_STEP;
            pq_auto_level_target_curve[i] = i * CURVE_STEP + CURVE_STEP;
        }
    }

    /* 2. */
    if (pq_auto_level_weight_sum == 0)
        pq_auto_level_set_weights(0);

    /* 3. A new target curve. */
    if (pq_auto_level_has_scene_changed()) {
        pq_auto_level_store_reference();
        dominant = 0;
        for (i = 0; i < 16; i++) {
            pq_auto_level_target_curve[i] = (CURVE_TOP - pq_auto_level_weight_sum) * pq_auto_level_bins[i] / pq_auto_level_sum;
            if (pq_auto_level_bins[i] * 10 / pq_auto_level_sum > DOMINANT_SHARE_X10) {
                dominant = 1;
                break;
            }
            pq_auto_level_target_curve[i] += pq_auto_level_weight_values[i];
            if (i != 0)
                pq_auto_level_target_curve[i] += pq_auto_level_target_curve[i - 1];
        }
        if (dominant) {
            for (i = 0; i < 16; i++)
                pq_auto_level_target_curve[i] = i * CURVE_STEP + CURVE_STEP;
        }
        changed = 1;
    } else
        changed = 0;

    /* 4. */
    step_and_send(reset, changed, CURVE_POINTS);
}

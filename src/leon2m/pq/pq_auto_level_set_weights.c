/* pq_auto_level_set_weights  (FUN_a012a1a0)
 *
 * Set the 16 weights, or the default 0x3A, and store their sum.
 * Name basis: descriptive - byte table at 0xA802CAE0, sum at 0xA802CA12; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012a1a0 @ 0xa012a1a0-0xa012a228 (34 words, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the null-pointer arm is written first ('if (!weights)'). The table loop reloads
 * pq_auto_level_weight_sum on each pass (the table may overlap it).
 */
extern unsigned short pq_auto_level_weight_sum;
extern unsigned char pq_auto_level_weight_values[];

#define AUTO_LEVEL_WEIGHTS 16
#define DEFAULT_WEIGHT     0x3a     /* as in pq_auto_level_task */

/*
 * Copy 16 weights into pq_auto_level_weight_values and add them up in pq_auto_level_weight_sum.
 *
 *   weights   16 bytes; null sets every weight to DEFAULT_WEIGHT
 *
 * Nothing in the firmware calls this routine: pq_auto_level_task (with the ROM table pq_auto_level_weights)
 * and pq_auto_level_update_curve (with null) each have their own copy of it.
 */
void pq_auto_level_set_weights(const unsigned char *weights)
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

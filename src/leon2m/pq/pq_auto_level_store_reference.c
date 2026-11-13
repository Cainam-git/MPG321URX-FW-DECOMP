/* pq_auto_level_store_reference  (FUN_a012a164)
 *
 * Store the 16 measured values as the new reference.
 * Name basis: descriptive - copy from 0xA802CA5C to 0xA802CA9C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012a164 @ 0xa012a164-0xa012a1a0 (60 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: an unsigned char loop counter.
 */
extern int pq_auto_level_bins[];
extern int pq_auto_level_reference_bins[];

#define AUTO_LEVEL_BINS 16      /* measured sums read from the ACE block (as in pq_auto_level_task) */

/*
 * Copy the 16 measured bins into pq_auto_level_reference_bins, which pq_auto_level_bin_difference and
 * pq_auto_level_has_scene_changed compare with.
 * Nothing in the firmware refers to this routine (no call and no stored address); pq_auto_level_update_curve
 * has its own copy of it.
 */
void pq_auto_level_store_reference(void)
{
    unsigned char i;

    for (i = 0; i < AUTO_LEVEL_BINS; i++)
        pq_auto_level_reference_bins[i] = pq_auto_level_bins[i];
}

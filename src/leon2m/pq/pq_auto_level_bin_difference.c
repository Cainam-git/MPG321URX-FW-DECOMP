/* pq_auto_level_bin_difference  (FUN_a012a128)
 *
 * Return how far one of the 16 measured values is from its stored reference.
 * Returns: difference
 * Name basis: descriptive - absolute difference of the word tables at 0xA802CA9C and 0xA802CA5C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012a128 @ 0xa012a128-0xa012a164 (60 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: __builtin_abs on the int difference.
 */
extern int pq_auto_level_bins[];
extern int pq_auto_level_reference_bins[];

/*
 * Return |reference - measured| of bin 'bin' (0..15), cut to 16 bits. The measured bins are the sums that
 * pq_auto_level_task reads; the reference is the copy pq_auto_level_store_reference makes.
 * Nothing in the firmware refers to this routine (no call and no stored address).
 */
unsigned short pq_auto_level_bin_difference(unsigned char bin)
{
    return __builtin_abs(pq_auto_level_reference_bins[bin] - pq_auto_level_bins[bin]);
}

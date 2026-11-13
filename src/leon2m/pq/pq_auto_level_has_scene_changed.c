/* pq_auto_level_has_scene_changed  (FUN_a012a228)
 *
 * Report whether enough of the 16 measured values moved away from the reference.
 * Returns: 0 or 1
 * Name basis: descriptive - counts differences above 0x40; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012a228 @ 0xa012a228-0xa012a2f0 (50 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two final conditions are int locals combined with '&' (the firmware computes both as values
 * and tests their AND); the neighbour flag is computed before 'moved < 3'.
 */
extern int abs(int);
extern int pq_auto_level_sum;
extern int pq_auto_level_bins[16];
extern int pq_auto_level_reference_bins[16];

#define AUTO_LEVEL_BINS   16
#define MOVE_LIMIT        0x40      /* a bin further than this from its reference has moved */
#define NEIGHBOURS_MOVED  0x80      /* flag in 'run': two neighbouring bins have moved */
#define FEW_MOVED         3

/*
 * Compare the 16 measured bins with the reference bins (pq_auto_level_store_reference).
 *
 * Returns 0 while pq_auto_level_sum is 0. Otherwise it counts the bins whose difference (cut to 16 bits) is
 * above 0x40 and returns 1 when three or more moved, or one or two that are not neighbours; 0 when none
 * moved, or one or two that include a neighbouring pair.
 *
 * Nothing in the firmware calls this routine directly; pq_auto_level_update_curve has its own copy of it.
 */
unsigned char pq_auto_level_has_scene_changed(void)
{
    unsigned char i, moved, run;
    unsigned short difference;
    int delta;
    int neighbours, few;

    if (pq_auto_level_sum == 0)
        return 0;
    moved = 0;
    run = 0;            /* low bits: moved bins in a row; NEIGHBOURS_MOVED stays once set */
    for (i = 0; i < AUTO_LEVEL_BINS; i++) {
        delta = pq_auto_level_reference_bins[i] - pq_auto_level_bins[i];
        difference = abs(delta);
        if (difference > MOVE_LIMIT) {
            moved++;
            run++;
            if (run > 1)
                run |= NEIGHBOURS_MOVED;
        } else
            run &= NEIGHBOURS_MOVED;
    }
    neighbours = (run & NEIGHBOURS_MOVED) != 0;
    few = moved < FEW_MOVED;
    if (few & neighbours)
        return 0;
    return moved != 0;
}

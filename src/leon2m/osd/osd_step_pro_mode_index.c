/* osd_step_pro_mode_index  (FUN_a00b6b88)
 *
 * Step a Pro mode list index (0..7) up or down with wrap-around.
 *   index
 *   dir: 1 down, else up
 * Returns: new index
 * Name basis: derived - called by the Pro mode handlers (osd_select_prev|next_pro_mode, accept, cancel)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6b88 @ 0xa00b6b88-0xa00b6bec (25 words), flags -mcpu=v8 -O3 -g.
 * Source form: early returns (the firmware writes each result straight into the return register before the
 * return; a result variable gives a shared tail and reordered tests); unsigned char return.
 */
#define PRO_MODE_LAST_INDEX 7                   /* the Pro mode list holds indices 0..7 */
#define STEP_DOWN 1                             /* any other value of dir steps up */

/*
 * Move a Pro mode list index by one place and wrap at the ends of the list.
 *
 *   index  the present index, 0..7
 *   dir    STEP_DOWN: one place down (0 wraps to 7); anything else: one place up (7 wraps to 0)
 *
 * Returns the new index. An index above 7 is returned unchanged.
 */
unsigned char osd_step_pro_mode_index(unsigned char index, unsigned char dir)
{
    unsigned char lower;

    if (dir == STEP_DOWN) {
        if (index == 0)
            return PRO_MODE_LAST_INDEX;
        lower = index - 1;
        if (lower <= PRO_MODE_LAST_INDEX - 1)
            return lower;
        return index;
    }
    if (index == PRO_MODE_LAST_INDEX)
        return 0;
    if (index > PRO_MODE_LAST_INDEX - 1)
        return index;
    return index + 1;
}

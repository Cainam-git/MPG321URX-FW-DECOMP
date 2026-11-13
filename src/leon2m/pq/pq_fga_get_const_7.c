/* pq_fga_get_const_7  (FUN_a012e848)
 *
 * Return the constant 7.
 * Returns: 7
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e848 @ 0xa012e848-0xa012e850 (8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a constant return; the value is set in the retl delay slot.
 */

/*
 * Return 7. It follows the two FGA mask getters; 7 is also the value of FGA_ROW_KEYS in FGA_Init, but nothing
 * in the firmware refers to this routine (no call and no stored address).
 */
int pq_fga_get_const_7(void)
{
    return 7;
}

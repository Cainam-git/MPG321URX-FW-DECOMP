/* sys_ddr_return_minus_one  (FUN_a00eecc8)
 *
 * Return -1.
 * Returns: -1
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00eecc8 @ 0xa00eecc8, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a constant return; the value is set in the retl delay slot.
 */
/* Returns -1. Nothing in the image refers to it. */
int sys_ddr_return_minus_one(void)
{
    return -1;
}

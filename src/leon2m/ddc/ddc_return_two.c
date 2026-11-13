/* ddc_return_two  (FUN_a00cf280)
 *
 * Return 2.
 * Returns: 2
 * Note: No caller found.
 * Name basis: descriptive - body is 'return 2'; lies among the DDC/CI routines
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default). Nothing in the image calls this routine.
 * Source form: a constant return; the value is set in the retl delay slot.
 */
/* Returns 2 and does nothing else. */
int ddc_return_two(void)
{
    return 2;
}

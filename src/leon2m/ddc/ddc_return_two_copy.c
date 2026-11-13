/* ddc_return_two_copy  (FUN_a00df804)
 *
 * Return 2.
 * Returns: 2
 * Note: No caller found. Identical copy of ddc_return_two.
 * Name basis: descriptive - body is 'return 2'; lies among the DDC/CI routines
 *
 * Matching notes
 * --------------
 * FUN_a00df804 (leon2m 0xa00df804-0xa00df80c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 2. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * switchdataD_a00df7d0 and sys_ddr_print_step. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Return 2. Nothing calls this copy. */
int ddc_return_two_copy(void)
{
    return 2;
}

/* sys_api_return_ff_copy  (FUN_a0147a88)
 *
 * Return 0xFF.
 * Returns: 0xFF
 * Note: Identical copy of sys_api_return_ff.
 * Name basis: descriptive - constant; called from the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * FUN_a0147a88 (leon2m, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Called by ddc_handle_request. Source form: a constant return; the value is set in the retl delay slot.
 */

/* Always returns 0xFF. */
int sys_api_return_ff_copy(void)
{
    return 0xff;
}

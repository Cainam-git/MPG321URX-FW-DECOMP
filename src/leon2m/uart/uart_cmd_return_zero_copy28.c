/* uart_cmd_return_zero_copy28  (FUN_a0125364)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a0125364 (leon2m 0xa0125364-0xa012536c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * edid_is_internal_edid_enabled and edid_get_port_flag. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Return 0. Nothing calls this copy. */
int uart_cmd_return_zero_copy28(void)
{
    return 0;
}

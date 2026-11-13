/* uart_cmd_return_zero_copy23  (FUN_a00deda8)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a00deda8 (leon2m 0xa00deda8-0xa00dedb0, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * uart_cmd_return_zero_copy22 and timer_get_flag. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Return 0. Nothing calls this copy. */
int uart_cmd_return_zero_copy23(void)
{
    return 0;
}

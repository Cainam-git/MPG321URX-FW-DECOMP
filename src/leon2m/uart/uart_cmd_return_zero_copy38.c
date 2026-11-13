/* uart_cmd_return_zero_copy38  (FUN_a014882c)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a014882c (leon2m 0xa014882c-0xa0148834, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * uart_cmd_return_zero_copy37 and uart_cmd_return_zero_copy39. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Does nothing and returns 0. Nothing refers to this copy; the same body exists as uart_cmd_return_zero. */
int uart_cmd_return_zero_copy38(void)
{
    return 0;
}

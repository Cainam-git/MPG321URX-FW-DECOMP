/* uart_cmd_return_zero_copy22  (FUN_a00deda0)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a00deda0 (leon2m 0xa00deda0-0xa00deda8, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * Source form: a constant return; the value is set in the retl delay slot.
 */

/* Return 0. Nothing calls this copy. */
int uart_cmd_return_zero_copy22(void)
{
    return 0;
}

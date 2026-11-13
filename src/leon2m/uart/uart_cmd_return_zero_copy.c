/* uart_cmd_return_zero_copy  (FUN_a00c0bec)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c0bec, flags -mcpu=v8 -O2 -g.
 * Source form: a constant return; the value is set in the retl delay slot.
 */


/*
 * Return 0. Identical to uart_cmd_return_zero. Nothing in the image refers to this routine.
 */
int uart_cmd_return_zero_copy(void)
{
    return 0;
}

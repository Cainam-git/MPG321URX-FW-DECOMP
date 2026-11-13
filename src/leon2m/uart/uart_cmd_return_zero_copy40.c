/* uart_cmd_return_zero_copy40  (FUN_a014dd58)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a014dd58 (leon2m 0xa014dd58-0xa014dd60, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * irq_empty_handler_copy84 and irq_empty_handler_copy85. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Does nothing and returns 0. Nothing refers to this copy; the same body exists as uart_cmd_return_zero. */
int uart_cmd_return_zero_copy40(void)
{
    return 0;
}

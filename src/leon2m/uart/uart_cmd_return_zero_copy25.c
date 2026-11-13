/* uart_cmd_return_zero_copy25  (FUN_a0107b9c)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a0107b9c (leon2m 0xa0107b9c-0xa0107ba4, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * input_set_port_pin_function and sys_poll_events_stub_copy5. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Return 0. Nothing calls this copy. */
int uart_cmd_return_zero_copy25(void)
{
    return 0;
}

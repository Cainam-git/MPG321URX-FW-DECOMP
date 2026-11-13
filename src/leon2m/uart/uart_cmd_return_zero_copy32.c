/* uart_cmd_return_zero_copy32  (FUN_a0132a38)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a0132a38 (leon2m 0xa0132a38-0xa0132a40, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * uart_cmd_return_zero_copy31 and ldc_set_direct_pwm_off. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Return 0. Nothing calls this copy. */
int uart_cmd_return_zero_copy32(void)
{
    return 0;
}

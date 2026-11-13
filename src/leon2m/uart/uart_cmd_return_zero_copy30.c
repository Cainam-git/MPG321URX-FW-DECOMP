/* uart_cmd_return_zero_copy30  (FUN_a012c0f8)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a012c0f8 (leon2m 0xa012c0f8-0xa012c100, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * sys_output_record1_add_flags_2001 and irq_empty_handler_copy57. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Return 0. Nothing calls this copy. */
int uart_cmd_return_zero_copy30(void)
{
    return 0;
}

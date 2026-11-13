/* uart_cmd_return_zero_copy34  (FUN_a013c894)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a013c894 (leon2m 0xa013c894-0xa013c89c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * sys_channel_apply_output_timing and switchdataD_a013c89c. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Does nothing and returns 0. Nothing refers to this copy; the same body exists as uart_cmd_return_zero. */
int uart_cmd_return_zero_copy34(void)
{
    return 0;
}

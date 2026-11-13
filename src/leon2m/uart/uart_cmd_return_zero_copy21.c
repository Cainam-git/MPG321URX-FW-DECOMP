/* uart_cmd_return_zero_copy21  (FUN_a00d24d8)
 *
 * Return 0.
 * Note: Called by ddc_tool_dispatch_command for factory tool command 0x6E. Identical copy of
 *   uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a00d24d8 (leon2m 0xa00d24d8-0xa00d24e0, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * Source form: a constant return; the value is set in the retl delay slot.
 */

/* Return 0. Called by ddc_tool_dispatch_command for factory tool command 0x6E (TOOL_CMD_6E); the value 0 becomes
   the result that ddc_tool_build_reply gets. */
int uart_cmd_return_zero_copy21(void)
{
    return 0;
}

/* uart_cmd_return_zero_copy33  (FUN_a01397ec)
 *
 * Return 0.
 * Note: No caller found. Identical copy of uart_cmd_return_zero.
 * Name basis: descriptive - body is 'return 0'; lies among the set handlers
 *
 * Matching notes
 * --------------
 * FUN_a01397ec (leon2m 0xa01397ec-0xa01397f4, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * ldc_power_down_handshake and ldc_send_peaking. Source form: a constant return; the value is set in the retl delay slot.
 */
/* Does nothing and returns 0. Nothing refers to this copy; the same body exists as uart_cmd_return_zero. */
int uart_cmd_return_zero_copy33(void)
{
    return 0;
}

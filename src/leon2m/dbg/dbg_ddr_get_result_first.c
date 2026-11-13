/* dbg_ddr_get_result_first  (FUN_a011818c)
 *
 * Return the first stored result byte of the stress test.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802C98C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011818c, flags -mcpu=v8 -O2 -g.
 * Source form: a direct read of the extern symbol (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned char dbg_ddr_result_first;

/* Return the byte dbg_ddr_set_result_first stored. dbg_ddr_reset_test_state clears it. No routine calls this. */
unsigned char dbg_ddr_get_result_first(void)
{
    return dbg_ddr_result_first;
}

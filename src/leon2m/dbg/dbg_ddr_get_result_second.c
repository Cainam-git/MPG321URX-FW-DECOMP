/* dbg_ddr_get_result_second  (FUN_a0118174)
 *
 * Return the second stored result byte of the stress test.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802C98D; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118174, flags -mcpu=v8 -O2 -g.
 * Source form: a direct read of the extern symbol (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned char dbg_ddr_result_second;

/* Return the byte dbg_ddr_set_result_second stored. dbg_ddr_reset_test_state clears it. No routine calls this. */
unsigned char dbg_ddr_get_result_second(void)
{
    return dbg_ddr_result_second;
}

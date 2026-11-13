/* dbg_ddr_set_result_second  (FUN_a0118180)
 *
 * Store the second result byte of the stress test.
 * Name basis: descriptive - byte at 0xA802C98D; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118180, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char dbg_ddr_result_second;

/* Store value in the second result byte (read back by dbg_ddr_get_result_second). No routine calls this. */
void dbg_ddr_set_result_second(unsigned char value)
{
    dbg_ddr_result_second = value;
}

/* dbg_ddr_set_result_first  (FUN_a0118198)
 *
 * Store the first result byte of the stress test.
 * Name basis: descriptive - byte at 0xA802C98C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118198, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char dbg_ddr_result_first;

/* Store value in the first result byte (read back by dbg_ddr_get_result_first). No routine calls this. */
void dbg_ddr_set_result_first(unsigned char value)
{
    dbg_ddr_result_first = value;
}

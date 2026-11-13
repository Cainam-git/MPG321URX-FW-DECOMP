/* reg_read24_bytes  (FUN_a00f30a8)
 *
 * Read a 24-bit value from three byte registers.
 * Returns: value
 * Name basis: proven - used for the clock generator values
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f30a8 @ 0xa00f30a8, flags -mcpu=v8 -O2 -g.
 * Source form: the first word is read into a local first.
 */
/*
 * Return a 24-bit value held in three registers that each hold one byte: reg[0] is bits 0..7, reg[1] bits
 * 8..15 and reg[2] bits 16..23. Used by panel_set_pll_frequency and input_adc_wait_clock_stable.
 */
unsigned int reg_read24_bytes(volatile unsigned int *reg)
{
    unsigned int low = reg[0];
    return low | reg[1] << 8 | reg[2] << 16;
}

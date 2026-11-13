/* reg_read16_bytes  (FUN_a00f3078)
 *
 * Read a 16-bit value from two byte registers.
 * Returns: value
 * Name basis: proven - (p[1] << 8) | p[0]
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3078 @ 0xa00f3078, flags -mcpu=v8 -O2 -g.
 * Source form: a volatile word pointer (with a plain pointer the compiler schedules the loads freely); the
 * return type is unsigned int; the low word is read first, in its own statement.
 */
/*
 * Return a 16-bit value held in two registers that each hold one byte: the word at 'reg' is the low byte and
 * the word at 'reg' + 4 is the high byte. Callers include sys_frc_get_output_frame_length, which passes the
 * addresses 0xCF011AE0, 0xCF011AE8 and 0xCF011AF0.
 */
unsigned int reg_read16_bytes(volatile unsigned int *reg)
{
    unsigned int low = reg[0];

    return (reg[1] << 8) | low;
}

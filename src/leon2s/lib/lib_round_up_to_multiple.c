/* lib_round_up_to_multiple  (FUN_a006182c)
 *
 * Round a value up to a multiple of another.
 *   value
 *   step
 * Returns: rounded value
 * Name basis: proven - returns a rounded up to a multiple of b, a when b is 0
 *
 * Matching notes
 * --------------
 * FUN_a006182c (leon2s 0xa006182c, 56 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The quotient is computed first and the test is 'value % step == 0' (the compiler reuses the quotient for it).
 */
/*
 * Round value up to the next multiple of step; a value that already is a multiple is returned unchanged.
 * A step of 0 returns the value unchanged.
 */
unsigned int lib_round_up_to_multiple(unsigned int value, unsigned int step)
{
    unsigned int quotient;

    if (step == 0)
        return value;
    quotient = value / step;
    if (value % step == 0)
        return value;
    return quotient * step + step;
}

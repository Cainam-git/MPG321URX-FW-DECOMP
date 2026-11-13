/* lib_div_round_up  (FUN_a00617f0)
 *
 * Divide and round the result up.
 *   dividend
 *   divisor
 * Returns: rounded-up quotient
 * Name basis: proven - returns a / b rounded up, a when b is 0
 *
 * Matching notes
 * --------------
 * FUN_a00617f0 (leon2s 0xa00617f0, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The quotient test is written 'if (dividend == quotient * divisor) return quotient; return quotient + 1;'
 * (a quotient++ form gives a branch-free subx sequence).
 */
/*
 * Divide and round the quotient up: dividend / divisor, plus 1 when the division leaves a remainder.
 * A divisor of 0 returns the dividend unchanged.
 */
unsigned int lib_div_round_up(unsigned int dividend, unsigned int divisor)
{
    unsigned int quotient;

    if (divisor == 0)
        return dividend;
    quotient = dividend / divisor;
    if (dividend == quotient * divisor)
        return quotient;
    return quotient + 1;
}

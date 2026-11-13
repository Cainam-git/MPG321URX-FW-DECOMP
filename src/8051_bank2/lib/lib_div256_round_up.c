/* lib_div256_round_up  (FUN_CODE_d7d0)
 *
 * Return a 32-bit number divided by 256, rounded up.
 *   value: size
 * Returns: quotient
 * Name basis: proven - code: (n + 255) / 256
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameter value (0x0912), local result (0x0916). value / 256 is
 * ?C?ULDIV, the test value % 256 == 0 is a ?C?ULCMP of the low byte against 0. Source form the bytes depend on: the
 * else arm stores the quotient and then increments it as a second statement (store, reload, add, store).
 */
/* lib_div256_round_up: return value / 256, rounded up (one more when value is not a multiple of 256).
 * Caller: fwupd_build_record_table, which adds the result for the size of every record after the first into
 * fwupd_record_total. */
unsigned long lib_div256_round_up(unsigned long value)
{
    unsigned long result;
    if (value % 256 == 0) result = value / 256;
    else {
        result = value / 256;
        result++;
    }
    return result;
}

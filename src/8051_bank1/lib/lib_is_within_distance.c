/* lib_is_within_distance  (FUN_CODE_d969)
 *
 * Report whether two values differ by less than a limit.
 *   first: first value
 *   second: second value
 *   limit
 * Returns: 1 when within
 * Name basis: derived - |a - b| < limit; used by the IR code matcher
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d969 @ 0xd969  OPTIMIZE(7,SPEED)
 * Source form: the unsigned `>` comparison produces the target's SETB C / SUBB compare.
 */
/*
 * Return 1 when the two values differ by less than 'limit', else 0.
 */
unsigned char lib_is_within_distance(unsigned char first, unsigned char second, unsigned char limit)
{
    if (first > second) {
        if (first - second < limit)
            return 1;
        return 0;
    }
    if (second - first < limit)
        return 1;
    return 0;
}

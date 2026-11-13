/* dbg_strcmp  (FUN_a00b1568)
 *
 * Compare two texts.
 * Returns: 0 when equal
 * Name basis: proven - difference of the first unequal characters
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1568 @ 0xa00b1568-0xa00b15ac (68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Both characters are read into char locals first (ldub plus sign extension in the firmware).
 */
/*
 * Compare two zero-terminated texts. Steps along both until the signed characters differ or the first text ends,
 * and returns the difference of the last pair of characters (0 when the texts are equal).
 */
int dbg_strcmp(const char *a, const char *b)
{
    int diff;
    char c, d;

    do {
        c = *a++;
        d = *b++;
        diff = c - d;
    } while (diff == 0 && c != 0);
    return diff;
}

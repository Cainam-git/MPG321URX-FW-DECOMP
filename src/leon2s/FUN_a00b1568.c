/* FUN_a00b1568 (leon2s 0xa00b1568-0xa00b15ac, 68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Steps through two zero-terminated byte strings until the signed characters differ or the first string ends, and
 * returns the difference of the last pair (0 when equal). Both characters are read into char locals first
 * (ldub + sign extension in the firmware).
 */
int FUN_a00b1568(const char *a, const char *b)
{
    int r;
    char c, d;

    do {
        c = *a++;
        d = *b++;
        r = c - d;
    } while (r == 0 && c != 0);
    return r;
}

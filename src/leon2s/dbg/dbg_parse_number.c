/* dbg_parse_number  (FUN_a00b25f8)
 *
 * Convert a text of up to 32 characters to a number, hexadecimal with 0x or decimal.
 * Returns: number
 * Name basis: proven - used by the command line
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b25f8 @ 0xa00b25f8-0xa00b2790, -mcpu=v8 -Os -g.
 * Source form: the decimal loop adds the digit before it tests it (v = v * 10 + s[i] - '0', then the test
 * s[i] - '0' > 9); the hexadecimal loop shifts first and tests the three digit ranges in the order 0-9, a-f, A-F.
 */
extern int dbg_strlen(char *);

/*
 * Convert the text s to a number. A text with the prefix 0x or 0X is hexadecimal, any other text is decimal.
 *
 * s is cut in place: at the first line feed, carriage return or NUL within its first 32 characters (at index 31
 * when there is none). s == 0 gives 0.
 * Hexadecimal: reads the characters from index 2 up to a space, tab or the end; a character that is not a hex
 * digit only shifts the value.
 * Decimal: at most 8 characters; the result is -1 for a longer text or a character above '9' (characters below
 * '0' are not rejected).
 * The command line handler uses it for the arguments of a command.
 */
int dbg_parse_number(char *s)
{
    int i, n, v;   /* i: index; n: length of the cut text; v: the value */

    if (s == 0)
        return 0;
    for (i = 0; i < 0x20; i++)
        if (s[i] == '\n' || s[i] == '\r' || s[i] == 0)
            break;
    if (i == 0x20)
        i = 0x1f;
    s[i] = 0;
    n = dbg_strlen(s);
    v = 0;
    if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
        for (i = 2; i < n; i++) {
            if (s[i] == ' ' || s[i] == '\t')
                break;
            v <<= 4;
            if ((unsigned char)(s[i] - '0') <= 9)
                v = v + s[i] - '0';
            else if ((unsigned char)(s[i] - 'a') <= 5)
                v = v + s[i] - 'a' + 10;
            else if ((unsigned char)(s[i] - 'A') <= 5)
                v = v + s[i] - 'A' + 10;
        }
        return v;
    }
    if (n > 8)
        return -1;
    for (i = 0; i < n; i++) {
        v = v * 10 + s[i] - '0';
        if (s[i] - '0' > 9)
            return -1;
    }
    return v;
}

/* dbg_parse_hex_digits  (FUN_a00b2790)
 *
 * Convert a number of hexadecimal characters to a value.
 * Returns: value
 * Name basis: proven - other characters count as 0
 *
 * Matching notes
 * --------------
 * FUN_a00b2790 (leon2s 0xa00b2790-0xa00b281c, 140 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the digit is a signed char that is set to 0 before the range tests.
 */
/*
 * Convert the first n characters of s to a value, four bits per character ('0'-'9', 'A'-'F', 'a'-'f'; any other
 * character counts as digit 0). The command line handler reads the address and the value of a tool line
 * with it.
 */
int dbg_parse_hex_digits(const unsigned char *s, int n)
{
    int value = 0;
    int i;

    for (i = 0; i < n; i++) {
        unsigned char c = s[i];
        signed char digit = 0;

        if ((unsigned char)(c - '0') <= 9)
            digit = c - '0';
        else if ((unsigned char)(c - 'A') <= 5)
            digit = c - 'A' + 10;
        else if ((unsigned char)(c - 'a') <= 5)
            digit = c - 'a' + 10;
        value = value * 16 + digit;
    }
    return value;
}

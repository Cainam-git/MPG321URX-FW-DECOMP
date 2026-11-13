/* dbg_parse_number  (FUN_a00dcd38)
 *
 * Convert a text to a number, hexadecimal with 0x or decimal.
 * Returns: number
 * Name basis: proven - cut at the line end, up to 9 decimal digits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dcd38 @ 0xa00dcd38, flags -mcpu=v8 -O3 -g.
 * Source form: value = 0 is set after the dbg_strlen call (the value is not kept across the call).
 */

#define PARSE_MAX_LENGTH   32       /* characters examined for a line end */
#define PARSE_MAX_DECIMAL  9        /* longest decimal text that is converted */
#define PARSE_TOO_LONG     0xffffffff

extern int dbg_strlen(const char *);

/*
 * Turn a command argument of the debug command line into a number.
 *
 *   text  the argument; 0 gives 0. The text is changed: a 0 is stored at the first '\n' or '\r' within its
 *         first 32 characters (at index 31 when there is none).
 *
 * "0x" or "0X" in front means hexadecimal: digits 0-9, a-f, A-F up to the end or the first space or tab; any
 * other character only shifts the value up by one digit. Otherwise the text is decimal: a text longer than 9
 * characters gives 0xffffffff, and every character counts as a digit without being checked.
 */
unsigned int dbg_parse_number(char *text)
{
    int i, length;
    unsigned int value;
    char c;

    if (text == 0)
        return 0;
    /* Cut the text at the line end. */
    for (i = 0; i < PARSE_MAX_LENGTH; i++) {
        if (text[i] == '\n' || text[i] == '\r')
            break;
        if (text[i] == 0)
            break;
    }
    if (i == PARSE_MAX_LENGTH)
        i = PARSE_MAX_LENGTH - 1;
    text[i] = 0;
    length = dbg_strlen(text);
    value = 0;
    if (text[0] == '0' && (text[1] == 'X' || text[1] == 'x')) {
        for (i = 2; i < length; i++) {
            c = text[i];
            if (c == ' ' || c == '\t')
                break;
            value *= 16;
            if ((unsigned char)(c - '0') < 10)
                value = value + c - '0';
            else if ((unsigned char)(c - 'a') < 6)
                value = value + c - 'a' + 10;
            else if ((unsigned char)(c - 'A') < 6)
                value = value + c - 'A' + 10;
        }
        return value;
    }
    if (length > PARSE_MAX_DECIMAL)
        return PARSE_TOO_LONG;
    for (i = 0; i < length; i++)
        value = value * 10 + text[i] - '0';
    return value;
}

/* leon2m FUN_a00dcd38 @ 0xa00dcd38-0xa00dcec4 (396 bytes), flags -mcpu=v8 -O3 -g. Callers: FUN_a00dcec4 (four
 * calls).
 * Converts the text s to a number. A null s gives 0. The text is cut at the first '\n', '\r' or 0 within 32
 * characters (at 31 when none is found) by storing 0 there. With n = FUN_a00dd83c(s) (its length): a "0X" / "0x"
 * prefix reads hex digits 0-9, a-f, A-F from index 2 up to n or the first ' ' or '\t' (other characters only
 * multiply by 16); otherwise more than 9 characters give 0xffffffff and up to 9 are read as decimal digits.
 * Source form: v = 0 is set after the FUN_a00dd83c call (the value is not kept across the call).
 */
extern int FUN_a00dd83c(const char *);

unsigned int FUN_a00dcd38(char *s)
{
    int i, n;
    unsigned int v;
    char c;

    if (s == 0)
        return 0;
    for (i = 0; i < 32; i++) {
        if (s[i] == '\n' || s[i] == '\r')
            break;
        if (s[i] == 0)
            break;
    }
    if (i == 32)
        i = 31;
    s[i] = 0;
    n = FUN_a00dd83c(s);
    v = 0;
    if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
        for (i = 2; i < n; i++) {
            c = s[i];
            if (c == ' ' || c == '\t')
                break;
            v *= 16;
            if ((unsigned char)(c - '0') < 10)
                v = v + c - '0';
            else if ((unsigned char)(c - 'a') < 6)
                v = v + c - 'a' + 10;
            else if ((unsigned char)(c - 'A') < 6)
                v = v + c - 'A' + 10;
        }
        return v;
    }
    if (n > 9)
        return 0xffffffff;
    for (i = 0; i < n; i++)
        v = v * 10 + s[i] - '0';
    return v;
}

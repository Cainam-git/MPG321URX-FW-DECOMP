/* FUN_a00b2790 (leon2s 0xa00b2790-0xa00b281c, 140 bytes), flags -mcpu=v8 -Os -g.
 * Converts n hexadecimal characters of s ('0'-'9', 'A'-'F', 'a'-'f'; any other character counts as 0) and returns
 * the value (r = r * 16 + digit). The digit is a signed char that starts at 0 (set before the tests).
 */
int FUN_a00b2790(const unsigned char *s, int n)
{
    int r = 0;
    int i;

    for (i = 0; i < n; i++) {
        unsigned char c = s[i];
        signed char d = 0;

        if ((unsigned char)(c - '0') <= 9)
            d = c - '0';
        else if ((unsigned char)(c - 'A') <= 5)
            d = c - 'A' + 10;
        else if ((unsigned char)(c - 'a') <= 5)
            d = c - 'a' + 10;
        r = r * 16 + d;
    }
    return r;
}

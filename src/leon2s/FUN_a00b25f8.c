/* leon2s FUN_a00b25f8 @ 0xa00b25f8-0xa00b2790, -mcpu=v8 -Os -g.
 * (char *s), returns int; s == 0 gives 0. Cuts s at the first '\n', '\r' or NUL within 32 characters (at
 * index 31 when there is none), n = FUN_a00b1538(s) (string length). "0x"/"0X" prefix: hexadecimal digits
 * from index 2 are accumulated until a space, tab or the end (other characters only shift the value).
 * Otherwise a decimal number of at most 8 characters; -1 for a longer string or a character above '9'
 * (characters below '0' are not rejected).
 */
extern int FUN_a00b1538(char *);

int FUN_a00b25f8(char *s)
{
    int i, n, v;

    if (s == 0)
        return 0;
    for (i = 0; i < 0x20; i++)
        if (s[i] == '\n' || s[i] == '\r' || s[i] == 0)
            break;
    if (i == 0x20)
        i = 0x1f;
    s[i] = 0;
    n = FUN_a00b1538(s);
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

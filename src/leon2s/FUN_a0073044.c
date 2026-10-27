/* leon2s FUN_a0073044 @ 0xa0073044 (-mcpu=v8 -Os -g)
 * printf-style output (fmt, ...): the text between conversions goes to FUN_a0072fd8(s, n) unchanged. A conversion
 * is '%', an optional '-' (flags bit 0, left-justify), an optional '0' (flags bit 3, zero pad), a decimal width,
 * an optional '.' followed by digits (skipped), an optional 'l', then one of: 'b' (base 2), 'd'/'D' (base 10,
 * a negative value is negated and sets flags bit 1), 'o'/'O' (base 8), 'u'/'U' (base 10), 'x' (base 16),
 * 'X' (base 16, flags bit 2); these are formatted by FUN_a0072e60(buf, v, base, width, flags) into an 80-byte
 * stack buffer, and its return value is the length written. 'c' pads one character to width (at least 1) with
 * spaces, 's' pads a string to width with spaces (left or right), both in the same buffer. An unknown character
 * is written as itself; a '\0' right after the conversion prefix ends the string. At the end FUN_a0072fd8 gets
 * s_a00b3a18 (an empty string) with length 1, which writes nothing. Returns 0.
 * Source form: the 'l' modifier sets a flag that selects va_arg(ap, long) or va_arg(ap, int) in every number
 * case (identical code; with a plain 'if (*fmt == 'l') fmt++;' the skip compiles to subx and va_arg loses its
 * copy of the argument pointer); every case makes its own FUN_a0072fd8 call; 'case 0' is listed before
 * 'default'; the 'c' and 's' cases use their own buffer pointer, the 'c' case counts with len; in 'c' the
 * buffer pointer is set before the va_arg.
 */
typedef __builtin_va_list va_list;
#define va_start(v, l) __builtin_va_start(v, l)
#define va_arg(v, t) __builtin_va_arg(v, t)

extern void FUN_a0072fd8(const char *s, int n);
extern int FUN_a0072e60(char *buf, unsigned int v, unsigned int base, int width, char flags);
extern const char s_a00b3a18[];

int FUN_a0073044(const char *fmt, ...)
{
    va_list ap;
    char buf[80];
    const char *p;
    char *s;
    char *d;
    const char *q;
    const char *str;
    int width;
    char flags;
    int n;
    int len;
    int i;
    char c;
    int v;
    int lng;

    va_start(ap, fmt);
    for (;;) {
        p = fmt;
        while (*fmt != 0 && *fmt != '%')
            fmt++;
        FUN_a0072fd8(p, fmt - p);
        if (*fmt == 0)
            break;
        width = 0;
        fmt++;
        flags = 0;
        if (*fmt == '-') {
            fmt++;
            flags = 1;
        }
        if (*fmt == '0') {
            fmt++;
            flags |= 8;
        }
        while ((unsigned char)(*fmt - '0') < 10) {
            width = width * 10 + *fmt - '0';
            fmt++;
        }
        if (*fmt == '.') {
            do
                fmt++;
            while ((unsigned char)(*fmt - '0') < 10);
        }
        lng = 0;
        if (*fmt == 'l') {
            fmt++;
            lng = 1;
        }
        switch (*fmt) {
        case 'b':
            if (lng)
                v = va_arg(ap, long);
            else
                v = va_arg(ap, int);
            FUN_a0072fd8(buf, FUN_a0072e60(buf, v, 2, width, flags));
            break;
        case 'd':
        case 'D':
            if (lng)
                v = va_arg(ap, long);
            else
                v = va_arg(ap, int);
            if (v < 0) {
                v = -v;
                flags |= 2;
            }
            FUN_a0072fd8(buf, FUN_a0072e60(buf, v, 10, width, flags));
            break;
        case 'o':
        case 'O':
            if (lng)
                v = va_arg(ap, long);
            else
                v = va_arg(ap, int);
            FUN_a0072fd8(buf, FUN_a0072e60(buf, v, 8, width, flags));
            break;
        case 'u':
        case 'U':
            if (lng)
                v = va_arg(ap, long);
            else
                v = va_arg(ap, int);
            FUN_a0072fd8(buf, FUN_a0072e60(buf, v, 10, width, flags));
            break;
        case 'x':
            if (lng)
                v = va_arg(ap, long);
            else
                v = va_arg(ap, int);
            FUN_a0072fd8(buf, FUN_a0072e60(buf, v, 16, width, flags));
            break;
        case 'X':
            if (lng)
                v = va_arg(ap, long);
            else
                v = va_arg(ap, int);
            FUN_a0072fd8(buf, FUN_a0072e60(buf, v, 16, width, flags | 4));
            break;
        case 'c':
            s = buf;
            c = va_arg(ap, int);
            n = width;
            if (n <= 0)
                n = 1;
            if (flags & 1) {
                s[0] = c;
                for (len = 1; len < n; len++)
                    s[len] = ' ';
            } else {
                for (len = 0; len < n - 1; len++)
                    s[len] = ' ';
                s[n - 1] = c;
            }
            FUN_a0072fd8(s, n);
            break;
        case 's':
            str = va_arg(ap, const char *);
            d = buf;
            n = width;
            len = 0;
            q = str;
            while (*q++ != 0)
                len++;
            if (width < len)
                n = len;
            d[0] = 0;
            if (flags & 1) {
                for (i = 0; i < len; i++)
                    d[i] = str[i];
                for (i = len; i < n; i++)
                    d[i] = ' ';
            } else {
                for (i = 0; i < n - len; i++)
                    d[i] = ' ';
                for (i = n - len; i < n; i++)
                    d[i] = str[i - n + len];
            }
            FUN_a0072fd8(d, n);
            break;
        case 0:
            fmt--;
            break;
        default:
            FUN_a0072fd8(fmt, 1);
            break;
        }
        fmt++;
    }
    FUN_a0072fd8(s_a00b3a18, 1);
    return 0;
}

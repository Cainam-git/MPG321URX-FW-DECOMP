/* dbg_printf  (FUN_a0073044)
 *
 * Print formatted text on the debug console (printf).
 * Name basis: proven - handles %d %u %x %X %o %b %s %c with width and flags; called by every message print
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073044 @ 0xa0073044 (-mcpu=v8 -Os -g)
 * Source forms the exact build depends on:
 *  - the 'l' modifier sets long_arg, which selects va_arg(ap, long) or va_arg(ap, int) in every number case
 *    (identical code; with a plain 'if (*fmt == 'l') fmt++;' the skip compiles to subx and va_arg loses its copy
 *    of the argument pointer);
 *  - every case makes its own dbg_write_chars call; 'case 0' is listed before 'default';
 *  - the 'c' and 's' cases use their own buffer pointer (char_out, str_out); the 'c' case counts with len, and
 *    sets char_out before its va_arg;
 *  - flags is a plain char here, while dbg_format_number declares it unsigned char.
 */
typedef __builtin_va_list va_list;
#define va_start(v, l) __builtin_va_start(v, l)
#define va_arg(v, t) __builtin_va_arg(v, t)

/* Bits of 'flags', as dbg_format_number reads them. */
#define FMT_LEFT_JUSTIFY 1      /* '-': pad on the right */
#define FMT_NEGATIVE     2      /* the number was negative: a '-' is added */
#define FMT_UPPER_CASE   4      /* 'X': hex digits 'A'..'F' */
#define FMT_ZERO_PAD     8      /* '0': pad with '0' instead of ' ' (only when not left-justified) */

extern void dbg_write_chars(const char *s, int n);
extern int dbg_format_number(char *buf, unsigned int v, unsigned int base, int width, char flags);
extern const char s_a00b3a18[];         /* an empty string */

/*
 * printf for the input program's debug console. dbg_write_chars sends the characters out one by one and adds a
 * carriage return after each line feed.
 *
 *   fmt  format text, followed by its arguments
 *
 * Returns 0 (not the number of characters).
 *
 * A conversion is '%' [-] [0] [width] [.digits] [l] type. The precision is skipped and has no effect; 'l' is
 * accepted and reads the same 32-bit argument. Types: b (base 2), d / D (signed base 10), o / O (base 8),
 * u / U (base 10), x / X (base 16, lower / upper case), c (one character), s (string). Any other character
 * after the prefix is printed as itself (so "%%" prints '%'); a format that ends right after the prefix ends
 * the output.
 *
 * Numbers, characters and padded strings are built in an 80-byte buffer on the stack. Neither the width nor
 * the string length is checked against that size.
 */
int dbg_printf(const char *fmt, ...)
{
    va_list ap;
    char buf[80];
    const char *text_start;
    char *char_out;
    char *str_out;
    const char *scan;
    const char *arg_str;
    int width;
    char flags;
    int field_len;
    int len;
    int i;
    char ch;
    int value;
    int long_arg;

    va_start(ap, fmt);
    for (;;) {
        /* Plain text up to the next '%' goes out unchanged. */
        text_start = fmt;
        while (*fmt != 0 && *fmt != '%')
            fmt++;
        dbg_write_chars(text_start, fmt - text_start);
        if (*fmt == 0)
            break;

        /* The conversion prefix: flags, width, precision, size. */
        width = 0;
        fmt++;
        flags = 0;
        if (*fmt == '-') {
            fmt++;
            flags = FMT_LEFT_JUSTIFY;
        }
        if (*fmt == '0') {
            fmt++;
            flags |= FMT_ZERO_PAD;
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
        long_arg = 0;
        if (*fmt == 'l') {
            fmt++;
            long_arg = 1;
        }

        /* The conversion itself. */
        switch (*fmt) {
        case 'b':
            if (long_arg)
                value = va_arg(ap, long);
            else
                value = va_arg(ap, int);
            dbg_write_chars(buf, dbg_format_number(buf, value, 2, width, flags));
            break;
        case 'd':
        case 'D':
            if (long_arg)
                value = va_arg(ap, long);
            else
                value = va_arg(ap, int);
            /* The formatter takes unsigned values; the sign travels in the flags. */
            if (value < 0) {
                value = -value;
                flags |= FMT_NEGATIVE;
            }
            dbg_write_chars(buf, dbg_format_number(buf, value, 10, width, flags));
            break;
        case 'o':
        case 'O':
            if (long_arg)
                value = va_arg(ap, long);
            else
                value = va_arg(ap, int);
            dbg_write_chars(buf, dbg_format_number(buf, value, 8, width, flags));
            break;
        case 'u':
        case 'U':
            if (long_arg)
                value = va_arg(ap, long);
            else
                value = va_arg(ap, int);
            dbg_write_chars(buf, dbg_format_number(buf, value, 10, width, flags));
            break;
        case 'x':
            if (long_arg)
                value = va_arg(ap, long);
            else
                value = va_arg(ap, int);
            dbg_write_chars(buf, dbg_format_number(buf, value, 16, width, flags));
            break;
        case 'X':
            if (long_arg)
                value = va_arg(ap, long);
            else
                value = va_arg(ap, int);
            dbg_write_chars(buf, dbg_format_number(buf, value, 16, width, flags | FMT_UPPER_CASE));
            break;
        case 'c':
            /* One character, padded with spaces to the width (at least 1). */
            char_out = buf;
            ch = va_arg(ap, int);
            field_len = width;
            if (field_len <= 0)
                field_len = 1;
            if (flags & FMT_LEFT_JUSTIFY) {
                char_out[0] = ch;
                for (len = 1; len < field_len; len++)
                    char_out[len] = ' ';
            } else {
                for (len = 0; len < field_len - 1; len++)
                    char_out[len] = ' ';
                char_out[field_len - 1] = ch;
            }
            dbg_write_chars(char_out, field_len);
            break;
        case 's':
            /* A string, padded with spaces to the width; a longer string is printed whole. */
            arg_str = va_arg(ap, const char *);
            str_out = buf;
            field_len = width;
            len = 0;
            scan = arg_str;
            while (*scan++ != 0)
                len++;
            if (width < len)
                field_len = len;
            str_out[0] = 0;
            if (flags & FMT_LEFT_JUSTIFY) {
                for (i = 0; i < len; i++)
                    str_out[i] = arg_str[i];
                for (i = len; i < field_len; i++)
                    str_out[i] = ' ';
            } else {
                for (i = 0; i < field_len - len; i++)
                    str_out[i] = ' ';
                for (i = field_len - len; i < field_len; i++)
                    str_out[i] = arg_str[i - field_len + len];
            }
            dbg_write_chars(str_out, field_len);
            break;
        case 0:
            /* The format ends inside a conversion: step back so the loop sees the end. */
            fmt--;
            break;
        default:
            dbg_write_chars(fmt, 1);
            break;
        }
        fmt++;
    }
    /* dbg_write_chars writes nothing for an empty string with length 1. */
    dbg_write_chars(s_a00b3a18, 1);
    return 0;
}

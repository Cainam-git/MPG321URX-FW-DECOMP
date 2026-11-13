/* dbg_format_number  (FUN_a0072e60)
 *
 * Format an unsigned number in a base with padding and sign for the printf.
 * Returns: field width
 * Name basis: proven - digits, case, sign and pad flags; only caller dbg_printf
 *
 * Matching notes
 * --------------
 * FUN_a0072e60 (leon2s 0xa0072e60-0xa0072fd8, 376 bytes), flags -mcpu=v8 -Os -g.
 * Source form: quotient q and remainder (written as value - q * base into value); the '-' is stored before
 * n = p - buf; the reverse loop tests j > i.
 */
/* Bits of 'flags' (set by dbg_printf). */
#define FMT_LEFT_JUSTIFY 1      /* pad on the right */
#define FMT_NEGATIVE     2      /* append a '-' (the caller passes the magnitude) */
#define FMT_UPPER_CASE   4      /* hex digits 'A'..'F' instead of 'a'..'f' */
#define FMT_ZERO_PAD     8      /* pad with '0' instead of ' ' (ignored when left-justified) */

/*
 * Write the unsigned number value in the given base (2..16) into buf as text, padded to width, and return the
 * number of characters written (the field width: width, or more when the text is longer). No terminating zero is
 * written; buf must hold the result.
 *   flags: FMT_* bits
 * The text is built backwards and turned round at the end: digits least significant first, then the '-' when
 * FMT_NEGATIVE is set, then the pad up to width. With '0' padding (FMT_ZERO_PAD, not left-justified) a '-' goes
 * in front of the zeros, so the pad starts where the '-' was put and the '-' is stored last. The reversal covers
 * the first n characters (digits and sign) when left-justified, so the pad stays behind the text, and the whole
 * field otherwise, so the pad comes first.
 */
int dbg_format_number(char *buf, unsigned int value, unsigned int base, int width, unsigned char flags)
{
    char *p = buf;
    char digit;
    int n;
    int i;
    int k;
    int j;
    char pad;
    char t;
    unsigned int q;

    do {
        q = value / base;
        value = value - q * base;
        digit = value;
        if (digit < 10)
            *p++ = digit + '0';
        else if (flags & FMT_UPPER_CASE)
            *p++ = digit + '7';                 /* 10 -> 'A' */
        else
            *p++ = digit + 'W';                 /* 10 -> 'a' */
        value = q;
    } while (value);
    if (flags & FMT_NEGATIVE)
        *p++ = '-';
    n = p - buf;                                /* characters so far, in reverse order */
    if (width < n)
        width = n;
    pad = ' ';
    if (!(flags & FMT_LEFT_JUSTIFY) && (flags & FMT_ZERO_PAD))
        pad = '0';
    if ((flags & FMT_NEGATIVE) && !(flags & FMT_LEFT_JUSTIFY) && pad == '0') {
        /* The '-' must end up in front of the zeros: overwrite it, then put it at the far end. */
        for (k = n - 1; k < width - 1; k++)
            buf[k] = pad;
        buf[width - 1] = '-';
    } else {
        for (k = n; k < width; k++)
            buf[k] = pad;
    }
    i = 0;
    if (flags & FMT_LEFT_JUSTIFY)
        j = n - 1;
    else
        j = width - 1;
    for (; j > i; i++, j--) {
        t = buf[i];
        buf[i] = buf[j];
        buf[j] = t;
    }
    return width;
}

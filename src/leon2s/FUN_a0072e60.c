/* FUN_a0072e60 (leon2s 0xa0072e60-0xa0072fd8, 376 bytes), flags -mcpu=v8 -Os -g.
 * Writes the unsigned value v in the given base into buf and returns the field width used. Digits are produced
 * least significant first ('0'-'9', then 'A'.. when bit 2 of flags is set, else 'a'..); bit 1 of flags appends
 * a '-'. width is raised to the digit count n. The pad character is '0' when bit 3 is set and bit 0 is clear,
 * else ' '. With bit 1 set, bit 0 clear and '0' padding, the pad runs from n - 1 to width - 2 and '-' goes to
 * width - 1; otherwise the pad fills n .. width - 1. Finally the first n (bit 0 set) or width (bit 0 clear)
 * characters are reversed in place. No terminating zero is written.
 * Source form: quotient q and remainder written as v - q * base in v; '-' stored before n = p - buf; the
 * reverse loop tests j > i.
 */
int FUN_a0072e60(char *buf, unsigned int v, unsigned int base, int width, unsigned char flags)
{
    char *p = buf;
    char d;
    int n;
    int i;
    int k;
    int j;
    char c;
    char t;
    unsigned int q;

    do {
        q = v / base;
        v = v - q * base;
        d = v;
        if (d < 10)
            *p++ = d + '0';
        else if (flags & 4)
            *p++ = d + '7';
        else
            *p++ = d + 'W';
        v = q;
    } while (v);
    if (flags & 2)
        *p++ = '-';
    n = p - buf;
    if (width < n)
        width = n;
    c = ' ';
    if (!(flags & 1) && (flags & 8))
        c = '0';
    if ((flags & 2) && !(flags & 1) && c == '0') {
        for (k = n - 1; k < width - 1; k++)
            buf[k] = c;
        buf[width - 1] = '-';
    } else {
        for (k = n; k < width; k++)
            buf[k] = c;
    }
    i = 0;
    if (flags & 1)
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

/* FUN_a011ce80: copies up to n bytes of one of five read-only tables into dst. sel 0: 0x9f1b0600 (at most 8
 * bytes), 1: 0x9f1b0608 (8), 2: 0x9f1b0610 (16), 3: 0x9f1b0620 (16), 4: 0x9f1b0630 (40); any other sel copies
 * nothing. Caller: FUN_a0115584. The copy is the u8-counter byte loop of FUN_a011cf88 (static helper, inlined).
 * Exact form: the count is a separate unsigned char len (copied from n before the limit test); len is
 * declared and initialised before src.
 */
static void rd8(unsigned char *d, const unsigned char *s, unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++)
        d[i] = s[i];
}

void FUN_a011ce80(unsigned int sel, unsigned char n, unsigned char *dst)
{
    unsigned char len = 0;
    const unsigned char *src = 0;

    switch (sel) {
    case 0:
        len = n;
        if (n > 8)
            len = 8;
        src = (const unsigned char *)0x9f1b0600;
        break;
    case 1:
        len = n;
        if (n > 8)
            len = 8;
        src = (const unsigned char *)0x9f1b0608;
        break;
    case 2:
        len = n;
        if (n > 16)
            len = 16;
        src = (const unsigned char *)0x9f1b0610;
        break;
    case 3:
        len = n;
        if (n > 16)
            len = 16;
        src = (const unsigned char *)0x9f1b0620;
        break;
    case 4:
        len = n;
        if (n > 40)
            len = 40;
        src = (const unsigned char *)0x9f1b0630;
        break;
    }
    rd8(dst, src, len);
}

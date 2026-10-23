/* FUN_a006fd78 (leon2s 0xa006fd78-0xa006fedc, 356 bytes), flags -mcpu=v8 -Os -g.
 * Clears a local 8-word buffer, calls FUN_a006faa8(10, 0, buf, 1) until buf[0] reads back 0, clamps len to 0x1c
 * and packs len / 4 little-endian words of d[] into buf[1..] and the remaining len % 4 bytes into the next word
 * (byte k shifted by 8 * k). Then buf[0] = id << 8 | (len + 4) << 16 | 0x55 (len as a byte), and calls
 * FUN_a006fb3c(buf, 8) and FUN_a006fad4(10, 0, buf, 8).
 * Source form: the byte count is split with / 4 and % 4 (the % gives the and on the masked length); the
 * partial word is addressed as buf[len / 4 + 1].
 */
extern void *FUN_a00b15ac(void *, int, unsigned int);
extern void FUN_a006faa8(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void FUN_a006fad4(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void FUN_a006fb3c(unsigned int *buf, unsigned char n);

void FUN_a006fd78(int id, unsigned char len, unsigned char *d)
{
    unsigned int buf[8];
    unsigned char pos;
    unsigned char i;
    unsigned char n;
    unsigned char rem;

    FUN_a00b15ac(buf, 0, 0x20);
    pos = 0;
    do
        FUN_a006faa8(10, 0, buf, 1);
    while (buf[0] != 0);
    if (len > 0x1c)
        len = 0x1c;
    n = len / 4;
    rem = len % 4;
    for (i = 0; i < n; i++) {
        buf[i + 1] = d[pos] | d[pos + 1] << 8 | d[pos + 2] << 16 | d[pos + 3] << 24;
        pos += 4;
    }
    if (rem)
        for (i = 0; i < rem; i++)
            buf[len / 4 + 1] |= d[pos + i] << (i * 8);
    len += 4;
    buf[0] = id << 8 | len << 16 | 0x55;
    FUN_a006fb3c(buf, 8);
    FUN_a006fad4(10, 0, buf, 8);
}

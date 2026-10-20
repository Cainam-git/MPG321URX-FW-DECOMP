/* leon2m FUN_a01348a0 @ 0xa01348a0-0xa013497c (55 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Takes m = min(n, halfword 0xa802cb94) bytes from the front of the buffer at 0xa802dd50: copies them to dst, moves
 * the remaining bytes (up to the old count) to the start of the buffer, lowers the count by m and returns m.
 * Halfword counters.
 */
extern unsigned short DAT_a802cb94;
extern unsigned char DAT_a802dd50[];

unsigned short FUN_a01348a0(unsigned char *dst, unsigned short n)
{
    unsigned short m = DAT_a802cb94;
    unsigned short i, j;

    if (n < m)
        m = n;
    for (i = 0; i < m; i++)
        dst[i] = DAT_a802dd50[i];
    for (i = m, j = 0; i < DAT_a802cb94; i++, j++)
        DAT_a802dd50[j] = DAT_a802dd50[i];
    DAT_a802cb94 -= m;
    return m;
}

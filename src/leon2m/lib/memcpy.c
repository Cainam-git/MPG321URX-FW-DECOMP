/* memcpy  (FUN_a013c910)
 *
 * Copy n bytes from src to dst.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013c910 @ 0xa013c910, written by hand: a byte loop that counts n down to -1.
 */
/*
 * Copy n bytes from src to dst, one byte at a time, and return dst. The areas must not overlap. n is a signed
 * int and the loop ends when it has counted down past 0, so a negative n would copy about 4 GB.
 */
void *memcpy(void *dst, const void *src, int n)
{
    unsigned char *d = dst;
    const unsigned char *s = src;
    while (n-- != 0)
        *d++ = *s++;
    return dst;
}

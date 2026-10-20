/* leon2s FUN_a00b15d8 @ 0xa00b15d8-0xa00b160c (13 words), flags -mcpu=v8 -Os -g.
 * Code facts: leaf memcpy: n bytes from src to dst, front to back; returns dst (%o0 is kept, the copy walks a
 * second pointer in %o5).
 * Fix vs the autoc draft (76.92): returns dst (a void version walks %o0 itself, 76.92). Aids: none.
 */
void *FUN_a00b15d8(void *dst, const void *src, int n)
{
    unsigned char *d = dst;
    const unsigned char *s = src;

    while (n--)
        *d++ = *s++;
    return dst;
}

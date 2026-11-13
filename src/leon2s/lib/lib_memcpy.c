/* lib_memcpy  (FUN_a00b15d8)
 *
 * Copy a block of memory.
 * Name basis: proven - byte loop; returns the destination
 *
 * Matching notes
 * --------------
 * FUN_a00b15d8 (leon2s 0xa00b15d8, 52 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns dst: the copy walks a second pointer, %o0 is kept. A void version walks %o0 itself.
 */
/* Copy count bytes from src to dst, front to back; returns dst. */
void *lib_memcpy(void *dst, const void *src, int count)
{
    unsigned char *d = dst;
    const unsigned char *s = src;

    while (count--)
        *d++ = *s++;
    return dst;
}

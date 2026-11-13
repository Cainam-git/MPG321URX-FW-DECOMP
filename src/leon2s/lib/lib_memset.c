/* lib_memset  (FUN_a00b15ac)
 *
 * Fill a block of memory with one byte value.
 * Name basis: proven - byte loop; returns the destination
 *
 * Matching notes
 * --------------
 * FUN_a00b15ac (leon2s 0xa00b15ac, 44 bytes, leaf), flags -mcpu=v8 -Os -g.
 * A separate destination pointer and 'return dst' are required: the copy keeps %o0 live, which gives the
 * firmware's 'mov %o0,%g1'; a void form without the return stores through %o0.
 */
/* Set count bytes at dst to value (loop until the count wraps to -1); returns dst. */
void *lib_memset(unsigned char *dst, unsigned char value, int count)
{
  unsigned char *d = dst;

  while (--count != -1)
    *d++ = value;
  return dst;
}

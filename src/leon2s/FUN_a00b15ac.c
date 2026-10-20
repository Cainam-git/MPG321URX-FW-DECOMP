/* leon2s FUN_a00b15ac @ 0xa00b15ac-0xa00b15d8 (11 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0 mismatches / 11 words. Leaf (retl).
 * Code facts: memset-like byte fill: d = dst (copy in %g1, %o0 is never changed), while (--n != -1)
 * *d++ = (u8)v; returns dst in %o0. Same shape as FUN_a00b15d8 (memcpy that returns dst).
 * Required form: a separate destination pointer and 'return dst' (the copy keeps %o0 live,
 * which gives the fw 'mov %o0,%g1'; a void form without the return gives the stores through %o0). Aids: none.
 */
void *FUN_a00b15ac(unsigned char *dst, unsigned char v, int n)
{
  unsigned char *d = dst;

  while (--n != -1)
    *d++ = v;
  return dst;
}

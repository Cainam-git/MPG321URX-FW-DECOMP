/* leon2m FUN_a0124220 @ 0xa0124220-0xa0124244 (9 words), flags -mcpu=v8 -O3 -g.
 * Code facts: r = 0; if (FUN_a0125b94() & 0xff) r = 2 (bne,a with the mov in the annulled slot); returns r (the
 * fw's 'and %i0, 2, %i0' is the u8 return extension, narrowed by combine to the nonzero bits of {0, 2}).
 * Source form: r and the return type are unsigned char; FUN_a0125b94 returns unsigned char (its code:
 * cmp %g0,%o0; subx -> 0 or 1).
 */
extern unsigned char FUN_a0125b94(void);

unsigned char FUN_a0124220(void)
{
  unsigned char r = 0;

  if (FUN_a0125b94())
    r = 2;
  return r;
}

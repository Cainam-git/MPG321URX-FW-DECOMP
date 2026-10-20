/* FUN_a00aa4e0 (leon2m 0xa00aa4e0-0xa00aa520, 64 bytes), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp (rawcmp.py) 0 mismatches of 16 words.
 * Code facts: one u8 param id (and %i0,0xff). id != 5 -> returns 1. id == 5 -> calls FUN_a00d7d48()
 * (no argument: %o0 is not set before the call) and returns 1 only when that call returned 0 AND the
 * word DAT_a802d484 is >= 0 (ld + cmp + bge,a), else 0.
 * BEHAVIOUR fix: the draft tested param_1 == 0 instead of FUN_a00d7d48()'s return value; 1 parameter, not 2.
 * Aids: none.
 */
extern int DAT_a802d484;
extern int FUN_a00d7d48(void);

int FUN_a00aa4e0(unsigned char id)
{
  int ok = 1;

  if (id == 5) {
    ok = 0;
    if (FUN_a00d7d48() == 0 && DAT_a802d484 >= 0)
      ok = 1;
  }
  return ok;
}

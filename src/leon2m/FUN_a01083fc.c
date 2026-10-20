/* leon2m FUN_a01083fc @ 0xa01083fc-0xa01084a8 (43 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * BEST FLAGS DIFFER: needs -msoft-float (plain -O3 -g gives 27.78; the FUN_a0155xxx callees are libgcc
 * soft-float routines, as in FUN_a0105af8). BYTE-EXACT with those flags:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 43 words.
 * Code facts: FUN_a00df170(s_0019abc8 "FRC_AutoFrameDown dclk =%ld\r\n", *dclk); x = *dclk (re-read). x <
 * 2408000000 (0x8f872a00) returns 100. Else v = 100, and when x > 2408000000: v = (unsigned)((float)x /
 * 2407000000.0f * 100.0f) + 1 (unsigned-to-float = __floatsisf FUN_a0155c40 with the >>1|&1 + __addsf3
 * FUN_a015578c fix-up for bit 31; __divsf3 FUN_a0155a18 by the constant 0x4f0f77e8 at ROM 0x19acc8; __mulsf3
 * FUN_a0155830 by 100.0f at ROM 0x198754; __fixunssfsi FUN_a01551bc). Returns (u16)v.
 * Required forms: float source with -msoft-float, the print takes the format + value; 'v = 100' before
 * the first test gives the fw mov 0x64,%o0 / mov 0x64,%g1 order. Aids: none.
 */
extern char s_0019abc8[];
extern void FUN_a00df170(char *, unsigned int);

unsigned short FUN_a01083fc(unsigned int *dclk)
{
  unsigned int x;
  unsigned int v;

  FUN_a00df170(s_0019abc8, *dclk);
  x = *dclk;
  v = 100;
  if (x < 2408000000u)
    return 100;
  if (x > 2408000000u)
    v = (unsigned int)((float)x / 2407000000.0f * 100.0f) + 1;
  return v;
}

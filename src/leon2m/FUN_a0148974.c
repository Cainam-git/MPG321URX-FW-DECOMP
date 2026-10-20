/* leon2m FUN_a0148974 @ 0xa0148974-0xa0148a24 (44 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 44 words.
 * Code facts: r = 0xff; switch on FUN_a0152f70() (u8): 8 -> r = FUN_a0125140(byte 0xa802e126);
 * 9 -> FUN_a0125140(byte 0xa802e138); 10 -> FUN_a0125140(FUN_a012ad6c() ? byte 0xa802e15c : byte 0xa802e14a);
 * 11 -> FUN_a0125140(FUN_a012ad6c() ? 0xa802e14a : 0xa802e15c); other values keep 0xff. Returns r as u8.
 * The four bytes are separate symbols (one sethi per load, none shared).
 * Fix vs the autoc draft (68.18): plain switch with r preset to 0xff; both 10/11 arms test 'if (FUN_a012ad6c())'
 * with the true arm first (an '== 0' form in case 11 swaps the %o2/%o3 HIGH registers, 90.91); real
 * prototypes (u8 returns, void params). Aids: none.
 */
extern unsigned char DAT_a802e126;
extern unsigned char DAT_a802e138;
extern unsigned char DAT_a802e14a;
extern unsigned char DAT_a802e15c;
extern unsigned char FUN_a0125140(unsigned char);
extern unsigned char FUN_a012ad6c(void);
extern unsigned char FUN_a0152f70(void);

unsigned char FUN_a0148974(void)
{
  unsigned char r = 0xff;

  switch (FUN_a0152f70()) {
  case 8:
    r = FUN_a0125140(DAT_a802e126);
    break;
  case 9:
    r = FUN_a0125140(DAT_a802e138);
    break;
  case 10:
    if (FUN_a012ad6c())
      r = FUN_a0125140(DAT_a802e15c);
    else
      r = FUN_a0125140(DAT_a802e14a);
    break;
  case 11:
    if (FUN_a012ad6c())
      r = FUN_a0125140(DAT_a802e14a);
    else
      r = FUN_a0125140(DAT_a802e15c);
    break;
  }
  return r;
}

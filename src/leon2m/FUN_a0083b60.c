/* leon2m FUN_a0083b60 @ 0xa0083b60-0xa0083be0 (32 words), flags -mcpu=v8 -O3 -g.
 * Code facts: k = (u8)FUN_a0148868(); FUN_a00df170(s_000feef8, k); ok = (k == 3) ? !(FUN_a0148a24() == 1)
 * : (k != 4) (fw: mov 1 / be,a clr for k == 3, xor 4 / addx store-flag otherwise); if ok: FUN_a0124b40() and
 * tail FUN_a0124a68(). void(void).
 * Fix vs the autoc draft (65.62): BEHAVIOUR: the print takes the format symbol s_000feef8 and k (the draft
 * passed nothing), FUN_a0148868 / FUN_a0148a24 take no args; written as a u8 'ok' flag set to 1 then
 * cleared in the k == 3 arm (a one-line '!= 1' store-flag gives 56.25). Aids: none.
 */
extern const char s_000feef8[];
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned char FUN_a0148868(void);
extern unsigned char FUN_a0148a24(void);
extern void FUN_a0124b40(void);
extern void FUN_a0124a68(void);

void FUN_a0083b60(void)
{
  unsigned char k;
  unsigned char ok;

  k = FUN_a0148868();
  FUN_a00df170(s_000feef8, k);
  if (k == 3) {
    ok = 1;
    if (FUN_a0148a24() == 1)
      ok = 0;
  } else
    ok = k != 4;
  if (ok) {
    FUN_a0124b40();
    FUN_a0124a68();
  }
}

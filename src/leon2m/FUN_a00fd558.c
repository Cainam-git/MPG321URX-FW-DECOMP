/* leon2m FUN_a00fd558 @ 0xa00fd558-0xa00fd594 (15 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0108f70(); word register 0xcf00ed84 = 0xb; FUN_a0123384(); FUN_a011e028(0, 1);
 * tail call FUN_a00df170(s_0019a498) (the log print, ONE argument: only %o0 is set). void, no params.
 * Fix vs the autoc draft (87.50): BEHAVIOUR, the print takes one argument (the draft forwarded
 * param_2..param_6). Aids: none.
 */
extern void FUN_a00df170(const char *, ...);
extern void FUN_a0108f70(void);
extern void FUN_a011e028(int, int);
extern void FUN_a0123384(void);
extern const char s_0019a498[];

void FUN_a00fd558(void)
{
  FUN_a0108f70();
  *(volatile unsigned int *)0xcf00ed84 = 0xb;
  FUN_a0123384();
  FUN_a011e028(0, 1);
  FUN_a00df170(s_0019a498);
}

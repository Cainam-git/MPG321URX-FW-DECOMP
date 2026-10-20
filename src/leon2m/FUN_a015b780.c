/* leon2m FUN_a015b780 @ 0xa015b780-0xa015b7a0 (8 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a015b5f4(); tail call FUN_a015bf7c(*(void **)0xa802aa18, 0x000fb738) (newlib
 * _fwalk-style walk over the reent pointer word _DAT_a802aa18 with a callback at 0x000fb738).
 * The callback address is 0x000fb738 (fw sethi 0xfb400 | 0x338), not FUN_a015b738; the source names it
 * FUN_000fb738 so that the link resolves to the real address. Aids: none.
 */
extern unsigned int _DAT_a802aa18;
extern void FUN_a015b5f4(void);
extern int FUN_a015bf7c(void *reent, int (*fn)(void *));
extern int FUN_000fb738(void *fp);

void FUN_a015b780(void)
{
  FUN_a015b5f4();
  FUN_a015bf7c((void *)_DAT_a802aa18, FUN_000fb738);
}

/* leon2m FUN_a00f6f10 @ 0xa00f6f10-0xa00f6f54 (17 words), flags -mcpu=v8 -O3 -g. One of three twins FUN_a00f6e88 / FUN_a00f6ecc /
 * FUN_a00f6f10 (selector 3 / 4 / 5, register 0xcf00ef10 / ef14 / ef18).
 * Code facts: v = param_1 & 0xff; if the hook word _DAT_a802b7b8 is non-zero it is called as
 * hook(5, v) (call %g1 with %o0 = 5 and %o1 = v); otherwise the word register 0xcf00ef18 = v. void.
 * Fixes vs the autoc draft (88.24): BEHAVIOUR, the hook takes TWO arguments (selector and v; the
 * draft passed only the selector); u8 parameter used directly (a separate 'unsigned int v'
 * copy puts the and in %i0 instead of %o1, 88.24); void. Aids: none.
 */
extern void (*_DAT_a802b7b8)(int, unsigned int);

void FUN_a00f6f10(unsigned char param_1)
{
  if (_DAT_a802b7b8 != 0)
    _DAT_a802b7b8(5, param_1);
  else
    *(volatile unsigned int *)0xcf00ef18 = param_1;
}

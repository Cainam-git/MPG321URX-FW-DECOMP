/* leon2m FUN_a00f6ecc @ 0xa00f6ecc-0xa00f6f10 (17 words), flags -mcpu=v8 -O3 -g.
 * One of three twins FUN_a00f6e88 / FUN_a00f6ecc / FUN_a00f6f10 (selector 3 / 4 / 5, register 0xcf00ef10 / ef14 /
 * ef18).
 * Code facts: v = param_1 & 0xff; if the hook word _DAT_a802b7b8 is non-zero it is called as hook(4, v) (call %g1
 * with %o0 = 4 and %o1 = v); otherwise the word register 0xcf00ef14 = v. void.
 * The hook takes two arguments (selector and v).
 * Source form: the u8 parameter is used directly (a separate 'unsigned int v' copy puts the and in %i0 instead of
 * %o1). Compiler aids: none.
 */
extern void (*_DAT_a802b7b8)(int, unsigned int);

void FUN_a00f6ecc(unsigned char param_1)
{
  if (_DAT_a802b7b8 != 0)
    _DAT_a802b7b8(4, param_1);
  else
    *(volatile unsigned int *)0xcf00ef14 = param_1;
}

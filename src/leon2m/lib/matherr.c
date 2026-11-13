/* matherr  (FUN_a01550a0)
 *
 * Report a maths library error; the default handler returns 0.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01550a0 @ 0xa01550a0, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept (an undefined4 return of the constant 0).
 */
typedef unsigned int undefined4;

/*
 * C library maths error hook: takes no arguments and always returns 0 (the default handler).
 */
undefined4 matherr(void)

{
  return 0;
}
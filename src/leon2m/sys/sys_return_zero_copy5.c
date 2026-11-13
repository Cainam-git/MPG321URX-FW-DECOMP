/* sys_return_zero_copy5  (FUN_a015e7d8)
 *
 * Return 0.
 * Returns: 0
 * Note: Identical copy of sys_return_zero.
 * Name basis: descriptive - constant; used as a status getter that is always 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e7d8 @ 0xa015e7d8 (-mcpu=v8 -O2 -g, the section default).
 * Source form: the decompiler's type name is kept.
 */
typedef unsigned int undefined4;

/* Return 0. Identical to sys_return_zero. _close_r (_close_r) calls it, passing the file descriptor, which it ignores. */
undefined4 sys_return_zero_copy5(void)

{
  return 0;
}

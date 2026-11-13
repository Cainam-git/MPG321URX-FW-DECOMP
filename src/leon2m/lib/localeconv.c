/* localeconv  (FUN_a015c1e4)
 *
 * Return the numeric formatting conventions of the C locale.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015c1e4 @ 0xa015c1e4, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept.
 */
extern unsigned int _impure_ptr;
extern int _localeconv_r();

/*
 * Call _localeconv_r with the state record _impure_ptr (0xA802AA18). The result is not returned.
 */
void localeconv(void)

{
  _localeconv_r(_impure_ptr);
  return;
}

/* __errno  (FUN_a01576dc)
 *
 * Return the address of the current errno variable.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01576dc @ 0xa01576dc, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept.
 */
typedef unsigned int undefined4;
extern unsigned int _impure_ptr;

/*
 * C library errno access: returns the word at _impure_ptr (0xA802AA18) as it is, without adding an offset.
 */
undefined4 __errno(void)

{
  return _impure_ptr;
}
/* wcsrtombs  (FUN_a0159840)
 *
 * Convert a wide-character string to multibyte using the global reentrancy structure.
 * Name basis: proven - wrapper that passes _impure_ptr to _wcsrtombs_r (newlib pattern)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0159840 @ 0xa0159840, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept; the callee is declared without a parameter list.
 */
typedef unsigned char byte;
typedef unsigned int uint;
extern unsigned int _impure_ptr;
extern int _wcsrtombs_r();

/*
 * C library wrapper: calls _wcsrtombs_r with the global reentrancy pointer (_impure_ptr) in front of its four
 * own arguments, which are passed on unchanged. The result of _wcsrtombs_r is not returned.
 */
void wcsrtombs(byte *dst,int *src,uint *len,uint *ps)

{
  _wcsrtombs_r(_impure_ptr,dst,src,len,ps);
  return;
}
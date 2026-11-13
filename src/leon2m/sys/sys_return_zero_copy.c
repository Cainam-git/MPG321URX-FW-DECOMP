/* sys_return_zero_copy  (FUN_a0110f54)
 *
 * Return 0.
 * Returns: 0
 * Note: Identical copy of sys_return_zero.
 * Name basis: descriptive - constant; used as a status getter that is always 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0110f54 @ 0xa0110f54, flags -mcpu=v8 -O2 -g (section default).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


/* Always returns 0 (a byte-for-byte copy of sys_return_zero). */
undefined4 sys_return_zero_copy(void)

{
  return 0;
}
/* sys_return_zero_copy2  (FUN_a011898c)
 *
 * Return 0.
 * Returns: 0
 * Note: Identical copy of sys_return_zero.
 * Name basis: descriptive - constant; used as a status getter that is always 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011898c @ 0xa011898c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


/* Always returns 0 (a byte-for-byte copy of sys_return_zero). The pq response-level routine pq_apply_response_level tests its result. */
undefined4 sys_return_zero_copy2(void)

{
  return 0;
}
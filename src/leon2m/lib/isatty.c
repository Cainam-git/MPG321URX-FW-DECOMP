/* isatty  (FUN_a015e7f4)
 *
 * Tell whether a file descriptor is a terminal.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e7f4 @ 0xa015e7f4 (-mcpu=v8 -O2 -g)
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


/* Return 1 for every descriptor; the routine takes no parameter. */
undefined4 isatty(void)

{
  return 1;
}
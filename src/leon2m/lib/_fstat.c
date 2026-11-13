/* _fstat  (FUN_a015e7e0)
 *
 * Report every file as a character device: set st_mode to 0x2000 and return 0.
 * Returns: 0
 * Name basis: proven - stores S_IFCHR at offset 8 of the stat buffer; called by _fstat_r (libnosys stub)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e7e0 @ 0xa015e7e0 (-mcpu=v8 -O2 -g)
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


/*
 * Store 0x2000 as the halfword at offset 8 of the status buffer and 0 as the word at offset 0x30; return 0.
 * fd (param_1) is not used.
 */
undefined4 _fstat(undefined4 fd,int stat_buf)

{
  *(undefined2 *)(stat_buf + 8) = 0x2000;
  *(undefined4 *)(stat_buf + 0x30) = 0;
  return 0;
}
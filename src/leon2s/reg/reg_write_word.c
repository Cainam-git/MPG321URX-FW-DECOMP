/* reg_write_word  (FUN_a00b2304)
 *
 * Store a word at an address.
 * Name basis: derived - plain store
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b2304 @ 0xa00b2304 (-mcpu=v8 -Os -g)
 * Source form: the decompiler's type name undefined4 is kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


/*
 * Store value in the 32-bit word at address.
 * Used by the debug line handler for the write commands.
 */
void reg_write_word(undefined4 *address,undefined4 value)

{
  *address = value;
  return;
}
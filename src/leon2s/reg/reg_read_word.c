/* reg_read_word  (FUN_a00b22fc)
 *
 * Return the word at an address.
 * Returns: word
 * Name basis: derived - plain load
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b22fc @ 0xa00b22fc (-mcpu=v8 -Os -g)
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
 * Return the 32-bit word at address.
 * Used by the debug line handler (reads at an address typed on the line) and by the mailbox dump (CED_ALL_3).
 */
undefined4 reg_read_word(undefined4 *address)

{
  return *address;
}
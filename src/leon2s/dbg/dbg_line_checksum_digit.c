/* dbg_line_checksum_digit  (FUN_a00b288c)
 *
 * Compute the check digit: '0' plus the low four bits of the byte sum of two 32-bit values.
 * Returns: character
 * Name basis: derived - 0x30 + (sum of all bytes & 0x0F)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b288c @ 0xa00b288c (-mcpu=v8 -Os -g)
 * Source form: the decompiler's type names are kept; each value is shifted right by eight bits until it is zero.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


/*
 * Check digit of a line of the tool protocol: the character '0' plus the low four bits of the sum of all bytes of
 * first and second. The command line handler calls it with the address (second = 0) or with address and value.
 */
int dbg_line_checksum_digit(uint first,uint second)

{
  uint sum;
  
  sum = 0;
  for (; first != 0; first = first >> 8) {
    sum = sum + (first & 0xff);
  }
  for (; second != 0; second = second >> 8) {
    sum = sum + (second & 0xff);
  }
  return (sum & 0xf) + 0x30;
}
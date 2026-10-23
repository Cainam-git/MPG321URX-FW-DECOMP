/* leon2s FUN_a00b035c @ 0xa00b035c (-mcpu=v8 -Os -g)
 * Returns the address 0xA807DCF7 + 300 * (p & 0xff) (byte +0xdf of the 300-byte record p at 0xA807DC18).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


int FUN_a00b035c(uint param_1)

{
  return (param_1 & 0xff) * 300 + -0x57f82309;
}
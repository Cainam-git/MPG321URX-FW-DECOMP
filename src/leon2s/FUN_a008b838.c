/* FUN_a008b838 (leon2s 0xa008b838-0xa008b84c, 20 bytes), flags -mcpu=v8 -Os -g.
 * int (u8 p1). Returns FUN_a00a6f08(p1, 99) as a tail call (register 99 of port p1). Called by FUN_a008c538,
 * which uses the full returned register.
 * Source form: Ghidra's type names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a00a6f08(unsigned char, unsigned short);

int FUN_a008b838(undefined1 param_1)

{
  return FUN_a00a6f08(param_1,99);
}
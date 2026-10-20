/* leon2m FUN_a002d174 @ 0xa002d174 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern code *_DAT_a802b0e0;

int FUN_a002d174(undefined4 param_1,undefined4 param_2)

{
  if (_DAT_a802b0e0 != (code *)0x0) {
    (*_DAT_a802b0e0)(4);
  }
  return CONCAT44(param_2,param_1);
}
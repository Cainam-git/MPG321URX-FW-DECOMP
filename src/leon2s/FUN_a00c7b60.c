/* leon2s FUN_a00c7b60 @ 0xa00c7b60  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int func_0xa0fb7fd8();
extern int func_0xa0fb8054();

void FUN_a00c7b60(uint param_1)

{
  unsigned char uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = func_0xa0fb7fd8(param_1,0,0xf3);
  func_0xa0fb8054(param_1,0,0xf3,uVar1 & 0xff | 0xf);
  return;
}
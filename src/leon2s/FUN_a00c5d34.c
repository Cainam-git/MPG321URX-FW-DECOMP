/* leon2s FUN_a00c5d34 @ 0xa00c5d34 (-mcpu=v8 -Os -g)
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
extern int func_0xa0fb6c98();
extern int func_0xa0fb7e14();

void FUN_a00c5d34(byte param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  unsigned char cVar1;
  
  cVar1 = param_1 - 4;
  if (param_1 < 4) {
    func_0xa0fb7e14(param_1,0x2e,0x40,param_2,param_5,param_6);
    return;
  }
  func_0xa0fb6c98(cVar1,0x30,0x80,1);
  func_0xa0fb6c98(cVar1,0x2a8,2,param_2);
  func_0xa0fb6c98(cVar1,0x30,0x80,0,param_5,param_6);
  return;
}
/* leon2s FUN_a00c85b8 @ 0xa00c85b8 (-mcpu=v8 -Os -g)
 * k = p1 & 0xff. Reads v = func_0xa0fb7fd8(k, 0, 0xf) and writes v with bit 3 cleared through func_0xa0fb8054(k,
 * 0, 0xf, v & 0xf7).
 * Source form: Ghidra's type and symbol names are kept.
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

void FUN_a00c85b8(uint param_1)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = func_0xa0fb7fd8(param_1,0,0xf);
  func_0xa0fb8054(param_1,0,0xf,uVar1 & 0xf7);
  return;
}
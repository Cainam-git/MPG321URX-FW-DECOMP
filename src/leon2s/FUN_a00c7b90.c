/* leon2s FUN_a00c7b90 @ 0xa00c7b90  MATCH (-mcpu=v8 -Os -g)
 * 
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

void FUN_a00c7b90(uint param_1)

{
  unsigned char uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = func_0xa0fb7fd8(param_1,0,0xf3);
  uVar1 = (uVar1 & 0xfffffff0) | 9;
  func_0xa0fb8054(param_1,0,0xf3,uVar1 & 0xf9);
  return;
}

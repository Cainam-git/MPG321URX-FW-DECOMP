/* leon2s FUN_a00af8bc @ 0xa00af8bc (-mcpu=v8 -Os -g)
 * k = FUN_a00add48(p1, func_0x9f1c6624(p1) & 0xff) & 0xff. Calls FUN_a00a8370(k, 4 / 5 / 6, byte 0 / 1 / 2 of p2)
 * and FUN_a00a8370(k, 8 / 9 / 10, byte 0 / 1 / 2 of p3).
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
extern void FUN_a00a8370();
extern int FUN_a00add48();
extern int func_0x9f1c6624();

void FUN_a00af8bc(unsigned char param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = func_0x9f1c6624(param_1);
  param_1 = FUN_a00add48(param_1,uVar1 & 0xff) & 0xff;
  FUN_a00a8370(param_1,4,param_2 & 0xff);
  FUN_a00a8370(param_1,5,param_2 >> 8 & 0xff);
  FUN_a00a8370(param_1,6,param_2 >> 0x10 & 0xff);
  FUN_a00a8370(param_1,8,param_3 & 0xff);
  FUN_a00a8370(param_1,9,param_3 >> 8 & 0xff);
  FUN_a00a8370(param_1,10,param_3 >> 0x10 & 0xff,param_4,param_5,param_6);
  return;
}
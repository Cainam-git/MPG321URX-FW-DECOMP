/* leon2s FUN_a00c9750 @ 0xa00c9750 (-mcpu=v8 -Os -g)
 * k = p1 & 0xff. Returns the low byte of FUN_a00c972c() when k == 2, of FUN_a00c9370(k) when k < 2, otherwise 0.
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
extern int FUN_a00c9370();
extern int FUN_a00c972c();

int FUN_a00c9750(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0xff;
  uVar1 = 0;
  if (uVar2 == 2) {
    uVar1 = FUN_a00c972c();
  }
  else if (uVar2 < 2) {
    uVar1 = FUN_a00c9370(uVar2);
  }
  return CONCAT44(param_2,uVar1) & 0xffffffff000000ff;
}
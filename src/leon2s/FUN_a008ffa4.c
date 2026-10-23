/* leon2s FUN_a008ffa4 @ 0xa008ffa4 (-mcpu=v8 -Os -g)
 * s = 0 when p1 == 0, s = 1 when p1 == 1. For those two values calls FUN_a0083618(s, 1), FUN_a008ff58(p1) and
 * FUN_a007f8a4(s); any other p1 returns without a call.
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
extern void FUN_a007f8a4(undefined1 param_1);
extern int FUN_a0083618();
extern void FUN_a008ff58(undefined1 param_1);

void FUN_a008ffa4(byte param_1,undefined4 param_2)

{
  unsigned char uVar1;
  
  uVar1 = 0;
  if ((param_1 != 0) && (uVar1 = 1, param_1 != 1)) {
    return CONCAT44(param_2,1);
  }
  FUN_a0083618(uVar1,1);
  FUN_a008ff58(param_1);
  return FUN_a007f8a4((byte)uVar1);
}
/* leon2s FUN_a008e484 @ 0xa008e484 (-mcpu=v8 -Os -g)
 * (a, b, c) = (0, 0, 6) for p2 == 1, (1, 1, 0) for p2 == 2, (0, 0, 0) for any other p2. Calls FUN_a00a80cc(p1, 1,
 * 0x39, 1, a), FUN_a00a80cc(p1, 1, 0x39, 2, b) and FUN_a00a8054(p1, 1, 0x30, c).
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
extern int FUN_a00a8054();
extern int FUN_a00a80cc();

void FUN_a008e484(undefined1 param_1, unsigned char param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  unsigned char uVar1;
  unsigned char uVar2;
  unsigned char uVar3;
  
  uVar1 = 0;
  uVar2 = 0;
  uVar3 = 0;
  if ((param_2 != '\0') && (uVar3 = 6, param_2 != '\x01')) {
    uVar1 = 1;
    uVar2 = 1;
    uVar3 = 0;
    if (param_2 != '\x02') {
      uVar1 = 0;
      uVar2 = 0;
    }
  }
  FUN_a00a80cc(param_1,1,0x39,1,uVar1);
  FUN_a00a80cc(param_1,1,0x39,2,uVar2);
  FUN_a00a8054(param_1,1,0x30,uVar3,param_5,param_6);
  return;
}
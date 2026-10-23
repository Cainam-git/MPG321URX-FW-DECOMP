/* leon2s FUN_a007f900 @ 0xa007f900 (-mcpu=v8 -Os -g)
 * For each bit i (0 .. 3) set in p2 (low byte) calls FUN_a00a7424(1, 4, p1 & 0xff, halfword i of the table at
 * 0xA00B3B68); then FUN_a00b1794(1); then the same loop with 0 as the first argument. Returns p1.
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
extern int FUN_a00a7424();
extern int FUN_a00b1794();
extern undefined2 ARR_a00b3b68[];

int FUN_a007f900(uint param_1,uint param_2)

{
  ushort uVar1;
  
  uVar1 = 0;
  do {
    if (((int)(param_2 & 0xff) >> uVar1 & 1U) != 0) {
      if (uVar1 < 4) {
        FUN_a00a7424(1,4,param_1 & 0xff,ARR_a00b3b68[(uint)uVar1]);
      }
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 4);
  FUN_a00b1794(1);
  uVar1 = 0;
  do {
    if (((int)(param_2 & 0xff) >> uVar1 & 1U) != 0) {
      if (uVar1 < 4) {
        FUN_a00a7424(0,4,param_1 & 0xff,ARR_a00b3b68[(uint)uVar1]);
      }
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 4);
  return CONCAT44(param_2,param_1);
}
/* leon2m FUN_a00b6ec8 @ 0xa00b6ec8 (-mcpu=v8 -O3 -g)
 * Formats p3 & 0xff with "n%3d" into an 8-byte local buffer (FUN_a01577f4, sprintf), sets its first byte to 3,
 * calls FUN_a0146b6c(2, 0) and FUN_a00a31a4(0, p1 & 0xff, p2 & 0xff, 2, buf, 0). Returns p1.
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
extern int FUN_a00a31a4();
extern void FUN_a0146b6c();
extern int FUN_a01577f4();

int FUN_a00b6ec8(uint param_1,uint param_2,undefined1 param_3)

{
  undefined1 local_10 [8];
  
  FUN_a01577f4(local_10,0x1981d0,param_3);
  local_10[0] = 3;
  FUN_a0146b6c(2,0);
  FUN_a00a31a4(0,param_1 & 0xff,param_2 & 0xff,2,local_10,0);
  return CONCAT44(param_2,param_1);
}
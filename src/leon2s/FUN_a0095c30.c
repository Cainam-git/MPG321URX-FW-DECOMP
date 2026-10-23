/* leon2s FUN_a0095c30 @ 0xa0095c30 (-mcpu=v8 -Os -g)
 * For b = 0 and 1 calls FUN_a0091578(b), FUN_a00950a0(b, 0x10), FUN_a0091c84(b, 100) and FUN_a00a80cc(b, 3, 0xf2,
 * 0x10, 1); then FUN_a00a4610(0) and FUN_a00a45d8(0, p2, p3, p4, p5, p6).
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
extern int FUN_a0091578();
extern void FUN_a0091c84();
extern void FUN_a00950a0();
extern int FUN_a00a45d8();
extern int FUN_a00a4610();
extern int FUN_a00a80cc();

void FUN_a0095c30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  byte bVar1;
  
  bVar1 = 0;
  do {
    FUN_a0091578(bVar1);
    FUN_a00950a0(bVar1,0x10);
    FUN_a0091c84(bVar1,100);
    FUN_a00a80cc(bVar1,3,0xf2,0x10,1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 2);
  FUN_a00a4610(0);
  FUN_a00a45d8(0,param_2,param_3,param_4,param_5,param_6);
  return;
}
/* leon2s FUN_a0094370 @ 0xa0094370 (-mcpu=v8 -Os -g)
 * Code: FUN_a00a80cc(p1, 0, 0x12f, 0x40, 0); FUN_a00a8054(p1, 0, 0x13e, 0); FUN_a00a8054(p1, 0, 0x13f, 0);
 * FUN_a00a80cc(p1, 0, 8, 1, 0).
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
extern void FUN_a00a8054();
extern void FUN_a00a80cc();

void FUN_a0094370(undefined1 param_1)

{
  
  FUN_a00a80cc(param_1,0,0x12f,0x40,0);
  FUN_a00a8054(param_1,0,0x13e,0);
  FUN_a00a8054(param_1,0,0x13f,0);
  FUN_a00a80cc(param_1,0,8,1,0);
  return;
}
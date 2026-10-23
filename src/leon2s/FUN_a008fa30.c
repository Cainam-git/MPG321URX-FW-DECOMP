/* leon2s FUN_a008fa30 @ 0xa008fa30 (-mcpu=v8 -Os -g)
 * Code: FUN_a00a65c4(p1, 0x72, 0xff); FUN_a00a65c4(p1, 0x73, 0xff); FUN_a00a65c4(p1, 0x74, 0xff); FUN_a00a65c4(p1,
 * 0x84, 0xff, p4, p5, p6).
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
extern void FUN_a00a65c4();

void FUN_a008fa30(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a65c4(param_1,0x72,0xff);
  FUN_a00a65c4(param_1,0x73,0xff);
  FUN_a00a65c4(param_1,0x74,0xff);
  FUN_a00a65c4(param_1,0x84,0xff,param_4,param_5,param_6);
  return;
}
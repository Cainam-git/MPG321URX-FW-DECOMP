/* leon2m FUN_a0120998 @ 0xa0120998 (-mcpu=v8 -O2 -g)
 * When p2 != 0 calls FUN_a00f2298(p1, 0x88, 0x11), FUN_a00f2068(p1, 0x1c, 0x20, 0) and FUN_a00f2068(p1, 1, 2, 1);
 * otherwise FUN_a00f2298(p1, 0x88, 0x10), FUN_a00f2068(p1, 0x1c, 0x20, 1) and FUN_a00f2068(p1, 1, 2, 0).
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
extern void FUN_a00f2068();
extern void FUN_a00f2298();

void FUN_a0120998(unsigned char param_1, unsigned char param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  if (param_2 != '\0') {
    FUN_a00f2298(param_1,0x88,0x11);
    FUN_a00f2068(param_1,0x1c,0x20,0);
    FUN_a00f2068(param_1,1,2,1,param_5,param_6);
    return;
  }
  FUN_a00f2298(param_1,0x88,0x10);
  FUN_a00f2068(param_1,0x1c,0x20,1);
  FUN_a00f2068(param_1,1,2,0,param_5,param_6);
  return;
}
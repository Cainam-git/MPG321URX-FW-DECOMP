/* leon2m FUN_a00e0090 @ 0xa00e0090 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern void FUN_a00dffa4();
extern void FUN_a00e05d8();

void FUN_a00e0090(undefined4 param_1)

{
  
  FUN_a00e05d8(param_1,0x2ce,0x8f,0x80);
  FUN_a00dffa4(1);
  FUN_a00e05d8(param_1,0x2ce,0x8f,0x8f);
  FUN_a00dffa4(1);
  FUN_a00e05d8(param_1,0x2cd,0x8f,0x80);
  FUN_a00dffa4(1);
  FUN_a00e05d8(param_1,0x2cd,0x8f,0x8f);
  FUN_a00dffa4(1);
  FUN_a00e05d8(param_1,0x5a,0x80,0);
  FUN_a00dffa4(1);
  FUN_a00e05d8(param_1,0x5a,0x80,0x80);
  return;
}
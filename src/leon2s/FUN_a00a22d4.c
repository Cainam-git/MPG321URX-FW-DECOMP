/* leon2s FUN_a00a22d4 @ 0xa00a22d4 (-mcpu=v8 -Os -g)
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
extern void FUN_a007f8a4(undefined1 param_1);
extern int FUN_a0083618();
extern int FUN_a009f66c();

void FUN_a00a22d4(unsigned char param_1,undefined4 param_2)

{
  unsigned char uVar1;
  
  uVar1 = 2;
  if ((param_1 != '\0') && (uVar1 = 3, param_1 != '\x01')) {
    return CONCAT44(param_2,3);
  }
  FUN_a0083618(uVar1,1);
  FUN_a009f66c(param_1);
  return FUN_a007f8a4((byte)uVar1);
}
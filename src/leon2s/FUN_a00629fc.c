/* leon2s FUN_a00629fc @ 0xa00629fc (-mcpu=v8 -Os -g)
 * For i from byte p1 + 0x58 up to 14, stores 0x3FF in halfword i of the halfword array at p1 + 0x5A.
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


void FUN_a00629fc(int param_1)

{
  unsigned char uVar1;
  uint uVar2;
  
  uVar1 = (uint)*(byte *)(param_1 + 0x58);
  uVar2 = uVar1;
  while (uVar2 < 0xf) {
    uVar1 = uVar1 + 1;
    *(undefined2 *)(uVar2 * 2 + param_1 + 0x5a) = 0x3ff;
    uVar2 = uVar1 & 0xff;
  }
  return;
}
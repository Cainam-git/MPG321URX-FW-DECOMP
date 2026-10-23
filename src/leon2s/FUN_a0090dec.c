/* leon2s FUN_a0090dec @ 0xa0090dec (-mcpu=v8 -Os -g)
 * v = FUN_a00a657c(p1, 0x45) & 7. Returns 10 for v = 0, 1, 2, 3 or 5, 0xC for v = 6, 0x10 for v = 7 and 8 for v =
 * 4.
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
extern int FUN_a00a657c();

int FUN_a0090dec(unsigned char param_1)

{
  unsigned char uVar1;
  
  param_1 = FUN_a00a657c(param_1,0x45) & 0xff;
  switch(param_1 & 7) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 5:
    uVar1 = 10;
    break;
  case 6:
    uVar1 = 0xc;
    break;
  case 7:
    uVar1 = 0x10;
    break;
  default:
    uVar1 = 8;
  }
  return uVar1;
}